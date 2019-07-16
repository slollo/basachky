/*
 *      Print.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>


template <class cont, bool empty = IsEmpty<cont>::result>
struct Print
{
	Print()
	{
		std::cout << Head<cont>::result << " ";
		Print<typename Tail<cont>::Result>();
	}
};


template <class cont>
struct Print<cont, true>
{
	Print()
	{
		std::cout << std::endl;
	}
};

#endif /* PRINT_HPP */
