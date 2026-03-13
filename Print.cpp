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


template <class cont, bool empty = IsEmpty<cont>::result>
struct Print_
{
	Print_()
	{
		std::cout << Head<cont>::result << ' ';
		Print_<typename Tail<cont>::Result>();
	}
};


template <class cont>
struct Print_<cont, true>
{
	Print_()
	{
		std::cout << std::endl;
	}
};


export
{
template <class cont>
struct Print: public Print_<cont>
{
};
}
