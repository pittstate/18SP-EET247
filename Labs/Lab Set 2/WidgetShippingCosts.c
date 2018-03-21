/***********************************************************************
 * Assignment and Date:  Inclass Exercise - Shipping Costs                                              
 *                                                                     
 * Programmer:  Ondrusek                                                       
 *                                                                      
 * Title:    Determine Shipping Costs of a Cube Widget with a hole in it                                                        
 *                                                                     
 * Target user:    Students  EET-247 SP2017                                                    
 *                                                                     
 * Specifications:  Per handout Lab2 In-Class Exercise                                                   
 *                                                                     
 * Inputs/Outputs:  INPUT: Quantity of parts, Size of Cube, Diameter of Hole 
					OUTPUT: Quantity of parts, Cost of Shipping 
 *                                                                     
 * Variables:   Length of a side of cube, diameter of hole , volume of cube, volume of cylinder                                                      
 *                                                                     
 * Constants:   Density of Aluminium, PI, shipping costs                                                     
 *                                                                     
 * Non-standard Libraries or functions:    Math.h                            
 *                                                                      
 * Description and Purpose:   The program calculates the shipping costs of a cube widget 
   after calculating the volume of the cube - the volume of the cylinder created by the hole
   multiple by the density of aluminium and the shipping costs	                                         
 *                                                                     
 * Additional Information:   In class exercise                                         
 * *********************************************************************/

#include <stdio.h>								/* printf, scanf definitions */
#include <math.h>								/* sqrt, power, acos */
#define PI 3.1415926535897932384626433832795				/* Constant: PI  */
#define SHIPCOST 3.50							/* Constant: shipping cost in $ */
#define DENSITYOFALUMINUM 0.098					/* Constant: Density of aluminum in lbs/SqrInches) */

void display(void);							/* Declaring void function */

int
main(void)
{	
	/*  declaring variables */

	int quantity;
	double widgetsize, holediameter, volumeofcube, volumeofcylinder,volumeofwidget, shippingcost;

	/* Calling Header Display Function  */
	
	display();

	/* Getting input data */
	printf("Enter number of widget parts needing to be shipped  > ");				
	scanf("%d", &quantity);
	
	
	printf("\nEnter length of Widget Part Side in inches (ex 1.25)  > ");
	scanf("%lf", &widgetsize);
	
	printf("\nEnter diameter of hole in widget part in inches (ex 1.25)  > ");
	scanf("%lf", &holediameter);
	
	/* Calculating volume of cube, volume of cylinder and shipping costs */
	volumeofcube = (pow(widgetsize,3));
	volumeofcylinder = PI * pow(holediameter/2,2) * widgetsize;
	volumeofwidget = volumeofcube - volumeofcylinder;
	shippingcost = quantity * volumeofwidget * DENSITYOFALUMINUM * SHIPCOST;
		
	 /* Displaying output */
	printf ("\nThe Shipping cost for %d widget parts is:  $%5.2lf", quantity, shippingcost); 
	

     getchar();
     getchar();
     return(0);
}

void
display (void)	/* Defining void function DISPLAY  */
{
	printf ("\n***********************************");
	printf ("\n***********************************");
  	printf ("\n** Shipping Cost of Widget Parts **");
	printf ("\n** EET-247 SP 2017               **");
	printf ("\n** Programmer: Alec Ondrusek     **");
	printf ("\n***********************************");
	printf ("\n***********************************");
	printf ("\n\n");
}