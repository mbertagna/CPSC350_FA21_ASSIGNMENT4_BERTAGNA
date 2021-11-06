// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 4

/* RPNCalc.cpp contains the implementation of the RPNCalc class. It implements a constructor, a destructor, and four functions:
1) evaluatePostfixExpression: gets postfix expression from user input, evaluates, prints to console
2) getUserInputExpression: returns true if int, else false
3) isInt: returns true if operator, else false
4) isOperator: gets user input expression
*/

#include "RPNCalc.h"

//default constructor
RPNCalc::RPNCalc(){
    calcStack = new GenStack<int>();
}

//destructor
RPNCalc::~RPNCalc(){
    delete calcStack;
}

//gets postfix expression from user input, evaluates, prints to console
void RPNCalc::evaluatePostfixExpression(){
    string expression = getUserInputExpression();

    bool validExpression = true;

    //track the current position
    int currPos = 0;
    //operand/operator
    string op = "";
    
    int rightOperand = 0;
    int leftOperand = 0;

    //if no expression then invalid
    if(expression.size() == 0){
        validExpression = false;
    }

    // loop through the operands/operators (tracked by spaces) in the expression until end of expression
    while(currPos < expression.size()){
        //get next operand/operator
        for(currPos; expression[currPos] != ' ' && currPos < expression.size() ; ++currPos){
            op += expression[currPos];
        }

        //increment current position
        ++currPos;

        //if int, push to stack
        if(isInt(op)){
            calcStack->push(std::stoi(op));
        }
        //if operator, perform operation
        else if(isOperator(op)){

            //if less than 2 ints in stack, false expression bc cannot perform calculations
            if(calcStack->getSize() < 2){
                validExpression = false;
                break;
            }

            //perform correct operation by matching operator and then poping top two ints off stack to perform operations on; finish by pushing result to stack
            switch(op[0]){
                case '+':
                    rightOperand = calcStack->pop();
                    leftOperand = calcStack->pop();
                    calcStack->push(leftOperand + rightOperand);
                    break;
                case '-':
                    rightOperand = calcStack->pop();
                    leftOperand = calcStack->pop();
                    calcStack->push(leftOperand - rightOperand);
                    break;
                case '*':
                    rightOperand = calcStack->pop();
                    leftOperand = calcStack->pop();
                    calcStack->push(leftOperand * rightOperand);
                    break;
                case '/':
                    rightOperand = calcStack->pop();
                    leftOperand = calcStack->pop();
                    calcStack->push(leftOperand / rightOperand);
                    break;
                case '%':
                    rightOperand = calcStack->pop();
                    leftOperand = calcStack->pop();
                    calcStack->push(leftOperand % rightOperand);
                    break;
            }
        }
        //if something in expression that is not int or operator, invalid expression
        else{
            validExpression = false;
            break;
        }
        //make op empty string again
        op = "";
    }
    //if stack has more than one value at end, invalid expression
    if(calcStack->getSize() != 1){
        throw runtime_error("Invalid input: please input proper postfix expression.");
    }
    //if valid expression print result
    else if(validExpression){
        cout << expression << " = " << calcStack->peek() << endl;
    }
    //if invalid expression throw error
    else{
        throw runtime_error("Invalid input: please input proper postfix expression.");
    }
}

//returns true if int, else false
string RPNCalc::getUserInputExpression(){
    string expression = "";
    cout << "Expression in Postfix Notation: ";
    getline(cin , expression);
    return expression;
}

//returns true if operator, else false
bool RPNCalc::isInt(string posInt){
    if(posInt.size() == 0)//return false if string has length zero
        return false;

    for(int i = 0; i < posInt.length(); ++i){//loop through chars in string
    
        if(i == 0 && posInt[i] == '-'){//account for negative ints
            continue;
        }

        if(!(isdigit(posInt[i]))){//if char is not numeric return false
            return false;
        }
    }

    if(posInt == "-")//account for only - sign
        return false;
    
    return true;//if int
}

//gets user input expression
bool RPNCalc::isOperator(string posOperator){

    //return true if operator, else false
    if(posOperator == "+" || posOperator == "-" || posOperator == "*" || posOperator == "/" || posOperator == "%")
        return true;

    return false;
}

