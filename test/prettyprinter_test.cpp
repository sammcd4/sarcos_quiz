/// @file src/sarcos/prettyprinter_test.cpp

#include <gtest/gtest.h>
#include "sarcos/prettyprinter.hpp"
#include <memory>

using namespace std;

/**
 * @brief All tests for PrettyPrinter
 * 
 * @see PrettyPrinter()
 * 
 */
class PrettyPrinterTest : public testing::Test
{
protected:

    /**
     * @brief Called before each test case
     * 
     */
    void SetUp() override
    {
        p_printer_ = std::make_unique<PrettyPrinter>();

        // reset/start capturing output
        startCapture();
    }

    /**
     * @brief wrapper to gtest CaptureStdout call
     * used to retrieve stdout and verify format
     * 
     */
    void startCapture()
    {
        testing::internal::CaptureStdout();
    }

    /**
     * @brief wrapper to gtest GetCapturedStdout call
     * 
     * @return std::string 
     */
    std::string getCapture()
    {
        return testing::internal::GetCapturedStdout();
    }

    /**
     * @brief object under test
     * 
     * @see PrettyPrinter()
     * 
     */
    std::unique_ptr<PrettyPrinter> p_printer_;
};

/**
 * @brief Set desired precision on vector print
 * 
 */
TEST_F(PrettyPrinterTest, printVec3_Precision)
{
    // change the precision from the default
    p_printer_->setPrecision(5);

    // Vector with all zero values
    Vec3 vec = {0,0,0};

    // print vector
    p_printer_->print(vec);

    // verify the formatted string
    EXPECT_EQ("[ 0.00000  0.00000  0.00000 ]\n\n", getCapture());
}

/**
 * @brief Set desired width buffer on vector print
 * 
 */
TEST_F(PrettyPrinterTest, printVec3_WidthBuffer)
{
    // change the precision from the default
    p_printer_->setWidthBuffer(6);

    // Vector with all zero values
    Vec3 vec = {0,0,0};

    // print vector
    p_printer_->print(vec);

    // verify the formatted string
    EXPECT_EQ("[ 0.000      0.000      0.000 ]\n\n", getCapture());
}

/**
 * @brief Print a vector of all positive values
 * 
 */
TEST_F(PrettyPrinterTest, printVec3_Pos)
{
    // Vector with all positive values
    Vec3 vec = {1.72, 5000, 84.6};

    // print vector
    p_printer_->print(vec);

    // verify the formatted string
    EXPECT_EQ("[ 1.720  5000.000  84.600 ]\n\n", getCapture());
}

/**
 * @brief Print a vector of all negative values
 * 
 */
TEST_F(PrettyPrinterTest, printVec3_Neg)
{
    // Vector with all positive values
    Vec3 vec = {-55.75, -88, -4};

    // print vector
    p_printer_->print(vec);

    // verify the formatted string
    EXPECT_EQ("[ -55.750  -88.000  -4.000 ]\n\n", getCapture());
}

/**
 * @brief Print a vector of both positive and negative values
 * 
 */
TEST_F(PrettyPrinterTest, printVec3_Mixed)
{
    // Vector with all positive values
    Vec3 vec = {55.75, -88, -4000};

    // print vector
    p_printer_->print(vec);

    // verify the formatted string
    EXPECT_EQ("[ 55.750  -88.000  -4000.000 ]\n\n", getCapture());
}

/**
 * @brief Print a 3x3 matrix with desired precision
 * 
 */
TEST_F(PrettyPrinterTest, printMat33_Precision)
{
    p_printer_->setPrecision(2);
    Mat33 mat = {{{0,0,0}, {0,0,0}, {0,0,0}}};

    // print vector
    p_printer_->print(mat);

    // verify the formatted string
    EXPECT_EQ("[ 0.00  0.00  0.00 ]\n"
              "[ 0.00  0.00  0.00 ]\n"
              "[ 0.00  0.00  0.00 ]\n"
              "\n", getCapture());
}

/**
 * @brief Print a 3x3 matrix with desired width buffer
 * 
 */
TEST_F(PrettyPrinterTest, printMat33_WidthBuffer)
{
    p_printer_->setWidthBuffer(8);
    Mat33 mat = {{{0,0,0}, {200000,0,0}, {0,800,0}}};

    // print vector
    p_printer_->print(mat);

    // verify the formatted string
    EXPECT_EQ("[ 0.000        200000.000          0.000 ]\n"
              "[ 0.000             0.000        800.000 ]\n"
              "[ 0.000             0.000          0.000 ]\n"
              "\n", getCapture());
}

/**
 * @brief Print a 3x3 matrix of all positive values
 * 
 */
TEST_F(PrettyPrinterTest, printMat33_Pos)
{
    Mat33 mat = {{{1,2,3.5}, {4,5000,6}, {7,8.888,9}}};

    // print vector
    p_printer_->print(mat);

    // verify the formatted string
    EXPECT_EQ("[ 1.000     4.000  7.000 ]\n"
              "[ 2.000  5000.000  8.888 ]\n"
              "[ 3.500     6.000  9.000 ]\n"
              "\n", getCapture());
}

/**
 * @brief Print a 3x3 matrix of all negative values
 * 
 */
TEST_F(PrettyPrinterTest, printMat33_Neg)
{
    Mat33 mat = {{{-1,-2543,-3}, {-4123,-5,-6}, {-75.6,-8,-9}}};

    // print vector
    p_printer_->print(mat);

    // verify the formatted string
    EXPECT_EQ("[    -1.000  -4123.000  -75.600 ]\n"
              "[ -2543.000     -5.000   -8.000 ]\n"
              "[    -3.000     -6.000   -9.000 ]\n"
              "\n", getCapture());
}

/**
 * @brief Print a 3x3 matrix of both positive and negative values
 * 
 */
TEST_F(PrettyPrinterTest, printMat33_Mixed)
{
    Mat33 mat = {{{1,2543,-3}, {-4123,5,-6}, {75.6,-8,-9}}};

    // print vector
    p_printer_->print(mat);

    // verify the formatted string
    EXPECT_EQ("[    1.000  -4123.000  75.600 ]\n"
              "[ 2543.000      5.000  -8.000 ]\n"
              "[   -3.000     -6.000  -9.000 ]\n"
              "\n", getCapture());
}

/**
 * @brief Print a Node that points to no children.
 * This print should be identical to a matrix print,
 * except for the additional "Node data:" printed before
 * the matrix
 */
TEST_F(PrettyPrinterTest, printNode)
{
    // single node, without children
    Node* node = new Node();
    node->data = {{{1,2543,-3}, {-4123,5,-6}, {75.6,-8,-9}}};
    node->children = nullptr;

    // first, obtain the output of the matrix print
    p_printer_->print(node->data);
    string matCapture = getCapture();

    // now, obtain the output of the node print
    startCapture();
    p_printer_->print(node);
    string nodeCapture = getCapture();

    // should be the same except for "Node data:" in print node
    EXPECT_EQ("Node data:\n" + matCapture, nodeCapture);

    // cleanup
    delete node;
    node = nullptr;
}

/**
 * @brief Print a Node and all its descendants
 * 
 */
TEST_F(PrettyPrinterTest, printNodeChildren)
{
    // Create the nodes under test
    Node* node1 = new Node();
    node1->data = {{{2,0,0}, {67,7,6}, {7,-1,9}}};
    node1->numChildren = 2;

    Node* node2 = new Node();
    node2->data = {{{3,2,5}, {3,5,1}, {7,0,9}}};
    node2->numChildren = 1;

    Node* node3 = new Node();
    node3->data = {{{4,12,3}, {4,4,7}, {-54.8,8,0}}};
    node3->numChildren = 0;

    // assign child nodes
    node1->children = node2;
    node2->children = node3;

    // print the node
    p_printer_->print(node1);

    EXPECT_EQ("Node data:\n"
              "[ 2.000  67.000   7.000 ]\n"
              "[ 0.000   7.000  -1.000 ]\n"
              "[ 0.000   6.000   9.000 ]\n"
              "\n"
              "   |\n"
              "Children\n"
              "   |\n"
              "   V\n"
              "\n"
              "Node data:\n"
              "[ 3.000  3.000  7.000 ]\n"
              "[ 2.000  5.000  0.000 ]\n"
              "[ 5.000  1.000  9.000 ]\n"
              "\n"
              "   |\n"
              "Children\n"
              "   |\n"
              "   V\n"
              "\n"
              "Node data:\n"
              "[  4.000  4.000  -54.800 ]\n"
              "[ 12.000  4.000    8.000 ]\n"
              "[  3.000  7.000    0.000 ]\n"
              "\n", getCapture());


    // cleanup
    delete node1;
    node1 = nullptr;
    delete node2;
    node2 = nullptr;
    delete node3;
    node3 = nullptr;
}