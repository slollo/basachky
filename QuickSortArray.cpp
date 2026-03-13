/*
 *      QuickSortArray.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

import Array;
import QuickSort;
import TestSort;

#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	return !test_sort<QSort, Array<SORT_TEST_INPUT>>("Quick");
}
