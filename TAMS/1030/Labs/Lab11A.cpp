/*  Author:       David Zhao (davidzhao@my.unt.edu)
    Date:         11-21-17
    Instructor:   Helsing
    Description:  Takes an input file with a bunch of integers and displays the integer,
                  the square root of the integer, and the sum up to that point. Finally,
                  it displays the average of these square roots
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int main()
{
  int x, count = 0;
  float sum = 0, avg;
  string input_file;
  char tempInput[15];

  ifstream in_s;

  cout << "Please enter the input file name: ";
  cin >> input_file;

  strcpy(tempInput, input_file.c_str());
  in_s.open(tempInput);
  if(in_s.fail())
  {
    cout << "ERROR : Unable to open input file.\n";
    exit(EXIT_FAILURE);
  }

  cout << "\t  x \t\t x^ (1/2) \t Current Sum\n";
  cout << "\t === \t\t ======== \t ==========\n";

  while(in_s >> x)
  {
    sum = sum +sqrt(x);
    cout << "\t  " << x << "\t\t  " << sqrt(x) << "\t\t  " << sum << "\n";
    count++;
  }

  avg = sum/count;
  cout << "\n \t The average of these " << count << " square roots is: " << avg << endl;

  in_s.close();

  return 0;
}
