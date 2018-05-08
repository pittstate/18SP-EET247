/* Assignment and Date:		LAB 4A, Due 01MAY18
 *
 * Programmer: 				S Kirkland, 0208135
 *
 * Title:					LAB4A
 *
 * Target user:				Evil Encrypting Erudites
 *
 * Specifications:			Encrypt all the things
 *
 * Inputs/Outputs:			I/user - encrypt, decrypt
 *							I/file - the data (maybe)
 *							O/user - secrets
 *							O/file - other data (nothing probably)
 *
 * Variables:				counters and stack char array
 *
 * Constants:				array size, et.al.
 *
 * Non-standard Libraries:	stdlib.h stdio.h string.h 'Ondrusek ROT20/21'
 *
 * Description and Purpose: decrypt and/or encrypt all the things
 *
 * Additional Comments:		decrypt the secrets
 *							
 *****************************************************************************/   

#include <stdio.h>			/* printf, scanf 								 */
#include <stdlib.h>			/* Microsoft host system commands				 */
#include <string.h>			/* strings										 */

#define COL_LENGTH 32		/* col span for pseudo columnar Outputs 		 */
#define CON_LENGTH 80		/* 80 chars wide or it didn't happen			 */
#define LINE_CHAR "#"		/* char to use for bar lines 					 */
#define STACK_ARRAY_WIDTH 200/* safe size array for stack memory(modern arch)*/
#define STACK_ARRAY_HEIGHT 4


#define _CENTER_START_POS(x) ((CON_LENGTH - x)/2)
							/* inline macro for centered printf Outputs 	 */
#define NAMECO "Crypty Co"
							/* Company Name									 */
#define SLOGANCO "Encrypting Things and Losing the Cypher for 83 Years."
							/* Company Slogan 								 */

void cosmeticWait(void);	/* for the lols									 */
int readFromFile(FILE*, char**);/* borrow some file read stuff from last lab */ 
int outputHeader(void);		/* return 0 for no issues because all the things
							   want to be error checked...					 */
int outputItemsList(void);	/* items list and sizes							 */
							/* no cmdline vars but I die a little inside
							   each time I see main(void) :( 				 */

int main(int argc, char **argv) 
{
	/* some vars below														 */
	char c = 0;
	int readysetstartORabort = 0, encryptTrue = -1; /* decrypt on encrypt false*/
	char *dataFilenameDefault = "CONSOLE";
	char *dataFileName = dataFilenameDefault;
	FILE* dataFile;
	char *itemArray[STACK_ARRAY_HEIGHT][STACK_ARRAY_WIDTH]; 
								/* array for the things 					 */
	char string[STACK_ARRAY_WIDTH]; /* almost out of time solution			 */
	for(register int i;i<STACK_ARRAY_WIDTH;i++)
		string[i]='\0';

	/* sanitize our array of arrays	super fast!								 */
	for(register int i=0; i!=STACK_ARRAY_HEIGHT;i++) 
		for(register int j = 0;j!=STACK_ARRAY_WIDTH;j++)
			itemArray[i][j]='\0';


	/* assuming user meant to specify an external file 				  		 */
	if(argc>=2)
		dataFileName = argv[1];
	

	system("cls");
	outputHeader();			/* not worried about return val I guess			 */

							/* user input time, use while to get input		 */
	printf("\nLets do a thing; (E)ncrypt or (D)ecrypt from source %s > ", dataFileName);
	printf("\n\nYou can also e(X)it if you've already encrypted all the things.");
	
	if(!strcmp(dataFileName,"TEST")==0) {
		while(!(readysetstartORabort)) {
			switch(c = getchar()) {
				case '\n': case '\r':break;
								/* capture and throw out newline and/or return   */
								/* from user presses enter						 */
				case 'e': case 'E':
					readysetstartORabort=1;
					printf("\nEncrypt Selection Confirmed. Deleting Cypher.");
					cosmeticWait();
					encryptTrue=1;
					break;
				case 'd': case 'D':
					readysetstartORabort=1;
					printf("\nDecrypt Confirmed. Doing Stuff.");
					encryptTrue=0;
					break;
				case 'x': case 'X':
					return(2); /* normal exit from menu							 */
				default:
					printf("\nERROR -- Invalid Selection! Select Harder.\n\nLets do a thing; (E)ncrypt or (D)ecrypt > ");
					break;
				}
				
			}
		}


	/* we didn't abort so it must be time to do stuff. 					 	 */
	printf("\n\n");
	for(int i = 0; i!=CON_LENGTH;i++) printf(LINE_CHAR);
	/* skeleton'd out line things from previous lab							 */
	/* read from file if specified by cli option							 */
	if(strcmp(dataFileName,"CONSOLE")==0) { /* strings match on 0			 */
		int strLen = 0;
		char newString[STACK_ARRAY_WIDTH];
		for(int i=0;i<STACK_ARRAY_WIDTH;i++)
			newString[i]='\0';
	
		/* using *itemArray[0]												 */
		printf("\nType the value to Ondrusek20-shift "); encryptTrue==1?printf("encrypt."):printf("decrypt.");
		printf("\n");
		//gets(itemArray[0]);
		//scanf("%s", &string[0]);
		gets(&string[0]);
		gets(&string[0]);

		printf("\nLooks like you want to use '%s' which is %d chars long.", string, strLen=(int)strlen(string));


		for(int i=0;i<strLen;i++) {
			if(encryptTrue)
				newString[i] = (int)string[i] + 20;
			else
				newString[i] = (int)string[i] - 20;
		}

		printf("\n\nThe resultant %s is %s",encryptTrue==1?"ciphertext":"plaintext", newString);



	} else if(strcmp(dataFileName,"TEST")==0) { /* the TEST 				 */
		printf("\n\nThe cipher text compared to the actual text provided..");
		char* cipherText="`UVHUAYYhFHK";
		char* plainText ="LAB4A-EET247";
		int len=0;

		printf("\nstrlen of cipher is %d and of plain is %d", len=(int)strlen(cipherText), (int)strlen(plainText));
		for(int i=0;i<len;i++) {
			printf("\n%c MINUS %c = %d", cipherText[i], plainText[i], (int)cipherText[i]-(int)plainText[i]);
		}
		printf("\nLooks like the cipher is ASCII code value MINUS 20 of the plaintext value.\nBye.");

	} else { /* from a file? sure.											 */
		printf("Nothing here yet, bye.");
		return(0);
	}


	printf("\n\n");
	for(int i = 0; i!=CON_LENGTH;i++) printf(LINE_CHAR);
	printf("\n");

	system("pause > nul");
	return(0);
}

void cosmeticWait(void)
{
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	system("ping localhost -n 1 > nul");
	printf(".");
	
}

int readFromFile(FILE* dataFile, char** dataFileName)
{
	int fileScanStatus = 0, counter = 0;
	char* fileScanItem[STACK_ARRAY_WIDTH];
	//extern char* itemArray[STACK_ARRAY_HEIGHT][STACK_ARRAY_WIDTH];
	
	dataFile = fopen(dataFileName, "r");
	fileScanStatus = fscanf(dataFile, "%s", *fileScanItem);

	system("cls");
	printf("\n\n");
	for(int i = 0; i<CON_LENGTH;i++) printf(LINE_CHAR);
	printf("\n\n");
	while(fileScanStatus == 1)
	{
		printf("%s \n",*fileScanItem);
	//	*itemArray[counter] = *fileScanItem;

		counter++;

		fileScanStatus = fscanf(dataFile, "%s", *fileScanItem);

	}

	fclose(dataFile);
	
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

