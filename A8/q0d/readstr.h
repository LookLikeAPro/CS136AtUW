// module that provides the function readstr

// readstr() returns a NEW string read from the input (keyboard) of arbitrary length
//   effects: input is read until a newline (\n) or EOF is encountered.
//            returned string is the correct size and null terminated ('\0').
//            caller must eventually free returned string.
//   time: O(n), where n is the number of characters read
// example: char *s = readstr();
char *readstr(void);
