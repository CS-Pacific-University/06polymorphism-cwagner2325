//***************************************************************************
// File name:	  Source.cpp
// Author:		  Cayden Wagner
// Date:		    April 28 2021
// Class:		    CS250
// Assignment:  06Polymorphism
// Purpose:		  To create a mail delivery system that handles several types 
//              of mail
// Hours:       6
// Computer OS: MacOS
//***************************************************************************
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Parcel.h"
#include "Letter.h"
#include "Postcard.h"
#include "Overnight.h"

using namespace std;

void printMenu();
bool openFileForRead(ifstream& inputFile, string fileName);
void closeFileForRead(ifstream& inputFile);
//***************************************************************************
// Function:    main
//
// Description:	Provide functionality for the Parcel class and its sub
//              classes Letter, Postcard, and Overnight
//
// Parameters:	none
//
// Returned:		exit status
//***************************************************************************
int main() {
  const int MAX_FILE_SIZE = 25;
  const string PRINT_ALL = "1", ADD_INSURANCE = "2", ADD_RUSH = "3";
  const string DELIVER = "4", QUIT = "5";
  const char LETTER = 'L', POSTCARD = 'P', OVERNIGHT = 'O';
  const string INPUT_FILE = "parcels.txt";

  Parcel* apcParcels[MAX_FILE_SIZE] = { nullptr };
  char parcelIndex;
  int numParcels = 0, userParcelChoice;
  string userChoice;
  ifstream inputFile;

  bool readInCorrectly = true;

  cout << "Mail Simulator!" << endl << endl;

  if (!(openFileForRead(inputFile, INPUT_FILE))) {
    cout << "The File Failed to Open" << endl;
    return EXIT_FAILURE;
  }
  
  while (!inputFile.eof() && readInCorrectly) {
    inputFile >> parcelIndex;
    if (parcelIndex == LETTER) {
      apcParcels[numParcels] = new Letter;
      readInCorrectly = apcParcels[numParcels]->read(inputFile);
      numParcels++;
    }
    if (parcelIndex == POSTCARD) {
      apcParcels[numParcels] = new Postcard;
      readInCorrectly = apcParcels[numParcels]->read(inputFile);
      numParcels++;
    }
    if (parcelIndex == OVERNIGHT) {
      apcParcels[numParcels] = new Overnight;
      readInCorrectly = apcParcels[numParcels]->read(inputFile);
      numParcels++;
    }
  }

  if (!readInCorrectly) {
    cout << "The File is Invalid";
  }
  else {
    for (int i = 0; i < numParcels; i++) {
      apcParcels[i]->setCost();
    }

    do {
      printMenu();
      cout << endl << "Choice> ";
      cin >> userChoice;
      cout << endl;

      if (PRINT_ALL == userChoice) {
        for (int i = 0; i < numParcels; i++) {
          if (apcParcels[i] != nullptr) {
            apcParcels[i]->print(cout);
            cout << endl;
          }
        }
        cout << endl;
      }
      else if (ADD_INSURANCE == userChoice) {
        cout << "TID> ";
        cin >> userParcelChoice;
        if (userParcelChoice >= 0 && userParcelChoice <= numParcels) {
          cout << "Added Insurance for $"
            << fixed << setprecision(2)
            << apcParcels[userParcelChoice - 1]->addInsurance() << endl;
          apcParcels[userParcelChoice - 1]->print(cout);
          cout << endl << endl;
        }
      }
      else if (ADD_RUSH == userChoice) {
        cout << "TID> ";
        cin >> userParcelChoice;
        if (userParcelChoice >= 0 && userParcelChoice <= numParcels) {
          cout << "Added Rush for $"
            << fixed << setprecision(2)
            << apcParcels[userParcelChoice - 1]->addRush() << endl;
          apcParcels[userParcelChoice - 1]->print(cout);
          cout << endl << endl;
        }
      }
      else if (DELIVER == userChoice) {
        cout << "TID> ";
        if (userParcelChoice >= 0 && userParcelChoice <= numParcels) {
          cin >> userParcelChoice;
          cout << endl << "Delivered!" << endl
            << apcParcels[userParcelChoice - 1]->getDeliveryDay() << " Day, $"
            << apcParcels[userParcelChoice - 1]->getCost() << endl;
          apcParcels[userParcelChoice - 1]->print(cout);
          cout << endl << endl;
          delete apcParcels[userParcelChoice - 1];
          apcParcels[userParcelChoice - 1] = { nullptr };
        }
      }
    } while (userChoice != QUIT);
  }
  
  closeFileForRead(inputFile);
  delete *apcParcels;

  return EXIT_SUCCESS;
}
//***************************************************************************
// Function:     openFileForRead
//
// Description:  Allows the user to enter a text file to open for inputting
//
// Parameters:	 inputFile - Allows the input file to open
//							 message - A prompt displayed on screen to direct the user
//	
// Returned:		 None
//***************************************************************************
bool openFileForRead(ifstream& inputFile, string fileName) {
	inputFile.open(fileName);

	return (inputFile.is_open());
}
//***************************************************************************
// Function:     closeFileForRead
//
// Description:  Closes the input file
//
// Parameters:	 inputFile - Allows the input file to close
//	
// Returned:		 None
//***************************************************************************
void closeFileForRead(ifstream& inputFile) {
	inputFile.close();
}
//***************************************************************************
// Function:     printMenu
//
// Description:  Prints the user menu in the correct format
//
// Parameters:	 None
//	
// Returned:		 None
//***************************************************************************
void printMenu() {
  cout << "1. Print All" << endl << "2. Add Insurance" << endl
       << "3. Add Rush" << endl << "4. Deliver" << endl << "5. Quit" << endl;
}