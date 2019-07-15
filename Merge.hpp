/*
 *      Merge.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef MERGE_HPP
#define MERGE_HPP

#include "HeadTail.hpp"
#include "Operator.hpp"
#include "Select.hpp"
#include "IsEmpty.hpp"


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


#endif /* MERGE_HPP */
