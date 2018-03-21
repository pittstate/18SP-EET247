/***********************************************************************
 * Assignment and Date:  LAB2C; 20MAR18                                              
 *                                                                     
 * Programmer:  Ondrusek; Kirkland 208135
 *                                                                      
 * Title:    Determine Shipping Costs of a Cube Widget with a hole in it with modifications per
 *			 LAB2C condtions.
 *                                                                     
 * Target user:    Students  EET-247 SP2017                                                    
 *                                                                     
 * Specifications:  Per handout Lab2 In-Class Exercise, additional modifications per LAB2C
 *                                                                     
 * Inputs/Outputs:  INPUT: Quantity of parts, Size of Cube, Diameter of Hole 
 *	 				OUTPUT: Quantity of parts, Cost of Shipping, Reduced Shipping Cost
 *                                                                     
 * Variables:   Length of a side of cube, diameter of hole , volume of cube, volume of cylinder
 *				shipping modifier
 *                                                                     
 * Constants:   Density of Aluminium, PI, shipping costs, shipping discount
 *                                                                     
 * Non-standard Libraries or functions:    Math.h, stdlib.h
 *                                                                      
 * Description and Purpose:   The program calculates the shipping costs of a cube widget 
 * after calculating the volume of the cube - the volume of the cylinder created by the hole
 * multiple by the density of aluminium and the shipping costs with editional conditions
 * to evaluate user specified variables before processing and provide the user additional
 * feedback if those conditions are not met.
 * 1Ci dictates exceeding 100 and not meeting or exceeding so true if qty>100
 * 1Cii dictates exceeding 450 lbs and not meeting or exceeding so true if lbs>450
 * 		important since qty>=100 or lbs>=450 true if also equals the value
 *
 *		Limitation in rounding using .2lf with printf. also, can ship thousands
 *			of tiny widgets (0.001) with very tiny holes for less than a dollar.
 *                                                                     
 * Additional Information:   In class exercise with extra things done from LAB2C                                        
 * *********************************************************************/

#include <stdio.h>								/* printf, scanf definitions */
#include <math.h>								/* sqrt, power, acos */
#include <stdlib.h>								/* pause, cls */

#define PI 3.1415926535897932384626433832795	/* Constant: PI  */
#define SHIPCOST 3.50							/* Constant: shipping cost in $ */
#define DENSITYOFALUMINUM 0.098					/* Constant: Density of aluminum in lbs/SqrInches) */
#define MINWIDGETINTEGRITY 0.9					/* B: min widget hole vs widget side size integrity
													  it's global so won't need passed to function  */
#define SHIPPINGDISCOUNT (1-0.15)				/* shipping discount 15% */

void display(void);								/* Declaring void function */
int validateWidgetIntegrity(double,double);		/* B: verify hole is no greater than 90% of the widget */

int main(void)
{	
	/*  declaring variables */

	int quantity;
	double widgetsize, holediameter, volumeofcube, volumeofcylinder,volumeofwidget, shippingcost,shippingModifier; 

	/* Sanitize (some people like it and so will our while) */
	quantity=0; widgetsize=0.0; holediameter=0.0; volumeofcube=0.0; volumeofcylinder=0.0; volumeofwidget=0.0; shippingcost=0.0; shippingModifier=1.0;

	/* Calling Header Display Function  */
	
	display();

	while(quantity < 1){ /* A: while loop for quantity var to keep asking user if the value given is less than 0 */
		/* Getting input data */
		printf("\nEnter number of widget parts needing to be shipped  > ");				
		scanf("%d", &quantity);

		/* notify user is quantity is going to fail while loop */
		if(quantity < 1)
			printf("\nError -- Number of widget parts MUST be greater than 0");
	}
	
	
	printf("\nEnter length of Widget Part Side in inches (ex 1.25)  > ");
	scanf("%lf", &widgetsize);
	
	printf("\nEnter diameter of hole in widget part in inches (ex 1.25)  > ");
	scanf("%lf", &holediameter);
	
	/* B: widget integrity check user feedback */
	if(validateWidgetIntegrity(widgetsize, holediameter)){
		printf("\nWARNING -- Widget Part strength is compromised:\nhole diameter is %.2lf%c of widget part size\n",(holediameter/widgetsize*100.00),'%');
		return(-1);
	}


	/* Calculating volume of cube, volume of cylinder and shipping costs */
	volumeofcube = (pow(widgetsize,3));
	volumeofcylinder = PI * pow(holediameter/2,2) * widgetsize;
	volumeofwidget = volumeofcube - volumeofcylinder;
	shippingcost = quantity * volumeofwidget * DENSITYOFALUMINUM * SHIPCOST;
		
	/* Displaying output */
	/* alter shipping costs using original printf if Ci or Cii are met */
	if(quantity>100)
		shippingModifier=SHIPPINGDISCOUNT;
	else if ((volumeofwidget * DENSITYOFALUMINUM)>450) /* else if to skip if discount already due to qty */
		shippingModifier=SHIPPINGDISCOUNT;

	printf ("\nThe Shipping cost for %d widget parts is:  $%5.2lf\n", quantity, shippingcost*shippingModifier); 

	/* C: display original shipping cost and savings */
	if(shippingModifier==SHIPPINGDISCOUNT)
		printf("With the shipping discount you've saved $%5.2lf\n over the original shipping cost of $%5.2lf\n\n",(shippingcost-(shippingcost*shippingModifier)),shippingcost);
	

    system("pause");

    return(0);
}

int validateWidgetIntegrity(double sideSize, double holeSize){
	double widgetIntegiry = 0.0;

	widgetIntegiry = holeSize / sideSize;

	if(widgetIntegiry <= 0.9)
		return(0); /* no error so return false */
	else
		return(1); /* something unfavorable so true */
}

void display (void)	/* Defining void function DISPLAY  */
{
	system("cls");
	printf ("\n***********************************");
	printf ("\n***********************************");
  	printf ("\n** Shipping Cost of Widget Parts **");
	printf ("\n** EET-247 SP 2017               **");
	printf ("\n** Programmer: Alec Ondrusek     **");
	printf ("\n** Modifications: S Kirkland     **");
	printf ("\n***********************************");
	printf ("\n***********************************");
	printf ("\n\n");
}