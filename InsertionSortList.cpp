/*
 *      InsertionSortList.cpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#include "InsertionSort.hpp"
#include "Length.hpp"
#include "List.hpp"
#include "Print.hpp"
#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	typedef ToList<SORT_TEST_INPUT>::Result Input;

	std::cout << "Input:       ";
	Print<Input>();
	std::cout << "Length:      " << Length<Input>::result << std::endl;

	std::cout << "Insertion Sort:  ";
	Print<InsertionSort<Input>::Result>();

	return 0;
}
