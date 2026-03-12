/*
 *      QuickSortList.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#include <iostream>

import Length;
import List;
import Print;
import QuickSort;

#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	typedef ToList<SORT_TEST_INPUT>::Result Input;

	std::cout << "Input:      ";
	Print<Input>();
	std::cout << "Length:     " << Length<Input>::result << std::endl;

	std::cout << "Quick Sort: ";
	Print<QSort<Input>::Result>();

	return 0;
}
