/*
 *      MergeSortArray.cpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#include "Array.hpp"
#include "MergeSort.hpp"
#include "Print.hpp"
#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	typedef Array<SORT_TEST_INPUT> Input;

	std::cout << "Input:       ";
	Print<Input>();
	std::cout << "Length:      " << Length<Input>::result << std::endl;

	std::cout << "Merge Sort:  ";
	Print<MergeSort<Input>::Result>();

	return 0;
}
