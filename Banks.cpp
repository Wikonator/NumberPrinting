#include "Header.h"

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

// converting numbers to words 
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

	// hundreds
	if ((n < 1000) && (n >= 100)) {


	}
}