/**********************************************************************************************************************
 * Assignment and Date:    File read/write operation	  Apr 2017                                            
 *                                                                     
 * Programmer:  Ondrusek                                                       
 *                                                                      
 * Title:   DATA MANIPULATION - Modified Demonstration of file read/write operation based on Fig 6.2 to include ADDITIONAL array manipulation                                                          
 *                                                                     
 * Target user:  EET-247 students                                                      
 *                                                                     
 * Specifications:   No unique specifications                                                   
 *                                                                     
 * Inputs/Outputs:  Input: Text file (indata.txt), Keyboard  OUTPUT: Text file (outdata.txt)                                                   
 *                                                                     
 * Variables:  *inp, *outp, sum, item, input_status, count, cnt,row,column, ARRAY, ARRAY_TABLE all defined in source code body                                                        
 *                                                                     
 * Constants:      None                                                    
 *                                                                     
 * Non-standard Libraries or functions:  None                              
 *                                                                      
 * Description and Purpose:  This  program demonstrats how to read, format/manipulate and the write data to a text file.
	The path to the files are specified in the source code.  Figure 6.2- Reads each number from an input file and writes it 
	rounded to 2 decimal places on a line of an output file.
 *                                                                     
 * Additional Information: Last modified Apr 2017 by AO to improve documentation & Include more array functions                                        
 * **********************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define array_size 200   //used to define the size of the array

//--------------------DECLARING FUNCTIONS -------------------------
double get_max(const double list[], int n);
double get_min(const double list[], int n);
void ascending_sort(int n, double list[]);	
void descending_sort(int n, double list[]);
void delay(int time);

int 
main(void) 

{/**********Defining Variables ************************/
    FILE *inp;																//-> pointer to input file
    FILE *outp;																//-> pointer to ouput file 
    double sum=0,															//used to calculae the quantity of the values read into the system
			item;															//variable assigned the input value when data is read from file
    int input_status,														// status value returned by fscanf
		count=0,cnt=0,row=0, column=0;										//used to track number entries of read-in data & manipulation within arrays
	double array[array_size];												//declaring array size
	double array_table[array_size][3];

    /* Prepare files for input or output */   
    inp = fopen("c://temp//indata.txt", "r");								//assigning variable inp as a buffer to recieve data from file
    outp = fopen("c://temp//outdata.txt", "w");								//assigning variable outp as a buffer to write data to file

    /*** Data INPUT/OUTPUT routine -  Read each item, format it, and write it */ 
   system("cls");
   printf("Dispalying RAW DATA as it is being read for file: indata.txt \n \n");
	
	input_status = fscanf(inp, "%lf", &item);								//Reading initial data to ensure file exists and data is in the file
	array[count] = item;
	while (input_status == 1)												// Validating that the file has NOT reached the EOF. EOF is indicated when input_status==-1
		{																	//**BEGIN while routine
        printf("%10.2lf \t",item);											//prints data to display screen in proper format
		fprintf(outp, "%.2f\n", item);										//outputs data to specified output file
		 array_table[count][0]=array[count];
		 count+=1;															// tracks number of entries read from file
        input_status = fscanf(inp, "%lf", &item);							//Reads data from file in order to verify there is still any data left to read
		 array[count] = item;
		
		 if (count % 4 == 0){ printf("\n");	 delay(1);	}							//Used to determine number of columns
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
	
	printf("\n Displaying Data from FUNCTIONS \n");
	printf("Largest number is:          %8.2f \n", get_max(array,count));
	printf("Smallest number is:         %8.2f \n", get_min(array,count));
	
	system("pause");

	system("cls");

	/******** Writing sorted data information to Screen ***************/
	printf("Displaying sorted array - ASCENDING \n");
	ascending_sort(count,array);
	for (cnt=0; cnt< count; ++cnt) 
		{
			if (cnt%4==0) {printf("\n"); delay(1);}
		printf("%12.2lf",array[cnt]);
		array_table[cnt][1]=array[cnt];
		} //END FOR Loop

	printf("\n\nDisplaying sorted array - DESCENDING\n");
	descending_sort(count,array);
	for (cnt=0; cnt< count; ++cnt) 
		{
			if (cnt%4==0){ printf("\n");delay(1);}
		printf("%12.2lf",array[cnt]);
		array_table[cnt][2]=array[cnt];
		} //END FOR Loop

	printf("\n");
	system("pause");

	/************* Routine to display raw data **********************/ 
	system("cls");															//Clears screen
	printf("\n+++++++++++++INDATA.TXT+++++++++++++++++++++++++++++++\n");	//Displays header
	system("type c:\\temp\\indata.txt");									//Using operating system command 'type' to dump contents of file to screen
	getchar();																//pause
	system("cls");															//Clears screen
	printf("\n+++++++++++++OUTDATA.TXT++++++++++++++++++++++++++++++\n");	//Displays header
	system("type c:\\temp\\outdata.txt");									//Using operating system command 'type' to dump contents of file to screen
	printf("\t");
	system("pause");													    //pause
	system("cls");

	/******************************* Generating Final Table *******************************/
	printf("_________________________________________________________________________ \n");
	printf("Index|      ORG    |   Ascend    |     Desc    | Ascend + Desc|   SQRT   |\n");           //Printing Header
	printf("-----+-------------+-------------+-------------+--------------+----------");

	for (row=0; row< count; ++row)                                    //Determines what row is being evaluated
		{
			printf("\n%4d |", row);                                     //prints first columns - index of array
			for(column=0; column<=2; ++column) printf("%12.2lf |",array_table[row][column]); //Displaying each row and column of array original, ascending & descending
			printf("%14.2lf|%10.2lf|",array_table[row][1] + array_table[row][2], sqrt(array_table[row][1] + array_table[row][2]));      //Adding additional columns of sum of ascending & descending
			delay(1);                                                     //delay after printing each row
		} //END FOR statement for COLUMNS
	printf("\n_________________________________________________________________________ \n");
	
	system("pause");
    return (0);																//end of program - returning code 0 to OS  indicating normal termination/conclusion of program
}//*********************END of MAIN Program *************************

//--------DEFINING FUNCTIONS -------------------------------
//**BEGIN FINCTION: get_max  From Fig 7.6 - modified - AO **
double get_max(const double list [], int n) /* input – ARRAY of doubles, input – number of list elements to examine */
            
{
      int count;               //count
      double cur_large;       /* largest value so far                        */

      /* Initial array element is largest so far.                         */
      cur_large = list[0];

      /* Compares each remaining list element to the largest so far save the larger      */
      for  (count=1; count< n; ++count) if (list [count] > cur_large) cur_large = list [count];

      return (cur_large);
} //END OF FUNCTION  get_max

 //***BEGIN Function: get_min **************************
double get_min(const double list [], int n) /* input – ARRAY of doubles, input – number of list elements to examine */
             
{
      int count;
      double cur_min;       /* smallest value so far   */

      /* Initial array element is largest so far.      */
      cur_min = list[0];

      /* Compares each remaining list element to the largest so far save the larger      */
      for  (count=1; count< n; ++count) if (list [count] < cur_min) cur_min = list [count];

      return (cur_min);
} //END OF FUNCTION:  get_min

 //***BEGIN Function: delay **************************
void delay(int time)  //Routine is for time delays. Each value inoputted represent 1 second of delay
{	int count;
	for (count=0; count < time * 100000000; ++count);	
	return ;
		
} //END FUNCTION: delay

 //***BEGIN Function ascending_sort *****************************
 void ascending_sort(int quantity, double list[ ])
   {                                                           
       int index, index2;
	   double temp;                                            
                                                               
       for(index = 1; index <= quantity-1; index++)                               
          for(index2 = 1; index2 <= quantity-index; index2++)                             
             if(list[index2-1] >= list[index2])                                
             {
                temp = list[index2-1];                                    
                list[index2-1] = list[index2];                                 
                list[index2] = temp;                                      
             }                                                 
   }   /*End Function: ascending_ort */

 //***BEGIN Function descending_sort ***************************
  void descending_sort(int quantity, double list[ ])
   {                                                           
       int index, index2;
	   double temp;                                            
                                                               
       for(index = 1; index <= quantity-1; index++)                               
          for(index2 = 1; index2 <= quantity-index; index2++)                             
             if(list[index2-1] <= list[index2])                                
             {
                temp = list[index2-1];                                    
                list[index2-1] = list[index2];                                 
                list[index2] = temp;                                      
             }                                                 
   }   /*End Function: descending_sort */

  
  