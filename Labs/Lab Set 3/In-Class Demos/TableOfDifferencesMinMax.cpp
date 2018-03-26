/***********************************************************************
 * Assignment and Date:  Demonstration of ARRAYS	Apr 2017                                              
 *                                                                     
 * Programmer:  Ondrusek                                                       
 *                                                                      
 * Title: TableOfDifferencesMinMax                                                             
 *                                                                     
 * Target user:  EET-247 students                                                      
 *                                                                     
 * Specifications:  Generates the Sum, Std Deviation, Mean, Minimum & Maximum of a group of doubles                                                   
 *                                                                     
 * Inputs/Outputs:  Input - Keyboard (8 real numbers)                                                 
 *                                                                       
 * Variables:  Double Array x, mean, std_dev, sum, sum_sqr   int count                                                       
 *                                                                     
 * Constants:                                                          
 *                                                                     
 * Non-standard Libraries or functions:    math, stdlib                            
 *                                                                      
 * Description and Purpose:   Demontstartes basc idea of arrays used in main function and passed into functions                                           
 *                                                                     
 * Additional Information:   Based on book figures 7.2 & 7.6                                          
 * *********************************************************************/
 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_ITEM 8   /* maximum number of items in list of data       */

//DECLARE FUNCTION get_max - AO
double get_max(const double list[], int n);
double get_min(const double list[], int n);

int
main (void)
{
      double x[MAX_ITEM],   /* data list                              */
             mean,          /* mean (average) of the data             */
             st_dev,        /* standard deviation of the data         */
             sum,           /* sum of the data                        */
             sum_sqr;       /* sum of the squares of the data         */
      int    count;				//Counting variable

      /* Gets the data                                                */
      printf("Enter %d numbers separated by blanks or <return>s\n> ", MAX_ITEM);
      for   (count= 0; count< MAX_ITEM; ++ count) scanf("%lf", &x[count]);
	   
      /* Computes the sum and the sum of the squares of all data      */
      sum = 0;								//initialize sum
      sum_sqr = 0;							//initialize sum_sqr
      for   (count= 0; count< MAX_ITEM; ++count) 
		{//Start FOR LOOP
             sum += x[count];
             sum_sqr += x[count]  *  x[count];
		}//END FOR LOOP

    /* computes and prints the mean and standard deviation            */
    mean = sum / MAX_ITEM;									//calculating the MEAN
    st_dev = sqrt (sum_sqr / MAX_ITEM - mean * mean);		//Caluclating the Std Deviation

	printf("The SUM is:                 %8.2f \n",sum);
    printf("The mean is                 %8.2f \n", mean);
    printf ("The standard deviation is   %8.2f \n", st_dev);
	printf("Largest number is:          %8.2f \n", get_max(x,count));
	printf("Smallest number is:         %8.2f \n", get_min(x,count));

    /* Displays the  difference table between each item and the mean         */
    printf ("\nTable of differences between data values and mean\n");
    printf ("Index       Item      Difference\n");
    for  (count= 0; count< MAX_ITEM;  ++count)
        printf ("%3d%4c%9.2f%5c%9.2f\n", count, ' ', x[count], ' ', x[count] - mean);
	system("pause");

    return (0);
}

/* FIGURE 7.6  Function to Find the Largest Element in an Array */
/*
 *  Returns the largest of the first n values in array list
 *  Pre: First n elements of array list are defined and n > 0
 */

//BEGIN FINCTION get_max  From Fig 7.6 - modified to utilize DOUBLES - AO

double get_max(const double list [], int n) /* input – ARRAY of doubles, input – number of list elements to examine */
            
{
      int count;
      double cur_large;       /* largest value so far                        */

      /* Initial array element is largest so far.                         */
      cur_large = list[0];

      /* Compares each remaining list element to the largest so far save the larger      */
      for  (count=1; count< n; ++count) if (list [count] > cur_large) cur_large = list [count];

      return (cur_large);
} //END OF FUNCTION  get_max


//BEGIN FINCTION get_min  From Fig 7.6 - modified to utilize DOUBLES - AO

double get_min(const double list [], int n) /* input – ARRAY of doubles, input – number of list elements to examine */
             
{
      int count;
      double cur_min;       /* smallest value so far   */

      /* Initial array element is largest so far.      */
      cur_min = list[0];

      /* Compares each remaining list element to the largest so far save the larger      */
      for  (count=1; count< n; ++count) if (list [count] < cur_min) cur_min = list [count];

      return (cur_min);
} //END OF FUNCTION  get_min