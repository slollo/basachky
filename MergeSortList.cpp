/*
 *      MergeSortList.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#include <iostream>

import List;
import MergeSort;
import TestSort;

#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	return !test_sort<MergeSort, ToList<SORT_TEST_INPUT>::Result>("Merge");
}
