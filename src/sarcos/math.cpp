/// @file src/sarcos/math.cpp

#include "sarcos/math.hpp"
#include <algorithm>

using namespace std;

double dotProduct(const Vec3& vec1, const Vec3& vec2)
{
    return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
}

void transposeMat(Mat33& mat)
{
    // perform swap 1: y1 <-> x2
    std::swap(mat.col[0].y, mat.col[1].x);

    // perform swap 2: z1 <-> x3
    std::swap(mat.col[0].z, mat.col[2].x);

    // perform swap 3: z2 <-> y3
    std::swap(mat.col[1].z, mat.col[2].y);
}

Mat33 copyMat(const Mat33& mat)
{
    Mat33 matCopy;
    for (int c=0; c<3; c++)
    {
        matCopy.col[c].x = mat.col[c].x;
        matCopy.col[c].y = mat.col[c].y;
        matCopy.col[c].z = mat.col[c].z;
    }
    return matCopy;
}