/*
 *      Length.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

module;

#include <cstddef>

export module Length;

import IsEmpty;
import HeadTail;


template <class cont, bool empty = IsEmpty<cont>::result>
struct Length_
{
	static const size_t result = 1 + Length_<typename Tail<cont>::Result>::result;
};


template <class cont>
struct Length_<cont, true>
{
	static const size_t result = 0;
};


export
{
template <class cont>
struct Length
{
	static const size_t result = Length_<cont>::result;
};
}
