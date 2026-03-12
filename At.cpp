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

export
{
template <class cont, typename cont::KeyT pos, bool empty = IsEmpty<cont>::result>
struct At
{
	static const typename cont::Type result =
	    (pos == 0) ? Head<cont>::result
	               : At<typename Tail<cont>::Result, pos - 1>::result;
};
}

#endif /* AT_HPP */
