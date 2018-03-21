/* Assignment and Date: Lab 2A, due 06MAR18 
 *
 * Programmer: Steven Kirkland, 0208135
 *
 * Title: LAB2A
 *
 * Target user: AC Phasor group chat
 * 
 * Specifications: it makes you know imaginary numbers but also real numbers
 *
 * Inputs/Outputs: 2 doubles from user
 *
 * Variables: 2 doubles dblMag, dblTheta;
 *
 * Constants: M_PI because it's not getting pulled from math.h correctly
 *
 * Non-standard Libraries or functions: stdlib for the system, stdio for interfacing 
 										user, math for trig
 *
 * Description and Purpose: get some whole numbers from the user and do some trig,
 *							learn to use math.h
 *
 * Additional Comments: No error checking, M_PI not pulled from math.h but best val for
 *						double precession
 ***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI		3.14159265358979323846

void DoTheMaths(void);

int main(void) {
	/* copy/paste from earlier for basics, get values from the user */
	/* after cls I guess */
	system("cls");
		DoTheMaths();

    return 0; /* profit */
}

void DoTheMaths(void) {
	double dblMag, dblTheta;

	printf("Enter a magnitude integer\n");scanf("%lf",&dblMag);
	printf("Enter the angle in degrees\n");scanf("%lf",&dblTheta);

	/* math.h magic */
	printf("The real part is:		%-6.6lf\n", (dblMag * (cos(M_PI / 180 * dblTheta)))); /* feed cos degrees in radians */
	printf("The imaginary part is:		%-6.6lf\n", (dblMag * (sin(M_PI / 180 * dblTheta)))); /* feed sin degree in radians */

}