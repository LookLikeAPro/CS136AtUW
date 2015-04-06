// art.h
// A module to print simple shape using ASCII

/************************************************************************************\
 * struct shape structure has four fields as follows:
 * char type: can be either 'A' or 'B' indicating the type of diagonal.
 * char upper: is the character to be used for filling the cells over the major diagonal.
 * char diag: is the character to be used for filling the cells below the major diagonal.
 * char lower: is the character to be used for filling the cells below the major diagonal.
 * ------
 * Here is an example of a type 'A' object of size 4 with upper='u', lower='l' and diag='d'
 * duuu
 * lduu
 * lldu
 * llld
 * Here is an example of a type 'B' object of size 4 with upper='u', lower='l' and diag='d'
 * uuud
 * uudl
 * udll
 * dlll
\************************************************************************************/
struct shape {
   char type;
   char upper;
   char diag;
   char lower;
};

// This function prints two shapes side-by-side, as defined by the ps1 and ps2 parameters. 
// Each shape is size characters high and size characters wide. 
// requires: ps1 and ps2 are not NULL; size >= 1
// effects: prints two shapes in size lines, with 2*size characters in each line.
void ascii_shape(struct shape *ps1, struct shape *ps2, int size);
