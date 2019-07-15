/*
 *      MergeSort.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <cstddef>

#include "Length.hpp"
#include "Merge.hpp"
#include "Operator.hpp"
#include "Slice.hpp"


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

#endif /* MERGESORT_HPP */
