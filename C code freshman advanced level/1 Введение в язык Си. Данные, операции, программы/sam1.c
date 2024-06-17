/****************************************************************************
 *                                                                          *
 * File    : main.c                                                         *
 *                                                                          *
 * Purpose : Console mode (command line) program.                           *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>

/****************************************************************************
 *                                                                          *
 * Function: main                                                           *
 *                                                                          *
 * Purpose : Main entry point.                                              *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

int main(int argc, char *argv[])
{
	int a,b,c,a1,b1,c1;
	scanf("%d %d", &a, &b);
	c = (a + b)*3;
	a = a/10;
	a1= a + 48;
	b = b/10;
	b1= b + 48;
	c = c/10;
	if (c>9){
		c = c/10;
	}
	c1 = c + 48;
	printf("%d:%5o%5d%5x\n", a,a1,a1,a1);
	printf("%d:%5o%5d%5x\n", b,b1,b1,b1);
	printf("%d:%5o%5d%5x\n", c,c1,c1,c1);
    return 0;
}

