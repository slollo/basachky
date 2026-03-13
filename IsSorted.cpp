/*
 *      IsSorted.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

module;

#include <cstddef>

export module IsSorted;

import Operator;
import HeadTail;
import Length;


template <class cont, template <class> class Cmp = LessEq,
          size_t len = Length<cont>::result>
struct IsSorted_
{
private:
	static const typename cont::Type chead = Head<cont>::result;
	typedef typename Tail<cont>::Result CTail;
	static const typename cont::Type cthead = Head<CTail>::result;

public:
	static const bool result = Cmp<typename cont::Type>::check(chead, cthead)
	                               ? IsSorted_<CTail, Cmp, len - 1>::result
	                               : false;
};

template <class cont, template <class> class Cmp>
struct IsSorted_<cont, Cmp, 1>
{
	static const bool result = true;
};


template <class cont, template <class> class Cmp>
struct IsSorted_<cont, Cmp, 0>
{
	static const bool result = true;
};


export
{
template <class cont, template <class> class Cmp = LessEq>
struct IsSorted
{
	static const bool result = IsSorted_<cont, Cmp>::result;
};
}
