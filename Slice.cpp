/*
 *      Slice.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

export module Slice;

import IsEmpty;
import HeadTail;
import Select;

template <class cont, typename cont::KeyT begin, typename cont::KeyT end,
          typename cont::KeyT i, bool empty = IsEmpty<cont>::result>
struct Slice_
{
	typedef typename cont::Empty Empty;
	typedef typename Slice_<typename Tail<cont>::Result, begin, end, i + 1>::Result T;
	typedef typename Select<
	            (i >= end), Empty,
	            typename Select<
	                (i < begin), T,
	                typename PushFront<T, Head<cont>::result>::Result
	            >::Result
	        >::Result Result;
};


template <class cont, typename cont::KeyT begin, typename cont::KeyT end, typename cont::KeyT i>
struct Slice_<cont, begin, end, i, true>
{
	typedef cont Result;
};


export
{
template <class cont, typename cont::KeyT begin, typename cont::KeyT end>
struct Slice
{
	typedef typename Slice_<cont, begin, end, 0>::Result Result;
};
}
