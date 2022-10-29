/// @file src/sarcos/prettyprinter.hpp

#ifndef SARCOS_PRETTYPRINTER_H
#define SARCOS_PRETTYPRINTER_H

#include <string>
#include "sarcos/math.hpp"

/**
 * @brief Class for handling all formatted prints of vectors, matrices, nodes, etc.
 * 
 */
class PrettyPrinter
{
public:
    /**
     * @brief Default Constructor
     * 
     */
    PrettyPrinter();

    /**
     * @brief Construct a new Pretty Printer object
     * 
     * @param widthBuffer - number of spaces between numbers
     * @param precision - number of desired decimal places
     */
    PrettyPrinter(int widthBuffer, int precision);

    /**
     * @brief Destructor
     * 
     */
    ~PrettyPrinter();

    /**
     * @brief construct pretty print of a Vec3, given width offsets
     * 
     * @param vec - vector
     * @param width - specify x,y,z width offsets to print (used to format column placement)
     */
    void print(const Vec3& vec, const Vec3& width);

    /**
     * @brief pretty print a Vec3
     * 
     * Aligns the columns (right justified), fixed point notation
     * leaving equal fill space between numbers
     * 
     * Example:
     * 
     * [ 1000.000  -2.000  33.000 ]
     * 
     * @param vec - vector
     */
    void print(const Vec3& vec);
    
    /**
     * @brief pretty print a Mat33
     * 
     * Aligns the columns (right justified), fixed point notation
     *  
     * Example:
     * 
     *[  1.000  -2.000   3.000 ]
     *
     *[  1.000   5.000  66.000 ]
     *
     *[ 10.000  -2.000   9.000 ]
     * 
     * @param mat - matrix
     */
    void print(const Mat33& mat);

    /**
     * @brief print node and descendants
     * 
     * @param node 
     */
    void print(Node* node);

    /**
     * @brief compute the size of the formatted string, given a double value
     * 
     * @param val - floating point number
     * @return int 
     */
    int computeStrSize(double val);

    /**
     * @brief compute the max string size among vector values
     * determines the max of x,y,z floating point string sizes
     * 
     * @param vec - vector
     * @return int 
     */
    int computeMaxSize(const Vec3& vec);

    /**
     * @brief set the precision value
     * 
     * @param precision - desired number of decimal places
     */
    void setPrecision(int precision);

    
    /**
     * @brief set the width buffer value
     * 
     * @param widthBuffer - desired number of spaces between numbers
     */
    void setWidthBuffer(int widthBuffer);

private:

    /**
     * @brief default number of spaces between numbers
     * 
     */
    int m_widthBuffer;

    /**
     * @brief number of decimal places used in formatting the floating point numbers
     * 
     */
    int m_precision;
};

#endif // SARCOSPRETTYPRINTER_H