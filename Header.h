#pragma once

/*
 This is a header for the NumberPrinting.cpp it contains a bunch of stuff I haven't figured out yet

*/ 

#include <string>
#include <cstring>
#include <vector>

void parseEachDigit(int x, int cifry);
void compareDigitToMap(int digit, int cifry);
void fillRawVector(std::vector<int> &vec, int digit, int cifry);

int wordNumberParser(int);