/*
 *      InsertionSort.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include "HeadTail.hpp"
#include "IsEmpty.hpp"
#include "Operator.hpp"
#include "SortedInsert.hpp"


template <class cont, class sorted_cont, template <class> class Cmp = Less,
          bool empty = IsEmpty<cont>::result>
struct InsertionSort_
{
	typedef typename InsertionSort_<
	            typename Tail<cont>::Result,
	            typename SortedInsert<sorted_cont, Head<cont>::result, Cmp>::Result,
	            Cmp
	        >::Result Result;
};


template <class cont, class sorted_cont, template <class> class Cmp>
struct InsertionSort_<cont, sorted_cont, Cmp, true>
{
	typedef sorted_cont Result;
};


template <class cont, template <class> class Cmp = Less>
struct InsertionSort
{
	typedef typename InsertionSort_<cont, typename cont::Empty, Cmp>::Result Result;
};

#endif /* INSERTIONSORT_HPP */
