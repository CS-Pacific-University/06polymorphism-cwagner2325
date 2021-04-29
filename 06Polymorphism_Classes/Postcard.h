//***************************************************************************
// File name:	  Postcard.h
// Author:		  Cayden Wagner
// Date:		    April 28 2021
// Class:		    CS250
// Assignment:  06Polymorphism
// Purpose:		  A user defined child class that represents a Postcard and 
//							inherits data from parent class Parcel
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