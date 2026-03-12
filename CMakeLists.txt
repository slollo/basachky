cmake_minimum_required(VERSION 3.31)
set(CMAKE_COLOR_DIAGNOSTICS ON)

project(TSort)

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
	math(EXPR NUM "${SIGN}${NUM} + 0")
	set(SORT_TEST_INPUT "${SORT_TEST_INPUT},${NUM}")
endforeach ()

message(${SORT_TEST_INPUT})
#set(SORT_TEST_INPUT 1,32,8,8,3,4,7,-4,2,67,9764,5,-1)

add_library(Containers STATIC)
target_sources(Containers PUBLIC
	FILE_SET CXX_MODULES
	FILES
		# Containers
		Array.cpp
		List.cpp

		# Algorithms
		Concat.cpp
		Filter.cpp
		HeadTail.cpp
		IsEmpty.cpp
		Length.cpp
		Merge.cpp
		Operator.cpp
		Print.cpp
		Select.cpp
		Slice.cpp
		SortedInsert.cpp
	)
set_property(TARGET Containers PROPERTY CXX_STANDARD 20)

add_library(Sorts STATIC)
target_sources(Sorts PUBLIC
	FILE_SET CXX_MODULES
	FILES
		BubbleSort.cpp
		InsertionSort.cpp
		MergeSort.cpp
		QuickSort.cpp
	)
target_link_libraries(Sorts PUBLIC Containers)
set_property(TARGET Sorts PROPERTY CXX_STANDARD 20)

function (add_sort_exec_run name)
	add_executable(${name} ${name}.cpp)

	set_property(TARGET ${name} PROPERTY CXX_STANDARD 20)
	target_compile_definitions(${name} PRIVATE -DSORT_TEST_INPUT=${SORT_TEST_INPUT})
	target_link_libraries(${name} PRIVATE Sorts)

	add_custom_target(run_${name}
		COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${name}
		DEPENDS ${name}
		USES_TERMINAL
		)
	add_custom_command(
		COMMAND objdump --disassemble=main ${name} | sed 's/${name}/NAME/g' >${name}.asm
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		DEPENDS ${name}
		OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${name}.asm
		COMMENT "Disassembling ${name}"
		)
endfunction ()

foreach (sort IN ITEMS ${sorts})
	add_sort_exec_run(${sort})
	list(APPEND run_sorts run_${sort})
	list(APPEND asm_sorts ${CMAKE_CURRENT_BINARY_DIR}/${sort}.asm)
endforeach (sort)


add_custom_target(run DEPENDS ${run_sorts})
add_custom_target(asm DEPENDS ${asm_sorts})

set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")
