/*
 *      MergeSortArray.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#include <iostream>

import Array;
import MergeSort;
import TestSort;

#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	return !test_sort<MergeSort, Array<SORT_TEST_INPUT>>("Merge");
}
