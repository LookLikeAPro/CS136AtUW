#include "art.h"
#include <stdio.h>

void diamond(int size){
	struct shape topLeft = {'B', ' ', '/', '#'};
	struct shape topRight = {'A', ' ', '\\', '#'};
	struct shape bottomRight = {'B', '#', '/', ' '};
	struct shape bottomLeft = {'A', '#', '\\', ' '};
	ascii_shape(&topLeft, &topRight, size);
	ascii_shape(&bottomLeft, &bottomRight, size);
}

void window(int size){
	struct shape topLeft = {'B', '#', '/', ' '};
	struct shape topRight = {'A', '#', '\\', ' '};
	struct shape bottomRight = {'B', ' ', '/', '#'};
	struct shape bottomLeft = {'A', ' ', '\\', '#'};
	ascii_shape(&topLeft, &topRight, size);
	ascii_shape(&bottomLeft, &bottomRight, size);
}

void flag(int size){
	struct shape topLeft = {'A', ' ', '\\', '&'};
	struct shape topRight = {'B', ' ', '/', '&'};
	struct shape bottomRight = {'A', ' ', '\\', ' '};
	struct shape bottomLeft = {'B', ' ', '/', ' '};
	ascii_shape(&topLeft, &topRight, size);
	ascii_shape(&bottomLeft, &bottomRight, size);
}