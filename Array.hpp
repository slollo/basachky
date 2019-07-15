/*
 *      Array.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#include "HeadTail.hpp"
#include "IsEmpty.hpp"


template <class EType, EType ...arr>
struct Array
{
	typedef EType Type;
	typedef size_t KeyT;
	typedef Array<EType> Empty;
	// constexpr static const EType array[] = {arr...};
};


template <class EType>
struct IsEmpty<Array<EType>>
{
	static const bool result = true;
};


template <class EType, EType e, EType ...arr>
struct Head<Array<EType, e, arr...>>
{
	static const EType result = e;
};


template <class EType, EType e, EType ...arr>
struct Tail<Array<EType, e, arr...>>
{
	typedef Array<EType, arr...> Result;
};


template <class EType>
struct Tail<Array<EType>>
{
	typedef Array<EType> Result;
};


template <class EType, EType ...arr, EType pe>
struct PushFront<Array<EType, arr...>, pe>
{
	typedef Array<EType, pe, arr...> Result;
};

#endif /* ARRAY_HPP */
