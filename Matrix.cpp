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
================================================================================*/

#include "Matrix.h"

/*=============================================================================
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/
template<typename T>
Matrix<T>::Matrix(){
    std::cout << "\tTest default constructor \n"; //remove
    rows = 0;
    cols = 0;
    **array = NULL;

}

/*=============================================================================
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/
template<typename T>
Matrix<T>::Matrix(int n_rows, int n_cols){

    std::cout << "\tTest overloaded construtctor \n"; //remove

    resize(n_rows, n_cols, false);
}

/*=============================================================================
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/
template<typename T>
Matrix_ops<T>::Matrix_ops(const Matrix_ops<T> &m1){

    std::cout << "\tTest copy construtctor \n"; //remove
    *this = m1;
}

/*=============================================================================
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
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
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
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
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/
template<typename T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T> &m1){

    if(this->rows != m1.rows || this->cols != m1.cols) {
        resize(m1.rows, m1.cols);
    }
    for(int i = 0; i < m1.rows; ++i){
        for(int j = 0; j < m1.cols; j++){
            array[i][j] = m1.array[i][j];
            std::cout << array[i][j] << " ";
        }

    }

    return *this;
}

/*=============================================================================
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/
template<typename T>
void Matrix<T>::resize(int s_row, int s_col, bool doclear){

    if(doclear) clear();
    std::cout << "Resizing to " << s_row << "x" << s_col << std::endl; // remove
    rows = s_row;
    cols = s_col;

    array = new T*[s_row];

    for(int i = 0; i < s_row; ++i){
        array[i] = new T[s_col];
        for(int j = 0; j < s_col; ++j){

            array[i][j] = 0;

        }
    }

}

/*=============================================================================
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/

template<typename T>
Matrix_ops<T>::Matrix_ops(int i, int j) : Matrix<T>::Matrix(i, j) {}

/*=============================================================================
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/

template<typename T>
Matrix_ops<T> Matrix_ops<T>::operator + (const Matrix_ops<T> &m1) const{

    Matrix_ops<T> m2(this->rows,this->cols);

    for(int i = 0; i < m1.rows; ++i){
        for(int j = 0; j < m1.cols; j++){
            m2.array[i][j] = this->array[i][j] + m1.array[i][j];
        }

    }
    return m2;
}


template<typename T>
Matrix_ops<T> Matrix_ops<T>::operator - (const Matrix_ops<T> &m1) const{

    Matrix_ops<T> m2(this->rows,this->cols);

    for(int i = 0; i < m1.rows; ++i){
        for(int j = 0; j < m1.cols; j++){
            m2.array[i][j] = this->array[i][j] - m1.array[i][j];
        }

    }
    return m2;
}

template<typename T>
Matrix_ops<T> Matrix_ops<T>::operator * (const Matrix_ops<T> &m1) const{

    int r = this->rows;
    int c = m1.cols;
    int h = m1.rows;

    Matrix_ops<T> m2(r,c);

    //if(this->cols != m1.rowsr,c) {error};

    for(int k = 0; k < r; ++k){
        for(int i = 0; i < c; ++i) {
            for (int j = 0; j < h; ++j) {
                m2.array[k][i] += (this->array[k][j] * m1.array[j][i]);
            }
        }
    }
    return m2;
}

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
template<typename T>
T Matrix_ops<T>::det(){
    std::cout << "\tTest Determinant\n"; // remove



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



template<typename T>
Matrix_ops<T> Matrix_ops<T>::inv(){

    Matrix_ops<T> m1(this->rows, (2 * this->cols));



    return m1;
}

template<typename T>
Matrix_ops<T> Matrix_ops<T>::solve(){

    if(this->cols - 1 != this->rows)
            throw "\tThis system can not be solved by Cramer's rule!\n";

    //T resultarray[this->rows - 1]; // contains the number of variables
    Matrix_ops<T> maj_det(this->rows, this->cols - 1);
    Matrix_ops<T> var_det(this->rows, this->cols - 1);
    Matrix_ops<T> result_mat(this->cols - 1, 1);
    //T result_array[this->rows - 1];

    for (int i = 0; i < this->cols; ++i) {
        for (int j = 0; j < this->rows; ++j) {
            for(int k = 0; k < this->cols-1; ++k){

                    var_det.array[j][k] = this->array[j][k];
                        if(!i){
                            maj_det.array[j][k] = this->array[j][k];
                            std::cout << "\tTest maj det if statement";
                            std::cout << maj_det; //remove
                        }
                        if(k == i){
                           var_det.array[j][k] = this->array[j][this->cols - 1];
                           std::cout << "\tTest var det if statement";
                            std::cout << var_det; //remove
                        }
                }

            }
            if(i == this->cols - 1) continue;
                result_mat.array[i][0] = (var_det.det() / maj_det.det());
                std::cout << "\nfoo\n";
                std::cout << result_mat.array[i][0];

        }

        return result_mat;
}



/*=============================================================================
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/
template<typename T>
Matrix<T>::~Matrix(){
    std::cout <<"\t Destructor\n";
    clear();

}
template<typename T>
void Matrix<T>::clear(){
    std::cout <<"\t clear\n";
    for(int i = 0; i < rows; ++i)
    delete [] array[i];

    delete [] array;
}


template<typename T>
T expo(const T &base, const T &power){

    switch(power){
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