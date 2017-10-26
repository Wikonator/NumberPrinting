// NumberPrinting.cpp : Defines the entry point for the console application.
//



#pragma once

#include "stdafx.h"
#include "Header.h"
#include <iostream>
#include <map>

int n = 0;

int wordNumberParser(int x) {

	// parse the int and detect amount of numbers
	int length = 1;

	while (x /= 10) {
		
		length++;
	}

	return length ;	
}

void compareDigitToMap(int digi, int count, int cifry) {
	
	std::map< int, std::string> ones {
		{1, "jeden"},
		{2, "dva"},
		{3, "tri"},
		{4, "styri"},
		{5, "pat" },
		{6, "sest" },
		{7, "sedem" },
		{8, "osem" },
		{9, "devat" }
	};

	std::map< int, std::string> tens {
		{ 11, "jedenast" },
		{ 12, "dvanast" },
		{ 13, "trinast" },
		{ 14, "strnast" },
		{ 15, "patnast" },
		{ 16, "sestnast" },
		{ 17, "sedemnast" },
		{ 18, "osemnast" },
		{ 19, "devatnast" },
		{ 10, "desat" },
		{ 20, "dvadsat" },
		{ 30, "devatnast" },
		{ 40, "devatnast" },
		{ 50, "devatnast" },
		{ 60, "devatnast" },
		{ 70, "devatnast" },
		{ 80, "devatnast" },
		{ 90, "devatnast" },

	};

	switch (cifry)
	{
	case 1: std::cout << ones.find(digi)->second << std::endl;
	break;
	case 2: 
	default:
		std::cout << digi << std::endl;
		break;
	}
		
}

void fillRawVector(std::vector<int> *vector, int n, int cifry) {

	parseEachDigit(n, cifry);
}


void parseEachDigit(int x, int cifry)
{

	int digit = x % 10;
	int counter = 1;

	//compareDigitToMap(digit, counter, cifry);
	counter++;

	if (x >= 10) {

		parseEachDigit(x / 10, cifry);
	}
		

	
}


int main() {

	n = 1275;
	
	int Stringy = wordNumberParser(n);

	std::vector<int> rawVector;

	fillRawVector(&rawVector, n, Stringy);
	//parseEachDigit(n, Stringy);

		return 0;
}




// loop through the array of ints and for every space check the number against the numbers map
// push the string from map into a an array/vector 
// when done, print the arr/vec to the user 