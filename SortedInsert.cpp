/*
 *      SortedInsert.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

export module SortedInsert;

import HeadTail;
import IsEmpty;
import Operator;
import Select;

export
{
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
}
