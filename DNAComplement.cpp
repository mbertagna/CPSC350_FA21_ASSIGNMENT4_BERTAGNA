// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 4

/* DNAComplement.cpp contains the implementation of the DNAComplement class. It implements a constructor, a destructor, and five functions:
1) getDnaInfo: return organized string of sequence, comp, and revcomp
2) getRevComplement: calculate and return revcomp
3) getComplement: calculate and return comp
4) getUpperSequence: return sequence in uppercase format
5) isDNA: return true if only A,T,G,C, else false
*/

#include "DNAComplement.h"

//default constructor
DNAComplement::DNAComplement(){
    dnaStack = new GenStack<char>();
}

//destructor
DNAComplement::~DNAComplement(){
    delete dnaStack;
}

//return organized string of sequence, comp, and revcomp
string DNAComplement::getDnaInfo(string sequence){
    string info = "Sequence: " + getUpperSequence(sequence) + "\nComplement: " + getComplement(sequence) + "\nReverse Complement: " + getRevComplement(sequence) + "\n";
    return info;
}

//calculate and return revcomp
string DNAComplement::getRevComplement(string sequence){
    string revComplement = "";

    //push all bases to stack
    for(int i = 0 ; i < sequence.size() ; ++i){
        dnaStack->push(sequence[i]);
    }

    string base = "";

    //pop bases from stack to reverse order and get comp of each to save to string
    for(int i = 0 ; i < sequence.size() ; ++i){
        base = dnaStack->peek();
        revComplement += getComplement(base);
        dnaStack->pop();
    }

    return revComplement;
}

//calculate and return comp
string DNAComplement::getComplement(string sequence){
    string complement = "";

    //loop through sequence and return sequence with comp bases A-T and G-C
    for(int i = 0 ; i < sequence.size() ; ++i){
        switch(toupper(sequence[i])){
            case 'A':
                complement += 'T';
                break;
            case 'T':
                complement += 'A';
                break;
            case 'G':
                complement += 'C';
                break;
            case 'C':
                complement += 'G';
                break;
        }
    }
    return complement;
}

//return sequence in uppercase format
string DNAComplement::getUpperSequence(string sequence){
    string upperSequence = "";

    for(int i = 0 ; i < sequence.size() ; ++i){
        switch(toupper(sequence[i])){
            case 'A':
                upperSequence += 'A';
                break;
            case 'T':
                upperSequence += 'T';
                break;
            case 'G':
                upperSequence += 'G';
                break;
            case 'C':
                upperSequence += 'C';
                break;
        }
    }
    return upperSequence;
}

//return true if only A,T,G,C, else false
bool DNAComplement::isDNA(string sequence){
    for(int i = 0 ; i < sequence.size() ; ++i){
        //return false if all chars not A,T,G,C
        if(toupper(sequence[i]) != 'A' && toupper(sequence[i]) != 'T' && toupper(sequence[i]) != 'G' && toupper(sequence[i]) != 'C'){
            return false;
        }
    }
    return true;
}