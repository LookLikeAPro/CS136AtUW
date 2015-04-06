#include "robot.h"
#include "get-input.h"
#include <stdio.h>

// Jiayu Zhou
// CS136, Winter 2015
// Assignment 3, Problem 3

void display (char c){
    if (c=='F')
        printf("move-forward");
    else if (c=='B')
        printf("move-backward");
    else if (c=='L')
        printf("turn-left");
    else if (c=='R')
        printf("turn-right");
    else if (c=='N')
        printf("North");
    else if (c=='S')
        printf("South");
    else if (c=='E')
        printf("East");
    else if (c=='W')
        printf("West");
}

int loop(struct robot r1, struct robot r2, int round){
    if (round>=30){
        printf("VINCENT has escaped!\n");
        return 0;
    }
    else
        round++;
    char c = get_character();
    if (c!='F' && c!='B' && c!='L' && c!='R'){
        round--;
        return loop(r1, r2, round);
    }
    else if (round%2==1){
        r1 = move_robot(r1, c);
        printf("VINCENT has made a ");
        display(c);
        printf(" to location (%d,%d) facing ", r1.location.x, r1.location.y);
        display(r1.orientation);
        printf(".\n");
    }
    else{
        r2 = move_robot(r2, c);
        printf("MAXIMILLIAN has made a ");
        display(c);
        printf(" to location (%d,%d) facing ", r2.location.x, r2.location.y);
        display(r2.orientation);
        printf(".\n");
    }
    if (round%2==0){
    	if (is_visible(r1, r2)){
        	printf("Facing ");
        	display(r1.orientation);
        	printf(", I see MAXIMILLIAN. Run!\n");
    	}
    	if (is_visible(r2, r1)){
        	printf("You can't run VINCENT. Exterminate!\n");
       		return 0;
    	}
    }
    return loop(r1, r2, round);
}


int main(void) {
    struct arena_posn loc1 = {40,40};
    struct arena_posn loc2 = {60,60};
	struct robot r1 = create_robot(VINCENT,'E', loc1, 10);
    struct robot r2 = create_robot(MAXIMILLIAN,'W', loc2, 5);
    loop(r1, r2, 0);
}
