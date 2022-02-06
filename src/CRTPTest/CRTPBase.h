#pragma once

#include <iostream>

namespace nopoly 
{

template <typename T>
class BaseTemplate
{
public:
	explicit BaseTemplate(const T& inData) :m_data(inData) {}
	void showSomething() const { std::cout << "This Is Base Class" << std::endl; } // nothing to show

protected:
	T m_data;
};

}

// not working
namespace dynamicpoly
{

template <typename T>
class BaseTemplate
{
public:
	explicit BaseTemplate(const T& inData) :m_data(inData) {}
	virtual void showSomething() const { std::cout << "This Is Base Class" << std::endl; } 

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
	void showSomething() const { derived()->showSomething(); }

protected:
	T m_data;

public:
	const Derived* derived() const { return static_cast<const Derived*>(this); }
	Derived* derived() { return static_cast<Derived*>(this); }

};

}
