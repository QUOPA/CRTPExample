#pragma once

#include <iostream>
namespace crtpvirtual {
namespace nopoly
{
	template <typename T>
	class BaseTemplate
	{
	public:
		BaseTemplate(const T& rhs) : m_data(rhs) {}
		inline T eval() const { return T(); } // nothing to show
	
	protected:
		T m_data;
	};
}


namespace dynamicpoly
{

	template <typename T>
	class BaseTemplate
	{
	public:
		BaseTemplate(const T& rhs) : m_data(rhs) {}
		virtual inline T eval() const { return T(); }

	protected:
		T m_data;
	};

}

namespace CRTPstaticpoly
{

	template <typename T, typename Derived>
	class BaseTemplate
	{
	public:
		BaseTemplate(const T& rhs) : m_data(rhs) {}
		T eval() const { return derived()->eval(); }

	protected:
		T m_data;

	private:
		const Derived* derived() const { return static_cast<const Derived*>(this); }
		Derived* derived() { return static_cast<Derived*>(this); }

	};

}
}