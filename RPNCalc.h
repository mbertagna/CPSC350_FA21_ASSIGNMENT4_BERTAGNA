// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 4

/* RPNCalc.h is a header file which lays out the elements of the RPNCalc class. */

#ifndef RPNCALC_H
#define RPNCALC_H

#include <iostream>
#include <exception>
#include "GenStack.h"

using namespace std;

class RPNCalc{
    public:
        //default constructor
        RPNCalc();
        //destructor
        ~RPNCalc();
        
        //gets postfix expression from user input, evaluates, prints to console
        void evaluatePostfixExpression();
        //returns true if int, else false
        bool isInt(string posInt);
        //returns true if operator, else false
        bool isOperator(string posOperator);
        //gets user input expression
        string getUserInputExpression();

    private:
        //stack for calculations
        GenStack<int> *calcStack;
};

#endif