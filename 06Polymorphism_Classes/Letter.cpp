//***************************************************************************
// File name:	 
// Author:		 
// Date:		   
// Class:		   
// Assignment: 
// Purpose:		 
//***************************************************************************

#include "Parcel.h"
#include "Letter.h"

#include <iostream>
#include <string>

//***************************************************************************
// Constructor:	
//
// Description:
//
// Parameters:	
//
// Returned:		
//***************************************************************************
Letter::Letter() : Parcel() {
}
//***************************************************************************
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
//***************************************************************************
void Letter::setCost() {
	mCost = mWeight * COST_PER_OUNCE;
}
//***************************************************************************
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
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
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
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
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
//***************************************************************************
bool Letter::read(istream& rcIn) {
	bool bIsRead = true;
	if (!(rcIn >> mTrackingNumber >> mTo >> mFrom >> mWeight >> mDistance)) {
		bIsRead = false;
	}
	return bIsRead;
}
//***************************************************************************
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
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