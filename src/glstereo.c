/**
    MIT License

    Copyright (c) 2022 Sk. Mohammadul Haque

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

/**
 * @file glstereo.c
 * @author Sk. Mohammadul Haque
 * @version 1.0.0.0
 * @copyright
 * Copyright (c) 2015-2022 Sk. Mohammadul Haque.
 * @brief This file contains definitions of GLStereo structures and functions.
 */

#include "../include/glstereo.h"

GLSTEREOVIEW glstereo_new(float baseline, float refdepth, float fov, float nplane, float fplane, float aratio, int type)
{
    float top, bottom, left, right, a, b, c;
    GLSTEREOVIEW sv = NULL;
    if((sv = (GLSTEREOVIEW) malloc(sizeof(glstereoview)))==NULL) glstereo_error(GLSTEREO_ERROR_MALLOC);
    if(type==GLSTEREO_MONO||baseline==0.0f)
    {
        sv->mono = 1;
        baseline = 0.0f;
    }
    else sv->mono = 0;
    sv->aratio = aratio;
    sv->baseline = baseline;
    sv->fov = fov*GLSTEREO_PI/180.0;
    sv->fplane = fplane;
    sv->nplane = nplane;
    sv->refdepth = refdepth;
    top = nplane*tanf(sv->fov/2);
    bottom  = -top;
    a = aratio*tanf(sv->fov/2)*refdepth;
    b = a-baseline/2;
    c = a+baseline/2;

    left = -b*nplane/refdepth;
    right = c*nplane/refdepth;
    __glstereo_set_frustum(sv->lfrustum, left, right, top, bottom, nplane, fplane);

    left = -c*nplane/refdepth;
    right = b*nplane/refdepth;
    __glstereo_set_frustum(sv->rfrustum, left, right, top, bottom, nplane, fplane);

    memset(sv->modelview, 0, 16*sizeof(float));
    sv->modelview[0] = 1.0f;
    sv->modelview[5] = 1.0f;
    sv->modelview[10] = 1.0f;
    sv->modelview[15] = 1.0f;
    switch(type)
    {
    case GLSTEREO_RED_CYAN:
        sv->lcmask[0] = GL_TRUE;
        sv->lcmask[1] = GL_FALSE;
        sv->lcmask[2] = GL_FALSE;
        sv->lcmask[3] = GL_FALSE;

        sv->rcmask[0] = GL_FALSE;
        sv->rcmask[1] = GL_TRUE;
        sv->rcmask[2] = GL_TRUE;
        sv->rcmask[3] = GL_FALSE;
        break;

    case GLSTEREO_GREEN_MAGENTA:
        sv->lcmask[0] = GL_FALSE;
        sv->lcmask[1] = GL_TRUE;
        sv->lcmask[2] = GL_FALSE;
        sv->lcmask[3] = GL_FALSE;

        sv->rcmask[0] = GL_TRUE;
        sv->rcmask[1] = GL_FALSE;
        sv->rcmask[2] = GL_TRUE;
        sv->rcmask[3] = GL_FALSE;
        break;

    case GLSTEREO_MONO:
        sv->lcmask[0] = GL_TRUE;
        sv->lcmask[1] = GL_TRUE;
        sv->lcmask[2] = GL_TRUE;
        sv->lcmask[3] = GL_TRUE;

        sv->rcmask[0] = GL_FALSE;
        sv->rcmask[1] = GL_FALSE;
        sv->rcmask[2] = GL_FALSE;
        sv->rcmask[3] = GL_FALSE;
        break;

    default:
        glstereo_error(GLSTEREO_ERROR_TYPE);
    }
    return sv;
}

void glstereo_delete(GLSTEREOVIEW sv)
{
    if(sv!=NULL) free(sv);
}


void glstereo_set_frustum(mat4f fst, float left, float right, float top, float bottom, float nplane, float fplane)
{
    fst[0] = 2.0*nplane/(right-left);
    fst[1] = 0.0f;
    fst[2] = 0.0f;
    fst[3] = 0.0f;
    fst[4] = 0.0f;
    fst[5] = 2.0*nplane/(top-bottom);
    fst[6] = 0.0f;
    fst[7] = 0.0f;
    fst[8] = (right+left)/(right-left);
    fst[9] = (top+bottom)/(top-bottom);
    fst[10] = -(fplane+nplane)/(fplane-nplane);
    fst[11] = -1.0f;
    fst[12] = 0.0f;
    fst[13] = 0.0f;
    fst[14] = -(2*fplane*nplane)/(fplane-nplane);
    fst[15] = 0.0f;
}

void glstereo_set_modelview(GLSTEREOVIEW sv, mat3f R, vec3f t)
{
    mat4f tmp;
    tmp[0] = R[0];
    tmp[1] = R[1];
    tmp[2] = R[2];
    tmp[3] = 0.0f;
    tmp[4] = R[3];
    tmp[5] = R[4];
    tmp[6] = R[5];
    tmp[7] = 0.0f;
    tmp[8] = R[6];
    tmp[9] = R[7];
    tmp[10] = R[8];
    tmp[11] = 0.0f;
    tmp[12] = t[0];
    tmp[13] = t[1];
    tmp[14] = t[2];
    tmp[15] = 1.0f;
    glstereo_mat4_inv(tmp, sv->modelview);
}

void glstereo_load_modelview(GLSTEREOVIEW sv, mat4f mv)
{
    memcpy(mv, sv->modelview, sizeof(float)*16);
}

void glstereo_left(GLSTEREOVIEW sv)
{
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(sv->lfrustum);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef((sv->baseline)/2, 0.0f, 0.0f);
    glMultMatrixf(sv->modelview);
    glColorMask(sv->lcmask[0], sv->lcmask[1], sv->lcmask[2], sv->lcmask[3]);
    glClear(GL_DEPTH_BUFFER_BIT);
}

void glstereo_right(GLSTEREOVIEW sv)
{
    if(sv->mono==0)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixf(sv->rfrustum);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(-(sv->baseline)/2, 0.0f, 0.0f);
        glMultMatrixf(sv->modelview);
        glColorMask(sv->rcmask[0], sv->rcmask[1], sv->rcmask[2], sv->rcmask[3]);
        glClear(GL_DEPTH_BUFFER_BIT);
    }
}

