/*
 *      Concat.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef CONCAT_HPP
#define CONCAT_HPP

#include "HeadTail.hpp"
#include "IsEmpty.hpp"


template <class cont0, class cont1, bool empty = IsEmpty<cont0>::result>
struct Concat
{
	typedef
	       typename PushFront<
	           typename Concat<typename Tail<cont0>::Result, cont1>::Result,
	           Head<cont0>::result
	       >::Result Result;
};


template <class cont0, class cont1>
struct Concat<cont0, cont1, true>
{
	typedef cont1 Result;
};

#endif /* CONCAT_HPP */
