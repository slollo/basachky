/*
 *      BubbleSortArray.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

import Array;
import BubbleSort;
import TestSort;

#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	return !test_sort<BubbleSort, Array<SORT_TEST_INPUT>>("Bubble");
}
