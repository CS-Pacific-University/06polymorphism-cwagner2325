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

class Postcard : public Parcel{

	public:
		Postcard();
		
		void setCost();

		bool read(istream&);
		void print(ostream&) const;

		double addInsurance();
		double addRush();
		int getDeliveryDay();

	private:
		string mMessage;
		static const int MILES_PER_DAY = 10;
		static constexpr double BASE_COST = .15;
		static constexpr double INSURANCE_COST = .15;
		static constexpr double RUSH_COST = .25;
};