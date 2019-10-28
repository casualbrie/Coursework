/*
===============================================================================
Name        : homework3.cpp
Author      : David Zhao
Date        : 10-15-17
Description : Program prompts for an even integer between 2 and 12,
              finds the factorial of that number, then prints a right-aligned
              triangle with a height of the number and stuff
===============================================================================
*/
#include <stdio.h>
#include <iostream>
using namespace std;


//function for detecting if the prompted number is even
bool detectEven (int num);
//function for calculating the factorial of the prompted number
int calc (int num);
//function for drawing the triangle
void triangle (int num);


int main()
{
  cout << "Department:     Computer Science\n"
       << "Course Number:  CSCE 1030\n"
       << "Name:           David Zhao\n"
       << "EUID:           dz0086\n"
       << "Email:          davidzhao@unt.edu\n";
  int prompted;
  //loop for getting a number from user
  do {
    printf("Please enter an even integer between 2 and 12: ");
    scanf("%d",&prompted);

  } while(detectEven(prompted) == false);
  //doing function calls
  int result = calc (prompted);
  printf("The product of integers from 1 to %d is %d", prompted, result);
  triangle(prompted);
  cout << endl;
}
/*
===============================================================================
Function    : detectEven
Parameters  : an even integer for the input
Returns     : boolean saying whether the number is within the range and even
Description : Function prompts for an even integer between 2 and 12
===============================================================================
*/
bool detectEven (int num)
{
  //boolean check
  if (((num >= 2) && (num <=12)) && ((num % 2) == 0))
  {
    return true;
  }
  else
  {
    return false;
  }
}
/*
===============================================================================
Function    : triangle
Parameters  : an even integer for the input
Returns     : void
Description : Function draws a triangle with height based on input, composed of
              the input and previous numbers
===============================================================================
*/
void triangle (int num)
{
  //bunch of nested for loops for drawing
  for (int i = 1; i <= num; i++)
  {
    //goes to next line before every iteration
    cout << endl;
    //spacing for right justified
    for (int k = 0; k <= (num - i); k++)
    {
      cout << "  ";
    }
    //actual content
    for (int j = 1; j <= i; j++)
    {
      if (i < 10)
      {
        cout << " ";
        cout << i;
      }
      else
      {
        cout << i;
      }
    }
  }
}
/*
===============================================================================
Function    : calc
Parameters  : an even integer for the input
Returns     : factorial of the input
Description : Function calculates the factorial of the input number
===============================================================================
*/
int calc (int num)
{
  int factorial = 1;
  //calculation loop
  for (int i = 1;i <= num; i++)
  {
    factorial = i * factorial;
  }
  return factorial;
}
