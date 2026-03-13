/*
 *      QuickSortList.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#include <iostream>

import List;
import QuickSort;
import TestSort;

#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	return !test_sort<QSort, ToList<SORT_TEST_INPUT>::Result>("Quick");
}
