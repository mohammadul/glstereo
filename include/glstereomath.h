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

#define GLSTEREO_PI (3.14159265359)


typedef int vec3i[3];
typedef int vec4i[4];
typedef int mat3i[9];
typedef int mat4i[16];
typedef float vec3f[3];
typedef float vec4f[4];
typedef float mat3f[9];
typedef float mat4f[16];

void glstereo_mat4_mul(mat4f a, mat4f b, mat4f c);
void glstereo_mat4_transpose(mat4f a);
void glstereo_mat4_disp(mat4f a);
void glstereo_mat4_inv(mat4f a, mat4f b);
void glstereo_rot_vec3_to_mat4(mat4f r, vec3f axis, float ang);

#endif

