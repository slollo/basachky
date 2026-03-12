/*
 *      Merge.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

export module Merge;

import HeadTail;
import IsEmpty;
import Operator;
import Select;

export
{
template <class cont0, class cont1, template <class> class Cmp = Less,
          bool cont0Empty = IsEmpty<cont0>::result,
          bool cont1Empty = IsEmpty<cont1>::result>
struct Merge
{
	static const typename cont0::Type e0 = Head<cont0>::result;
	static const typename cont1::Type e1 = Head<cont1>::result;
	typedef typename Tail<cont0>::Result T0;
	typedef typename Tail<cont1>::Result T1;
	typedef typename Select<
	            Cmp<typename cont0::Type>::check(e0, e1),
	            typename PushFront<typename Merge<T0, cont1, Cmp>::Result, e0>::Result,
	            typename PushFront<typename Merge<cont0, T1, Cmp>::Result, e1>::Result
	        >::Result Result;
};


template <class cont0, class cont1, template <class> class Cmp>
struct Merge<cont0, cont1, Cmp, true, false>
{
	typedef cont1 Result;
};


template <class cont0, class cont1, template <class> class Cmp>
struct Merge<cont0, cont1, Cmp, false, true>
{
	typedef cont0 Result;
};


template <class cont0, class cont1, template <class> class Cmp>
struct Merge<cont0, cont1, Cmp, true, true>
{
	typedef cont0 Result;
};
}
