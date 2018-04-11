/*	Assignment and Date:		LAB3B, Due 10APR18
 *
 *	Programmer:					S Kirkland, 0208135
 *
 *	Title:						LAB3B
 *
 *	Target User:				Peoples who's brains don't invert images but want to see a pyramid.
 *
 *	Specifications:				Make an upside-down pyramid
 *
 *	Inputs/Outputs:				I/pyramid height
 *								O/pyramid balanced on its 1
 *
 *	Variables:					loop counters, pyramid height from 1 to 9, stuff for center
 *
 *	Constants:					static assume console size instead of asking env
 *
 *	Non-standard Libraries:		stdlib.h stdio.h
 *
 *	Description and Purpose:	Develope a globally linked system to secure people from
 *								harming each other into extenction while also reselling
 *								all the things learnt from predicting how a pleb might
 *								act but this will only work if a tiny pyramid can be
 *								calibrated to stand on end.
 *
 *	Additional Comments:		Hic Sunt dracones
 *
 **************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define COL_LENGTH 32
#define CON_LENGTH 80

#define _CENTER_ON_START(x) ((CON_LENGTH-x)/2)

void alignment(void);

void plantThePyramid(int);

void closingBanner(int);

int main(int argc, char *argv[])
{

	int usrVal = 0, prevLineLength = 0;

	system("cls");
	printf("Images in our vision system are inverted and is up to our brain makes it rational.\nEnter a value to de-invert a triangular pyramid shaped thing: ");
	scanf("%d",&usrVal);


	/* val not newline or return prevent strange behavior if a letter is entered */
	while(((usrVal<1)||(usrVal>9))&&((usrVal!='\n')||(usrVal!='\r'))) {
		printf("\nMaybe we should start with rules and directions. The number that you enter should not be greater than 9\nnor lower than 1.  When you think you've got that under control\nlets go ahead and try that number entry thing again (from 1 to 9): ");

		scanf("%d",&usrVal);

	}
	/* should have our valid value now, joy! */

	system("cls");
	/* quick line drop */
	for(int i = 0; i<7;i++)
		system("echo."); /* this way breaks portability maybe but the cool kids do it */

	/* testing condition, not the droids you're looking for */
	if(argc==2)
		alignment();

	plantThePyramid(usrVal);

	closingBanner(usrVal);

	system("pause > nul");

	return(0);

}

void closingBanner(int centerPos)
{
	/* time to put an end to this madness */
	const char closing1[]="### Your Brain Did This To You ###";
	const char closing2[]="###    Programmer S Kirkland   ###";
	for(int i = 0; i<3;i++)
		system("echo.");

	printf("\n%*c%s",_CENTER_ON_START(strlen(closing1))-2,' ', closing1);
	printf("\n%*c%s",_CENTER_ON_START(strlen(closing2))-2,' ', closing2);



}

void plantThePyramid(int height)
{
	/* represent 	i=edge and height qualifier 
					j=col derived height from iteration and max val
	   				k=track our left shift padding										 */
	int i, j, k;
	i = j = k = 0;

	/* make rows */
	do {
		printf("\n");
		/* increment and assign for local looping */
		j = height - i++;

		/* left padding */
		/* center start val of 5 puts the tip of the iceberg on position 4 
		   which is the same thing as center(0)-3 for num spacing but looks silly both ways*/
		k = _CENTER_ON_START(4)- (2* j);
		printf("%*c",k,' ');


		/* left step */	
		for(int p = 1; p < j; p++)
			printf("%2d",p);

		printf("%2d",j);

		/* right step */
		for(int p = --j; p != 0; p--)
			printf("%2d",p);


	} while(i != height);
	
	system("echo.");
}

void alignment(void)
{
	/* alignment ref thing used for format finding. you won't see it unless you want to see it */
	int p = 0;
	p = printf("\n%*d",(CON_LENGTH/2)-2,0);
	printf("\n%*s",_CENTER_ON_START(p)*2,"CENTER");


}