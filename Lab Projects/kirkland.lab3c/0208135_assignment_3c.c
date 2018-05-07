/* Assignment and Date:		LAB 3C, Due 24APR18
 *
 * Programmer: 				S Kirkland, 0208135
 *
 * Title:					LAB3C
 *
 * Target user:				Read/Write Sorting Emporium
 *
 * Specifications:			Read, write, and sort (or don't) all the things
 *
 * Inputs/Outputs:			I/user - start, abort, display, sort
 *							I/file - the data
 *							O/user - the data
 *							O/file - other data
 *
 * Variables:				sorting vars(many), read/write buffer var, nonsensical
 *							user feedback.(users don't know what they want)
 *
 * Constants:				array size, 
 *
 * Non-standard Libraries:	stdlib.h stdio.h string.h mergesort routine
 *							 (pretty much standard)
 *
 * Description and Purpose: Read some data, write some data, sort some data, show
 *							the user some data, entertain the consortium
 *
 * Additional Comments:		attempt to align the header in a pseudo columnar
 *							fashion in faithful memory of 80 column console
 *							I invented merge sort hours before Al Gore
 *							invented the internet. And gopher but it flopped.
 *****************************************************************************/   

#include <stdio.h>			/* printf, scanf 								 */
#include <stdlib.h>			/* Microsoft host system commands				 */
#include <string.h>			/* strings										 */

#define COL_LENGTH 32		/* col span for pseudo columnar Outputs 		 */
#define CON_LENGTH 80		/* 80 chars wide or it didn't happen			 */
#define LINE_CHAR "*"		/* char to use for bar lines 					 */
#define STACK_ARRAY 200		/* safe size array for stack memory (modern arch)*/


#define _CENTER_START_POS(x) ((CON_LENGTH - x)/2)
							/* inline macro for centered printf Outputs 	 */
#define NAMECO "Sort Co"
							/* Company Name									 */
#define SLOGANCO "Sorting Stuff With Bubble Sort (just kidding) for 83 years."
							/* Company Slogan 								 */


void mergesort(int[], int, int); /* magic mergesort							 */
void merge(int[], int, int, int, int);
							 /* magic merge 								 */
int outputHeader(void);		/* return 0 for no issues because all the things
							   want to be error checked...					 */
int outputItemsList(void);	/* items list and sizes							 */
							/* no cmdline vars but I die a little inside
							   each time I see main(void) :( 				 */

int main(int argc, char **argv) 
{
	/* some vars below														 */
	char c = 0;
	int readysetstartORabort = 0, doNothing = 0;
	int fileScanItemCount = 0, fileScanStatus = 0;
							/* init and sanitize vars county things.		 */
	double fileScanItem = 0.0, fileScanItemSum = 0.0, itemLargest = 0.0,
		itemSmallest = 0.0;
	char *dataFilenameDefault = "Lab3cdata.txt";
	char *dataFileName = dataFilenameDefault;
	FILE* dataFile;
	int itemArray[STACK_ARRAY];

	for(int i = 0; i!=STACK_ARRAY;i++) itemArray[i]=0;

	/* assuming user meant to specify an external file of real numbers		 */
	if(argc>=2)
		dataFileName = argv[1];


	system("cls");
	outputHeader();			/* not worried about return val I guess			 */

							/* user input time, use while to get input		 */
	printf("\nLets do a thing; (S)tart or (A)bort sorting on data file %s > ", dataFileName);

	while(!(readysetstartORabort)) {
		switch(c = getchar()) {
			case '\n': case '\r':break;
							/* capture and throw out newline and/or return   */
							/* from user presses enter						 */
			case 's': case 'S':
				readysetstartORabort = 1;
				printf("\nStart Selection Confirmed. Doing Stuff.");
				break;
			case 'a': case 'A':
				printf("\nAbort Confirmed. Exiting.");
				return(101);
				break;
			default:
				printf("\nERROR -- Invalid Selection! Selecte Harder.\n\nLets do a thing; (S)tart or (A)bort > ");
				break;
			}
			
	}

	/* we didn't abort so it must be time to do stuff. The only stuff we 	 */
	/* know how to do...													 */
	dataFile = fopen(dataFileName, "r");
	fileScanStatus = fscanf(dataFile, "%lf", &fileScanItem);

	system("cls");
	printf("\n\n");
	for(int i = 0; i<CON_LENGTH;i++) printf(LINE_CHAR);
	printf("\n\n");
	while(fileScanStatus == 1)
	{
		printf("%12.2lf \t",fileScanItem);
		itemArray[fileScanItemCount] = (int)fileScanItem;
		/* 							it's all ints anyway					 */

		fileScanItemCount++;

		fileScanStatus = fscanf(dataFile, "%lf", &fileScanItem);
		if((fileScanItemCount % 5) == 0) 
			printf("\n");

		fileScanItemSum += fileScanItem;
		fileScanItem<itemSmallest?itemSmallest=fileScanItem:(fileScanItem > itemLargest)?itemLargest=fileScanItem:doNothing++;
	}

	fclose(dataFile);

	printf("\n\n");
	for(int i = 0; i!=CON_LENGTH;i++) printf(LINE_CHAR);
	printf("\n\nCOUNT total is: %64d",fileScanItemCount);
	printf("\n\nSUM of numbers is: %61.2lf",fileScanItemSum);
	printf("\n\nSMALLEST of numbers is: %56.2lf",itemSmallest);
	printf("\n\nLARGEST of numbers is: %57.2lf",itemLargest);
	printf("\n\nI did nothing %d times in a conditional operator! (stats for nerds)",doNothing);
	printf("\n\n");
	for(int i = 0; i!=CON_LENGTH;i++) printf(LINE_CHAR);
	printf("\n");

	system("pause > nul");

	/* sort time															 */
	printf("\n\n");
	for(int i=0;i!=CON_LENGTH;i++) printf(LINE_CHAR);
	printf("\n\nMerge Sorting...");
	mergesort(itemArray,0,fileScanItemCount-1);
	printf("\n\nMerge Sorting done on %d records",fileScanItemCount);
	printf("\n\n");
	for(int i=0;i!=CON_LENGTH;i++) printf(LINE_CHAR);

	for(int i=0;i!=fileScanItemCount;i++) {
		(i%5==0)?printf("\n"):printf("\t");
		printf("%12d",itemArray[i]);

	}

	printf("\n\n");
	for(int i=0;i!=CON_LENGTH;i++) printf(LINE_CHAR);
	printf("\n");
	system("pause > nul");
	return(0);
}


int outputHeader(void)		/* fancy header and new lines for the items list */
{
	const char instructionLineOne[]="Read it and then";
	const char instructionLineTwo[]="Select the thing below.";
	printf("%*c",_CENTER_START_POS(COL_LENGTH),' ');

	for(int i = 0;i!=COL_LENGTH;i++)
	{
		printf("*");
	}

	printf("\n%*c%s", (int) _CENTER_START_POS(strlen(NAMECO)), ' ',NAMECO);
	printf("\n\n%*c%s", (int) _CENTER_START_POS(strlen(SLOGANCO)),' ',SLOGANCO);
	printf("\n\n%*c%s", (int) _CENTER_START_POS(strlen(instructionLineOne)),' ',instructionLineOne);
	printf("\n\n%*c%s", (int) _CENTER_START_POS(strlen(instructionLineTwo)),' ',instructionLineTwo);

	printf("\n\n%*c",_CENTER_START_POS(COL_LENGTH),' ');

	for(int i = 0;i!=COL_LENGTH;i++)
	{
		printf("*");
	}
	
	printf("\n\n");
	return(0);
}

/* attribs for sorty things
   https://www.thecrazyprogrammer.com/2014/03/c-program-for-implementation-of-merge-sort.html */
void mergesort(int a[],int i,int j)
{
    int mid;
        
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[STACK_ARRAY];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    
    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
        
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
        
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}
