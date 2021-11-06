// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 4

/* main.cpp contains the main method and creates an instance of the RPNCalc and FileProcessor classes
in order to facilitate an RPN calculator and a DNA sequence file reader and writer. It takes one command line arguement:
1) app type: "RPN" for calculator or "DNA" for DNA sequence complement and reverse complement generator
*/

#include "RPNCalc.h"
#include "FileProcessor.h"

int main(int argc, char** argv)
{
    try{
        if(argc < 2){//if not two cmd line arguements, error
            throw runtime_error("Invalid input: please provide a valid command line arguement (RPN or DNA).");
        }

        string appChoice = argv[1];

        if(appChoice != "RPN" && appChoice != "DNA"){//if cmd line arguement not RPN or DNA, error
            throw runtime_error("Invalid input: please provide a valid command line arguement (RPN or DNA).");
        }
        
        //if RPN then run calculator
        if(appChoice == "RPN"){
            RPNCalc *rpn = new RPNCalc();
            rpn->evaluatePostfixExpression();
            delete rpn;
        }

        //if DNA then fileprocessor with dnacomplement encompassed within is run
        if(appChoice == "DNA"){
            FileProcessor *dnaFP = new FileProcessor();
            dnaFP->processFile();
            delete dnaFP;
        }
    }
    //if error thrown stop running and print to user
    catch(runtime_error &excpt){
        cerr << excpt.what() << endl;
    }
    return 0;
}
