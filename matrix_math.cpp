/*===============================================================================
FILE:              matrix_math.cpp
DESCRIPTION:       This program is the main driver program for matrix.cpp and Matrix.h
COMPILER:          Linux GNU g++ compiler c++ -std=c++11
                    using custom makefile and Clion IDE editor
NOTES:             Includes the implementation file Matrix.cpp
MODIFICATION HISTORY:
Author                  Date               Version
---------------         ----------         --------------
Shawn Ray       	    2017-04-13         Version 1.0 started project
Shawn Ray       	    2017-04-14         Version 1.1
Shawn Ray       	    2017-04-15         Version 1.2 overloaded operators
Shawn Ray               2017-04-16         Version 1.3 added functions for command line
Shawn Ray               2017-04-17         Version 1.4 templated open file.
Shawn Ray               2017-04-18         Version 1.5
Shawn Ray               2017-04-19         Version 1.6 fixed bugged
Shawn Ray               2017-04-20         Version 1.7 templates
Shawn Ray               2017-04-21         Version 1.8 inheritance
Shawn Ray               2017-04-22         Version 1.9
Shawn Ray               2017-04-23         Version 2.0
Shawn Ray               2017-04-23         Version 2.1
Shawn Ray               2017-04-25         Version 2.2 added stuffs for class objects
Shawn Ray               2017-04-26         Version 2.3 added stuffs for class objects
Shawn Ray               2017-04-27         Version 2.4 added stuffs for class objects
Shawn Ray               2017-04-28         Version 2.5 added stuffs for class objects
Shawn Ray               2017-04-29         Version 2.6  bug fix
Shawn Ray               2017-04-30         Version 2.7  bug fix
Shawn Ray               2017-05-01         Version 2.8
Shawn Ray               2017-04-02         Version 2.9
Shawn Ray               2017-04-03         Version 3.0 bug fix
================================================================================*/


#include "Matrix.cpp" // specification


/*=============================================================================
FUNCTION:          main()
DESCRIPTION:       Creates a matrix object, sets some values and displays it
RETURNS:           Main being in type returns a 0 to signify successful completion
NOTES:             Put other information here ...
===============================================================================*/


int main(int argc, char *argv[]){

    Stuff command_var;

    std::cout << "\tTest main\n"; // remove

    if(test_arg(argc, command_var)) return 0;
    std::cout << "\tTest main after \n"; // remove

    compare_arg(argc, argv, command_var);
    std::cout << "\tTest compare_arg after \n";//remove
    return 0;
}

/*=============================================================================
FUNCTION:          bool test_arg(int argc, const Stuff &command_var)
DESCRIPTION:       This function tests to see if there are enough command line
RETURNS:           Being boolean type, it returns true or false depending on
                    if there are enough command line arguments
NOTES:             passed another class object for variables
===============================================================================*/

bool test_arg(int argc, Stuff &command_var){
    std::cout << "\tTest testg_arg \n";//remove
    if(argc < 2){
        std::cout << "Not enough Arguments ?\n\n";
        return true;
    } else {
        command_var.position = 1;
        return false;
    }

}

/*=============================================================================
FUNCTION:          void compare_arg(char *argv[], Stuff &command_var)
DESCRIPTION:       This function tests the argument vector to see if there are valid
                    commands
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
===============================================================================*/

void compare_arg(int argc, char *argv[], Stuff &command_var){
    std::cout << "\tTest compare_arg inside \n";//remove
    try {

        if ((strcmp(argv[command_var.position], "-h")) == 0) {
            help();
        }
        if ((strcmp(argv[command_var.position], "-inp")) == 0) {
            Matrix<int> mat1 = open_file<Matrix<int> >(argc, argv, command_var);
            std::cout << mat1;
        }
        if ((strcmp(argv[command_var.position], "-out")) == 0) {
            std::cout << "\toutput file test stuff\n";

        }
        if ((strcmp(argv[command_var.position], "-add")) == 0) {
            Matrix_ops<int> mat1 = open_file<Matrix_ops<int> >(argc, argv, command_var);
            Matrix_ops<int> mat2 = open_file<Matrix_ops<int> >(argc, argv, command_var);
            std::cout << mat2 + mat1;
        }
        if ((strcmp(argv[command_var.position], "-sub")) == 0) {
            Matrix_ops<int> mat1 = open_file<Matrix_ops<int> >(argc, argv, command_var);
            Matrix_ops<int> mat2 = open_file<Matrix_ops<int> >(argc, argv, command_var);
            std::cout << mat2 - mat1;
        }
        if ((strcmp(argv[command_var.position], "-mul")) == 0) {
            Matrix_ops<int> mat1 = open_file<Matrix_ops<int> >(argc, argv, command_var);
            Matrix_ops<int> mat2 = open_file<Matrix_ops<int> >(argc, argv, command_var);
            std::cout << mat1 * mat2;
        }
        if ((strcmp(argv[command_var.position], "-eq")) == 0) {
            Matrix_ops<int> mat1 = open_file<Matrix_ops<int> >(argc, argv, command_var);
            Matrix_ops<int> mat2 = open_file<Matrix_ops<int> >(argc, argv, command_var);
            if (mat1 == mat2)
                std::cout << "\tYes: the two matrices are equal\n";
            else
                std::cout << "\tNo: the two matrices are not equal\n";
        }
        if ((strcmp(argv[command_var.position], "-T")) == 0) {
            Matrix_ops<int> mat1 = open_file<Matrix_ops<int> >(argc, argv, command_var);
            std::cout << mat1.trans();
        }
        if ((strcmp(argv[command_var.position], "-det")) == 0) {
            Matrix_ops<int> mat1 = open_file<Matrix_ops<int> >(argc, argv, command_var);
            std::cout << mat1.det();
        }
        if ((strcmp(argv[command_var.position], "-1")) == 0) {
            Matrix_ops<double> mat1 = open_file<Matrix_ops<double> >(argc, argv, command_var);
            std::cout << mat1.inv();
            //std::cout << mat1.reduced_row();
            //Matrix_ops<double> mat2(mat1);
            //std::cout << "test mat2 \n";
            //std::cout << mat2;
        }
        if ((strcmp(argv[command_var.position], "-solve")) == 0) {
            Matrix_ops<double> mat1 = open_file<Matrix_ops<double> >(argc, argv, command_var);
            std::cout << mat1.solve();
        }
    }

    catch(const char *msg)
    {
        std::cout << msg;
    }
}

/*=============================================================================
FUNCTION:          Matrix open_file(int argc, char *argv[],Stuff &command_var)
DESCRIPTION:       This function opens the file to be read from, then creates a class
                    object of the matrix
RETURNS:           Being class type, this function returns the matrix created after
                    opening the file
NOTES:             passed another class object for variables, passed position from Stuff
                    to generate a matrix object from multiple files
===============================================================================*/
template<typename T>
T open_file(int argc, char *argv[],Stuff &command_var){
    std::cout << "\tTest open_file \n";//remove
    ++command_var.position; // incrememnt the position of the command line, to account for multiple args
    if(argc > 1){ //
        strcpy(command_var.file1, argv[command_var.position]);
        strcat(command_var.file1, ".mtx");
        command_var.infile.open(command_var.file1);

    }
    if(!command_var.infile){
        throw "\n\tError opening the file, please try another command\n";

    }

    command_var.infile >> command_var.m >> command_var.let_x >> command_var.n;

    T mat1(command_var.m,command_var.n);

    command_var.infile >> mat1;

    command_var.infile.close();

    return mat1;
}


/*=============================================================================
FUNCTION:          void help()
DESCRIPTION:       This function displays the help menu instructing the user
                    what commands to enter.
RETURNS:           Nothing (Void Function)
===============================================================================*/

void help(){

    std::cout << "\t===========================================================\n";
    std::cout << "\t======= Welcome to the Help menu for matrix_math.cpp ======\n";
    std::cout << "\t= This Help menu will guide you through the valid commands =\n";
    std::cout << "\t========= that you can enter: They are as follows =========\n";
    std::cout << "\t=== -h for the help menu =\n";
    std::cout << "\t===========================================================\n";
    std::cout << "\t=== -inp to read input from a file and display the matrix  ==\n";
    std::cout << "\t=== -out tells the current operation to be printed to a file =\n";
    std::cout << "\t=== -add input the two matrices and adds them together\n";
    std::cout << "\t=== -sub inputs the two matrices and subtracts them=\n";
    std::cout << "\t=== -mul multiplies two matrices together=\n";
    std::cout << "\t=== -eq tests to see if two matrices are equal=\n";
    std::cout << "\t=== -T computes the tranverse of a matrix=\n";
    std::cout << "\t=== -1 computes the inverse of a matrix=\n";
    std::cout << "\t=== -det calculates the determinant of a matrix=\n";
    std::cout << "\t=== -solve solves a system of linear equations=\n";
    std::cout << "\t===========================================================\n";
}
