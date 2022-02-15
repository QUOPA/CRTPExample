#pragma once

#include "CRCPandVirtual/CRTPVirtualBase.h"

namespace crtpvirtual {
namespace nopoly
{
	template<typename T>
	class DerivedVanila : public BaseTemplate<T>
	{
	public:
		explicit DerivedVanila(const T& inData) :BaseTemplate<T>(inData) {}

		inline T eval() const { return this->m_data; }
	};

	template<typename T>
	class DerivedSquared : public BaseTemplate<T>
	{
	public:
		explicit DerivedSquared(const T& inData) :BaseTemplate<T>(inData) {}

		inline T eval() const { return this->m_data * this->m_data; }
	};

	template<typename T>
	class DerivedDouble : public BaseTemplate<T>
	{
	public:
		explicit DerivedDouble(const T& inData) :BaseTemplate<T>(inData) {}

		inline T eval() const { return 2 * this->m_data; }
	};

	template <typename T>
	inline void showEvaluation(const BaseTemplate<T>& inobj) { std::cout << inobj.eval() << std::endl; }

}

namespace dynamicpoly
{

	template<typename T>
	class DerivedVanila : public BaseTemplate<T>
	{
	public:
		explicit DerivedVanila(const T& inData) :BaseTemplate<T>(inData) {}

		virtual inline T eval() const { return this->m_data; }
	};

	template<typename T>
	class DerivedSquared : public BaseTemplate<T>
	{
	public:
		explicit DerivedSquared(const T& inData) :BaseTemplate<T>(inData) {}

		virtual inline auto eval() const { return this->m_data.eval() * this->m_data.eval(); }
	};

	template<typename T>
	class DerivedDouble : public BaseTemplate<T>
	{
	public:
		explicit DerivedDouble(const T& inData) :BaseTemplate<T>(inData) {}

		virtual inline auto eval() const { return 2 * this->m_data.eval(); }
	};

	template <typename T>
	inline void showEvaluation(const BaseTemplate<T>& inobj) { std::cout << inobj.eval() << std::endl; }

}


namespace CRTPstaticpoly
{
	template<typename T>
	class DerivedVanila : public BaseTemplate<T, DerivedVanila<T>>
	{
	public:
		explicit DerivedVanila(const T& inData) :BaseTemplate<T, DerivedVanila<T>>(inData) {}

		inline T eval() const { return this->m_data; }
	};

	template<typename T>
	class DerivedSquared : public BaseTemplate<T, DerivedSquared<T>>
	{
	public:
		explicit DerivedSquared(const T& inData) :BaseTemplate<T, DerivedSquared<T>>(inData) {}

		inline T eval() const { return this->m_data * this->m_data; }
	};

	template<typename T>
	class DerivedDouble : public BaseTemplate<T, DerivedDouble<T>>
	{
	public:
		explicit DerivedDouble(const T& inData) :BaseTemplate<T, DerivedDouble<T>>(inData) {}

		inline T eval() const { return 2 * this->m_data; }
	};

	template <typename T, typename Derived>
	inline void showEvaluation(const BaseTemplate<T, Derived>& inobj) { std::cout << inobj.eval() << std::endl; }

}}