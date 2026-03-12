/*
 *      MergeSort.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

module;

#include <cstddef>

export module MergeSort;

import Length;
import Merge;
import Operator;
import Slice;

export
{
template <class cont, template <class> class Cmp = Less,
          size_t len = Length<cont>::result>
struct MergeSort
{
	static const size_t len2 = len / 2;
	typedef typename Merge<
	            typename MergeSort<typename Slice<cont, 0, len2>::Result, Cmp>::Result,
	            typename MergeSort<typename Slice<cont, len2, len>::Result, Cmp>::Result,
	            Cmp
	        >::Result Result;
};


template <class cont, template <class> class Cmp>
struct MergeSort<cont, Cmp, 1>
{
	typedef cont Result;
};


template <class cont, template <class> class Cmp>
struct MergeSort<cont, Cmp, 0>
{
	typedef cont Result;
};
}
