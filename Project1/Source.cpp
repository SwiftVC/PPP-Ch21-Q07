/*
*	Author:	CS
*	Date:	2022_03_17	YYYY_MM_DD
*
*	Implement a binary search function.
*	The binary search function is correct and generalised, it returns all entries in the three cases:
*	std::list<std::string>, size 10
*	std::vector<std::string>, size 11
*	std::vector<int>, size 100
* 
*	The index checked is continually halved in the direction (array is sorted, direction is determined by < operator)
*	of the desired value, index checked are printed as a tracer. [index, index, index..]answer
* 
*	std::advance is just as efficient for random access iterators and uses random access in the vector case.
*/

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>

template <typename T, typename V>
auto binary_search(T& li, V find) {
	int index_to_check = li.size() / 2;
	int difference = li.size() / 2;
	std::cout << "[";
	for (int iteration = 1; iteration < li.size(); ++iteration) {
		auto it = li.begin();
		std::advance(it, index_to_check);

		difference /= 2;
		if (difference == 0)
			difference = 1;

		if (*it == find)		// found in middle
		{
			std::cout << index_to_check;
			std::cout << "]";
			return it;
		}
		else if (*it < find) {	// check upper quarter
			std::cout << index_to_check << ",";
			index_to_check += difference;
		}
		else {					//check lower quarter
			std::cout << index_to_check << ",";
			index_to_check -= difference;
		}
	}

	return li.end();
}

int main() {
	{
		std::list<std::string> list{ "alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india", "juliet", "zulu" };
		std::cout << "Testing a std::list<std::string> of size: " << list.size() << std::endl;
		list.sort(); // (no change)

		auto it = list.begin();
		for (int i = 0; i < list.size(); i++)
		{
			std::string test = *it;
			std::cout << *binary_search(list, test) << std::endl;
			++it;
		}
	}

	std::cout << std::endl;

	{
		std::vector<std::string> vect{ "alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india", "juliet"};
		std::cout << "Testing a std::vector<int> of size: " << vect.size() << std::endl;
		auto it = vect.begin();
		for (int i = 0; i < vect.size(); i++)
		{
			std::string test = *it;
			std::cout << *binary_search(vect, test) << std::endl;
			++it;
		}
	}
	
	std::cout << std::endl;

	{
		std::vector<int> vect;
		for (int i = 0; i < 100; i++) vect.push_back(i);
		std::cout << "Testing a std::vector<int> of size: " << vect.size() << std::endl;
		auto it = vect.begin();
		for (int i = 0; i < vect.size(); i++)
		{
			int test = *it;
			std::cout << *binary_search(vect, test) << std::endl;
			++it;
		}
	}

	return 0;
}