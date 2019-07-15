/*
 *      HeadTail.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef HEADTAIL_HPP
#define HEADTAIL_HPP

template <class cont>
struct Head
{
};


template <class cont>
struct Tail
{
};


template <class cont, typename cont::Type e>
struct PushFront
{
};

#endif /* HEADTAIL_HPP */
