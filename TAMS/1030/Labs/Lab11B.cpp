/*  Author:       David Zhao (davidzhao@my.unt.edu)
    Date:         11-21-17
    Instructor:   Helsing
    Description:  Sets up some variables then uses pointers to print out their values
                  and memory locations
*/
#include <iostream>
using namespace std;

int main()
{
  int num;
  char ch;
  float val;

  int *p1 = NULL;
  char *p2 = NULL;
  float *p3 = NULL;

  p1 = &num;
  p2 = &ch;
  p3 = &val;

  *p1 = 3;
  *p2 = 'A';
  *p3 = 3.14;

  cout << "num is " << &num << endl;
  cout << "ch's address is " << &ch << endl;
  cout << "val's address is " << &val << endl;

  cout << "pointer to num's address is " << p1 << endl;
  cout << "pointer to ch's address is " << p2 << endl;
  cout << "pointer to val's address is " << p3 << endl;

  return 0;
}
