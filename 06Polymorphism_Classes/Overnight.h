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

class Overnight : public Parcel {

public:
	Overnight();

	void setCost();

	bool read(istream&);
	void print(ostream&) const;

	double addInsurance();
	double addRush();
	int getDeliveryDay();

private:
	int mVolume;
	static const int DELIVERY_CUTOFF = 1000;
	static const int VOLUME_CUTOFF = 100;
	static constexpr double BASE_COST_LARGE = 20.0;
	static constexpr double BASE_COST_SMALL = 12.0;
	static constexpr double INSURANCE_COST = .25;
	static constexpr double RUSH_COST = .75;
};