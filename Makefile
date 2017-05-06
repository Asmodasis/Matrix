#/* -----------------------------------------------------------------------------
#
#FILE:              xxx.CPP or xxx.HPP
#
#DESCRIPTION:       A brief description of this source code file ...
#
#COMPILER:          Linux g++ compiler
#NOTES:             Put other information here ...
#
#MODIFICATION HISTORY:
#
#Author                  Date               Version
#---------------         ----------         --------------
#Shawn Ray       		2017-03-12         Version 1.0 started Project
#Shawn Ray       		2017-03-19         Version 1.1 worked on variable usage for makes
#Shawn Ray       		2017-03-19         Version 1.2
#Shawn Ray       		2017-03-20         Version 1.3
#Shawn Ray			2017-03-30	   Version 1.4 added clean targets
#----------------------------------------------------------------------------- */
CC = g++
OUTPUT = matrix_math
CXXFLAGS = -pedantic -std=c++11 -Wall -g
OBJS = matrix_math.o	#non-classes
LIBS = 			#libraries
DEPS = Matrix.o	#classes = DEPS
#
#
#
#
#
all: $(OUTPUT)
	
$(OUTPUT): $(OBJS) $(DEPS)
	$(CC) $(CCXXFLAGS) $(OBJS) $(DEPS) -o $(OUTPUT) $(LIBS)
#
#
#
#
#
#
Matrix.o : Matrix.cpp Matrix.h 
	$(CC) $(CXXFLAGS) -c Matrix.cpp $(LIBS)
#
#
#

clean:
	rm -f $(OUTPUT)
	rm -f *.o
#
	reset
	@echo Make clean, removed object and executable files ...
	@echo Contents in this Directory ...
	ls -lt
#
#
#
#



