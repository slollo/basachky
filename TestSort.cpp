/*
 *      TestSort.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

module;

#include <iostream>

export module TestSort;

import IsSorted;
import Length;
import Print;

export
template <template <class> class Sort, class Input>
bool test_sort(const std::string& name)
{
	std::cout << "Input:       ";
	Print<Input>();
	std::cout << "Length:      " << Length<Input>::result << std::endl;

	typedef typename Sort<Input>::Result SortedInput;
	std::cout << name << " Sort: ";
	Print<SortedInput>();

	const bool result = IsSorted<SortedInput>::result;
	std::cout << "IsSorted: " << result << std::endl;

	return result;
}
