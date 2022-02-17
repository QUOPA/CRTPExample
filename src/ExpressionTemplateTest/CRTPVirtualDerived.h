#pragma once

#include <iostream>
#include "ExpressionTemplateTest/CRTPVirtualBase.h"

namespace crtpvirtual {

namespace CRTPstaticpoly
{
	template<typename Derived>
	class BaseTemplate;

	template<typename T>
	class DerivedVanila : public BaseTemplate<DerivedVanila<T>>
	{
	public:
		explicit DerivedVanila(const T& inData) : 
			BaseTemplate<DerivedVanila<T>>(), m_data(inData) {}

		template<typename OtherDerived>
		DerivedVanila(const OtherDerived& rhs) 
			: BaseTemplate<DerivedVanila<T>>() { this->operator=(rhs); std::cout << "dataCopy, "; }

		template<typename OtherDerived>
		void operator= (const OtherDerived& rhs) 
		{
			m_data = rhs.eval();
		}


		inline T eval() const { return this->m_data; }

		T m_data;
	};

	template<typename T>
	class DerivedSquared : public BaseTemplate<DerivedSquared<T>>
	{
	public: 
		inline auto eval() const { return this->m_InData.eval() * this->m_InData.eval(); }

	private:
		DerivedSquared(const T& rhs) : m_InData(rhs) {}
		T m_InData;

		template<typename Derieved>
		friend class BaseTemplate;
	};

	template<typename T>
	class DerivedDouble : public BaseTemplate<DerivedDouble<T>>
	{
	public:
		inline auto eval() const { return 2 * this->m_InData.eval(); }

	private:
		DerivedDouble(const T& rhs) : m_InData(rhs) { }
		T m_InData;

		template<typename Derieved>
		friend class BaseTemplate;
	};

	template <typename Derived>
	inline void showEvaluation(const BaseTemplate<Derived>& inobj) { std::cout << inobj.eval() << std::endl; }

}}