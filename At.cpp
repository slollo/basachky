/*
 *      At.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

export module At;

import IsEmpty;
import HeadTail;


template <class cont, typename cont::KeyT pos, bool empty = IsEmpty<cont>::result>
struct At_
{
	static const typename cont::Type result =
	    (pos == 0) ? Head<cont>::result
	               : At_<typename Tail<cont>::Result, pos - 1>::result;
};


export
{
template <class cont, typename cont::KeyT pos>
struct At
{
	typedef At_<cont, pos>::Result Result;
};
}

#endif /* AT_HPP */
