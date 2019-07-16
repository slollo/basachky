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
struct ListNull
{
	typedef EType Type;
	typedef size_t KeyT;
};


template <class EType, EType elem, class T>
struct List
{
	typedef EType Type;
	typedef size_t KeyT;
	typedef ListNull<EType> Empty;
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
	typedef List<EType, e, ListNull<EType>> Result;
};


template <class EType>
struct IsEmpty<ListNull<EType>>
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
struct Tail<ListNull<EType>>
{
	typedef ListNull<EType> Result;
};


template <class EType, EType e, class T, EType ie>
struct PushFront<List<EType, e, T>, ie>
{
	typedef List<EType, ie, List<EType, e, T>> Result;
};


template <class EType, EType ie>
struct PushFront<ListNull<EType>, ie>
{
	typedef List<EType, ie, ListNull<EType>> Result;
};

#endif /* LIST_HPP */
