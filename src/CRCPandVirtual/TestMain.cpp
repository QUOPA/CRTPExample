

#include "CRCPandVirtual/CRTPVirtualDerived.h"


void comparePolymorphism()
{
	//namespace ns = crtpvirtual::nopoly;
	namespace ns = crtpvirtual::dynamicpoly;
	//namespace ns = crtpvirtual::CRTPstaticpoly;

	std::cout << "Inserted Value : 3.1 (double)" << std::endl;
	double dvalue = 3.1;

	ns::DerivedSquared<double> tmpdSqr(dvalue);
	ns::DerivedVanila<double> tmpdVanila(dvalue);

	tmpdVanila.setData(tmpdSqr);

	ns::DerivedVanila<double> dVanila(tmpdVanila.eval());
	ns::DerivedSquared<double> dSqr(tmpdVanila.eval());
	ns::DerivedDouble<double> dDouble(tmpdVanila.eval());

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


