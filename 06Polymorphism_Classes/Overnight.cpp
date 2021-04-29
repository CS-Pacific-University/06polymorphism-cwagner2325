//***************************************************************************
// File name:	 
// Author:		 
// Date:		   
// Class:		   
// Assignment: 
// Purpose:		 
//***************************************************************************

#include "Parcel.h"
#include "Overnight.h"

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
Overnight::Overnight() : Parcel() {
	mVolume = 0;
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
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
//***************************************************************************
void Overnight::print(ostream& rcOut) const {
	Parcel::print(rcOut);
	rcOut << "\t OVERNIGHT!";
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
void Overnight::setCost() {
	if (mVolume > VOLUME_CUTOFF) {
		mCost = BASE_COST_LARGE;
	}
	else {
		mCost = BASE_COST_SMALL;
	}
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
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
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
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
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