/*
 *      Filter.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

export module Filter;

import HeadTail;
import IsEmpty;
import Select;

export
{
template <template <class> class Pred, class cont,
          bool empty = IsEmpty<cont>::result>
struct Filter
{
	typedef typename Filter<Pred, typename Tail<cont>::Result>::Result Tail;
	typedef typename Select<Pred<typename cont::Type>::check(Head<cont>::result),
	                        typename PushFront<Tail, Head<cont>::result>::Result,
	                        Tail>::Result Result;
};


template <template <class> class Pred, class cont>
struct Filter<Pred, cont, true>
{
	typedef cont Result;
};
}
