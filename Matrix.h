/*===============================================================================
FILE:              Matrix.h
DESCRIPTION:       This header file creates the Classes used for Matrices
COMPILER:          Linux GNU g++ compiler c++ -std=c++11
                    using custom makefile and Clion IDE editor
NOTES:             Matrix_ops inherits from Matrix class and Stuff class just contains the stuff used
                        in the Driver
                         Matrix has protected members so Matrix_ops can inherit, so no private members
MODIFICATION HISTORY:
Author                  Date               Version
---------------         ----------         --------------
Shawn Ray       	    2017-04-13         Version 1.0 started project
Shawn Ray       	    2017-04-14         Version 1.1
Shawn Ray       	    2017-04-15         Version 1.2 overloaded operators
Shawn Ray               2017-04-16         Version 1.3 added class definition
                                                for  command line stuffs
Shawn Ray               2017-04-17         Version 1.4 Template class
Shawn Ray               2017-04-18         Version 1.5
Shawn Ray               2017-04-19         Version 1.6 fixed bugged
Shawn Ray               2017-04-20         Version 1.7 templates
Shawn Ray               2017-04-21         Version 1.8 inheritance
Shawn Ray               2017-04-22         Version 1.9
Shawn Ray               2017-04-23         Version 2.0 member function, trans/multi
Shawn Ray               2017-04-24         Version 2.1 member function for det
Shawn Ray               2017-04-25         Version 2.2
Shawn Ray               2017-04-26         Version 2.3
Shawn Ray               2017-04-27         Version 2.4 cleaned up code
Shawn Ray               2017-04-28         Version 2.5 added Clear and resize functions
                                                clear clears the memory and resize resizes
                                                a class object
Shawn Ray               2017-04-29         Version 2.6
Shawn Ray               2017-04-30         Version 2.7
Shawn Ray               2017-05-01         Version 2.8 virtual destruction
Shawn Ray               2017-04-02         Version 2.9
Shawn Ray               2017-04-03         Version 3.0
================================================================================*/


#ifndef PROJ3_MATRIX_H
#define PROJ3_MATRIX_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>


template<typename T>
class Matrix {

protected:
    int rows;
    int cols;
    T **array;
    T deter;
    void resize(const int&, const int&, bool = true);
    void clear();

public:
    Matrix();   // default constructor
    Matrix(int, int);	// overloaded constructor
    Matrix(const Matrix<T> &); // copy constructor

    template<typename U>
    friend std::istream& operator >> (std::istream &, Matrix<U> &);
    template<typename U>
    friend std::ostream& operator << (std::ostream &, const Matrix<U> &);

    Matrix<T>& operator = (const Matrix<T> &);


    virtual ~Matrix();
};

template<typename T>
class Matrix_ops : public Matrix<T>
{

public:

    Matrix_ops(int, int); // intialized constructor
    Matrix_ops(const Matrix_ops<T> &); // initialized copy constructor

    Matrix_ops<T> operator + (const Matrix_ops<T> &) const;
    Matrix_ops<T>  operator - (const Matrix_ops<T>  &) const;
    Matrix_ops<T> operator * (const Matrix_ops<T> &) const;
    bool operator == (const Matrix_ops<T> &) const;

    Matrix_ops<T> trans() const;
    T det();
    Matrix_ops<T> inv();
    Matrix_ops<T> reduced_row() const;
    Matrix_ops<T>& div_row(int);
    Matrix_ops<T> solve() const;

};

class Stuff{
public:
    int m;
    int n;
    int position;
    char let_x;
    char file1[20];
    std::ifstream infile;
};

//function declarations
template<typename T> T expo(const T &, const T &); // to replace the pow function
bool test_arg(int, Stuff &);
void compare_arg(int, char * [], Stuff &);
template<typename T> T open_file(int, char * [], Stuff &);
void help();

#endif //PROJ3_MATRIX_H