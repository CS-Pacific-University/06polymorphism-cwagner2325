//***************************************************************************
// File name:		Overnight.cpp
// Author:			Cayden Wagner
// Date:				April 28 2021
// Class:				CS250
// Assignment:	06Polymorphism
// Purpose:			To define functionality for class Overnight
//***************************************************************************

#include "Parcel.h"
#include "Overnight.h"

#include <iostream>
#include <string>

//***************************************************************************
// Constructor:		Overnight
//
// Description:		Sets member data to default values
//
// Parameters:		None
//***************************************************************************
Overnight::Overnight() : Parcel() {
	mVolume = 0;
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
bool Overnight::read(istream& rcIn) {
	bool bIsRead = Parcel::read(rcIn);

	if (bIsRead) {
		if (!(rcIn >> mVolume)) {
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
void Overnight::print(ostream& rcOut) const {
	Parcel::print(rcOut);
	rcOut << "\t OVERNIGHT!";
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
void Overnight::setCost() {
	if (mVolume > VOLUME_CUTOFF) {
		mCost = BASE_COST_LARGE;
	}
	else {
		mCost = BASE_COST_SMALL;
	}
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
double Overnight::addInsurance() {
	double insuranceCost = 0;
	if (!(mbIsInsured)) {
		insuranceCost = mCost * INSURANCE_COST;
		mbIsInsured = true;
		mCost = mCost + mCost * INSURANCE_COST;
	}
	return insuranceCost;
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
double Overnight::addRush() {
	double rushCost = 0;
	if (!(mbIsRushed)) {
		rushCost = mCost * RUSH_COST;
		mbIsRushed = true;
		mCost = mCost + mCost * RUSH_COST;
	}
	return rushCost;
}
//***************************************************************************
// Function:			getDeliveryDay
//
// Description:		Calculates the delivery date based on how far away the 
//								package is and its rush status
//
// Parameters:		none
//
// Returned:			The number of days until delivery
//***************************************************************************
int Overnight::getDeliveryDay() {
	int deliveryDay;
	if (mDistance <= DELIVERY_CUTOFF) {
		deliveryDay = 1;
	}
	else if (mbIsRushed) {
		deliveryDay = 1;
	}
	else {
		deliveryDay = 2;
	}
	return deliveryDay;
}