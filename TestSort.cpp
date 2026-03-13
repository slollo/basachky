/*
 *      TestSort.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

module;

#include <iomanip>
#include <iostream>

export module TestSort;

import IsSorted;
import Length;
import Print;

export template <template <class> class Sort, class Input>
bool test_sort(const std::string& name)
{
	const int header_w = 20;
	std::cout << std::left << std::setw(header_w) << "Input:";
	Print<Input>();
	std::cout << std::left << std::setw(header_w)
	          << "Length:" << Length<Input>::result << std::endl;

	typedef typename Sort<Input>::Result SortedInput;
	std::cout << std::left << std::setw(header_w) << (name + " Sort:");
	Print<SortedInput>();

	const bool result = IsSorted<SortedInput>::result;
	std::cout << std::left << std::setw(header_w)
	          << "IsSorted:" << std::boolalpha << result << std::endl;

	return result;
}
