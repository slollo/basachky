/*
 *      InsertionSortList.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#include <iostream>

import InsertionSort;
import List;
import TestSort;

#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	return !test_sort<InsertionSort, ToList<SORT_TEST_INPUT>::Result>("Insertion");
}
