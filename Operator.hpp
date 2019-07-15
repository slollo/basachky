/*
 *      Operator.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef OPERATOR_HPP
#define OPERATOR_HPP


template <template <class> class Op, class T>
struct Not
{
	typedef typename Op<T>::ParamT ParamT;

	constexpr static bool check(ParamT e0, ParamT e1)
	{
		return not Op<T>::check(e0, e1);
	}

	constexpr static bool check(ParamT e)
	{
		return not Op<T>::check(e);
	}
};


template <template <class> class Op0, template <class> class Op1, class T>
struct And
{
	typedef typename Op0<T>::ParamT ParamT;

	constexpr static bool check(ParamT e0, ParamT e1)
	{
		return Op0<T>::check(e0, e1) and Op1<T>::check(e0, e1);
	}

	constexpr static bool check(ParamT e)
	{
		return Op0<T>::check(e) and Op1<T>::check(e);
	}
};


template <template <class> class Op0, template <class> class Op1, class T>
struct Or
{
	typedef typename Op0<T>::ParamT ParamT;

	constexpr static bool check(ParamT e0, ParamT e1)
	{
		return Op0<T>::check(e0, e1) or Op1<T>::check(e0, e1);
	}

	constexpr static bool check(ParamT e)
	{
		return Op0<T>::check(e) or Op1<T>::check(e);
	}
};


template <class A, class B>
struct IsSame
{
	static const bool result = false;
};


template <class A>
struct IsSame<A, A>
{
	static const bool result = true;
};


template <class T>
struct Equal
{
	typedef T ParamT;
	constexpr static bool check(T e0, T e1)
	{
		return e0 == e1;
	}
};


template <class T>
struct Less
{
	typedef T ParamT;
	constexpr static bool check(T e0, T e1)
	{
		return e0 < e1;
	}
};


template <class T>
using LessEq = Or<Less, Equal, T>;

template <class T>
using Greater = Not<LessEq, T>;

template <class T>
using GreaterEq = Not<Less, T>;

#endif /* OPERATOR_HPP */
