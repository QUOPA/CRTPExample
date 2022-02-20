#pragma once

#include <iostream>
#include "ExpressionTemplateTest/CRTPVirtualDerived.h"

namespace crtpvirtual{

namespace CRTPstaticpoly
{
	template <typename T>
	class DerivedVanila;

	template<typename T>
	class DerivedSquared;

	template<typename T>
	class DerivedDouble;

	template <typename Derived>
	class BaseTemplate
	{
	public:

		inline auto eval() const { return derived()->eval(); }

		inline DerivedSquared<Derived> calcSquare() const { return  DerivedSquared<Derived>(*derived()); }
		inline DerivedDouble<Derived> calcDouble() const { return  DerivedDouble<Derived>(*derived()); }
		
	private:
		const Derived* derived() const { return static_cast<const Derived*>(this); }
		Derived* derived() { return static_cast<Derived*>(this); }
	};

}
}