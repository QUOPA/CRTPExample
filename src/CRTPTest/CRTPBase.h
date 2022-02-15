#pragma once

#include <iostream>

namespace nopoly 
{

template <typename T>
class BaseTemplate
{
public:
	explicit BaseTemplate(const T& inData) :m_data(inData) {}
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
	explicit BaseTemplate(const T& inData) :m_data(inData) {}
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
	explicit BaseTemplate(const T& inData) :m_data(inData) {}
	T eval() const { return derived()->eval(); }

protected:
	T m_data;

private:
	const Derived* derived() const { return static_cast<const Derived*>(this); }
	Derived* derived() { return static_cast<Derived*>(this); }

};

}
