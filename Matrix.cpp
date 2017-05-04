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
Shawn Ray               2017-04-02         Version 2.9  inverse of a matrix
Shawn Ray               2017-04-03         Version 3.0  continued project
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
Matrix<T>::Matrix(const Matrix<T> &m1){

    std::cout << "\tTest copy construtctor \n"; //remove
    (*this) = m1;
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
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/
template<typename T>
void Matrix<T>::resize(const int &s_row, const int &s_col, bool doclear){


    if(doclear){
        std::cout << "doclear\n";
        this->clear();

    }

    std::cout << "Resizing to " << s_row << "x" << s_col << std::endl; // remove
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
Matrix_ops<T>::Matrix_ops(const Matrix_ops<T>& m1) : Matrix<T>::Matrix(m1) {}

/*=============================================================================
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
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

template <typename T>
Matrix_ops<T> Matrix_ops<T>::reduced_row() const{

    if(this->rows >= this->cols)
        throw "\n\tThis is not an augmented matrix!\n";


    Matrix_ops<T> m1(this->rows, this->cols);
    m1 = *this;

    std::cout << "\n\n\t Post assign \n"; //remove
    std::cout << m1; //remove


    std::cout << "\n\n\tthis rows \n"; //remove
    std::cout << this->rows;
    std::cout << "\n\n\tthis cols \n"; //remove
    std::cout << this->cols;
    std::cout << "\n\n\tm1 rows \n"; //remove
    std::cout << m1.rows;
    std::cout << "\n\n\tm1 cols \n"; //remove
    std::cout << m1.cols;

    for(int i = 0; i < m1.rows; ++i) {

        m1.div_row(i);

            for (int j = 0; j < m1.rows; ++j) {

                if (j != i){
                    for (int n = 0; n < m1.cols; ++n) {
                        T temp = m1.array[i][i];
                        m1.array[j][n] -= (temp * m1.array[j][n]);
                    }
                }
        }
    }
    std::cout << "\tTest inverse m1 \n"; //remove
    std::cout << m1; //remove

    return m1;
}

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
FUNCTION:          name-of-function()
DESCRIPTION:       A brief description of this function ...
RETURNS:           What the function returns ... or ...
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/

template<typename T>
Matrix<T>::~Matrix(){
    std::cout <<"\t Destructor\n"; //remove
    this->clear();

}
template<typename T>
void Matrix<T>::clear(){
    std::cout <<"\t clear\n";//remove
    for(int i = 0; i < this->rows; ++i){
        std::cout <<"\t before delete\n";//remove
        delete [] this->array[i];
        //this->array[i] = NULL;
        std::cout <<"\t after delete\n";//remove
    }
    std::cout <<"\t post for loop clear\n";//remove
    delete [] this->array;
/*
    for(int i = this->cols; i >= 0; --i){
        for(int j = 0; j < this->rows; ++j){
            free(this->array[j]);
        }
        free(this->array[i]);
    }*/

}


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
