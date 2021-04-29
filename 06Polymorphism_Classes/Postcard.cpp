//***************************************************************************
// File name:		Postcard.cpp
// Author:			Cayden Wagner
// Date:				April 28 2021
// Class:				CS250
// Assignment:	06Polymorphism
// Purpose:			To define functionality for class Postcard
//***************************************************************************

#include "Parcel.h"
#include "Postcard.h"

#include <iostream>
#include <string>

//***************************************************************************
// Constructor:		Postcard
//
// Description:		Sets member data to default values
//
// Parameters:		None
//***************************************************************************
Postcard::Postcard() : Parcel() {
	mMessage = "";
}
//***************************************************************************
// Function:			setCost
//
// Description:		sets the cost variable to the base cost
//
// Parameters:		none
//
// Returned:			none
//***************************************************************************
void Postcard::setCost() {
	mCost = BASE_COST;
}
//***************************************************************************
// Function:			Read
//
// Description:		Calls read from the parent class Parcel, then reads in 
//								unique data members from a stream
//
// Parameters:		rcIn - determines from which stream the data is read
//
// Returned:			True if the data is read in, otherwise false
//***************************************************************************
bool Postcard::read(istream& rcIn) {
	bool bIsRead = Parcel::read(rcIn);

	if (bIsRead) {
		if (!(rcIn >> mMessage)) {
			bIsRead = false;
		}
	}
	return bIsRead;
}
//***************************************************************************
// Function:			Print
//
// Description:		Calls print from the parent class Parcel, then prints 
//								unique member data to a stream in the correct format
//
// Parameters:		rcOut - determines to which stream the data is displayed
//
// Returned:			None
//***************************************************************************
void Postcard::print(ostream& rcOut) const {
	Parcel::print(rcOut);
	rcOut << "\t" << mMessage;
}
//***************************************************************************
// Function:			addInsurance
//
// Description:		Turns the object's insurance status to true, calculates the
//								cost of insurance, and adds it to the total cost
//
// Parameters:		None
//
// Returned:			The cost of adding insurance
//***************************************************************************
double Postcard::addInsurance() {
	double insuranceCost = 0;
	if (!(mbIsInsured)) {
		insuranceCost = INSURANCE_COST;
		mbIsInsured = true;
		mCost += INSURANCE_COST;
	}
	return INSURANCE_COST;
}
//***************************************************************************
// Function:			addRush
//
// Description:		Turns the object's rush status to true, calculates the
//								cost of rush, and adds it to the total cost
//
// Parameters:		None
//
// Returned:			The cost of adding rush
//***************************************************************************
double Postcard::addRush() {
	double rushCost = 0;
	if (!(mbIsRushed)) {
		rushCost = RUSH_COST;
		mbIsRushed = true;
		mCost += RUSH_COST;
	}
	return rushCost;
}
//***************************************************************************
// Function:			getDeliveryDay
//
// Description:		Calculates the delivery date based on how far away the 
//								postcard is and its rush status
//
// Parameters:		none
//
// Returned:			The number of days until delivery
//***************************************************************************
int Postcard::getDeliveryDay() {
	int deliveryDay;
	mbIsDelivered = true;
	if (mDistance % MILES_PER_DAY == 0) {
		deliveryDay = mDistance / MILES_PER_DAY;
	}
	else {
		deliveryDay = mDistance / MILES_PER_DAY + 1;
	}
	if (mbIsRushed) {
		deliveryDay -= 2;
	}
	if (deliveryDay <= 0) {
		deliveryDay += 1;
	}
	return deliveryDay;
}