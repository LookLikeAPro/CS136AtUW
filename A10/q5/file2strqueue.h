// file2strqueue.h: a simple module for converting
//   a file to a StrQueue

#include "strqueue.h"

// file2StrQueue(filename) reads in the contents of filename 
//     and produces a new StrQueue of all of the words in the file
//     NOTE: file2StrQueue(NULL) will read in from the keyboard (.in file)
//   requires:  filename exists in the current directory, or is NULL
//   effects: returns a new valid StrQueue (client must call destroy_StrQueue)
//            or prints a message and exits if an error occurs
//   time: O(n), where n is the size of the file
StrQueue file2StrQueue(const char *filename);
