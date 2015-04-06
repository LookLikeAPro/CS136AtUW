#include "rpslk.h"
#include <stdio.h>
// Jiayu Zhou
// CS136, Winter 2015
// Assignment 5, Problem 5

int playerWin = 0;
int botWin = 0;
int tie = 0;
int rpslk_winner(char player, char bot){
	if (player == bot){
		printf("It's a tie!\n");
		tie++;
		return 0;
	}
	else if (player == 'r'){
		if (bot == 'p'){
			printf("Paper covers rock. ");
			printf("Bot wins!\n");
			botWin++;
			return 1;
		}
		else if (bot == 'k'){
			printf("Spock vaporizes rock. ");
			printf("Bot wins!\n");
			botWin++;
			return 1;
		}
		else if (bot == 'l'){
			printf("Rock crushes lizard. ");
			printf("Player wins!\n");
			playerWin++;
			return -1;
		}
		else if (bot == 's'){
			printf("Rock crushes scissors. ");
			printf("Player wins!\n");
			playerWin++;
			return -1;
		}
	}
	else if (player == 'p'){
		if (bot == 'r'){
			printf("Paper covers rock. ");
			printf("Player wins!\n");
			playerWin++;
			return -1;
		}
		else if (bot == 's'){
			printf("Scissors cut paper. ");
			printf("Bot wins!\n");
			botWin++;
			return 1;
		}
		else if (bot == 'k'){
			printf("Paper disproves Spock. ");
			printf("Player wins!\n");
			playerWin++;
			return -1;
		}
		else if (bot == 'l'){
			printf("Lizard eats paper. ");
			printf("Bot wins!\n");
			botWin++;
			return 1;
		}
	}
	else if (player == 's'){
		if (bot == 'r'){
			printf("Rock crushes scissors. ");
			printf("Bot wins!\n");
			botWin++;
			return 1;
		}
		else if (bot == 'p'){
			printf("Scissors cut paper. ");
			printf("Player wins!\n");
			playerWin++;
			return -1;
		}
		else if (bot == 'k'){
			printf("Spock smashes scissors. ");
			printf("Bot wins!\n");
			botWin++;
			return 1;
		}
		else if (bot == 'l'){
			printf("Scissors decapitate lizard. ");
			printf("Player wins!\n");
			playerWin++;
			return -1;
		}
	}
	else if (player == 'l'){
		if (bot == 'r'){
			printf("Rock crushes lizard. ");
			printf("Bot wins!\n");
			botWin++;
			return 1;
		}
		else if (bot == 'p'){
			printf("Lizard eats paper. ");
			printf("Player wins!\n");
			playerWin++;
			return -1;
		}
		else if (bot == 's'){
			printf("Scissors decapitate lizard. ");
			printf("Bot wins!\n");
			botWin++;
			return 1;
		}
		else if (bot == 'k'){
			printf("Lizard poisons Spock. ");
			printf("Player wins!\n");
			playerWin++;
			return -1;
		}
	}
	else if (player == 'k'){
		if (bot == 'r'){
			printf("Spock vaporizes rock. ");
			printf("Player wins!\n");
			playerWin++;
			return -1;
		}
		else if (bot == 'p'){
			printf("Paper disproves Spock. ");
			printf("Bot wins!\n");
			botWin++;
			return 1;
		}
		else if (bot == 's'){
			printf("Spock smashes scissors. ");
			printf("Player wins!\n");
			playerWin++;
			return -1;
		}
		else if (bot == 'l'){
			printf("Lizard poisons Spock. ");
			printf("Bot wins!\n");
			botWin++;
			return 1;
		}
	}
	return 9;
}

int get_challenge_rating(void){
	int rating;
	printf("Choose a challenge rating (1 - 1000000): ");
	scanf("%d", &rating);
	return rating;
}

char get_player_throw(void){
	char throw;
	printf("What do you throw (r/p/s/l/k)? ");
	while (!(throw=='r'|| throw=='p'|| throw=='s'|| throw=='l'|| throw=='k')){
		scanf("%c", &throw);
	}
	return throw;
}

char get_play_again_response(void){
	char again;
	printf("Would you like to play again (y/n)? ");
	while (!(again=='y'|| again=='n')){
		scanf("%c", &again);
	}
	return again;
}

void print_game_summary(void){
	printf("----- Game Summary -----\n");
	printf("Player won %d rounds...\n", playerWin);
	printf("Bot won %d rounds...\n", botWin);
	printf("Player and bot tied %d rounds...\n", tie);
    if (playerWin>botWin){
        printf("Player wins!\n");
    }
    else if (botWin>playerWin){
        printf("Bot wins!\n");
    }
    else {
        printf("It's a tie!\n");
    }
}
