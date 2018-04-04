/* Assignment and Date:		LAB 2D, Due 03APR18
 *
 * Programmer: 				S Kirkland, 0208135
 *
 * Title:					LAB2D
 *
 * Target user:				Math Novice People and Other Pronouns
 *
 * Specifications:			Times Table Reference
 *
 * Inputs/Outputs:			I/User val for tables size <= 12
 *							O/A usable and formatted times table
 *
 * Variables:				user table size, line count, col count
 *
 * Constants:				*
 *
 * Non-standard Libraries:	stdlib.h stdio.h
 *
 * Description and Purpose: produce cheat sheet times table from
 *							user dictated size
 *
 * Additional Comments:		print to pdf, reduce to 3x5 index card, print
 *							to index card. profit
 *
 *
 *   Copyright (C) <2018>  Steven Kirkland
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>

#define HEADCHAR '*'
#define CHARTCHAR 'X'

void hdrOfChar(int,int);
void hdrOfInfo(int);

int main(void)
{
	/* vars for doing things later */
	int maxTableSize=-1, scanfStateDone = 0, maxTableLen;
	short singleOrDoubleDigit;

	/* start of the thing so lets sanitize the screen like we do vars! */
	system("cls");

	
	/* to not put in an integer is mean man */

	do {
		printf("\nIf you'd be so kind as to give us an integer between 1 and 12, please : ");
		scanf("%d",&maxTableSize);


		if((maxTableSize > 0) && (maxTableSize <= 12))
	 		scanfStateDone = 0;
	 	else {
	 		scanfStateDone = 1;
	 		/* stop trying to break things */
	 		while(getchar()!='\n');
	 		printf("\a");
	 	}


	} while(scanfStateDone);


	/* now lets do things k? but first! a tiny bit of cheating /emote kackle */

	maxTableLen = (maxTableSize+2) * printf("%*d",(maxTableSize >=3?4:3),maxTableSize);
	system("cls");
	hdrOfChar(HEADCHAR,maxTableLen);



	/* some mathing time-pre line */
	printf("%*c",(maxTableSize >=3?4:3),' ');
	for(int i = 0;i <= maxTableSize; i++) {
		i != 0? (printf("%*d",(maxTableSize >=3?4:3),i)):(printf("%*c",(maxTableSize >=3?4:3),CHARTCHAR));
	}
	printf("\n");

	/* better divider */
	hdrOfChar(CHARTCHAR,maxTableLen);

	/* loopy math stuffs */
	for(int i = 1;i<= maxTableSize; i++) {
		i != 0? (printf("%*d",(maxTableSize >=3?4:3),i)):(printf("%*c",(maxTableSize >=3?4:3),CHARTCHAR));
		printf("%*c",(maxTableSize >=3?4:3),CHARTCHAR);

		for(int j = 1; j<= maxTableSize; j++) {
			printf("%*d",(maxTableSize >=3?4:3),j*i);
		}

		printf("\n");
	}

	hdrOfChar(HEADCHAR,maxTableLen);
	printf("\n\n");

	/* end the thing */
	hdrOfInfo(maxTableLen/4);

	system("pause > nul");
	return(0);
}


void hdrOfInfo(int thisSizeTable) 
{
	const char THETHING[]="== Math Magic Maker ==";

	printf("%*c%s", thisSizeTable, ' ', THETHING);


	printf("\n\n");
}

void hdrOfChar(int thingToCon, int thisManyTimes)
{
	/* print a thing x number of times then new line */
	for(int i=0;i<thisManyTimes;++i)
		printf("%c",thingToCon);

	printf("\n");
}

