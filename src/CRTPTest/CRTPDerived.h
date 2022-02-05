#pragma once

#include "CRTPBase.h"

namespace nopoly
{

	template<typename T>
	class DerivedVanila : public BaseTemplate<T>
	{
	public:
		explicit DerivedVanila(const T& inData) :BaseTemplate<T>(inData) {}

		void showSomething() const { std::cout << this->m_data << std::endl; }
	};

	template<typename T>
	class DerivedSquared : public BaseTemplate<T>
	{
	public:
		explicit DerivedSquared(const T& inData) :BaseTemplate<T>(inData) {}

		void showSomething() const { std::cout << this->m_data * this->m_data << std::endl;; }
	};

	template<typename T>
	class DerivedDouble : public BaseTemplate<T>
	{
	public:
		explicit DerivedDouble(const T& inData) :BaseTemplate<T>(inData) {}

		void showSomething() const { std::cout << 2 * this->m_data << std::endl;; }
	};

	template <typename T>
	inline void showAnything(const BaseTemplate<T>& inobj) { inobj.showSomething(); }

}

namespace dynamicpoly
{

	template<typename T>
	class DerivedVanila : public BaseTemplate<T>
	{
	public:
		explicit DerivedVanila(const T& inData) :BaseTemplate<T>(inData) {}

		virtual void showSomething() const { std::cout << this->m_data << std::endl; } 
	};

	template<typename T>
	class DerivedSquared : public BaseTemplate<T>
	{
	public:
		explicit DerivedSquared(const T& inData) :BaseTemplate<T>(inData) {}

		virtual void showSomething() const { std::cout << this->m_data * this->m_data << std::endl;; }
	};

	template<typename T>
	class DerivedDouble : public BaseTemplate<T>
	{
	public:
		explicit DerivedDouble(const T& inData) :BaseTemplate<T>(inData) {}

		virtual void showSomething() const { std::cout << 2 * this->m_data << std::endl;; }
	};

	template <typename T>
	inline void showAnything(const BaseTemplate<T>& inobj) { inobj.showSomething(); }

}


namespace CRTPstaticpoly
{
	template<typename T>
	class DerivedVanila : public BaseTemplate<T, DerivedVanila<T>>
	{
	public:
		explicit DerivedVanila(const T& inData) :BaseTemplate<T, DerivedVanila<T>>(inData) {}

		void showSomething() const { std::cout << this->m_data << std::endl; }
	};

	template<typename T>
	class DerivedSquared : public BaseTemplate<T, DerivedSquared<T>>
	{
	public:
		explicit DerivedSquared(const T& inData) :BaseTemplate<T, DerivedSquared<T>>(inData) {}

		void showSomething() const { std::cout << this->m_data * this->m_data << std::endl;; }
	};

	template<typename T>
	class DerivedDouble : public BaseTemplate<T, DerivedDouble<T>>
	{
	public:
		explicit DerivedDouble(const T& inData) :BaseTemplate<T, DerivedDouble<T>>(inData) {}

		void showSomething() const { std::cout << 2 * this->m_data << std::endl;; }
	};

	template <typename T, typename Derived>
	inline void showAnything(const BaseTemplate<T, Derived>& inobj) { inobj.showSomething(); }
}