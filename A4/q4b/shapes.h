// A module to print fancy shapes using ASCII characters

/****************************************************************\
 * prints a dimond shape. uses ascii_art(...) in module art.h
 * effects: prints size*2 lines, with size*2 char in each line
 * requires: size >= 1
 * example:  diamond(4); note the spaces. e.g., first line has
 *           3 spaces in the begning and 3 spaces at the end.
 *           The last line ends with a newline character.
   /\   
  /##\  
 /####\ 
/######\
\######/
 \####/ 
  \##/  
   \/   
\*****************************************************************/
void diamond(int size);

/****************************************************************\
 * prints a window shape. uses ascii_art(...) in module art.h
 * requires: size >= 1
 * effects: prints size*2 lines, with size*2 char in each line.
 * example:  window(4); The last line ends with a newline character.
###/\###
##/  \##
#/    \#
/      \
\      /
#\    /#
##\  /##
###\/###
\*****************************************************************/
void window(int size);

/****************************************************************\
 * prints a flag shape. uses ascii_art(...) in module art.h
 * requires: size >= 1
 * effects: prints size*2 lines, with size*2 char in each line.
 * example:  flag(5); The last line ends with a newline character.
\        /
&\      /&
&&\    /&&
&&&\  /&&&
&&&&\/&&&&
    /\    
   /  \   
  /    \  
 /      \ 
/        \
\*****************************************************************/
void flag(int size);
