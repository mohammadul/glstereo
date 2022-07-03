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
 * @file glstereomath.c
 * @author Sk. Mohammadul Haque
 * @version 1.0.0.0
 * @copyright
 * Copyright (c) 2015-2022 Sk. Mohammadul Haque.
 * @brief This file contains definitions of GLStereo math structures and functions.
 */

#include "../include/glstereomath.h"


void glstereo_mat4_mul(mat4f a, mat4f b, mat4f c)
{
    int i, j, k;
    for(i=0; i<4; ++i)
    {
        for(j=0; j<4; ++j)
        {
            k = j*4;
            c[i+4*j] = a[i]*b[k]+a[i+4]*b[k+1]+a[i+8]*b[k+2]+a[i+12]*b[k+3];
        }
    }
}

void glstereo_mat4_transpose(mat4f a)
{
    float tmp;
    tmp = a[1]; a[1] = a[4]; a[4] = tmp;
    tmp = a[2]; a[2] = a[8]; a[8] = tmp;
    tmp = a[3]; a[3] = a[12]; a[12] = tmp;
    tmp = a[6]; a[6] = a[9]; a[9] = tmp;
    tmp = a[7]; a[7] = a[13]; a[13] = tmp;
    tmp = a[11]; a[11] = a[14]; a[14] = tmp;
}

void glstereo_mat4_disp(mat4f a)
{
    printf("%g %g %g %g \n%g %g %g %g \n%g %g %g %g \n%g %g %g %g \n",
            a[0], a[4], a[8], a[12],
            a[1], a[5], a[9], a[13],
            a[2], a[6], a[10], a[14],
            a[3], a[7], a[11], a[15]);
}

void glstereo_mat4_inv(mat4f a, mat4f b)
{
    float det;
    b[0] = a[5]*a[10]*a[15]-a[5]*a[11]*a[14]-a[9]*a[6]*a[15]+a[9]*a[7]*a[14]+a[13]*a[6]*a[11]-a[13]*a[7]*a[10];
    b[4] = -a[4]*a[10]*a[15]+a[4]*a[11]*a[14]+a[8]*a[6]*a[15]-a[8]*a[7]*a[14]-a[12]*a[6]*a[11]+a[12]*a[7]*a[10];
    b[8] = a[4]*a[9]*a[15]-a[4]*a[11]*a[13]-a[8]*a[5]*a[15]+a[8]*a[7]*a[13]+a[12]*a[5]*a[11]-a[12]*a[7]*a[9];
    b[12] = -a[4]*a[9]*a[14]+a[4]*a[10]*a[13]+a[8]*a[5]*a[14]-a[8]*a[6]*a[13]-a[12]*a[5]*a[10]+a[12]*a[6]*a[9];
    b[1] = -a[1]*a[10]*a[15]+a[1]*a[11]*a[14]+a[9]*a[2]*a[15]-a[9]*a[3]*a[14]-a[13]*a[2]*a[11]+a[13]*a[3]*a[10];
    b[5] = a[0]*a[10]*a[15]-a[0]*a[11]*a[14]-a[8]*a[2]*a[15]+a[8]*a[3]*a[14]+a[12]*a[2]*a[11]-a[12]*a[3]*a[10];
    b[9] = -a[0]*a[9]*a[15]+a[0]*a[11]*a[13]+a[8]*a[1]*a[15]-a[8]*a[3]*a[13]-a[12]*a[1]*a[11]+a[12]*a[3]*a[9];
    b[13] = a[0]*a[9]*a[14]-a[0]*a[10]*a[13]-a[8]*a[1]*a[14]+a[8]*a[2]*a[13]+a[12]*a[1]*a[10]-a[12]*a[2]*a[9];
    b[2] = a[1]*a[6]*a[15]-a[1]*a[7]*a[14]-a[5]*a[2]*a[15]+a[5]*a[3]*a[14]+a[13]*a[2]*a[7]-a[13]*a[3]*a[6];
    b[6] = -a[0]*a[6]*a[15]+a[0]*a[7]*a[14]+a[4]*a[2]*a[15]-a[4]*a[3]*a[14]-a[12]*a[2]*a[7]+a[12]*a[3]*a[6];
    b[10] = a[0]*a[5]*a[15]-a[0]*a[7]*a[13]-a[4]*a[1]*a[15]+a[4]*a[3]*a[13]+a[12]*a[1]*a[7]-a[12]*a[3]*a[5];
    b[14] = -a[0]*a[5]*a[14]+a[0]*a[6]*a[13]+a[4]*a[1]*a[14]-a[4]*a[2]*a[13]-a[12]*a[1]*a[6]+a[12]*a[2]*a[5];
    b[3] = -a[1]*a[6]*a[11]+a[1]*a[7]*a[10]+a[5]*a[2]*a[11]-a[5]*a[3]*a[10]-a[9]*a[2]*a[7]+a[9]*a[3]*a[6];
    b[7] = a[0]*a[6]*a[11]-a[0]*a[7]*a[10]-a[4]*a[2]*a[11]+a[4]*a[3]*a[10]+a[8]*a[2]*a[7]-a[8]*a[3]*a[6];
    b[11] = -a[0]*a[5]*a[11]+a[0]*a[7]*a[9]+a[4]*a[1]*a[11]-a[4]*a[3]*a[9]-a[8]*a[1]*a[7]+a[8]*a[3]*a[5];
    b[15] = a[0]*a[5]*a[10]-a[0]*a[6]*a[9]-a[4]*a[1]*a[10]+a[4]*a[2]*a[9]+a[8]*a[1]*a[6]-a[8]*a[2]*a[5];
    det = a[0]*b[0]+a[1]*b[4]+a[2]*b[8]+a[3]*b[12];
    if(det==0.0f) glstereo_error(GLSTEREO_ERROR_MATH);
    det = 1.0f/det;
    b[0] *= det; b[1] *= det; b[2] *= det; b[3] *= det;
    b[4] *= det; b[5] *= det; b[6] *= det; b[7] *= det;
    b[8] *= det; b[9] *= det; b[10] *= det; b[11] *= det;
    b[12] *= det; b[13] *= det; b[14] *= det; b[15] *= det;
}

void glstereo_rot_vec3_to_mat4(mat4f r, vec3f axis, float ang)
{
    float L, u2, v2, w2;
    ang = ang*GLSTEREO_PI/180.0;
    u2 = axis[0]*axis[0];
    v2 = axis[1]*axis[1];
    w2 = axis[2]*axis[2];
    L = (u2+v2+w2);

    r[0] = (u2+(v2+w2)*cosf(ang))/L;
    r[4] = (axis[0]*axis[1]*(1-cosf(ang))-axis[2]*sqrtf(L)*sinf(ang))/L;
    r[8] = (axis[0]*axis[2]*(1-cosf(ang))+axis[1]*sqrtf(L)*sinf(ang))/L;
    r[12] = 0.0;

    r[1] = (axis[0]*axis[1]*(1-cosf(ang))+axis[2]*sqrtf(L)*sinf(ang))/L;
    r[5] = (v2+(u2+w2)*cosf(ang))/L;
    r[9] = (axis[1]*axis[2]*(1-cosf(ang))-axis[0]*sqrtf(L)*sinf(ang))/L;
    r[13] = 0.0;

    r[2] = (axis[0]*axis[2]*(1-cosf(ang))-axis[1]* sqrtf(L)*sinf(ang))/L;
    r[6] = (axis[1]*axis[2]*(1-cosf(ang))+axis[0]*sqrtf(L)*sinf(ang))/L;
    r[10] = (w2+(u2+v2)*cosf(ang))/L;
    r[14] = 0.0;

    r[3] = 0.0;
    r[7] = 0.0;
    r[11] = 0.0;
    r[15] = 1.0;
}

