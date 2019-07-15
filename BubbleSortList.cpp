/*
 *      BubbleSortList.cpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#include "BubbleSort.hpp"
#include "List.hpp"
#include "Print.hpp"
#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	typedef ToList<SORT_TEST_INPUT>::Result Input;

	std::cout << "Input:       ";
	Print<Input>();
	std::cout << "Length:      " << Length<Input>::result << std::endl;

	std::cout << "Bubble Sort: ";
	Print<BubbleSort<Input>::Result>();

	return 0;
}
