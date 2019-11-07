// CppKataPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
// About Kata: http://codekata.com/kata/kata01-supermarket-pricing/

#include <iostream>

#include "CppKataPractice.h"

namespace kata_practice
{
	//always return -1 if can't find the number
	int ChopAndFindNumber(int numberToFind, std::vector<int>& ArrayToTraverse)
	{
		if (ArrayToTraverse.empty())
			return -1;

		if (ArrayToTraverse.size() == 1)
		{
			if (ArrayToTraverse[0] == numberToFind)
			{
				return 0;
			}
		}

		int isOdd = ArrayToTraverse.size() % 2;
		int halfIndex = ArrayToTraverse.size() / 2;

		if (ArrayToTraverse[halfIndex] == numberToFind)
		{
			return halfIndex;
		}
		else
		{
			int startIndex = ArrayToTraverse[halfIndex] > numberToFind ? 0 : halfIndex;
			if (isOdd == 1)
			{
				startIndex = ArrayToTraverse[halfIndex] > numberToFind ? 0 : halfIndex + 1;
			}

			std::vector<int> halfArray;
			for (int i = startIndex; i < startIndex+halfIndex; i++)
			{
				halfArray.push_back(ArrayToTraverse[i]);
			}
			
			int result = ChopAndFindNumber(numberToFind, halfArray);
			return result == -1 ? result : startIndex + result;
		}

		return -1;
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
