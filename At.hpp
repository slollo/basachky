/*
 *      At.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef AT_HPP
#define AT_HPP

#include "IsEmpty.hpp"
#include "HeadTail.hpp"

template <class cont, typename cont::KeyT pos, bool empty = IsEmpty<cont>::result>
struct At
{
	static const typename cont::Type result =
	    (pos == 0) ? Head<cont>::result
	               : At<typename Tail<cont>::Result, pos - 1>::result;
};

#endif /* AT_HPP */
