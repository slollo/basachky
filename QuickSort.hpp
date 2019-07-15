/*
 *      QuickSort.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "Concat.hpp"
#include "Filter.hpp"
#include "HeadTail.hpp"
#include "Operator.hpp"
#include "Length.hpp"
#include "IsEmpty.hpp"


template <class cont, template <class> class Cmp = Less,
          bool empty = IsEmpty<cont>::result>
struct QSort
{
	template <class T>
	struct Cmp2
	{
		typedef T ParamT;
		constexpr static bool check(T e0)
		{
			return Cmp<T>::check(e0, Head<cont>::result);
		}
	};

	template <class T>
	using NotCmp2 = Not<Cmp2, T>;

	typedef typename Concat<
	            typename QSort<
	                typename Filter<Cmp2, typename Tail<cont>::Result>::Result,
	                Cmp>::Result,
	            typename PushFront<
	                 typename QSort<typename Filter<NotCmp2,
	                                         typename Tail<cont>::Result>::Result,
	                                Cmp>::Result,
	                 Head<cont>::result
	            >::Result
	        >::Result Result;
};

template <class cont, template <class> class Cmp>
struct QSort<cont, Cmp, true>
{
	typedef cont Result;
};

#endif /* QUICKSORT_HPP */
