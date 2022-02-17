

#include "ExpressionTemplateTest/CRTPVirtualDerived.h"


void expressionTemplateTest()
{
	namespace ns = crtpvirtual::CRTPstaticpoly;

	std::cout << "Inserted Value : 3.1 (double)" << std::endl;
	double dvalue = 3.1;

	ns::DerivedVanila<double> tmpdVanila(dvalue);

	auto dDouble = tmpdVanila.calcDouble();
	auto dSqrDoubleSqr = tmpdVanila.calcSquare().calcDouble().calcSquare();

	ns::showEvaluation(dSqrDoubleSqr);
	ns::showEvaluation(dDouble);

	std::cout << "Inserted Value : 5 (int)" << std::endl;
	int nvalue = 5;

	ns::DerivedVanila<int> nVanila(nvalue);
	auto nSqrDbl = nVanila.calcSquare().calcDouble();
	auto nDblSqr = nVanila.calcDouble().calcSquare();

	ns::showEvaluation(nVanila);
	ns::showEvaluation(nSqrDbl);
	ns::showEvaluation(nDblSqr);
}

int main()
{
	expressionTemplateTest();

	char buff[256];
	std::cin.getline(buff, 256);

	return 0;
}


