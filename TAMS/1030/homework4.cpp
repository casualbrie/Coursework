/*
===============================================================================
Name        : homework4.cpp
Author      : David Zhao
Date        : 10-31-17
Description : Program takes in a set of items, encrypts and outputs a file. It can
              then decrypt the files.
===============================================================================
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <cctype>
using namespace std;

void initial ();
void encrypt(ifstream& input, ofstream& output);
void decrypt(ifstream& input, ofstream& output);

int main()
{
  //initial little display
  initial();
  //variable declarations
  char choice, title[33], inputFile[33], outputFile[33];
  ifstream input;
  ofstream output;
  //prompt for action from user
  do {
    cout << "To decrypt a file, type d. To encrypt, type e: ";
    cin >> choice;
  } while((choice != 'd') && (choice != 'e'));

    cout << "Please enter the name of the input file: ";
    cin >> inputFile;
    cout << "Please enter the name of the output file: ";
    cin >> outputFile;

    //io fail checks
    input.open(inputFile);
    if (input.fail())
    {
      cout << "Unable to open input file.\n";
      exit(EXIT_FAILURE);
    }
    output.open(outputFile);
    if (output.fail())
    {
      cout << "Unable to open output file.\n";
      exit(EXIT_FAILURE);
    }

    //determining which function to use based on user interaction
    if (choice == 'e')
    {
      encrypt(input, output);
    }
    if (choice == 'd')
    {
      decrypt(input, output);
    }

    //closing out streams
    input.close();
    output.close();
}
/*
===============================================================================
Function    : initial
Parameters  : none
Returns     : void
Description : Function outputs the initial display
===============================================================================
*/
void initial()
{
  cout << "Department:     Computer Science\n"
       << "Course Number:  CSCE 1030\n"
       << "Name:           David Zhao\n"
       << "EUID:           dz0086\n"
       << "Email:          davidzhao@unt.edu\n";

       return;
}
/*
===============================================================================
Function    : encrypt
Parameters  : an output and an input stream
Returns     : void
Description : Function encrypts a given input file and outputs it
===============================================================================
*/
void encrypt(ifstream& input, ofstream& output)
{
  //variable declarations
  char key[33], character;
  ofstream keyFile;
  int randomNum, keyTemp;
  string result;

  //prompting for key file name
  cout << "Please enter the name of the file that will contain the encryption key: ";
  cin >> key;

  //failure check
  keyFile.open(key);
  if (keyFile.fail())
  {
    cout << "Unable to open the file.";
    exit(EXIT_FAILURE);
  }

  //seeding the rand()
  srand(time(NULL));
  //actual encryption loop
  do {
    //grabs the first character
    input.get(character);
    //to stop encryption of eof
    if (input.eof())
    {
      break;
    }
    //just to make sure whitespace is never encrypted
    if(isspace(character) == false)
    {
      //random number generation
      randomNum = rand() % 275 + 3;
      keyTemp = randomNum;
      //various equations
      if (isalpha(character) && isupper(character))
      {
        result += ((((character-65) + randomNum) % 26) + 65);
      }
      else if(isalpha(character) && islower(character))
      {
        result += ((((character-97) + randomNum) % 26) + 97);
      }
      else if(isdigit(character))
      {
        result += ((((character-48) + randomNum) % 10) + 48);
      }
      else if(ispunct(character))
      {
        result += character;
      }
      else
      {
        cout << "Error. Found unknown character " << "\"" << character << "\"."
             << "\nContinuing on and ignoring unknown.";
      }
      //creating the key file
      keyFile << keyTemp << " ";
  }


  } while(!input.eof());

  //send resulting encrypted file to output stream
  output << result;
  //closing file
  keyFile.close();

  return;
}

/*
===============================================================================
Function    : decrypt
Parameters  : an output and an input stream
Returns     : void
Description : Function decrypts a given encrypted file and outputs it as plaintext
===============================================================================
*/
void decrypt(ifstream& input, ofstream& output)
{
  //variable declarations
  char keyName[33], character;
  int key, tempKey;
  ifstream keyFile;
  string result;
  //prompt for key file name
  cout << "Please enter the name of the file with the keys: ";
  cin >> keyName;
  //checking for opening failure
  keyFile.open(keyName);
  if (keyFile.fail())
  {
    cout << "Unable to open the file.";
    exit(EXIT_FAILURE);
  }
  //actual decryption
  do {
    keyFile >> key;
    int cipher;
    //grabbing the encrypted character
    input.get(character);
    if (input.eof())
    {
      break;
    }
    //bunch of equations
    if (isalpha(character) && isupper(character))
    {
      cipher = character - 65 - key;
      /*using these little do while loops to loop around the alphabet
      using do while loops instead of while loops to make sure its always run at least once.
      May not be necessary but the modulo takes care of any issues regardless*/
      do {
        cipher += 26;
      } while(cipher < 0);

      result += ((cipher % 26) + 65);
    }
    else if(isalpha(character) && islower(character))
    {
      cipher = character - 97 - key;
      do {
        cipher += 26;
      } while(cipher < 0);

      result += ((cipher % 26) + 97);
    }
    else if(isdigit(character))
    {
      cipher = character - 48 - key;
      do {
        cipher += 10;
      } while(cipher < 0);
      result += ((cipher % 10) + 48);
    }
    else if(ispunct(character))
    {
      result += character;
    }
    else
    {
      cout << "Error. Found unknown character " << "\"" << character << "\"."
           << "\nContinuing on and ignoring unknown.";
    }
  } while(!input.eof());

  output << result;
  //closing out file
  keyFile.close();

  return;
}
