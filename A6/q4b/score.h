/**
 File: score.h
  Reads a list of student records and allows foldl on the list
  */
#include <stdbool.h>

  // store grade components of one student
  struct score {
        char id[11];        // student id can be at most 10 characters
            int clicker;            // iclicker score out of 5
                int assn;               // assignment marks out of 20
                    int mid;                // midterm marks out of 25
                        int final;              // final marks out of 50
  };

  // store grades for all students. 
  struct database {
        int count;              // number of scores in data
            struct score data[100]; // there can be at most 100 students
  };

  // read_database(db) reads student records using scanf until EOF 
  // is reached and returns true if at least one record was read; false otherwise
  // score data for each student appears in separate line in the following format:
  // id clicker assignment midterm final
  // you can safely assume that zero or more complete score data lines will be
  // given in the input and all values in a score data will be valid
  //
  // requires: db != NULL
  // effects: reads score data into db->data (starting from index 0) and updates 
  //      db->count according to the number of scores read. 
  bool read_database(struct database *db);

  // foldl(fn(scr, acc), init, db) calls fn(scr, acc) with each 
  // element (0 to db->count-1) in db->data i.e., fn(db->data[i], acc).
  // Passes the return value of the i-th call as the acc value for 
  //    the (i+1)-th call, i.e., fn(db->data[i+1], fn(db[i], ...)).
  // The first call to fn is with init, i.e. fn(db->data[0], init).
  // foldl returns the result from the last call to fn, i.e.
  //           returns fn(db->data[db->count-1], acc).
  // requires: db != NULL
  int foldl(int (*fn)(const struct score *scr, int acc), 
              int init, const struct database *db);
