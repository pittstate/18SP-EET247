
/****************************************************************************************************************
 * Assignment and Date:     Demonstration of Pointers based on Figure 6.7 in Textbook   - Mar 2017				                                       
 *																												
 * Programmer:      Alec  Ondrusek                                               
 *                                                                      
 * Title:     Demonstration of Pointers used in sorting 3 numbers                                                         
 *                                                                     
 * Target user:     EET-247 Class                                                   
 *                                                                     
 * Specifications:                                                     
 *                                                                     
 * Inputs/Outputs:   3 numbers (Real)                                                  
 *                                                                     
 * Variables:   double: num1, num2,num3  int: count  Within function order: int cnt  double: temp, *Pointer1, *Pointer2                                                    
 *                                                                     
 * Constants:    none                                                      
 *                                                                     
 * Non-standard Libraries or functions:                                
 *                                                                      
 * Description and Purpose:   Designed to provide variable locations in memory and showing how pointers within a 
 *							function can manipulate variables in the MAIN portion of the program
 *                                                                     
 * Additional Information:                                             
 * ***************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void order(double *Pointer1, double *Pointer2, int *count); //Declaring function order

int
main(void)
{
        double num1, num2, num3;/* three numbers to put in order       */
		
		int count=0; //Used to track the number of times the function order is accessed. Initialized to 0

        /* DATA INPUT - Gets test data   */
        printf("Enter three numbers separated by blanks> ");scanf("%lf%lf%lf", &num1, &num2, &num3);

       //Routine to display INITIAL variable and address location

		printf("\nThe variable num1 is:%6.2lf  \t The location of num1 is: %d", num1,&num1);  
		printf("\nThe variable num2 is:%6.2lf  \t The location of num2 is: %d", num2,&num2);  
		printf("\nThe variable num3 is:%6.2lf  \t The location of num3 is: %d\n", num3,&num3);  
		
		system("pause");

 /* Orders the three numbers    */

        order(&num1, &num2 ,&count);	//Passes the locations of num1, num2, count
        order(&num1, &num3, &count);	//Passes the locations of num1, num3, count
        order(&num2, &num3, &count);	//Passes the locations of num2, num3, count

        /* Displays results following the manipulation of the variables                                            */
        printf("\n\nThe numbers in ascending order are: %.2f %.2f %.2f\n",num1, num2, num3);

	//Routine to display FINAL variable and address location after numbers have been sorted
		printf("\nThe variable num1 is:%6.2lf  \t The location of num1 is: %d", num1,&num1);  
		printf("\nThe variable num2 is:%6.2lf  \t The location of num2 is: %d", num2,&num2);  
		printf("\nThe variable num3 is:%6.2lf  \t The location of num3 is: %d\n", num3,&num3); 
	

		printf("\nFinal count is: %d\n",count); //displays the final value of count
		system("pause");
        return (0);
} //END of Main Function

void order(double *Pointer1, double *Pointer2, int *count)    //Function to manipulate the order of the values
{
        double temp; /* temporary variable to hold one number during swap      */

        /* Compares values pointed to by Pointer1 and Pointer2 and switches if necessary */
		int cnt = *count;	//initializes local variable cnt to the value of count
		cnt+=1;				//Increments the value of cnt
		*count=cnt;			//Changes the variable count in the main function
		 
		//Displays the value and locations of the variables while inside th function
		printf("\n%d \tPointer1 ->: %d contains value of:%6.2f", *count, Pointer1,*Pointer1); printf("\tPointer 2 ->: %d contains value of: %6.2f", Pointer2, *Pointer2);

         if (*Pointer1 > *Pointer2)//Evaluates the values that Pointer1 and Pointer2 are pointing at. If TRUE than manipulate values
		 { 
                 temp = *Pointer1;			//assigns temp the value that Pointer1 is pointing to				
                 *Pointer1 = *Pointer2;		//assigns the value that Pointer1 is pointing to to that of which Pointer2 is pointing to
                 *Pointer2 = temp;			//assigns the value that Pointer2 is pointing to the that of temp	
				
        } //END of IF 
} //END of Function order


