// rpslk.h

// This module provides a number of utility functions 
// for playing a game of rpslk.

// rpslk_winner(player, bot) determines the winner of a round of rpslk
//            returns -1 if player beats bot,
//                    0 if player ties bot,
//                    1 if bot beats player
//   requires: player and bot are one of 'r', 'p', 's', 'l', 'k'
//   effects: updates statistics on who won (player, bot or tie)
//             displays winner message 
//             (e.g., "Paper covers rock. Player wins!\n")
//             hint: check out messages.txt
int rpslk_winner(char player, char bot);


// get_challenge_rating() prompts the user for the difficulty rating
//                  and returns that integer
//   effects: Displays a prompt message, and reads in input
int get_challenge_rating(void);


// get_player_throw() prompts the user for their throw,
//                     returns a valid throw
//   effects: Displays a prompt message, and reads in input
char get_player_throw(void);


// get_play_again_response() prompts the user to play again
//                          and returns the response ('y' or 'n')
//   effects: Displays a prompt message, and reads in input
char get_play_again_response(void);


// print_game_summary() prints the results of an rpslk game
//   effects: Displays several game statistics
void print_game_summary(void);

