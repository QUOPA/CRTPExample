

#include "CRTPTest/CRTPDerived.h"


void comparePolymorphism()
{
	//namespace ns = nopoly;
	//namespace ns = dynamicpoly;
	namespace ns = CRTPstaticpoly;

	std::cout << "Inserted Value : 3.1 (double)" << std::endl;
	double dvalue = 3.1;

	ns::DerivedVanila<double> dVanila(dvalue);
	ns::DerivedSquared<double> dSqr(dvalue);
	ns::DerivedDouble<double> dDouble(dvalue);

	ns::showEvaluation(dVanila);
	ns::showEvaluation(dSqr);
	ns::showEvaluation(dDouble);

	std::cout << "Inserted Value : 5 (int)" << std::endl;
	int nvalue = 5;

	ns::DerivedVanila<int> nVanila(nvalue);
	ns::DerivedSquared<int> nSqr(nvalue);
	ns::DerivedDouble<int> nDouble(nvalue);

	ns::showEvaluation(nVanila);
	ns::showEvaluation(nSqr);
	ns::showEvaluation(nDouble);
}

int main()
{
	
	comparePolymorphism();


	char buff[256];
	std::cin.getline(buff, 256);

	return 0;
}


