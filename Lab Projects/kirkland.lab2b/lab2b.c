/* Assignment and Date: Lab 2B, due 06MAR2018 
 *
 * Programmer: Steven Kirkland, 0208135
 *
 * Title: LAB2B
 *
 * Target user: user who want to buy a house
 * 
 * Specifications: add, subtract, multiply, and divide real numbers
 *
 * Inputs/Outputs: in and out are some ints and a long double here and there
 *
 * Variables:	int intPurchasePrice, intDownPayment, intNumPayments, printfCutter 	sidenote: falling into this yuppy trap of
																					not using hugarian-like notation but 
																					camelCase I do like
 *				long double dblMathStuff; double dblOtherMath; float fltApr
 *				some local counters int i and things 
 *
 * Constants: char *theMark, COL_LENGTH, CON_LENGTH, LENDINGCO
 *
 * Non-standard Libraries or functions: printf to print stuff to con, stdlib to pause,
 *		scanf to get some values, math.h because i might use the math stuff from it.
 *		PrettyLines() to print n number of i chars
 *		GetLastError() because it's about time to start doing error things.
 *		pow() becuase I'm a sucker this time.
 *
 * Description and Purpose: add, subtract, multiply, and divide the things
 *
 * Additional Comments: Sell all the things - limitations, no rounding as seen with
 * 			printf %9.2f where thousands is rounded up or down. can be seen with calculating
 *			total repayment such that 24 * 35.55 is actually 853.20. assignment is late enough
 *			and already tremendously jacked up.
 ***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> /* some env based error handling, might as well start */
#include <math.h>

#define COL_LENGTH 23
#define CON_LENGTH 80 /* for the good times */
#define LENDINGCO "Bank Co Lending Place"

#define _CENTER_TEXT_START_POS(x) ((CON_LENGTH - x)/2) /* mainly just because I keep remembering incorrectly*/

void PrettyLines(char,int);
void MakeSpaces(int);

int ErrorThanksBye(void);

double MonthlyPayment(float, int, int);

int main(void)
{
	/* get some env thing(s) */
	const char *theMark = getenv("USERNAME");
	int printfCutter = 0;

	int intPurchasePrice, intDownPayment, intNumPayments; /* these vars closely related and don't like to hang out with printfCutter*/
	/* long double dblMathStuff; double dblOtherMath; scratch */

	float fltApr; /* precession mathy stuff */

	/* formatty stuff  */
	if(system("cls"))
	{
		ErrorThanksBye();
	}

	/* draw stuff block of things */
	PrettyLines('$',CON_LENGTH); /* assume full sized con from the 640 x 480 days--moot comment now with con_length const but so much other redoing, I need to remember */
	MakeSpaces(1);
	printf("%*s%s",_CENTER_TEXT_START_POS(strlen(LENDINGCO))," ",LENDINGCO);
	MakeSpaces(3);
	printf("%*s%s",_CENTER_TEXT_START_POS(strlen("$$ Consignee $$"))," ","$$ Consignee $$"); /* maybe stick to preprocessor string literals but this was supposed to be a quick project */
	MakeSpaces(2);
	printf("%*s%s",_CENTER_TEXT_START_POS(strlen(theMark))," ",theMark);
	MakeSpaces(2);
	PrettyLines('$',CON_LENGTH);
	MakeSpaces(3);
	
	/* find out how much we can take 'theMark' for */
	printf("Enter the purchase price in whole dollars: ");scanf("%d",&intPurchasePrice);

	MakeSpaces(1);
	printf("Enter the sum you'll be paying down on this purchase in whole dollars: ");scanf("%d",&intDownPayment);

	MakeSpaces(1);
	printf("Enter your preferred loan term in years: ");scanf("%d",&intNumPayments); /* oh, we asked for years not number of payments, so lets fix that */
	intNumPayments *= 12; /* magic! loan term in years to months! */

	MakeSpaces(1);
	/* printf("Stuff we have at this point is %d and %d and %d\n",intPurchasePrice,intDownPayment,intNumPayments); 
	 * a thing I had for quick checking but have preserved for postarity
	 */

	printf("Good news, your terms qualify you for preferred lending! Enter your preferred APR: ");scanf("%f",&fltApr);
	fltApr /= 100; /* person percent into number percent */

	/* final display and calculations */

	/* formatty stuff  */
	if(system("cls"))
	{
		ErrorThanksBye();
	}

	/* draw stuff block of things */
	PrettyLines('$',CON_LENGTH); /* assume full sized con from the 640 x 480 days--moot comment now with con_length const but so much other redoing, I need to remember */
	MakeSpaces(1);
	printf("%*s%s",_CENTER_TEXT_START_POS(strlen(LENDINGCO))," ",LENDINGCO);
	MakeSpaces(3);
	printf("%*s%s",_CENTER_TEXT_START_POS(strlen("Loan Information Discosure Statement"))," ","Loan Information Discosure Statement");
	MakeSpaces(2);
	PrettyLines('$',CON_LENGTH);
	MakeSpaces(3);


	printfCutter = printf("Borrower Name:");printf("%*s%s", COL_LENGTH - printfCutter, " ", theMark);MakeSpaces(2);
	printfCutter = printf("Purchase Price:");printf("%*s$%-5.2f", COL_LENGTH - printfCutter, " ", (float)intPurchasePrice);MakeSpaces(2);
	printfCutter = printf("Down Payment:");printf("%*s$%-5.2f", COL_LENGTH - printfCutter, " ", (float)intDownPayment);MakeSpaces(2);
	printfCutter = printf("Principle Borrowed:");printf("%*s$%-5.2f", COL_LENGTH - printfCutter, " ",(float)(intPurchasePrice - intDownPayment));MakeSpaces(2);
	printfCutter = printf("Number of Payments");printf("%*s%-8d", COL_LENGTH - printfCutter, " ", intNumPayments);MakeSpaces(2);
	printfCutter = printf("Annual Interest Rate:");printf("%*s%.2f%c", COL_LENGTH - printfCutter, " ", fltApr * 100,'%');MakeSpaces(2);
	printfCutter = printf("Monthly Payment:");printf("%*s$%-5.2lf", COL_LENGTH - printfCutter, " ",MonthlyPayment(fltApr/12.0, (intPurchasePrice - intDownPayment) , intNumPayments));MakeSpaces(2);
	printfCutter = printf("Total Repayment:");printf("%*s$%-5.2f", COL_LENGTH - printfCutter, " ", MonthlyPayment(fltApr/12.0, (intPurchasePrice - intDownPayment) , intNumPayments) * (float)intNumPayments);MakeSpaces(2);
	printfCutter = printf("Total Interest:");printf("%*s$%-5.2f", COL_LENGTH - printfCutter, " ", MonthlyPayment(fltApr/12.0, (intPurchasePrice - intDownPayment) , intNumPayments) * (float)intNumPayments - (intPurchasePrice - intDownPayment));MakeSpaces(2);

	PrettyLines('$',CON_LENGTH);

	return(0);
}

double MonthlyPayment(float i, int p, int n)
{
	return(((i * p) / (1 - pow((1.0 + i), -n))));
}


int ErrorThanksBye(void)
{
	printf("Crap, a thing happened  %lu",GetLastError());
	return(-1);

}

void MakeSpaces(int lines)
{
		int i = 0;
		while(i!=lines)
	{
		printf("\n"); /* flex our loops. yeah, this one before for() actually got entered be.for()e-- and then moved to a sub */
		i++; /* while infinite loops are fun, I've got houses to sell and suckers to indenture */
	}

}

void PrettyLines(char charToPrint, int intConWidth)
{
	

	for(int i = 0; /* county thing to pritt a thing intConWidth many times */
		i < intConWidth; /* do it this  many times */
		i++) /* remember how many times i did a thing */
	{
		printf("%c",charToPrint);
	}
	printf("\n");

}