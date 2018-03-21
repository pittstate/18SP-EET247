/* Assignment and Date: Lab 1D, due 20FEB2018 
 *
 * Programmer: Steven Kirkland, 0208135
 *
 * Title: LAB1C
 *
 * Target user: user who wants to add, subtract, multiply, and divide integers
 * 
 * Specifications: add, subtract, multiply, and divide integers
 *
 * Inputs/Outputs: in and out are ints
 *
 * Variables: int n1, n2,
 *
 * Constants: N/A
 *
 * Non-standard Libraries or functions: printf to print stuff to con, getchar to fake a pause, scanf to get some values
 *
 * Description and Purpose: add, subtract, multiply, and divide the things
 *
 * Additional Comments: release control of all the things at the end
 ***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) { /* I like to brace for it right here */

	int n1;	/* make an int */
	int n2;	/* make another int */
	int intPrintfLength = 0, intHacky = 33; /* hacky col formatting if I get time -- I got time by not sleeping. */

	/* clear the screen */
	system("cls");

	printf("Enter a Number\n"); /* asks the user for a value */
	scanf("%d",&n1); /* stores the first user value */

	printf("Enter a Second Number\n"); /* asks for a second user supplied value */
	scanf("%d",&n2); /* stores the second user value */

	/* print the words and stuff */
	intPrintfLength = printf("The sum of %d and %d is:", n1, n2);
	/* align the things */
	printf("%*s%-2d\n", intHacky - intPrintfLength," ", n1+n2);

	/* subtract the things */
	intPrintfLength = printf("The difference of %d and %d is:",n1,n2);
	printf("%*s%-2d\n", intHacky - intPrintfLength," ", n1-n2);

	/* multiply the things */
	intPrintfLength = printf("The product of %d and %d is:", n1, n2);
	printf("%*s%-2d\n", intHacky - intPrintfLength," ", n1*n2);

	intPrintfLength = printf("%d divided by %d is:",n1,n2);
	printf("%*s%-2d\n", intHacky - intPrintfLength," ", n1/n2);


	system("pause > nul"); /* pause magic redirected to nul to match the screenshot*/
	return 0; /* OS, I'm done. */
}