#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utilities.h"
#include "playCrap.h"
#include "turtleGraphics.h"
#include "defs.h"
#include "knightsTour.h"




int main()
{
	char* str;
	str=(char*)malloc(sizeof(char)*20);
	strcpy(str, "saitelmas");
	toUpperCase(str);
	printf("%s\n",str);

	return 0;
}