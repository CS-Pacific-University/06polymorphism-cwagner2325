//***************************************************************************
// File name:	 
// Author:		 
// Date:		   
// Class:		   
// Assignment:  
// Purpose:		 
//***************************************************************************

#pragma once

#include <iostream>
#include "Parcel.h"

using namespace std;

class Letter : public Parcel {

public:
	Letter();

	void setCost(); 

	bool read(istream&);

	double addInsurance();
	double addRush();
	int getDeliveryDay();

private:
	string mMessage;
	static const int MILES_PER_DAY = 100;
	static constexpr double COST_PER_OUNCE = .45;
	static constexpr double INSURANCE_COST = .45;
	static constexpr double RUSH_COST = .10;
};