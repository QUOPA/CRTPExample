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
			BaseTemplate<DerivedVanila<T>>(), m_data(inData) { std::cout << "DerivedVanila Constructed" << std::endl; }

		template<typename OtherDerived>
		DerivedVanila(const OtherDerived& rhs) 
			: BaseTemplate<DerivedVanila<T>>() { this->operator=(rhs);}

		template<typename OtherDerived>
		void operator= (const OtherDerived& rhs) { 
			m_data = rhs.eval(); 
			std::cout << "DataCopied" << std::endl;
		}

		inline T eval() const { 
			std::cout << "DerivedVanila eval" << std::endl;
			return this->m_data; 
		}
		T m_data;
	};

	template<typename Expr>
	class DerivedSquared : public BaseTemplate<DerivedSquared<Expr>>
	{
	public: 
		inline auto eval() const { 
			std::cout << "DerivedSquared eval" << std::endl;
			return this->m_InExpr.eval() * this->m_InExpr.eval();  
		}

	private:
		DerivedSquared(const Expr& rhs) : m_InExpr(rhs) { std::cout << "DerivedSquared Constructed" << std::endl; }
		Expr m_InExpr;

		template<typename Derieved>
		friend class BaseTemplate;
	};

	template<typename Expr>
	class DerivedDouble : public BaseTemplate<DerivedDouble<Expr>>
	{
	public:
		inline auto eval() const { 
			std::cout << "DerivedDouble eval" << std::endl;
			return 2 * this->m_InExpr.eval(); 
		}

	private:
		DerivedDouble(const Expr& rhs) : m_InExpr(rhs) { std::cout << "DerivedDouble Constructed" << std::endl; }
		Expr m_InExpr;

		template<typename Derieved>
		friend class BaseTemplate;
	};

	template <typename OtherDerived>
	inline void showEvaluation(const BaseTemplate<OtherDerived>& inobj) { std::cout << inobj.eval() << std::endl; }

}}