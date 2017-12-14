// NumberPrinting.cpp : Defines the entry point for the console application.
// This bit of code is built to take an integer from the user and print out 
// the value in numbers to the console.

#pragma once

#include <cstdio>
#include <cstdint>
#include "stdafx.h"
#include "Header.h"

using namespace std;
using namespace Bank;



int main() {

	Bank::cifrySlovami toto;
	uint64_t cislo = 0;
	int integer = 0;

	printf("whats up? Input a number between 1 and 999999999999!\n");
	scanf_s("%d", &integer);
	printf("your input was: %d\n", integer);

	cislo = (uint64_t)integer;
	printf("n is %lld, %s\n", cislo, toto.konverzia(cislo));
	
	return 0;
}

/*  old version 

int wordNumberParser(int x) {

	// parse the int and detect amount of numbers
	int length = 1;

	while (x /= 10) {
		
		length++;
	}

	return length;	
}

//std::string checkAgainstBank(const Banks_t banks) {

	//return banks.ones.find(4);
//}

void loopingThrough()
{


};

void compareDigitsToMap(const Banks_t &banks, const std::vector<int> &vector) {
	
	
	
	int vectorSize = vector.size(); //4
	 for (int position = 0; position < vectorSize ; position++) {

		int numberAtPosition = vector.at(position);



		switch (position) // at position check the map based on - number at position
		{
		case 0:
		{

			std::cout << banks.ones.at(numberAtPosition) << std::endl;			break;
		}
		case 1:
		{

			std::cout << banks.ones.at(numberAtPosition) << std::endl;			break;
		}
		case 2:
		{
			std::cout << banks.ones.at(numberAtPosition) << std::endl;			break;
		}
		case 3:
		{
			std::cout << banks.ones.at(numberAtPosition) << std::endl;			break;
		}
		case 4:
		{	
			std::cout << banks.ones.at(numberAtPosition) << std::endl;			break;
		}
		case 5:
		{
			std::cout << banks.ones.at(numberAtPosition) << std::endl;			break;
		}
		case 6:
		{
			std::cout << banks.ones.at(numberAtPosition) << std::endl;			break;
		}
		case 7:
		{
			std::cout << banks.ones.at(numberAtPosition) << std::endl;			break;
		}
		case 8:
		{
			std::cout << banks.ones.at(numberAtPosition) << std::endl;			break;
		}
		case 9:
		{
			std::cout << banks.ones.at(numberAtPosition) << std::endl;			break;
		}
		default:
			std::cout << "something went wrong boss" << std::endl;			break;
		}
	}
	
		
}

void fillRawVector(std::vector<int> &vector, int n, int cifry) {
	std::cout << "filling vector" << std::endl;
	parseEachDigit(n, cifry, vector);

	// std::vector<int>::iterator it = vector.begin();
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it) {
		std::cout << *it << ' '<<std::endl;
	}
}

void parseEachDigit(int x, int cifry, std::vector<int> &vector) {

	
	int digit = x % 10;
	int counter = 1;
	
	vector.insert(vector.begin(), digit);

	//compareDigitToMap(digit, counter, cifry);
	counter++;

	if (x >= 10) {

		parseEachDigit(x / 10, cifry, vector); 
	}
	
}


*/