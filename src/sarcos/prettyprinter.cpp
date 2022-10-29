/// @file src/sarcos/prettyprinter.cpp

#include "sarcos/prettyprinter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

PrettyPrinter::PrettyPrinter() 
: m_widthBuffer(2) // default value for spaces between numbers
, m_precision(3)   // default value for decimal places
{}

PrettyPrinter::PrettyPrinter(int widthBuffer, int precision) 
: m_widthBuffer(widthBuffer) // init desired spaces between numbers
, m_precision(precision)   // init desired value for decimal places
{}

PrettyPrinter::~PrettyPrinter() {}

void PrettyPrinter::print(const Vec3& vec, const Vec3& width)
{
    cout << "[ "
        << setprecision(m_precision) << std::fixed << std::right
        << setw(width.x) << vec.x 
        << setw(width.y) << vec.y 
        << setw(width.z) << vec.z
        << " ]" << endl;
}

void PrettyPrinter::print(const Vec3& vec)
{
    // Compute the precise width offset to set for each column
    Vec3 width;
    width.x = computeStrSize(vec.x);                 // no need for buffer because single space from bracket   
    width.y = computeStrSize(vec.y) + m_widthBuffer; // add width buffer until next number
    width.z = computeStrSize(vec.z) + m_widthBuffer; // add width buffer until next number

    // printe the vector
    print(vec, width);

    // extra end line because only printing this vector
    cout << endl;
}

int PrettyPrinter::computeStrSize(double val)
{
    stringstream ss;
    // using the same precision as in formatted print, compute the size of the string
    ss << setprecision(m_precision) << fixed << val;
    return ss.str().size();
}

int PrettyPrinter::computeMaxSize(const Vec3& vec)
{
    // return largest of x, y and z
    int maxWidth = max(computeStrSize(vec.x), computeStrSize(vec.y));
    return max(maxWidth, computeStrSize(vec.z));
}

void PrettyPrinter::print(const Mat33& mat)
{
    // calculate the max widths for each column for alignment
    Vec3 width;
    width.x = computeMaxSize(mat.col[0]);
    width.y = computeMaxSize(mat.col[1]) + m_widthBuffer;
    width.z = computeMaxSize(mat.col[2]) + m_widthBuffer;

    // make a copy so we can transpose it
    Mat33 matCopy = copyMat(mat);

    // transpose mat first for print convenience
    // and allow re-use of print vector construct
    transposeMat(matCopy);

    // perform the pretty print
    print(matCopy.col[0], width);
    print(matCopy.col[1], width);
    print(matCopy.col[2], width);

    // extra end line to distinguish the matrix output
    cout << endl;

    // no need to transpose back the copy
}

void PrettyPrinter::print(Node* node)
{
    // first, print the data from this node
    cout << "Node data:" << endl;
    print(node->data);

    // print children, if any
    if (node->children)
    {
        // print an arrow to the children
        string children = "Children";
        cout << setw(children.size()/2) << "|" << endl;
        cout << "Children" << endl;
        cout << setw(children.size()/2) << "|" << endl;
        cout << setw(children.size()/2) << "V" << endl << endl;

        print(node->children);
    }
}

void PrettyPrinter::setPrecision(int precision)
{
    m_precision = precision;
}

void PrettyPrinter::setWidthBuffer(int widthBuffer)
{
    m_widthBuffer = widthBuffer;
}