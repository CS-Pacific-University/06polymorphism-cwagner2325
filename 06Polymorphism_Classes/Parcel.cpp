//***************************************************************************
// File name:		Parcel.cpp
// Author:			Cayden Wagner
// Date:				April 28 2021
// Class:				CS250
// Assignment:	06Polymorphism
// Purpose:			To define functionality for class Parcel
//***************************************************************************

#include "Parcel.h"

#include <iostream>
#include <string>

//***************************************************************************
// Constructor:		Parcel
//
// Description:		Sets member data to default values
//
// Parameters:		None
//***************************************************************************
Parcel::Parcel() {
	mTrackingNumber = mDistance = mWeight = 0;
	mTo = mFrom = "";
}
//***************************************************************************
// Function:			Print
//
// Description:		Prints member data to a stream in the correct format
//
// Parameters:		rcOut - determines to which stream the data is displayed
//
// Returned:			None
//***************************************************************************
void Parcel::print(ostream& rcOut) const {
	rcOut << "TID: " << mTrackingNumber << "	From: " << mFrom << "	To: "
			  << mTo;
	if (mbIsInsured) {
		cout << "\t INSURED";
	}
	if (mbIsRushed) {
		cout << "\t RUSH";
	}
}
//***************************************************************************
// Function:			Read
//
// Description:		Reads in data from a stream
//
// Parameters:		rcIn - determines from which stream the data is read
//
// Returned:			True if the data is read in, otherwise false
//***************************************************************************
bool Parcel::read(istream& rcIn) {
	bool bIsRead = true;
	if (!(rcIn >> mTrackingNumber >> mTo >> mFrom >> mWeight >> mDistance)) {
		bIsRead = false;
	}
	return bIsRead;
}
