/*
 *      QuickSort.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

export module QuickSort;

import Concat;
import Filter;
import HeadTail;
import IsEmpty;
import Length;
import Operator;

export
{
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
}
