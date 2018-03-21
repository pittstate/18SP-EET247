#include <stdio.h>
#include <stdlib.h>

#define _PI 3.1416
#define _SHIPPING_PER_POUND 3.50
#define _CYL_H 0.5
#define _CYL_B(x) ((x)/(2))
#define _CYL_VOL(r) (_PI * (r * r) * _CYL_H)
#define _PYR_VOL(b,h) ((b*b*h)/3.0)
#define _AL 0.098 /* lb/in^3 */
#define _CU 0.324 /* lb/in^3 */


int main(void) {
	double dblPyrBase, dblPyrHeight;
	float fltPyrVol, fltBaseVol, fltPyrMass, fltCylMass;

	printf("\nThe length of the thing? ");
	scanf("%lf",&dblPyrBase);

	printf("The height of the thing? ");
	scanf("%lf",&dblPyrHeight);

	printf("\n\nThe paperwork wants us to print the diameter so it's %.2lf\n", dblPyrBase/2.0);


	printf("Volume of the pointy thing is %.2lf\n", fltPyrVol = _PYR_VOL(dblPyrBase,dblPyrHeight));
	printf("Volume of the pointy thing support is %.2lf\n", fltBaseVol = _CYL_VOL(dblPyrBase/4.0));

	printf("Mass of the pointy thing is %.2f\n",fltPyrMass = fltPyrVol * _AL);
	printf("Mass of the base is %.2f\n", fltCylMass = fltBaseVol * _CU);

	printf("Est cost to ship might be $%.2f\n",(fltCylMass + fltPyrMass) * _SHIPPING_PER_POUND);

	return (0);
}