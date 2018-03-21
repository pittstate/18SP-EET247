/* Assignment and Date: Lab 1C, due 20FEB2018 
 *
 * Programmer: Steven Kirkland, 0208135
 *
 * Title: LAB1C
 *
 * Target user: the user breaking things
 * 
 * Specifications: fix and document the things that were messed up
 *
 * Inputs/Outputs: just some outputs here from some inputs without error checking
 *
 * Variables: int n1, n2, sum
 *
 * Constants: N/A
 *
 * Non-standard Libraries or functions: printf to print stuff to con, getchar to fake a pause, scanf to get some values
 *
 * Description and Purpose: add the things
 *
 * Additional Comments: release control of all the things at the end
 ***********************************************************************************/

#include <stdio.h>

int main(void) { /* I like to brace for it right here */

	int n1;	/* make an int */
	int n2;	/* make another int */
	int sum = 0; /* make and initialize yet another int */

	printf("Enter an integer\n"); /* asks the user for a value */
	scanf("%d",&n1); /* stores the first user value */

	printf("Enter a second integer\n"); /* asks for a second user supplied value */
	scanf("%d",&n2); /* stores the second user value */
	sum = n1 + n2; /* adds (since the following text makes me think we don't want a product dot dot dot) the things and hope that user gave us integer input */

	printf("Sum of entered number = %d\n",sum); /* prints the value of 'sum' to con */
	getchar(); /* pause magic */
	return 0; /* OS, I'm done. */
}