//***************************************************************************
// File name:	 
// Author:		 
// Date:		   
// Class:		   
// Assignment: 
// Purpose:		 
//***************************************************************************

#include "Parcel.h"
#include "Postcard.h"

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
Postcard::Postcard() : Parcel() {
	mMessage = "";
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
void Postcard::setCost() {
	mCost = BASE_COST;
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
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
//***************************************************************************
void Postcard::print(ostream& rcOut) const {
	Parcel::print(rcOut);
	rcOut << "\t" << mMessage;
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
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
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
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
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