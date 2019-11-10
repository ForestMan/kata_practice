// CppKataPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
// About Kata: http://codekata.com/kata/kata01-supermarket-pricing/

#include <iostream>

#include "CppKataPractice.h"

namespace kata_practice
{
	int FindElementInSubArray(int elementToFind, std::vector<int>& arrayToSearch, int startIndex, int endIndex)
	{
		int arrayLength = endIndex - startIndex;
		if (arrayLength == 0)
		{
			return -1;
		}
		if (arrayLength == 1)
		{
			return (arrayToSearch[startIndex] == elementToFind) ? startIndex : -1;
		}

		int middleIndex = startIndex + arrayLength / 2;
		if (arrayToSearch[middleIndex] > elementToFind)
		{
			return FindElementInSubArray(elementToFind, arrayToSearch, 0, middleIndex);
		}
		else if (arrayToSearch[middleIndex] < elementToFind)
		{
			return FindElementInSubArray(elementToFind, arrayToSearch, middleIndex, endIndex);
		}
		else if (arrayToSearch[middleIndex] == elementToFind)
		{
			return middleIndex;
		}
	}

	//always return -1 if can't find the number
	int ChopAndFindNumber(int numberToFind, std::vector<int>& ArrayToTraverse)
	{
		if (ArrayToTraverse.size() == 0)
		{
			return -1;
		}
		if (ArrayToTraverse.size() == 1)
		{
			return (ArrayToTraverse[0] == numberToFind) ? 0 : -1;
		}

		return FindElementInSubArray(numberToFind, ArrayToTraverse, 0, ArrayToTraverse.size());
	}
}

//int main()
//{
//    std::cout << "Hello World!\n";
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
