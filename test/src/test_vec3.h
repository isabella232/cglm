/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "test_common.h"

#define TEST_GLM_SHUFFLE3(z, y, x) (((z) << 4) | ((y) << 2) | (x))

#ifndef CGLM_TEST_VEC3_ONCE
#define CGLM_TEST_VEC3_ONCE

/* Macros */

TEST_IMPL(MACRO_GLM_VEC3_ONE_INIT) {
  vec3 v = GLM_VEC3_ONE_INIT;
  
  ASSERT(glm_eq(v[0], 1.0f))
  ASSERT(glm_eq(v[1], 1.0f))
  ASSERT(glm_eq(v[2], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC3_ZERO_INIT) {
  vec3 v = GLM_VEC3_ZERO_INIT;
  
  ASSERT(glm_eq(v[0], 0.0f))
  ASSERT(glm_eq(v[1], 0.0f))
  ASSERT(glm_eq(v[2], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC3_ONE) {
  ASSERT(glm_eq(GLM_VEC3_ONE[0], 1.0f))
  ASSERT(glm_eq(GLM_VEC3_ONE[1], 1.0f))
  ASSERT(glm_eq(GLM_VEC3_ONE[2], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_VEC3_ZERO) {
  ASSERT(glm_eq(GLM_VEC3_ZERO[0], 0.0f))
  ASSERT(glm_eq(GLM_VEC3_ZERO[1], 0.0f))
  ASSERT(glm_eq(GLM_VEC3_ZERO[2], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_YUP) {
  ASSERT(glm_eq(GLM_YUP[0], 0.0f))
  ASSERT(glm_eq(GLM_YUP[1], 1.0f))
  ASSERT(glm_eq(GLM_YUP[2], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_ZUP) {
  ASSERT(glm_eq(GLM_ZUP[0], 0.0f))
  ASSERT(glm_eq(GLM_ZUP[1], 0.0f))
  ASSERT(glm_eq(GLM_ZUP[2], 1.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_XUP) {
  ASSERT(glm_eq(GLM_XUP[0], 1.0f))
  ASSERT(glm_eq(GLM_XUP[1], 0.0f))
  ASSERT(glm_eq(GLM_XUP[2], 0.0f))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_SHUFFLE3) {
  ASSERT(TEST_GLM_SHUFFLE3(1, 0, 0) == GLM_SHUFFLE3(1, 0, 0))
  ASSERT(TEST_GLM_SHUFFLE3(0, 1, 0) == GLM_SHUFFLE3(0, 1, 0))
  ASSERT(TEST_GLM_SHUFFLE3(0, 0, 1) == GLM_SHUFFLE3(0, 0, 1))
  ASSERT(TEST_GLM_SHUFFLE3(1, 0, 0) == GLM_SHUFFLE3(1, 0, 0))
  ASSERT(TEST_GLM_SHUFFLE3(1, 0, 1) == GLM_SHUFFLE3(1, 0, 1))

  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_XXX) {
  ASSERT(TEST_GLM_SHUFFLE3(0, 0, 0) == GLM_XXX)
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_YYY) {
  ASSERT(TEST_GLM_SHUFFLE3(1, 1, 1) == GLM_YYY)
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_ZZZ) {
  ASSERT(TEST_GLM_SHUFFLE3(2, 2, 2) == GLM_ZZZ)
  TEST_SUCCESS
}

TEST_IMPL(MACRO_GLM_ZYX) {
  ASSERT(TEST_GLM_SHUFFLE3(0, 1, 2) == GLM_ZYX)
  TEST_SUCCESS
}

/* Deprecated */

TEST_IMPL(MACRO_glm_vec3_dup) {
  vec3 v1 = {13.0f, 12.0f, 11.0f}, v2;
  
  glm_vec3_dup(v1, v2);
  
  ASSERTIFY(test_assert_vec3_eq(v1, v2))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec3_flipsign) {
  vec3 v1 = {13.0f, -12.0f, 11.0f},
       v2 = {-13.0f, 12.0f, -11.0f};
  
  glm_vec3_flipsign(v1);

  ASSERTIFY(test_assert_vec3_eq(v1, v2))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec3_flipsign_to) {
  vec3 v1 = {13.0f, -12.0f, 11.0f},
       v2 = {-13.0f, 12.0f, -11.0f},
       v3;
  
  glm_vec3_flipsign_to(v1, v3);

  ASSERTIFY(test_assert_vec3_eq(v2, v3))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec3_inv) {
  vec3 v1 = {13.0f, -12.0f, 11.0f},
       v2 = {-13.0f, 12.0f, -11.0f};
  
  glm_vec3_inv(v1);

  ASSERTIFY(test_assert_vec3_eq(v1, v2))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec3_inv_to) {
  vec3 v1 = {13.0f, -12.0f, 11.0f},
       v2 = {-13.0f, 12.0f, -11.0f},
       v3;
  
  glm_vec3_inv_to(v1, v3);
  
  ASSERTIFY(test_assert_vec3_eq(v2, v3))
  
  TEST_SUCCESS
}

TEST_IMPL(MACRO_glm_vec3_mulv) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3;
  
  glm_vec3_mulv(v1, v2, v3);

  ASSERT(glm_eq(v1[0] * v2[0], v3[0]))
  ASSERT(glm_eq(v1[1] * v2[1], v3[1]))
  ASSERT(glm_eq(v1[2] * v2[2], v3[2]))
  
  TEST_SUCCESS
}

#endif /* CGLM_TEST_VEC3_ONCE */

/* --- */

TEST_IMPL(GLM_PREFIX, vec3) {
  vec4 v4 = {10.0f, 9.0f, 8.0f, 7.0f};
  vec3 v3;
  
  GLM(vec3)(v4, v3);
  
  ASSERT(glm_eq(v3[0], v4[0]))
  ASSERT(glm_eq(v3[1], v4[1]))
  ASSERT(glm_eq(v3[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_copy) {
  vec3 v1 = {10.0f, 9.0f, 8.0f};
  vec3 v2 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_copy)(v1, v2);
  
  ASSERTIFY(test_assert_vec3_eq(v1, v2))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_zero) {
  vec3 v1 = {10.0f, 9.0f, 8.0f};
  vec3 v2 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_zero)(v1);
  GLM(vec3_zero)(v2);
  
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC3_ZERO))
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC3_ZERO))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_one) {
  vec3 v1 = {10.0f, 9.0f, 8.0f};
  vec3 v2 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_one)(v1);
  GLM(vec3_one)(v2);
  
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC3_ONE))
  ASSERTIFY(test_assert_vec3_eq(v1, GLM_VEC3_ONE))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_dot) {
  vec3  a = {10.0f, 9.0f, 8.0f};
  vec3  b = {1.0f, 2.0f, 3.0f};
  float dot1, dot2;
  
  dot1 = GLM(vec3_dot)(a, b);
  dot2 = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  
  ASSERT(glm_eq(dot1, dot2))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_norm2) {
  vec3 a = {10.0f, 9.0f, 8.0f};
  float n1, n2;
  
  n1 = GLM(vec3_norm2)(a);
  n2 = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];

  ASSERT(glm_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_norm) {
  vec3  a = {10.0f, 9.0f, 8.0f};
  float n1, n2;
  
  n1 = GLM(vec3_norm)(a);
  n2 = sqrtf(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);

  ASSERT(glm_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_norm_one) {
  vec3  a = {-10.0f, 9.0f, -8.0f};
  float n1, n2;
  
  n1 = GLM(vec3_norm_one)(a);
  n2 = fabsf(a[0]) + fabsf(a[1]) + fabsf(a[2]);

  ASSERT(glm_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_norm_inf) {
  vec3  a = {-10.0f, 9.0f, -8.0f};
  float n1, n2;
  
  n1 = GLM(vec3_norm_inf)(a);
  n2 = fabsf(a[0]);
  
  if (fabsf(a[0]) < fabsf(a[1]))
    n2 = fabsf(a[1]);
  
  if (fabsf(a[1]) < fabsf(a[2]))
    n2 = fabsf(a[2]);
  
  ASSERT(glm_eq(n1, n2))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_add) {
  vec4 a = {-10.0f, 9.0f, -8.0f};
  vec4 b = {12.0f, 19.0f, -18.0f};
  vec4 c, d;
  
  c[0] = a[0] + b[0];
  c[1] = a[1] + b[1];
  c[2] = a[2] + b[2];
  
  GLM(vec3_add)(a, b, d);
  
  ASSERTIFY(test_assert_vec3_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_adds) {
  vec4  a = {-10.0f, 9.0f, -8.0f};
  vec4  c, d;
  float s = 7.0f;
  
  c[0] = a[0] + s;
  c[1] = a[1] + s;
  c[2] = a[2] + s;
  
  GLM(vec3_adds)(a, s, d);
  
  ASSERTIFY(test_assert_vec3_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_sub) {
  vec4 a = {-10.0f, 9.0f, -8.0f};
  vec4 b = {12.0f, 19.0f, -18.0f};
  vec4 c, d;
  
  c[0] = a[0] - b[0];
  c[1] = a[1] - b[1];
  c[2] = a[2] - b[2];
  
  GLM(vec3_sub)(a, b, d);
  
  ASSERTIFY(test_assert_vec3_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_subs) {
  vec4  a = {-10.0f, 9.0f, -8.0f};
  vec4  c, d;
  float s = 7.0f;
  
  c[0] = a[0] - s;
  c[1] = a[1] - s;
  c[2] = a[2] - s;
  
  GLM(vec3_subs)(a, s, d);
  
  ASSERTIFY(test_assert_vec3_eq(c, d))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_mul) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3;
  
  GLM(vec3_mul)(v1, v2, v3);

  ASSERT(glm_eq(v1[0] * v2[0], v3[0]))
  ASSERT(glm_eq(v1[1] * v2[1], v3[1]))
  ASSERT(glm_eq(v1[2] * v2[2], v3[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_scale) {
  vec3  v1 = {2.0f, -3.0f, 4.0f}, v2;
  float s  = 7.0f;
  
  GLM(vec3_scale)(v1, s, v2);

  ASSERT(glm_eq(v1[0] * s, v2[0]))
  ASSERT(glm_eq(v1[1] * s, v2[1]))
  ASSERT(glm_eq(v1[2] * s, v2[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_scale_as) {
  vec3  v1 = {2.0f, -3.0f, 4.0f}, v2;
  float s  = 7.0f;
  float norm;

  GLM(vec3_scale_as)(v1, s, v2);

  norm = sqrtf(v1[0] * v1[0] + v1[1] * v1[1] + v1[2] * v1[2]);
  if (norm == 0.0f) {
    ASSERT(glm_eq(v1[0], 0.0f))
    ASSERT(glm_eq(v1[1], 0.0f))
    ASSERT(glm_eq(v1[2], 0.0f))

    TEST_SUCCESS
  }
  
  norm = s / norm;
  
  ASSERT(glm_eq(v1[0] * norm, v2[0]))
  ASSERT(glm_eq(v1[1] * norm, v2[1]))
  ASSERT(glm_eq(v1[2] * norm, v2[2]))

  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_div) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3;
  
  GLM(vec3_div)(v1, v2, v3);

  ASSERT(glm_eq(v1[0] / v2[0], v3[0]))
  ASSERT(glm_eq(v1[1] / v2[1], v3[1]))
  ASSERT(glm_eq(v1[2] / v2[2], v3[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_divs) {
  vec3  v1 = {2.0f, -3.0f, 4.0f}, v2;
  float s  = 7.0f;
  
  GLM(vec3_divs)(v1, s, v2);

  ASSERT(glm_eq(v1[0] / s, v2[0]))
  ASSERT(glm_eq(v1[1] / s, v2[1]))
  ASSERT(glm_eq(v1[2] / s, v2[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_addadd) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {1.0f, 2.0f, 3.0f},
       v4 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_addadd)(v1, v2, v4);

  ASSERT(glm_eq(v3[0] + v1[0] + v2[0], v4[0]))
  ASSERT(glm_eq(v3[1] + v1[1] + v2[1], v4[1]))
  ASSERT(glm_eq(v3[2] + v1[2] + v2[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_subadd) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {1.0f, 2.0f, 3.0f},
       v4 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_subadd)(v1, v2, v4);

  ASSERT(glm_eq(v3[0] + v1[0] - v2[0], v4[0]))
  ASSERT(glm_eq(v3[1] + v1[1] - v2[1], v4[1]))
  ASSERT(glm_eq(v3[2] + v1[2] - v2[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_muladd) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {1.0f, 2.0f, 3.0f},
       v4 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_muladd)(v1, v2, v4);

  ASSERT(glm_eq(v3[0] + v1[0] * v2[0], v4[0]))
  ASSERT(glm_eq(v3[1] + v1[1] * v2[1], v4[1]))
  ASSERT(glm_eq(v3[2] + v1[2] * v2[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_muladds) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {1.0f, 2.0f, 3.0f},
       v3 = {1.0f, 2.0f, 3.0f};
  float s = 9.0f;
  
  GLM(vec3_muladds)(v1, s, v3);

  ASSERT(glm_eq(v2[0] + v1[0] * s, v3[0]))
  ASSERT(glm_eq(v2[1] + v1[1] * s, v3[1]))
  ASSERT(glm_eq(v2[2] + v1[2] * s, v3[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_maxadd) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {1.0f, 2.0f, 3.0f},
       v4 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_maxadd)(v1, v2, v4);

  ASSERT(glm_eq(v3[0] + glm_max(v1[0], v2[0]), v4[0]))
  ASSERT(glm_eq(v3[1] + glm_max(v1[1], v2[1]), v4[1]))
  ASSERT(glm_eq(v3[2] + glm_max(v1[2], v2[2]), v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_minadd) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {1.0f, 2.0f, 3.0f},
       v4 = {1.0f, 2.0f, 3.0f};
  
  GLM(vec3_minadd)(v1, v2, v4);

  ASSERT(glm_eq(v3[0] + glm_min(v1[0], v2[0]), v4[0]))
  ASSERT(glm_eq(v3[1] + glm_min(v1[1], v2[1]), v4[1]))
  ASSERT(glm_eq(v3[2] + glm_min(v1[2], v2[2]), v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_negate_to) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3, v4;
  
  GLM(vec3_negate_to)(v1, v3);
  GLM(vec3_negate_to)(v2, v4);

  ASSERT(glm_eq(-v1[0], v3[0]))
  ASSERT(glm_eq(-v1[1], v3[1]))
  ASSERT(glm_eq(-v1[2], v3[2]))
  
  ASSERT(glm_eq(-v2[0], v4[0]))
  ASSERT(glm_eq(-v2[1], v4[1]))
  ASSERT(glm_eq(-v2[2], v4[2]))
  
  TEST_SUCCESS
}

TEST_IMPL(GLM_PREFIX, vec3_negate) {
  vec3 v1 = {2.0f, -3.0f, 4.0f},
       v2 = {-3.0f, 4.0f, -5.0f},
       v3 = {2.0f, -3.0f, 4.0f},
       v4 = {-3.0f, 4.0f, -5.0f};
  
  GLM(vec3_negate)(v1);
  GLM(vec3_negate)(v2);

  ASSERT(glm_eq(-v1[0], v3[0]))
  ASSERT(glm_eq(-v1[1], v3[1]))
  ASSERT(glm_eq(-v1[2], v3[2]))
  
  ASSERT(glm_eq(-v2[0], v4[0]))
  ASSERT(glm_eq(-v2[1], v4[1]))
  ASSERT(glm_eq(-v2[2], v4[2]))
  
  TEST_SUCCESS
}
