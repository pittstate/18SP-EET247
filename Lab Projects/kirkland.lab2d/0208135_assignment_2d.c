/* Assignment and Date:		LAB 2D, Due 20MAR18
 *
 * Programmer: 				S Kirkland, 0208135
 *
 * Title:					LAB2D
 *
 * Target user:				Metal Ball Buyers
 *
 * Specifications:			Give shipping costs for various sizes and
 *							compositions of metal balls via a menu list
 *
 * Inputs/Outputs:			I/Ball composition and size
 *							O/Shipping cost and shipped weight
 *
 * Variables:				Ball size, ball composition, quantity
 *
 * Constants:				Au/Ag/Cu composition densities
 *
 * Non-standard Libraries:	stdlib.h stdio.h
 *
 * Description and Purpose: Provide shipping metrics output, make use
 *							of SWITCH statement in selection items
 *
 * Additional Comments:		attempt to align the header in a pseudo columnar
 *							fashion in faithful memory of 80 column console
 *****************************************************************************/   

#include <stdio.h>			/* printf, scanf 								 */
#include <stdlib.h>			/* Microsoft host system commands				 */

#define COL_LENGTH 32		/* col span for pseudo columnar Outputs 		 */
#define CON_LENGTH 80		/* 80 chars wide or it didn't happen			 */

#define AG 1				/* set identifiers for composition where gold=1  */
#define AU 2				/* silver=2 and copper=3						 */
#define CU 3

#define	LARGE 1				/* set identifiers for size where large=1        */
#define	MEDIUM 2			/* medium=2 and small=3							 */
#define	SMALL 3

#define SHIPCOST_CU 3.5		/* shipping cost for copper is alone and silver  */
#define SHIPCOST 4.5	 	/* and gold are both the greater				 */

#define AG_DENSITY .379		/* silver lb/in.cubed 							 */
#define AU_DENSITY	.698	/* gold lb/in.cubed								 */
#define CU_DENSITY	.324	/* copper lb/in.cubed 							 */
							/*************************************************
							density data reference
							http://www.coolmagnetman.com/magconda.htm
							https://www.engineeringtoolbox.com/metal-alloys-densities-d_50.html
							**************************************************/

#define _CENTER_START_POS(x) ((CON_LENGTH - x)/2)
							/* inline macro for centered printf Outputs 	 */
<<<<<<< HEAD
#define _SPHERE_VOL(x) ((4.0/3.0)*3.1415926*((x/2.0)*(x/2.0)*(x/2.0)))
							/* more yay for inline macro with sphr shaped thg*/
							/* yay also for remembering casting const as flt */
=======
>>>>>>> 0125e11e3fee89b58b28f9e9525f3df3ba766231

#define BALLCO "Acme Bearing Co, ABC"
							/* ball bearing drop shipper					 */
#define BALLCOSLOGAN "We've got the biggest balls of them all"
							/* credit ACDC for ballco slogan				 */

int outputHeader(void);		/* return 0 for no issues because all the things
							   want to be error checked...					 */

int outputItemsList(void);	/* items list and sizes							 */

							/* no cmdline vars but I die a little inside
							   each time I see main(void) :( 				 */
int main(int argc, char *argv[]) 
{
	char c = 0;
	int bearingComposition = 0, bearingQuantity = 0;
	int bearingSize = 0;	/* init and sanitize vars for selection.		 */
	double bearingWeight = 0.0;


	system("cls");
	outputHeader();			/* not worried about return val I guess			 */

							/* user input time, use while to get input		 */
	printf("\nSelect composition; (G)old, (S)ilver, or (C)opper > ");

	while(!(bearingComposition)) {
		switch(c = getchar()) {
			case '\n': case '\r':break;
							/* capture and throw out newline and/or return   */
							/* from user presses enter						 */
			case 'g': case 'G':
				bearingComposition=1;
				printf("\nGold Selection Confirmed");
				break;
			case 's': case 'S':
				bearingComposition=2;
				printf("\nSilver Selection Confirmed");
				break;
			case 'c': case 'C':
				bearingComposition=3;
				printf("\nCopper Selection Confirmed");
				break;
			default:
				printf("\nERROR -- Invalid Selection! Selected\nSelect composition; (G)old, (S)ilver, or (C)opper > ");
				break;
			}
			
	}

	printf("\nSelect size; (L)arge, (M)edium, or (S)mall > ");

	while(!(bearingSize)) {
		switch(c = getchar()) {
			case '\n': case '\r':break;
							/* capture and throw out newline and/or return   */
							/* from user presses enter						 */
			case 'l': case 'L':
				bearingSize=1;
				printf("\nLarge Selection Confirmed");
				break;
			case 'm': case 'M':
				bearingSize=2;
				printf("\nMedium Selection Confirmed");
				break;
			case 's': case 'S':
				bearingSize=3;
				printf("\nSmall Selection Confirmed");
				break;
			default:
				printf("\nERROR -- Invalid Selection! Selected\nSelect size; (L)arge, (M)edium, or (S)mall > ");
				break;
			}
			
	}

	while(bearingQuantity < 1) {
		printf("\nEnter the desired quantity > ");
		scanf("%d", &bearingQuantity);

		if(bearingQuantity < 1)
			printf("\nERROR - Invalid quantity!");

	}

							/* shipping costs and list of things to ship     */
	system("cls");
	outputHeader();

	printf("\nQuantity of bearings shipped: 		%d",bearingQuantity);
	printf("\n\nBearing Size and Material:		");
	(bearingSize == 1)?(printf("Large     ")):((bearingSize == 2)?(printf("Medium      ")):(printf("Small      ")));
	(bearingComposition == 1)?(printf("Gold\n")):((bearingComposition ==2)?(printf("Silver\n")):(printf("Copper\n")));

	printf("\nShipping weight comes to:		");
	switch(bearingComposition) {
		case 1:
			bearingWeight = AU_DENSITY;
			break;
		case 2:
			bearingWeight = AG_DENSITY;
			break;
		case 3:
			bearingWeight = CU_DENSITY;
			break;
		default:
			break;
	}
	switch(bearingSize) {
		case 1:
							/* large bearingweight * 1^3 is still 1			 */
<<<<<<< HEAD
							/* which clearly doesn't matter when given in    */
							/* a diameter of 1 inch... Dear future self, 	 */
							/* get gooder at thinkinking. thnxbye.			 */

			bearingWeight *= _SPHERE_VOL(1.0);
			break;
		case 2:
			bearingWeight *= _SPHERE_VOL(0.5);
			break;
		case 3:
			bearingWeight *= _SPHERE_VOL(0.25);
=======
			break;
		case 2:
			bearingWeight *= (.5*.5*.5);
			break;
		case 3:
			bearingWeight *= (.25*.25*.25);
>>>>>>> 0125e11e3fee89b58b28f9e9525f3df3ba766231
			break;
		default:
			break;
	}

	printf("%5.2lf",bearingWeight *= bearingQuantity);

	printf("\n\nTotal shipping costs come to:		$");
	switch(bearingComposition) {
		case 1: case 2:
			printf("%5.2lf", bearingWeight * SHIPCOST);
			break;
		default:
			printf("%5.2lf", bearingWeight*SHIPCOST_CU);
			break;
	}

	printf("\n\n");			/* The End. Man, this code got ugly when tired   
							   took me over :(								 */
	system("pause");
	return(0);
}


int outputHeader(void)		/* fancy header and new lines for the items list */
{
	const char instructionLineOne[]="Big (and small) Selection Routine";
	const char instructionLineTwo[]="Select your new ball size and composition";
	printf("%*c",_CENTER_START_POS(COL_LENGTH),' ');

	for(int i = 0;i<COL_LENGTH;i++)
	{
		printf("*");
	}

	printf("\n%*c%s",_CENTER_START_POS(strlen(BALLCO)), ' ',BALLCO);
	printf("\n\n%*c%s",_CENTER_START_POS(strlen(BALLCOSLOGAN)),' ',BALLCOSLOGAN);
	printf("\n\n%*c%s",_CENTER_START_POS(strlen(instructionLineOne)),' ',instructionLineOne);
	printf("\n\n%*c%s",_CENTER_START_POS(strlen(instructionLineTwo)),' ',instructionLineTwo);

	printf("\n\n%*c",_CENTER_START_POS(COL_LENGTH),' ');

	for(int i = 0;i<COL_LENGTH;i++)
	{
		printf("*");
	}
	
	printf("\n\n\n");
	return(0);
}