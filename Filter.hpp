/*
 *      Filter.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef FILTER_HPP
#define FILTER_HPP

#include "HeadTail.hpp"
#include "Select.hpp"
#include "IsEmpty.hpp"


template <template <class> class Pred, class cont,
          bool empty = IsEmpty<cont>::result>
struct Filter
{
	typedef typename Filter<Pred, typename Tail<cont>::Result>::Result Tail;
	typedef typename Select<Pred<typename cont::Type>::check(Head<cont>::result),
	                        typename PushFront<Tail, Head<cont>::result>::Result,
	                        Tail>::Result Result;
};


template <template <class> class Pred, class cont>
struct Filter<Pred, cont, true>
{
	typedef cont Result;
};

#endif /* FILTER_HPP */
