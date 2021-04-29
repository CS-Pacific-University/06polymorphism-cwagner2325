//***************************************************************************
// File name:	 
// Author:		 
// Date:		   
// Class:		   
// Assignment: 
// Purpose:		 
//***************************************************************************

#include "Parcel.h"

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
Parcel::Parcel() {
	mTrackingNumber = mDistance = mWeight = 0;
	mTo = mFrom = "";
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
// Function:	
//
// Description:
//
// Parameters:	
//
// Returned:		
//***************************************************************************
bool Parcel::read(istream& rcIn) {
	bool bIsRead = true;
	if (!(rcIn >> mTrackingNumber >> mTo >> mFrom >> mWeight >> mDistance)) {
		bIsRead = false;
	}
	return bIsRead;
}
