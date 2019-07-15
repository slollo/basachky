/*
 *      List.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

#include "HeadTail.hpp"
#include "IsEmpty.hpp"


template <class EType>
struct Null
{
	typedef EType Type;
	typedef size_t KeyT;
};


template <class EType, EType elem, class T>
struct List
{
	typedef EType Type;
	typedef size_t KeyT;
	typedef Null<EType> Empty;
	static const Type value = elem;
	typedef T tail;
};


template <class EType, EType e, EType ...lst>
struct ToList
{
	typedef List<EType, e, typename ToList<EType, lst...>::Result> Result;
};


template <class EType, EType e>
struct ToList<EType, e>
{
	typedef List<EType, e, Null<EType>> Result;
};


template <class EType>
struct IsEmpty<Null<EType>>
{
	static const bool result = true;
};


template <class EType, EType e, class T>
struct Head<List<EType, e, T>>
{
	static const EType result = e;
};


template <class EType, EType e, class T>
struct Tail<List<EType, e, T>>
{
	typedef T Result;
};


template <class EType>
struct Tail<Null<EType>>
{
	typedef Null<EType> Result;
};


template <class EType, EType e, class T, EType ie>
struct PushFront<List<EType, e, T>, ie>
{
	typedef List<EType, ie, List<EType, e, T>> Result;
};


template <class EType, EType ie>
struct PushFront<Null<EType>, ie>
{
	typedef List<EType, ie, Null<EType>> Result;
};

#endif /* LIST_HPP */
