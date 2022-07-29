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
 * @file glstereo.h
 * @author Sk. Mohammadul Haque
 * @version 1.0.0.0
 * @copyright
 * Copyright (c) 2015-2022 Sk. Mohammadul Haque.
 * @brief This file contains declarations of GLStereo structures and functions.
 */

#ifndef __GLSTEREO_H__
#define __GLSTEREO_H__

#define _CRT_SECURE_NO_DEPRECATE
#ifdef __cplusplus
#define __GLSTEREO__CPP__
extern "C"
{
#endif

#include "glstereoerror.h"
#include "glstereomath.h"
#include <malloc.h>
#include <string.h>
#ifdef _MSC_VER
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>


#define GLSTEREO_RED_CYAN (0)
#define GLSTEREO_GREEN_MAGENTA (1)
#define GLSTEREO_MONO (2)


typedef struct glstereoview
{
    float baseline; /**< Stereo baseline */
    float refdepth; /**< Stereo reference depth */
    float fov; /**< Camera field of view */
    float nplane; /**< Camera near plane */
    float fplane; /**< Camera far plane */
    float aratio; /**< Camera aspect ratio */
    mat4f lfrustum; /**< Left frustum matrix */
    mat4f rfrustum; /**< Right frustum matrix */
    mat4f modelview; /**< Modelview matrix */
    vec4i lcmask; /**< Left colour mask */
    vec4i rcmask; /**< Right colour mask */
    int mono; /**< Whether monoview? */
} glstereoview;
typedef glstereoview* GLSTEREOVIEW;

/** \brief Creates a new GLStereo structure
 *
 * \param[in] baseline Stereo baseline
 * \param[in] refdepth Reference depth plane
 * \param[in] fov Camera field of view
 * \param[in] nplane Camera near plane
 * \param[in] fplane Camera far plane
 * \param[in] aratio Camera aspect-ratio
 * \param[in] type Stereo type (GLSTEREO_RED_CYAN/GLSTEREO_GREEN_MAGENTA/GLSTEREO_MONO)
 * \return Pointer to GLStereoview structure
 *
 */

GLSTEREOVIEW glstereo_new(float baseline, float refdepth, float fov, float nplane, float fplane, float aratio, int type);

/** \brief Deletes a given GLStereo structure
 *
 * \param[in] sv  Given GLStereoview structure
 *
 */

void glstereo_delete(GLSTEREOVIEW sv);

#define __glstereo_set_frustum (glstereo_set_frustum)

/** \brief Sets a given frustum
 *
 * \param[out] fst Given frustum
 * \param[in] left Left plane
 * \param[in] right Right plane
 * \param[in] top Top plane
 * \param[in] bottom Bottom plane
 * \param[in] nplane Near plane
 * \param[in] fplane Far plane
 *
 */

void glstereo_set_frustum(mat4f fst, float left, float right, float top, float bottom, float nplane, float fplane);


/** \brief Sets a modelview to a given GLStereo structure
 *
 * \param[out] sv Given GLStereoview structure
 * \param[in] R Rotation matrix
 * \param[in] t Translation vector
 *
 */

void glstereo_set_modelview(GLSTEREOVIEW sv, mat3f R, vec3f t);

/** \brief Loads a modelview from a given GLStereo structure
 *
 * \param[in] sv Given GLStereoview structure
 * \param[out] mv Modelview matrix
 *
 */

void glstereo_load_modelview(GLSTEREOVIEW sv, mat4f mv);

/** \brief Assigns left view as current to a given GLStereo structure
 *
 * \param[in] sv Given GLStereoview structure
 *
 */

void glstereo_left(GLSTEREOVIEW sv);

/** \brief Assigns right view as current to a given GLStereo structure
 *
 * \param[in] sv Given GLStereoview structure
 *
 */

void glstereo_right(GLSTEREOVIEW sv);




#ifdef __cplusplus
}
#endif

#endif

