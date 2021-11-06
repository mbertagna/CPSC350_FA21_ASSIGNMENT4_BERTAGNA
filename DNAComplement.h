// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 4

/* DNAComplement.h is a header file which lays out the elements of the DNAComplement class. */

#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H

#include <iostream>
#include <exception>
#include "GenStack.h"

using namespace std;

class DNAComplement{
    public:
        //default constructor
        DNAComplement();
        //destructor
        ~DNAComplement();
        
        //return organized string of sequence, comp, and revcomp
        string getDnaInfo(string sequence);
        //calculate and return revcomp
        string getRevComplement(string sequence);
        //calculate and return comp
        string getComplement(string sequence);
        //return sequence in uppercase format
        string getUpperSequence(string sequence);
        //return true if only A,T,G,C, else false
        bool isDNA(string sequence);

    private:
        //stack to hold dna sequence data
        GenStack<char> *dnaStack;
};

#endif