/*
 *      IsEmpty.cpp
 *
 *
 * Copyright (C) 2026 Max V. Stotsky <maxstotsky@gmail.com>
 *
 */

export module IsEmpty;

export
{
template <class cont>
struct IsEmpty
{
	static const bool result = false;
};
}
