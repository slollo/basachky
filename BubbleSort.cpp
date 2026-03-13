/*
 *      BubbleSort.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

module;

#include <cstddef>

export module BubbleSort;

import HeadTail;
import IsEmpty;
import Length;
import Operator;
import Select;


template <class cont, template <class> class Cmp = Less, size_t i = 0,
          size_t len = Length<cont>::result>
struct BubblePush
{
	static const typename cont::Type chead = Head<cont>::result;
	typedef typename Tail<cont>::Result CTail;
	static const typename cont::Type cthead = Head<CTail>::result;
	typedef typename Tail<CTail>::Result CTailTail;

	typedef typename Select<
	    Cmp<typename cont::Type>::check(chead, cthead),
	    typename PushFront<
	        typename BubblePush<CTail, Cmp, i + 1, len - 1>::Result,
	        chead>::Result,
	    typename PushFront<
	        typename BubblePush<typename PushFront<CTailTail, chead>::Result,
	                            Cmp, i + 1, len - 1>::Result,
	        cthead>::Result>::Result Result;
};


template <class cont, template <class> class Cmp, size_t i>
struct BubblePush<cont, Cmp, i, 0>
{
	typedef cont Result;
};


template <class cont, template <class> class Cmp, size_t i>
struct BubblePush<cont, Cmp, i, 1>
{
	typedef cont Result;
};


template <class cont, template <class> class Cmp = Less,
          size_t len = Length<cont>::result>
struct BubbleSort_
{
	typedef
	    typename BubbleSort_<typename BubblePush<cont, Cmp, len, len>::Result,
	                         Cmp, len - 1>::Result Result;
};


template <class cont, template <class> class Cmp>
struct BubbleSort_<cont, Cmp, 0>
{
	typedef cont Result;
};


export
{
template <class cont, template <class> class Cmp = Less>
struct BubbleSort
{
	typedef typename BubbleSort_<cont, Cmp>::Result Result;
};
}
