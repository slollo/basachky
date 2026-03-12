/*
 *      Select.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

export module Select;

export
{
template <bool c, class T, class F>
struct Select { typedef T Result; };

template <class T, class F>
struct Select<false, T, F> { typedef F Result; };
}
