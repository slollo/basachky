/*
 *      Select.hpp
 *
 *
 * Copyright (C) 2019 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

#ifndef SELECT_HPP
#define SELECT_HPP

template <bool c, class T, class F>
struct Select { typedef T Result; };

template <class T, class F>
struct Select<false, T, F> { typedef F Result; };

#endif /* SELECT_HPP */

