/// @file src/sarcos/math_test.cpp

#include <gtest/gtest.h>
#include "sarcos/math.hpp"

/**
 * @brief Vec3 stack instance
 * 
 */
TEST(MathTest, Vec3_Stack)
{
    Vec3 vec0 = {0,0,0};    // zero
    Vec3 vec1 = {1,2,3};    // positive
    Vec3 vec2 = {-1,-2,-3}; // negative
    Vec3 vec3 = {-1,2,3};   // mixed
}

/**
 * @brief Vec3 heap instance
 * 
 */
TEST(MathTest, Vec3_Heap)
{
    Vec3* vec = new Vec3();
    vec->x = 4;
    vec->y = 7.4;
    vec->z = -800;

    // cleanup
    delete vec;
    vec = nullptr;
}

/**
 * @brief Compute dot product of two vectors and verify result
 * 
 */
TEST(MathTest, dotProduct)
{
    // define two vectors
    Vec3 vec1 = {0,0,0};
    Vec3 vec2 = {0,0,0};
    EXPECT_EQ(0.0, dotProduct(vec1, vec2));

    // test positive values
    vec1 = {1,2,3};
    vec2 = {4,5,6};

    // dot product should match answer
    EXPECT_EQ(32.0, dotProduct(vec1, vec2));

    // test negative values
    vec2 = {-4,-5,6};
    EXPECT_EQ(4.0, dotProduct(vec1, vec2));
}

/**
 * @brief Mat33 stack instance
 * 
 */
TEST(MathTest, Mat33_Stack)
{
    Mat33 mat = {{{0,0,5}, {0,0,0}, {4,0,0}}};
    EXPECT_EQ(5, mat.col[0].z);
    EXPECT_EQ(4, mat.col[2].x);
}

/**
 * @brief Mat33 heap instance
 * 
 */
TEST(MathTest, Mat33_Heap)
{
    Vec3 vec1 = {0,0,5};
    Vec3 vec2 = {0,0,0};
    Vec3 vec3 = {4,0,0};
    Mat33* mat = new Mat33();
    mat->col[0] = vec1;
    mat->col[1] = vec2;
    mat->col[2] = vec3;

    EXPECT_EQ(5, mat->col[0].z);
    EXPECT_EQ(4, mat->col[2].x);

    // cleanup
    delete mat;
    mat = nullptr;
}

/**
 * @brief Transpose a 3x3 matrix and verify the result
 * 
 */
TEST(MathTest, transposeMat)
{
    Mat33 mat = {{{1,2,3.5}, {4,5,6.65}, {7,8,9}}};

    // transpose the matrix
    transposeMat(mat);

    // Now mat is {{1,4,7}, {2,5,8}, {3.5,6.65,9}}};

    // diagonal remains unchanged
    EXPECT_EQ(1.0, mat.col[0].x);
    EXPECT_EQ(5.0, mat.col[1].y);
    EXPECT_EQ(9.0, mat.col[2].z);

    // y1 <-> x2
    EXPECT_EQ(4.0, mat.col[0].y);
    EXPECT_EQ(2.0, mat.col[1].x);

    // z1 <-> x3
    EXPECT_EQ(7.0, mat.col[0].z);
    EXPECT_EQ(3.5, mat.col[2].x);

    // z2 <-> y3
    EXPECT_EQ(8.0, mat.col[1].z);
    EXPECT_EQ(6.65, mat.col[2].y);
}

/**
 * @brief Perform a deep copy of a Mat33 and verify the result
 * 
 */
TEST(MathTest, copyMat)
{
    Mat33 mat = {{{1,2,3}, {4,5,6}, {7,8,9}}};

    // copy the matrix
    Mat33 matCopy = copyMat(mat);

    // all values equal
    for (int c=0; c<3; c++)
    {
        EXPECT_EQ(mat.col[c].x, matCopy.col[c].x);
        EXPECT_EQ(mat.col[c].y, matCopy.col[c].y);
        EXPECT_EQ(mat.col[c].z, matCopy.col[c].z);
    }
}