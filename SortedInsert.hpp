/*
 *      SortedInsert.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef SORTEDINSERT_HPP
#define SORTEDINSERT_HPP

#include "Operator.hpp"
#include "IsEmpty.hpp"
#include "HeadTail.hpp"
#include "Select.hpp"


template <class sorted_cont, typename sorted_cont::Type e,
          template <class> class Cmp = Less,
          bool empty = IsEmpty<sorted_cont>::result>
struct SortedInsert
{
	static const typename sorted_cont::Type chead = Head<sorted_cont>::result;
	typedef typename Tail<sorted_cont>::Result CTail;
	typedef typename Select<
	            Cmp<typename sorted_cont::Type>::check(e, chead),
	            typename PushFront<sorted_cont, e>::Result,
	            typename PushFront<typename SortedInsert<CTail, e, Cmp>::Result, chead>::Result
	        >::Result Result;
};


template <class sorted_cont, typename sorted_cont::Type e,
          template <class> class Cmp>
struct SortedInsert<sorted_cont, e, Cmp, true>
{
	typedef typename PushFront<sorted_cont, e>::Result Result;
};

#endif /* SORTEDINSERT_HPP */
