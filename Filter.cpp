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

template <template <class> class Pred, class cont,
          bool empty = IsEmpty<cont>::result>
struct Filter_
{
	typedef typename Filter_<Pred, typename Tail<cont>::Result>::Result Tail;
	typedef typename Select<Pred<typename cont::Type>::check(Head<cont>::result),
	                        typename PushFront<Tail, Head<cont>::result>::Result,
	                        Tail>::Result Result;
};


template <template <class> class Pred, class cont>
struct Filter_<Pred, cont, true>
{
	typedef cont Result;
};


export
{
template <template <class> class Pred, class cont>
struct Filter
{
	typedef Filter_<Pred, cont>::Result Result;
};
}
