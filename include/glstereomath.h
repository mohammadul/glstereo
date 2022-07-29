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
 * @file glstereomath.h
 * @author Sk. Mohammadul Haque
 * @version 1.0.0.0
 * @copyright
 * Copyright (c) 2015-2022 Sk. Mohammadul Haque.
 * @brief This file contains declarations of GLStereo math structures and functions.
 */

#ifndef __GLMATH_H__
#define __GLMATH_H__

#include <stdio.h>
#include <math.h>
#include "glstereoerror.h"

#define GLSTEREO_PI (3.14159265359) /**< \f$ \pi \f$ */


typedef int vec3i[3]; /**< 3-integer vector */
typedef int vec4i[4]; /**< 4-integer vector */
typedef int mat3i[9]; /**< 3x3-integer matrix */
typedef int mat4i[16]; /**< 4x4-integer matrix */
typedef float vec3f[3]; /**< 3-float vector */
typedef float vec4f[4]; /**< 4-float vector */
typedef float mat3f[9]; /**< 3x3-float matrix */
typedef float mat4f[16]; /**< 4x4-float matrix */

/** \brief Computes matrix-multiplication given two matrices
 *
 * \param[in] a First given matrix
 * \param[in] b Second given matrix
 * \param[out] c Output result matrix
 *
 */

void glstereo_mat4_mul(mat4f a, mat4f b, mat4f c);

/** \brief Computes in-place matrix-transposition given a matrix
 *
 * \param[in] a Given matrix
 *
 */

void glstereo_mat4_transpose(mat4f a);

/** \brief Displays a given matrix
 *
 * \param[in] a Given matrix
 *
 */

void glstereo_mat4_disp(mat4f a);

/** \brief Computes matrix-inverse given a matrix
 *
 * \param[in] a Given matrix
 * \param[out] b Output inverse matrix
 *
 */

void glstereo_mat4_inv(mat4f a, mat4f b);

/** \brief Computes matrix-representation given a rotation axis and a magnitude in degrees
 *
 * \param[out] r Output transformation matrix
 * \param[in] axis Given rotation axis
 * \param[in] ang Given rotation angle in degrees
 *
 */

void glstereo_rot_vec3_to_mat4(mat4f r, vec3f axis, float ang);

#endif

