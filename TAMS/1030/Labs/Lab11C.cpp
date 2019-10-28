/*  Author:       David Zhao (davidzhao@my.unt.edu)
    Date:         11-21-17
    Instructor:   Helsing
    Description:  Prompts for the number of pumpkin PIs and finds their combined
                  circumference.
*/
#include <iostream>
using namespace std;

int main()
{
  double *pumpkinPI;
  pumpkinPI = new double;

  cout << "Enter the numbers of PI's: ";
  cin >> *pumpkinPI;
  *pumpkinPI = *pumpkinPI * (2*3.14*4);
  cout << "Your 8 inch pumpkin PI's have a combined circumference of " << *pumpkinPI << " inches." << endl;

  delete pumpkinPI;

  return 0;
}
