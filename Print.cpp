/*
 *      Print.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */


module;

#include <iostream>

export module Print;

import IsEmpty;
import HeadTail;

export
{
template <class cont, bool empty = IsEmpty<cont>::result>
struct Print
{
	Print()
	{
		std::cout << Head<cont>::result << ' ';
		Print<typename Tail<cont>::Result>();
	}
};


template <class cont>
struct Print<cont, true>
{
	Print()
	{
		std::cout << "\n";
	}
};
}
