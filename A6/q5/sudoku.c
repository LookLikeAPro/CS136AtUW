#include <stdbool.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 6, Problem 5

bool is_valid(char *board){
	for (int i=0; i<9; i++){
		for (int i2=0; i2<9; i2++){
			if (board[i*9+i2]>='0' && board[i*9+i2]<='9'){
				for (int i3=0; i3<9; i3++){
					if (board[i*9+i3]==board[i*9+i2] && i3!=i2){
						return false;
					}
				}
				for (int i3=0; i3<9; i3++){
					if (board[i3*9+i2]==board[i*9+i2] && i3*9+i2!=i*9+i2){
						return false;
					}
				}
			}
			else if (board[i*9+i2]!='.'){
				return false;
			}
		}
	}
	for (int i=0; i<9; i++){
		for (int i2=0; i2<9; i2++){
			if (board[i/3*27+i%3*3+i2/3*9+i2%3]>='0' && board[i/3*27+i%3*3+i2/3*9+i2%3]<='9'){
				for (int i3=0; i3<9; i3++){
					if (board[i/3*27+i%3*3+i3/3*9+i3%3]==board[i/3*27+i%3*3+i2/3*9+i2%3] && i3/3*9+i3%3!=i2/3*9+i2%3){
						return false;
					}
				}
			}
		}
	}
	return true;
}
