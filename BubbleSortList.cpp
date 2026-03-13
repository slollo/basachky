/*
 *      BubbleSortList.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

import BubbleSort;
import List;
import TestSort;

#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	return !test_sort<BubbleSort, ToList<SORT_TEST_INPUT>::Result>("Bubble");
}
