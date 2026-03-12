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

export
{
template <class cont, bool empty = IsEmpty<cont>::result>
struct Length
{
	static const size_t result = 1 + Length<typename Tail<cont>::Result>::result;
};


template <class cont>
struct Length<cont, true>
{
	static const size_t result = 0;
};
}
