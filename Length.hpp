/*
 *      Length.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef LENGTH_HPP
#define LENGTH_HPP

#include <cstddef>

#include "IsEmpty.hpp"
#include "HeadTail.hpp"


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

#endif /* LENGTH_HPP */
