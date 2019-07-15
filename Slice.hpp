/*
 *      Slice.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef SLICE_HPP
#define SLICE_HPP

#include "IsEmpty.hpp"
#include "HeadTail.hpp"
#include "Select.hpp"


template <class cont, typename cont::KeyT begin, typename cont::KeyT end,
          typename cont::KeyT i, bool empty = IsEmpty<cont>::result>
struct _Slice
{
	typedef typename cont::Empty Empty;
	typedef typename _Slice<typename Tail<cont>::Result, begin, end, i + 1>::Result T;
	typedef typename Select<
	            (i >= end), Empty,
	            typename Select<
	                (i < begin), T,
	                typename PushFront<T, Head<cont>::result>::Result
	            >::Result
	        >::Result Result;
};


template <class cont, typename cont::KeyT begin, typename cont::KeyT end, typename cont::KeyT i>
struct _Slice<cont, begin, end, i, true>
{
	typedef cont Result;
};


template <class cont, typename cont::KeyT begin, typename cont::KeyT end>
struct Slice
{
	typedef typename _Slice<cont, begin, end, 0>::Result Result;
};

#endif /* SLICE_HPP */
