/*===============================================================================
FILE:              Matrix.cpp

DESCRIPTION:       This program is the implementation file for the Matrix and Matrix_ops
                    Classes declared in Matrix.h

COMPILER:          Linux GNU g++ compiler c++ -std=c++11
                    using custom makefile and Clion IDE editor

NOTES:             Includes the member functions for both the Matrix and Matrix_ops objects
                    includes Matrix.h for the Classes
                    includes Expo function but not a class member

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
Shawn Ray               2017-04-23         Version 2.0 Multiplication and Transpose
Shawn Ray               2017-04-24         Version 2.1 worked on the determinate
Shawn Ray               2017-04-25         Version 2.2
Shawn Ray               2017-04-26         Version 2.3
Shawn Ray               2017-04-27         Version 2.4 cleaned up code
Shawn Ray               2017-04-28         Version 2.5 added Clear and resize functions
                                               clear clears the memory and resize resizes
                                                a class object
Shawn Ray               2017-04-29         Version 2.6 destructor bug,
Shawn Ray               2017-04-30         Version 2.7 Virtual destruction,
Shawn Ray               2017-05-01         Version 2.8  inverse of a matrix
Shawn Ray               2017-05-02         Version 2.9  inverse of a matrix
Shawn Ray               2017-05-03         Version 3.0  continued project
Shawn Ray               2017-05-04         Version 3.1 added member function for
                                                    for output file
Shawn Ray               2017-05-05         Version 3.2 Worked on completing the inverse
================================================================================*/

#include "Matrix.h"

/*=============================================================================
FUNCTION:          Matrix<T>::Matrix(
DESCRIPTION:       This function is the default constructor for the Matrix class
                    it sets all values to null whenever an object is created.
RETURNS:           Being a constructor, this function returns a Matrix object
NOTES:             templated class functions
===============================================================================*/
template<typename T>
Matrix<T>::Matrix(){
    std::cout << "\tTest default constructor \n"; //remove
    rows = 0;
    cols = 0;
    array = NULL;

}

/*=============================================================================
FUNCTION:          Matrix<T>::Matrix(int n_rows, int n_cols)
DESCRIPTION:       This is the overloaded constructor for the Matrix class,
                    This takes a size of a matrix (rows, cols) and calls the
                      resize function
RETURNS:           Being a constructor, this function returns a Matrix object
NOTES:             templated class functions
===============================================================================*/
template<typename T>
Matrix<T>::Matrix(int n_rows, int n_cols){

    std::cout << "\tTest overloaded construtctor \n"; //remove

    resize(n_rows, n_cols, false);
}

/*=============================================================================
FUNCTION:          Matrix<T>::Matrix(const Matrix<T> &m1)
DESCRIPTION:       This is the copy constructor, it calls the assignment operator
                    to copy a Matrix to another.
RETURNS:           Being a constructor, this function returns a Matrix object
NOTES:             templated class functions
===============================================================================*/
template<typename T>
Matrix<T>::Matrix(const Matrix<T> &m1){

    std::cout << "\tTest copy construtctor \n"; //remove
    (*this) = m1;
}

/*=============================================================================
FUNCTION:          std::istream& operator >> (std::istream &input, Matrix<T> &m1)
DESCRIPTION:       This function overloads the extraction operators to take input
                    into a Matrix Object
RETURNS:           The function returns an istream type named input
NOTES:             templated class functions
===============================================================================*/
template<typename T>
std::istream& operator >> (std::istream &input, Matrix<T> &m1){

    for(int i = 0; i < m1.rows; ++i){
        for(int j = 0; j < m1.cols; ++j){
            input >> m1.array[i][j];
        }
    }
    return input;

}

/*=============================================================================
FUNCTION:          std::ostream& operator << (std::ostream &output, const Matrix<T> &m1)
DESCRIPTION:       This function overloads the insertion operators to display a Matrix
                    object not only to a screen but also a file
RETURNS:           This function returns the ostream type named output
NOTES:             templated class functions
===============================================================================*/
template<typename T>
std::ostream& operator << (std::ostream &output, const Matrix<T> &m1){

    output << std::endl;
    for(int i = 0; i < m1.rows; ++i){
        for(int j = 0; j < m1.cols; j++){
            output << std::setw(4) << m1.array[i][j];
        }
        output << std::endl;
    }
    output << std::endl;
    return output;

}

/*=============================================================================
FUNCTION:          Matrix Matrix::operator = (const Matrix &m1
DESCRIPTION:       Assigned the elements of polynomial m1 to the
                    this polynomial
RETURNS:           Returns the object being worked with (this)
NOTES:             templated class functions
===============================================================================*/
template<typename T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T> &m1){

    //if(this->rows != m1.rows || this->cols != m1.cols) {
    std::cout << "\tTest = operator resize prior\n"; // remove
    std::cout << "\tTest m1 rows\n"; // remove
    std::cout << m1.rows;// remove
    std::cout << "\tTest m1 cols\n"; // remove
    std::cout << m1.cols; // remove
    this->resize(m1.rows, m1.cols);
    std::cout << "\tTest = operator resize post\n"; // remove
    //}
    for(int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->cols; j++){
            this->array[i][j] = m1.array[i][j];
            std::cout << this->array[i][j] << " "; // remove
        }

    }

    return *this;
}

/*=============================================================================
FUNCTION:          Matrix<T>::resize(const int &s_row, const int &s_col, bool doclear)
DESCRIPTION:       The purpose of this function is to resize a Matrix object as needed
RETURNS:           Nothing (Void Function)
NOTES:             templated class functions and is a *protected* member
===============================================================================*/
template<typename T>
void Matrix<T>::resize(const int &s_row, const int &s_col, bool doclear){


    if(doclear){
        std::cout << "doclear\n";
        this->clear();

    }

    std::cout << "\tResizing to " << s_row << "x" << s_col << std::endl; // remove
    this->rows = s_row;
    this->cols = s_col;

    this->array = new T*[s_row];

    for(int i = 0; i < s_row; ++i){
        this->array[i] = new T[s_col];
        for(int j = 0; j < s_col; ++j){

            this->array[i][j] = 0;

        }
    }

}

/*=============================================================================
FUNCTION:          Matrix_ops<T>::Matrix_ops(int i, int j) : Matrix<T>::Matrix(i, j) {}
DESCRIPTION:       Overloaded constructor for Matrix_ops
RETURNS:           Being a constructor, this function returns a Matrix object
NOTES:             templated class functions -- initialized from the overloaded
                            constructor from Matrix class
===============================================================================*/

template<typename T>
Matrix_ops<T>::Matrix_ops(int i, int j) : Matrix<T>::Matrix(i, j) {}

/*=============================================================================
FUNCTION:          Matrix_ops<T>::Matrix_ops(const Matrix_ops<T>& m1) : Matrix<T>::Matrix(m1)
DESCRIPTION:       This function is the copy constructor for Matrix_ops class
RETURNS:           Being a constructor, this function returns a Matrix object
NOTES:             templated class functions -- initialized from the copy
                            constructor from Matrix class
===============================================================================*/

template<typename T>
Matrix_ops<T>::Matrix_ops(const Matrix_ops<T>& m1) : Matrix<T>::Matrix(m1) {}

/*=============================================================================
FUNCTION:          Matrix_ops<T> Matrix_ops<T>::operator + (const Matrix_ops<T> &m1) const
DESCRIPTION:       This function overloads the + operator to add to Matrices
RETURNS:           Returns the result of the addition as an Object
NOTES:             templated class functions -- declared const as to not modify
                        the objects passed to it.
===============================================================================*/

template<typename T>
Matrix_ops<T> Matrix_ops<T>::operator + (const Matrix_ops<T> &m1) const{

    if(this->rows != m1.rows || this->cols != m1.cols)
        throw "\tThe matrices are of different sizes!\n";

    Matrix_ops<T> m2(this->rows,this->cols);

    for(int i = 0; i < m1.rows; ++i){
        for(int j = 0; j < m1.cols; j++){
            m2.array[i][j] = this->array[i][j] + m1.array[i][j];
        }

    }
    return m2;
}

/*=============================================================================
FUNCTION:          Matrix_ops<T> Matrix_ops<T>::operator - (const Matrix_ops<T> &m1) const
DESCRIPTION:       This function overloads the - operator to subtract two Matrices
RETURNS:           Returns the result of the subtraction as an Object
NOTES:             templated class functions -- declared const as to not modify
                        the objects passed to it.
===============================================================================*/

template<typename T>
Matrix_ops<T> Matrix_ops<T>::operator - (const Matrix_ops<T> &m1) const{

    if(this->rows != m1.rows || this->cols != m1.cols)
        throw "\tThe matrices are of different sizes!\n";

    Matrix_ops<T> m2(this->rows,this->cols);

    for(int i = 0; i < m1.rows; ++i){
        for(int j = 0; j < m1.cols; j++){
            m2.array[i][j] = this->array[i][j] - m1.array[i][j];
        }

    }
    return m2;
}

/*=============================================================================
FUNCTION:          Matrix_ops<T> Matrix_ops<T>::operator * (const Matrix_ops<T> &m1) const
DESCRIPTION:       This function overloads the * operator to multiply two Matrices
RETURNS:           Returns the result of the multiplication as an Object
NOTES:             templated class functions -- declared const as to not modify
                        the objects passed to it.
===============================================================================*/

template<typename T>
Matrix_ops<T> Matrix_ops<T>::operator * (const Matrix_ops<T> &m1) const{

    Matrix_ops<T> m2(this->rows,m1.cols);

    if(this->cols != m1.rows)
        throw "\n\tYou can not multiply Matrices without matching sizes\n";

    for(int k = 0; k < this->rows; ++k){
        for(int i = 0; i < m1.cols; ++i) {
            for (int j = 0; j < m1.rows; ++j) {
                m2.array[k][i] += (this->array[k][j] * m1.array[j][i]);
            }
        }
    }
    return m2;
}

/*=============================================================================
FUNCTION:          Matrix_ops<T>::operator == (const Matrix_ops<T> &m1) const
DESCRIPTION:       This function tests if two Matrix objects are equal by
                    overloading the == sign
RETURNS:           This function returns true or false depending on if the Matrices
                        are equal or not.
NOTES:             templated class functions -- declared const as to not modify
                        the objects passed to it.
===============================================================================*/

template<typename T>
bool Matrix_ops<T>::operator == (const Matrix_ops<T> &m1) const{


    if(this->rows != m1.rows || this->cols != m1.cols){
        return false;
    }else {
        for(int i = 0; i < m1.rows; ++i){
            for(int j = 0; j < m1.cols; j++){
                if(this->array[i][j] != m1.array[i][j])
                    return false;
            }
        }
    }
    return true;

}

/*=============================================================================
FUNCTION:          Matrix_ops<T> Matrix_ops<T>::trans() const
DESCRIPTION:       This function computers the transpose of a Matrix
RETURNS:           Returns the resulting object of the tranpose
NOTES:             templated class functions -- declared const as to not modify
                        the objects passed to it.
===============================================================================*/

template<typename T>
Matrix_ops<T> Matrix_ops<T>::trans() const{

    Matrix_ops<T> m1(this->cols, this->rows);

    for(int i = 0; i < this->rows; ++i){
        for(int j = 0; j < this->cols; ++j){
            m1.array[j][i] = this->array[i][j];
        }
    }
    return m1;

}

/*=============================================================================
FUNCTION:          Matrix_ops<T>::det()
DESCRIPTION:       This function computes the determinant of a Matrix
RETURNS:           This function returns the result of the determinant as
                    the templated data after the result of determination
NOTES:             templated class functions -- This function uses Recursion
===============================================================================*/

template<typename T>
T Matrix_ops<T>::det(){
    std::cout << "\tTest Determinant\n"; // remove

    if(this->rows != this->cols)
        throw "\n\tYou can not take a determinant of a non-square matrix\n";

    if (this->rows == 2) {
        std::cout << "\tTest Determinant base case\n"; // remove
        this->deter = ((this->array[0][0] * this->array[1][1]) - (this->array[1][0] * this->array[0][1]));
    } else {

        std::cout << "\tTest Determinant recursive case\n"; // remove
        Matrix_ops<T> m1(this->rows - 1, this->cols - 1);

        this->deter = 0;
        int l = 0;

        for (int i = 0; i < this->cols; ++i) {
            for (int j = 1; j < this->rows; ++j) {
                l = 0;
                for (int k = 0; k < this->cols; ++k) {
                    if (k != i){
                        m1.array[j - 1][l] = this->array[j][k];
                        ++l;
                    }
                }
            }
            this->deter +=  this->array[0][i] * expo(-1,i) * m1.det() ;
        }
    }
    return this->deter;
}

/*=============================================================================
FUNCTION:          Matrix_ops<T> Matrix_ops<T>::inv()
DESCRIPTION:       This function computes the inverse of a Matrix
RETURNS:           The function returns the resulting Matrix inverse object
NOTES:             templated class functions
===============================================================================*/

template<typename T>
Matrix_ops<T> Matrix_ops<T>::inv(){

    if(this->det() == 0)
        throw "\n\tThis matrix does not have an inverse\n";

    Matrix_ops<T> m1(this->rows, (2 * this->cols));

    for (int i = 0; i < this->cols; ++i) { // add an identity matrix
        for (int j = 0; j < this->rows; ++j) {
            m1.array[i][j] = this->array[i][j];
            m1.array[i][this->cols + i] = 1;
        }
    }



    std::cout << "\n\n\tTest inverse m1 prior to reduced row \n"; //remove
    std::cout << m1; //remove

    m1.reduced_row();

    return m1;
}

/*=============================================================================
FUNCTION:          Matrix_ops<T> Matrix_ops<T>::reduced_row() const
DESCRIPTION:       This function puts a Matrix in reduced row echelon form
RETURNS:           This function returns the resulting Matrix object
NOTES:             templated class functions -- declared const as not to modify
                    the objects passed to it
===============================================================================*/

template <typename T>
Matrix_ops<T> Matrix_ops<T>::reduced_row() const{

    if(this->rows >= this->cols)
        throw "\n\tThis is not an augmented matrix!\n";


    Matrix_ops<T> m1(this->rows, this->cols);
    m1 = *this;

    std::cout << "\n\n\t Post assign \n"; //remove
    std::cout << m1; //remove
    std::cout << "\n\n\tthis rows \n"; //remove
    std::cout << this->rows;//remove
    std::cout << "\n\n\tthis cols \n"; //remove
    std::cout << this->cols;//remove
    std::cout << "\n\n\tm1 rows \n"; //remove
    std::cout << m1.rows;//remove
    std::cout << "\n\n\tm1 cols \n"; //remove
    std::cout << m1.cols;//remove

    for(int i = 0; i < m1.rows; ++i) {

        m1.div_row(i);

        for(int j =  i + 1; j < m1.rows; ++j){
            for(int k = 0; k < m1.cols; ++k){

                    m1.array[j][k] -= (m1.array[i][k] * m1.array[j][i]);

            }
        }


    }
    std::cout << "\tTest inverse m1 \n"; //remove
    std::cout << m1; //remove

    return m1;
}

/*=============================================================================
FUNCTION:          Matrix_ops<T>& Matrix_ops<T>::div_row(int i)
DESCRIPTION:       This function takes a Matrix object and divides a row
                    of that Matrix by the element in the position passed
RETURNS:           This function returns the object being worked with (this)
NOTES:             templated class functions
===============================================================================*/

template<typename T>
Matrix_ops<T>& Matrix_ops<T>::div_row(int i){

    T temp = this->array[i][i];

    for(int k = i; k < this->cols; ++k){
        this->array[i][k] /= temp;
        std::cout << "\n\n\t k loop \n"; //remove
        std::cout << std::setprecision(2) <<  *this; //remove
    }
    return *this;
}

/*=============================================================================
FUNCTION:          Matrix_ops<T> Matrix_ops<T>::solve() const
DESCRIPTION:       This function solves a system of equations using cramers rule
RETURNS:           Returns a *vector* Matrix of the results of the solving
NOTES:             templated class functions -- declared const as not to modify
                    the objects passed to it
===============================================================================*/

template<typename T>
Matrix_ops<T> Matrix_ops<T>::solve() const{

    std::cout << "\nTest solve\n"; //remove

    if(this->cols - 1 != this->rows)
        throw "\n\tThis system can not be solved by Cramer's rule!\n";


    Matrix_ops<T> maj_det(this->rows, this->cols - 1);
    Matrix_ops<T> var_det(this->rows, this->cols - 1);
    Matrix_ops<T> result_mat(this->cols - 1, 1);


    for (int i = 0; i < this->cols; ++i) {
        for (int j = 0; j < this->rows; ++j) {
            for(int k = 0; k < this->cols-1; ++k){

                var_det.array[j][k] = this->array[j][k];
                if(!i){
                    maj_det.array[j][k] = this->array[j][k];
                    std::cout << "\tTest maj det if statement"; // remove
                    std::cout << maj_det; //remove
                }
                if(k == i){
                    var_det.array[j][k] = this->array[j][this->cols - 1];
                    std::cout << "\tTest var det if statement"; //remove
                    std::cout << var_det; //remove
                }
            }

        }
        if(i == this->cols - 1) continue;
        result_mat.array[i][0] = (var_det.det() / maj_det.det());
        std::cout << "\nfoo\n"; //remove
        std::cout << result_mat.array[i][0]; //remove

    }

    return result_mat;
}

/*=============================================================================
FUNCTION:          Matrix_ops<T>& Matrix_ops<T>::out_file(char file [])
DESCRIPTION:       This function is a member of Matrix and does the output file
                    of the object passed into it.
RETURNS:           Returns the object being worked with (this) but implied
NOTES:             templated class functions
===============================================================================*/

template<typename T>
Matrix_ops<T>& Matrix_ops<T>::out_file(char file []){

    std::ofstream outfile;

    strcat(file, ".mtx");

    outfile.open(file);

    outfile << std::setw(4) << this->rows << " X " << this->cols;

    outfile << *this;

    outfile.close();

}



/*=============================================================================
FUNCTION:          Matrix<T>::~Matrix()
DESCRIPTION:       This is the destructor used by both Matrix and Matrix_ops classes
                    This destructs objects after they are done being used and calls
                     clear to do it.
RETURNS:           destructors do not return Objects
NOTES:             templated class functions
===============================================================================*/

template<typename T>
Matrix<T>::~Matrix(){
    std::cout <<"\t Destructor\n"; //remove
    this->clear();

}

/*=============================================================================
FUNCTION:          void Matrix<T>::clear()
DESCRIPTION:       This functions sole purpose is too clear out the memory of a
                    Matrix object
RETURNS:           Nothing (Void Function)
NOTES:             templated class functions -- *protected* member function
===============================================================================*/

template<typename T>
void Matrix<T>::clear(){
    std::cout <<"\t clear\n";//remove
    for(int i = 0; i < this->rows; ++i){
        delete [] this->array[i];
        this->array[i] = NULL;
    }

    delete [] this->array;

}

/*=============================================================================
FUNCTION:          expo(const T &base, const T &power)
DESCRIPTION:       This function computes the exponent of a base and the number
                        is is raised to (like the pow function)
RETURNS:           Returns the templated data after the result of exponentiation
NOTES:             templated class functions and uses recursion
===============================================================================*/

template<typename T>
T expo(const T &base, const T &power) {

    switch (power) {
        case 0:
            return 1;
        case 1:
            return base;
        case 2:
            return base * base;
        default:
            return (base * (expo(base, power - 1)));
    }
}