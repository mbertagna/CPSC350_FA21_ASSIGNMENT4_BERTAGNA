// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 4

/* FileProcessor.h is a header file which lays out the elements of the FileProcessor class. */

#include <iostream> //pre-processor directive
#include <fstream>
#include "DNAComplement.h"

using namespace std;

class FileProcessor{
public:
  FileProcessor();
  ~FileProcessor();

  void processFile();
};
