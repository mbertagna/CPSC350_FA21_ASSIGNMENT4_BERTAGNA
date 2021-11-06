// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 4

/* FileProcessor.cpp contains the implementation of the FileProcessor class. It implements a constructor, a destructor, and one function:
1) processFile: gets a DNA sequence input file path from the user and writes the sequences, the reverse complements, and the complements to a file named "dnaoutput.txt"*/

#include "FileProcessor.h"

FileProcessor::FileProcessor(){
}
FileProcessor::~FileProcessor(){
}

// gets a DNA sequence input file path from the user and writes the sequences, the reverse complements, and the complements to a file named "dnaoutput.txt"
void FileProcessor::processFile(){
  ifstream inFS;// input file stream
  ofstream outFS;// output file stream

  string dnaSequenceFilePath = "";
  string outputFilePath = "dnaoutput.txt";

  // prompt user continuously until proper input file path
  while (!inFS.is_open()) {
    cout << "Path to input file: ";
    cin >> dnaSequenceFilePath;
    inFS.open(dnaSequenceFilePath);// open input file
    if(inFS.is_open())
      break;
    cout << "Could not open the input file in path: " << dnaSequenceFilePath << "." << endl << "Please provide a valid input file path." << endl;
  }
  
  outFS.open(outputFilePath);// open output file

  // when both files are successfully opened run translation code
  
  // create instance of DNAComplement for function use
  DNAComplement *dna = new DNAComplement();
  string sequence = "";// stores sequence/line
  string dnaInfo = "";// stores sequence info

  getline(inFS, sequence);// store first line in file data

  // loop until the filestream is empty
  while (!inFS.fail()) {
    if(!(dna->isDNA(sequence))){//if not proper sequence then error
      //delete DNAComp from memory
      delete dna;
      inFS.close();// close input file stream
      outFS.close();// close output file stream
      throw runtime_error("Invalid input: please input DNA sequence files with proper format.");
    }
    //get dna info from sequence
    dnaInfo = dna->getDnaInfo(sequence);
    //write info to file
    outFS << dnaInfo << endl;

    getline(inFS, sequence);// store next line in file data
  }

  // if there is an input failure before reaching end of file, notify user
  if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
  }
  //delete DNAComp from memory
  delete dna;
  inFS.close();// close input file stream
  outFS.close();// close output file stream
}
