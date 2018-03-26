/**********************************************************************************************************************
 * Assignment and Date:    File read/write operation	  May 2015                                            
 *                                                                     
 * Programmer:  Ondrusek                                                       
 *                                                                      
 * Title:    Demonstration of file read/write operation based on Fig 6.2                                                           
 *                                                                     
 * Target user:  EET-247 students                                                      
 *                                                                     
 * Specifications:   No unique specifications                                                   
 *                                                                     
 * Inputs/Outputs:  Input: Text file (indata.txt), Keyboard  OUTPUT: Text file (outdata.txt)                                                   
 *                                                                     
 * Variables:  *inp, *outp, sum, item, input_status, count all defined in source code body                                                        
 *                                                                     
 * Constants:      None                                                    
 *                                                                     
 * Non-standard Libraries or functions:  None                              
 *                                                                      
 * Description and Purpose:  This  program demonstrats how to read, format/manipulate and the write data to a text file.
	The path to the files are specified in the source code.  Figure 6.2- Reads each number from an input file and writes it 
	rounded to 2 decimal places on a line of an output file.
 *                                                                     
 * Additional Information: Last modified Apr 2017 by AO to improve documentation                                         
 * **********************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int 
main(void) 

{/**********Defining Variables ************************/
    FILE *inp;																//-> pointer to input file
    FILE *outp;																//-> pointer to ouput file 
    double sum=0,															//used to calculae the quantity of the values read into the system
			item;															//variable assigned the input value when data is read from file
    int input_status,														// status value returned by fscanf
		count=0;															//used to track number of entries

    /* Prepare files for input or output */   
    inp = fopen("c://temp//indata.txt", "r");								//assigning variable inp as a buffer to recieve data from file
    outp = fopen("c://temp//outdata.txt", "w");								//assigning variable outp as a buffer to write data to file

    /*** Data INPUT/OUTPUT routine -  Read each item, format it, and write it */ 
    input_status = fscanf(inp, "%lf", &item);								//Reading initial data to ensure file exists and data is in the file
    while (input_status == 1)												// Validating that the file has NOT reached the EOF. EOF is indicated when input_status==-1
		{																	//**BEGIN while routine
        printf("%10.2lf \t",item);											//prints data to display screen in proper format
		fprintf(outp, "%.2f\n", item);										//outputs data to specified output file
		count+=1;															// tracks number of entries read from file
        input_status = fscanf(inp, "%lf", &item);							//Reads data from file in order to verify there is still any data left to read
		
		if (count % 6 == 0) printf("\n");									//Used to determine number of columns
		sum= sum + item;													//tracking the values or sum of the entries
		}																	//**END while routine

    /********************** Closing files routine**************** */
    fclose(inp);															//Closing input file
	fprintf(outp, "The count is %d \t The sum is: %10.4f",count,sum);		//Writes the count & sum information into the text file output
    fclose(outp);															//Closing the output file

	/******** Writing Summary Information to Screen ***************/
	printf("\n\nThe count is %d \t The sum is: %10.4f \n",count,sum);		//Displaying count & sum information
	system("date /T");														//Displaying operating system date
	system("time /T");														//Displaying operating system time
	getchar();


	/************* Routine to display raw data **********************/ 
	system("cls");															//Clears screen
	printf("\n+++++++++++++INDATA.TXT+++++++++++++++++++++++++++++++\n");	//Displays header
	system("type c:\\temp\\indata.txt");									//Using operating system command 'type' to dump contents of file to screen
	getchar();																//pause
	system("cls");															//Clears screen
	printf("\n+++++++++++++OUTDATA.TXT++++++++++++++++++++++++++++++\n");	//Displays header
	system("type c:\\temp\\outdata.txt");									//Using operating system command 'type' to dump contents of file to screen
	getchar();																//pause

    return (0);																//end of program - returning code 0 to OS  indicating normal termination/conclusion of program
}


