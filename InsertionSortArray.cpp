/*
 *      InsertionSortArray.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#include <iostream>

import Array;
import InsertionSort;
import Length;
import Print;

#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	typedef Array<SORT_TEST_INPUT> Input;

	std::cout << "Input:       ";
	Print<Input>();
	std::cout << "Length:      " << Length<Input>::result << std::endl;

	std::cout << "Insertion Sort:  ";
	Print<InsertionSort<Input>::Result>();

	return 0;
}
