#include <iostream>
#include <iomanip>
#include "sarcos/math.hpp"
#include "sarcos/prettyprinter.hpp"

using namespace std;

/**
 * @brief main entry function
 * 
 * @return int 
 */
int main()
{
    PrettyPrinter printer;

    Vec3 vec1;
    vec1.x = 4.6;
    vec1.y = -5;
    vec1.z = 10;

    Vec3 vec2;
    vec2.x = 3;
    vec2.y = 9.0;
    vec2.z = -1;

    Vec3 vec3;
    vec3.x = -2;
    vec3.y = 3.0;
    vec3.z = 1;

    /// --------------------------
    /// Simple demonstration of the requested functionality
    /// --------------------------
    cout << "\nDemonstration:\n";

    /// --------------------------
    /// Vector print
    /// --------------------------
    cout << "\nPretty print a vector:\n";
    cout << "vec1: ";
    printer.print(vec1);

    cout << "vec2: ";
    printer.print(vec2);


    /// --------------------------
    /// Dot product
    /// --------------------------
    cout << "Compute the dot product of two vectors:\n";
    cout << "dot(vec, vec2) = " << dotProduct(vec1, vec2) << endl;


    /// --------------------------
    /// Matrix print
    /// --------------------------
    cout << "\nPretty print a matrix:\n";
    Mat33 mat = {{{1,-2,13}, {4,-5.4,6}, {7.23,800,-9}}};
    printer.print(mat);

    Mat33 mat2 = {{{2,0,0}, {67,7,6}, {7,-1,9}}};
    Mat33 mat3 = {{{3,2,5}, {3,5,1}, {7,0,9}}};
    Mat33 mat4 = {{{4,12,3}, {4,4,7}, {-54.8,8,0}}};


    /// --------------------------
    /// Transpose a matrix
    /// --------------------------
    cout << "\nPretty print the transpose of that matrix:\n";
    transposeMat(mat);
    printer.print(mat);


    /// --------------------------
    /// Deep copy of a matrix
    /// --------------------------
    cout << "\nCopy the matrix:\n";
    cout << "Addr of mat: " << &mat << endl;
    Mat33 matCopy = copyMat(mat);
    cout << "Addr of matCopy: " << &matCopy << endl;
    cout << "\nPretty print the copy:\n";
    printer.print(matCopy);


    /// --------------------------
    /// Node Creation and print descendants
    /// --------------------------
    cout << "Node Creation:\n\n";

    cout << "Node 1:\n";
    Node* node1 = new Node();
    node1->data = mat;
    cout << "data:\n";
    printer.print(node1->data);
    node1->numChildren = 3;
    cout << "children: " << node1->numChildren << endl << endl;

    cout << "Node 2:\n";
    Node* node2 = new Node();
    node2->data = mat2;
    printer.print(node2->data);
    node2->numChildren = 2;
    cout << "children: " << node2->numChildren << endl << endl;

    cout << "Node 3:\n";
    Node* node3 = new Node();
    node3->data = mat3;
    printer.print(node3->data);
    node3->numChildren = 1;
    cout << "children: " << node3->numChildren << endl << endl;

    cout << "Node 4:\n";
    Node* node4 = new Node();
    node4->data = mat4;
    printer.print(node4->data);
    node4->numChildren = 0;
    cout << "children: " << node4->numChildren << endl << endl;

    // manually set children
    node1->children = node2;
    node2->children = node3;
    node3->children = node4;
    node4->children = nullptr;

    // pretty print node descendants
    cout << "Pretty print Node 1 and its descendants:\n";
    printer.print(node1);


    // cleanup memory
    delete node4;
    node4 = nullptr;
    delete node3;
    node3 = nullptr;
    delete node2;
    node2 = nullptr;
    delete node1;
    node1 = nullptr;

    return 0;
}