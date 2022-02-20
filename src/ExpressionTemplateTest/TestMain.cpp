

#include "ExpressionTemplateTest/CRTPVirtualDerived.h"


void expressionTemplateTest()
{
	namespace ns = crtpvirtual::CRTPstaticpoly;

	std::cout << "Inserted Value : 3.1 (double)" << std::endl;
	double dvalue = 3.1;

	ns::DerivedVanila<double> tmpdVanila(dvalue);

	auto dDouble = tmpdVanila.calcDouble();
	ns::showEvaluation(dDouble);

	auto dSqrDoubleSqr = tmpdVanila.calcSquare().calcDouble().calcSquare();
	ns::showEvaluation(dSqrDoubleSqr);
	
	std::cout << "Inserted Value : 5 (int)" << std::endl;
	int nvalue = 5;
	
	ns::DerivedVanila<int> nVanila(nvalue);
	ns::showEvaluation(nVanila);
	
	auto nSqrDbl = nVanila.calcSquare().calcDouble();
	ns::showEvaluation(nSqrDbl);
	
	auto nDblSqr = nVanila.calcDouble().calcSquare();
	ns::showEvaluation(nDblSqr);
	
	
	
}

int main()
{
	expressionTemplateTest();

	char buff[256];
	std::cin.getline(buff, 256);

	return 0;
}


