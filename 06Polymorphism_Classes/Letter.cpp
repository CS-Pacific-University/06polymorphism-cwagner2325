//***************************************************************************
// File name:		Letter.cpp
// Author:			Cayden Wagner
// Date:				April 28 2021
// Class:				CS250
// Assignment:	06Polymorphism
// Purpose:			To define functionality for class Letter
//***************************************************************************

#include "Parcel.h"
#include "Letter.h"

#include <iostream>
#include <string>

//***************************************************************************
// Constructor:		Letter
//
// Description:		Sets member data to default values
//
// Parameters:		None
//***************************************************************************
Letter::Letter() : Parcel() {
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
void Letter::setCost() {
	mCost = mWeight * COST_PER_OUNCE;
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
double Letter::addInsurance() {
	double insuranceCost = 0;
	if (!(mbIsInsured)) {
		mbIsInsured = true;
		mCost += INSURANCE_COST;
		insuranceCost = INSURANCE_COST;
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
double Letter::addRush() {
	double rushCost = 0;
	if (!(mbIsRushed)) {
		rushCost = mCost * RUSH_COST;
		mbIsRushed = true;
		mCost *= RUSH_COST;
	}
	return rushCost;
}
//***************************************************************************
// Function:			Read
//
// Description:	  Reads in data members from a stream
//
// Parameters:		rcIn - determines from which stream the data is read
//
// Returned:			True if the data is read in, otherwise false
//***************************************************************************
bool Letter::read(istream& rcIn) {
	bool bIsRead = true;
	if (!(rcIn >> mTrackingNumber >> mTo >> mFrom >> mWeight >> mDistance)) {
		bIsRead = false;
	}
	return bIsRead;
}
//***************************************************************************
// Function:			getDeliveryDay
//
// Description:		Calculates the delivery date based on how far away the 
//								letter is and its rush status
//
// Parameters:		none
//
// Returned:			The number of days until delivery
//***************************************************************************
int Letter::getDeliveryDay() {
	int deliveryDay;
	mbIsDelivered = true;
	if (mDistance % MILES_PER_DAY == 0) {
		deliveryDay = mDistance / MILES_PER_DAY;
	}
	else {
		deliveryDay = mDistance / MILES_PER_DAY + 1;
	}
	if (mbIsRushed) {
		deliveryDay -= 1;
	}
	if (deliveryDay == 0) {
		deliveryDay += 1;
	}
	return deliveryDay;
}