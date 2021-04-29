//***************************************************************************
// File name:	  Parcel.h
// Author:		  Cayden Wagner
// Date:		    April 28 2021
// Class:		    CS250
// Assignment:  06Polymorphism
// Purpose:		  A user defined parent class that represents a Parcel
//***************************************************************************

#pragma once

#include <iostream>

using namespace std;

class Parcel {
  public:
    Parcel();
 
    virtual void print(std::ostream& rcOutStream) const;
    virtual bool read(istream& rcIn) = 0;

    virtual void setCost() = 0;
    virtual int getDeliveryDay() = 0;

    virtual double addInsurance() = 0;
    virtual double addRush() = 0;

    double getCost() { return mCost; }

  protected:
    int mTrackingNumber, mWeight, mDistance;
    double mCost;
    string mTo, mFrom;
    bool mbIsInsured = false, mbIsRushed = false, mbIsDelivered = false;
};
