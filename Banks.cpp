#include "Header.h"
#include "stdafx.h"


using namespace Bank;

// private meth

// clearing buffer
void cifrySlovami::vymazBuffer() {

	if (buffer != nullptr) {
		free(buffer);
		buffer = nullptr;
	}
	bufferLength = 0;
}

// init buffer
void cifrySlovami::initBuf() {

	vymazBuffer();
	buffer = (char*) malloc(MAXLENGTH);
	*buffer = 0;
}

// pridavanie medzier
void cifrySlovami::space() {

	if (bufferLength) {

		addToBuffer(medzera);
	}
}

void cifrySlovami::addToBuffer(const char* string) {

	if (!string) { 
	
		return;
	}
	else {

		size_t stringLength = strnlen(string, MAXLENGTH); // method comes from string.h - sets the
		
		if (stringLength < 1) {
			return;
		}
		if ((stringLength + bufferLength + 1) >= MAXLENGTH) {

			return;
		}
		memcpy(buffer + bufferLength, string, stringLength);
		bufferLength += stringLength;
		buffer[bufferLength] = 0;
	}
}

// konverzia bez parametru
const char* cifrySlovami::konverzia() {

	return konverzia(cislo);
}

// pretazena s parametrom 
const char* cifrySlovami::konverzia( const uint64_t number ) {

	if (number > MAXNUMBER) {

		return chyba;
	}
	initBuf();
	uint64_t n = number;
	if (n == 0) {

		addToBuffer(jednotky[n]);
		return buffer;
	}

	// mocniny nad 1000
	if (n >= 1000) {

		for (int index = 5; index > 0; --index) {

			uint64_t moc = (uint64_t) pow(1000.0, index); // pow je z cmath
			uint64_t zvysok = ( n - ( n % moc ) ) / moc;
			if (zvysok) {

				int i = index;
				cifrySlovami objektZaujmu(zvysok); // vytvor objekt a daj mu vysledok loopu
				space();							// pridaj medzeru
				addToBuffer(objektZaujmu.konverzia()); // rekurzivne zavolaj konverziu a pridavaj do bufferu
				space();
				addToBuffer(mocniny[i]);
				n -= zvysok * moc;
			}
		}
	}

	// stovky
	if ((n < 1000) && (n >= 100)) {

		uint64_t zvysok = ( ( n - ( n % 100 ) ) /  100 );
		cifrySlovami objektZaujmu(zvysok);
		space();
		addToBuffer(objektZaujmu.konverzia());
		space();
		addToBuffer(stovky);
		n -= zvysok * 100;
	}

	// desiatky
	if ((n < 100) && (n >= 20)) {

		uint64_t zvysok = ( ( n - ( n % 10 ) ) / 10 );
		space();
		addToBuffer(desiatky[zvysok]);
		space();
	}
	// nasky
	if ((n < 20) && (n <= 10)) {

		space();
		addToBuffer(nast[n - 10]);
		n = 0;
	}

	// singles
	if ((n < 10) && (n > 0)) {

		space();
		addToBuffer(jednotky[n]);
	}

	return buffer;
}

// assignment 

uint64_t cifrySlovami::operator = (const uint64_t cislo) {

	setCislo(cislo);
	return getCislo();
}

// destruktor

cifrySlovami::~cifrySlovami() {

	vymazBuffer();			// Znic objekt a vymaz buffer
}