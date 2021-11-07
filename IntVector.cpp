#include "IntVector.h"
namespace P3_1 {
	IntVector::IntVector(int el) {			                            // 1 element constructor 
		SZ = QUOTA;
		ar = new int[SZ];
		ar[0] = el;												                            // assignment to 0 element of the passed value
		cSZ = 1;
	}

	IntVector::IntVector(int size, const int* ar1) {			          // elements massive constructor
		SZ = size;
		ar = new int[SZ];
		for (int i = 0; i < SZ; i++) {
			ar[i] = ar1[i];
		}
		cSZ = SZ;
	}

	IntVector::IntVector(const IntVector& iv) {
		cSZ = iv.cSZ;
		SZ = iv.SZ;
		ar = new int[SZ];
		for (int i = 0; i < cSZ; i++)
			ar[i] = iv.ar[i];
	}

	IntVector& IntVector::operator =(const IntVector& iv)
	{
		if (this != &iv) {
			cSZ = iv.cSZ;
			SZ = iv.SZ;
			delete[] ar;
			ar = new int[SZ];
			for (int i = 0; i < cSZ; i++)
				ar[i] = iv.ar[i];
		}
		return *this;
	}

	void IntVector::addEl(int el) {						          					  // including a new element in a vector
		if (cSZ >= SZ) {
			SZ += QUOTA;
			int* old = ar;
			ar = new int[SZ];
			for (int i = 0; i < cSZ; i++)
				ar[i] = old[i];
			delete[] old;
		}
		ar[cSZ] = el;
		cSZ++;
	}

	IntVector& IntVector::operator +=(const IntVector& iv) {				// += overload
		if (SZ < iv.cSZ) {
			SZ = iv.cSZ;
			int* old = ar;
			ar = new int[SZ];
			for (int i = 0; i < cSZ; i++)
				ar[i] = old[i];
			for (int i = cSZ; i < SZ; i++)
				ar[i] = 0;
			delete[] old;
			cSZ = SZ;
		}
		for (int i = 0; i < iv.cSZ; i++)
			ar[i] += iv.ar[i];
		return *this;
	}

	std::ostream& IntVector::print(std::ostream& s, int a, int l) const {	// output to stream and selection part of a vector with given length 
		if (cSZ == 0)
			s << "Vector is empty";
		else if (a + l > cSZ)
			s << "Too much elements";
		else
			for (int i = a; i < a + l; i++)									            // in default output a = 0, l = cSZ
				s << ar[i] << ' ';
		s << std::endl;
		return s;
	}

	std::ostream& operator <<(std::ostream& s, const IntVector& iv) {		// << overload
		if (iv.cSZ == 0)
			s << "Vector is empty";
		else
			for (int i = 0; i < iv.cSZ; i++)
				s << iv.ar[i] << ' ';
		s << std::endl;
		return s;
	}

	void IntVector::sort(int first, int last) {								      // quicksort vector			
		if (cSZ == 0)
			throw std::exception("Vector is empty");
		int i = first, j = last, x = ar[(first + last) / 2];
		do {
			while (ar[i] < x) i++;
			while (ar[j] > x) j--;

			if (i <= j) {
				int tmp = ar[i];
				ar[i] = ar[j];
				ar[j] = tmp;
				i++;
				j--;
			}
		} while (i <= j);
		if (i < last)
			sort(i, last);
		if (first < j)
			sort(first, j);
	}

	int IntVector::maxNum() const {											            // finding maximum element
		if (cSZ == 0)
			throw std::exception("Vector is empty");
		int m = ar[0];
		for (int i = 1; i < cSZ; i++) {
			if (ar[i] > m)
				m = ar[i];
		}
		return m;
	}

	IntVector& const IntVector::operator -() {								      // - overload	
		for (int i = 0; i < cSZ; i++) {
			ar[i] = -ar[i];
		}
		return *this;
	}

	const IntVector operator +(const IntVector& iv1, const IntVector& iv2) {// + overload
		IntVector iv3;
		int x;
		if (iv1.cSZ <= iv2.cSZ)
			x = iv2.cSZ;
		else
			x = iv1.cSZ;
		for (int i = 0; i < x; i++) {										              // componentwise addition of two vectors
			if (i < iv1.cSZ && i < iv2.cSZ)
				iv3.addEl(iv1.ar[i] + iv2.ar[i]);
			else if (i >= iv1.cSZ)
				iv3.addEl(iv2.ar[i]);
			else
				iv3.addEl(iv1.ar[i]);
		}
		return iv3;
	}

	int& IntVector::operator[] (const int index) {							    // [] overload
		if (index < 0 || index >= SZ)
			throw std::exception("Incorrect index");
		return ar[index];
	}

	IntVector& IntVector::operator++() {									          // pre ++ overload
		for (int i = 0; i < cSZ; i++) {
			ar[i]++;
		}
		return *this;
	}

	IntVector IntVector::operator++(int) {									        // post ++ overload
		IntVector temp = *this;
		++* this;
		return temp;
	}
}
