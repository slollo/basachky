cmake_minimum_required(VERSION 3.13)

project(TSort)

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." FALSE)
if (${FORCE_COLORED_OUTPUT})
	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
		add_compile_options (-fdiagnostics-color=always)
	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
		add_compile_options (-fcolor-diagnostics)
	endif ()
endif ()

set(sorts
	QuickSortList QuickSortArray
	BubbleSortList BubbleSortArray
	MergeSortList MergeSortArray
	InsertionSortList InsertionSortArray
	)

set(SORT_TEST_INPUT int)
foreach (i RANGE 9)
	string(RANDOM LENGTH 2 ALPHABET "0123456789" NUM)
	string(RANDOM LENGTH 1 ALPHABET "-+" SIGN)
	set(SORT_TEST_INPUT "${SORT_TEST_INPUT},${SIGN}${NUM}")
endforeach ()

message(${SORT_TEST_INPUT})
#set(SORT_TEST_INPUT 1,32,8,8,3,4,7,-4,2,67,9764,5,-1)

function (add_sort_exec_run name)
	add_executable(${name} ${name}.cpp)

	target_compile_options(${name} PRIVATE -O3)
	target_compile_definitions(${name} PRIVATE -DSORT_TEST_INPUT=${SORT_TEST_INPUT})

	add_custom_target(run_${name}
		COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${name}
		DEPENDS ${name}
		USES_TERMINAL
		)
endfunction ()

foreach (sort IN ITEMS ${sorts})
	add_sort_exec_run(${sort})
	list(APPEND run_sorts run_${sort})
endforeach (sort)


add_custom_target(run DEPENDS ${run_sorts})

set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")