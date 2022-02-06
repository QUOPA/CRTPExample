

#include "CRTPDerived.h"


void comparePolymorphism()
{
	//namespace ns = nopoly;
	//namespace ns = dynamicpoly;
	namespace ns = CRTPstaticpoly;

	double dvalue = 3.1;

	ns::DerivedVanila<double> dVanila(dvalue);
	ns::DerivedSquared<double> dSqr(dvalue);
	ns::DerivedDouble<double> dDouble(dvalue);

	ns::showAnything(dVanila);
	ns::showAnything(dSqr);
	ns::showAnything(dDouble);


	int nvalue = 5;

	ns::DerivedVanila<int> nVanila(nvalue);
	ns::DerivedSquared<int> nSqr(nvalue);
	ns::DerivedDouble<int> nDouble(nvalue);

	ns::showAnything(nVanila);
	ns::showAnything(nSqr);
	ns::showAnything(nDouble);
}

int main()
{
	
	comparePolymorphism();

	return 0;
}


