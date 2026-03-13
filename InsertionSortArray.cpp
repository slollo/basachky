/*
 *      InsertionSortArray.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

import Array;
import InsertionSort;
import TestSort;

#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	return !test_sort<InsertionSort, Array<SORT_TEST_INPUT>>("Insertion");
}
