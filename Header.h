#pragma once

/*
 This is a header for the NumberPrinting.cpp it contains a bunch of stuff I haven't figured out yet

*/ 

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <cstdlib>

#define MAXLENGTH 1024

#define MAXNUMBER 999999999999999999

namespace Bank
{
	static const char* chyba = "error"; // why must this be const?

	static const char* jednotky[] = { "jeden", "dva", "tri" ,"styri" , "pat", "sest", "sedem", "osem", "devat" };

	static const char* nast[] = { "desat", "jedenast", "dvanast", "trinast", "strnast", "patnast", "sestnast", "sedemnast", "osemnast", "devatnast" };

	static const char* desiatky[] = { chyba, chyba, "dvadsat", "tridsat", "styridsat", "patdesiat", "sestdesiat", "sedemdesiat", "osemdesiat", "devatdesiat" };

	static const char* stovky = "sto";

	static const char* mocniny[] = { chyba, "tisic", "milion", "miliarda", "bilion", "trilion" };

	static const char* medzera = " ";


	class cifrySlovami {

		uint64_t cislo = 0;		// using 64bit integer type - unsigned long long
		size_t bufferLength = 0;	// sets length of the buffer, size_t is unsigned int (for the string length)
		char* buffer = nullptr; // pointer to the first character in a buffer where the word is pasted together (initialized to 0)
		
	private :
		void initBuf(); // makes the buffer
		void vymazBuffer(); // erases the buffer
		void space(); // adds a space
		void addToBuffer(const char* string); // paste to the end of the buffer

	public :
		cifrySlovami() : cislo(0) {}
		cifrySlovami(const uint64_t num) : cislo(num) {}
		~cifrySlovami(); // destrukt
		void setCislo(const uint64_t num) { cislo = num; }
		uint64_t getCislo() const { return cislo; } // const lebo gettery by mali byt const
	
		const char* konverzia();
		const char* konverzia( const uint64_t num );
	
		uint64_t operator = ( const uint64_t num);
	};
};