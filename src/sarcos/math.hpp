/// @file src/sarcos/math.hpp

#ifndef SARCOS_MATH_H
#define SARCOS_MATH_H

/**
 * @brief 3D vector
 * 
 * [x, y, z]
*/
struct Vec3
{
    double x, y, z;
};

/**
 * @brief 3x3 matrix of double values
 * 
 * col1    col2    col3
 * 
 * x1      x2      x3
 * 
 * y1      y2      y3
 * 
 * z1      z2      z3
*/
struct Mat33
{
    Vec3 col[3];
};

/**
 * @brief Node containing matrix data
 * 
 */
struct Node
{
    /// matrix data
    Mat33 data;

    /// child node
    Node* children;

    /// number of children down the tree
    unsigned int numChildren;
};

/**
 * @brief compute dot product of two vectors
 * 
 * @param vec1 - vector 1
 * @param vec2 - vector 2
 * @return double 
 */
double dotProduct(const Vec3& vec1, const Vec3& vec2);

/**
 * @brief transpose matrix (in place)
 * 
 * @param mat - matrix
 */
void transposeMat(Mat33& mat);

/**
 * @brief deep copy of a Mat33
 * 
 * @param mat 
 * @return Mat33 
 */
Mat33 copyMat(const Mat33& mat);

#endif // SARCOS_MATH_H