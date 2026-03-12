/*
 *      Concat.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

export module Concat;

import HeadTail;
import IsEmpty;

export
{
template <class cont0, class cont1, bool empty = IsEmpty<cont0>::result>
struct Concat
{
	typedef
	       typename PushFront<
	           typename Concat<typename Tail<cont0>::Result, cont1>::Result,
	           Head<cont0>::result
	       >::Result Result;
};


template <class cont0, class cont1>
struct Concat<cont0, cont1, true>
{
	typedef cont1 Result;
};
}
