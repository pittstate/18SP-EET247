/***********************************************************************
 * Assignment and Date:    Demonstration of ENUMERATED Arrays       Apr 2017                                     
 *                                                                     
 * Programmer:    Ondrusek                                                     
 *                                                                      
 * Title:  EnumeratedArray                                                            
 *                                                                     
 * Target user:   EET-247 Students                                                     
 *                                                                     
 * Specifications:                                                     
 *                                                                     
 * Inputs/Outputs:  Keyboard, display screen                                                   
 *                                                                     
 * Variables:  Enumerated Types - expense_kind, dow                                                        
 *                                                                     
 * Constants:  None                                                        
 *                                                                     
 * Non-standard Libraries or functions:                                
 *                                                                      
 * Description and Purpose: Demonstrates how enumerated data types can be used                                             
 *                                                                     
 * Additional Information:   Based on Fig 7.18 in textbook                                          
 * *********************************************************************/

#include <stdio.h>
#include<stdlib.h>

//--------Declaring Enumerated types ------------------
typedef enum {entertainment, rent, utilities, food, clothing, automobile, insurance, miscellaneous} expense_t;
typedef enum {Sunday, Monday, Tuesday, Wensday, Thursday, Friday, Saturday} days_of_week;

//---------Declaring Functions
void print_expense(expense_t expense_kind);
void print_days_of_week (days_of_week dow);

int main(void)  //****starting main function ******
{//--------- Declaring Variables ----------
     expense_t expense_kind;
	 days_of_week dow;

//********* Begining Inputs *******************************
     printf("Enter an expense code between 0 and 7>>  ");
     scanf("%d", &expense_kind);
	 printf("Expense code %d represents ",expense_kind);
	 print_expense(expense_kind);
     printf(".\n\n");

	 printf("Enter a day of the week code between 1-(Monday) and 5-(Friday)>>  ");
     scanf("%d", &dow);
     printf("Day Of Week code %d represents ",dow);
     print_days_of_week(dow);
     printf(".\n\n");
	 system("pause");
     return (0);
} //END OF main

//--------------------------- Defining Functions --------------------------------
 
void print_expense(expense_t expense_kind) //** Display string corresponding to a value of type expense_t **
{
      switch (expense_kind) {
      case entertainment:
            printf("entertainment");
            break;
      case rent:
            printf("rent");
            break;
      case utilities:
            printf("utilities");
            break;
      case food:
            printf("food");
            break;
      case clothing:
            printf("clothing");
            break;
      case automobile:
            printf("automobile");
            break;
      case insurance:
            printf("insurance");
            break;
      case miscellaneous:
            printf("miscellaneous");
            break;
      default:
            printf("\n*** INVALID CODE ***\n");
      }//END Switch Statement
}//END function: print_expense

void print_days_of_week(days_of_week dow) //** Display string corresponding to a value of type days_of_week **
{
      switch (dow) {
	  case Sunday:
            printf("Sunday");
            break;
      case Monday:
            printf("Monday");
            break;
      case Tuesday:
            printf("Tuesday");
            break;
      case Wensday:
            printf("Wensday");
            break;
      case Thursday:
            printf("Thursday");
            break;
      case Friday:
            printf("Friday");
            break;
	  case Saturday:
		  printf("Saturday");
		  break;
      default:
            printf("\n*** INVALID CODE ***\n");
      }//END switch statement
}//END function: print_days_of_week