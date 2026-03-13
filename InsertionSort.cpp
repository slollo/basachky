/*
 *      InsertionSort.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

export module InsertionSort;

import HeadTail;
import IsEmpty;
import Operator;
import SortedInsert;


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


export
{
template <class cont, template <class> class Cmp = Less>
struct InsertionSort
{
	typedef typename InsertionSort_<cont, typename cont::Empty, Cmp>::Result Result;
};
}
