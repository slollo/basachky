/*
 *      Array.cpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#include "Array.hpp"
#include "test.hpp"


int main(int /*argc*/, char** /*argv*/)
{
	typedef Array<SORT_TEST_INPUT> Input;

	std::cout << "Array:  ";
	Print<Input>();

	return 0;
}
