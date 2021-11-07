#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_

#include <iostream>
#include <cmath>
#include <strstream>

namespace P3_1 {

	//////////////////////////////////////////////////////////////////////////////
	//					            		class and methods						              	    //			
	//////////////////////////////////////////////////////////////////////////////

	class IntVector {
	private:
		int cSZ;																                                  // current size			
		int* ar;
		int SZ;
		static const int QUOTA = 5;
	public:
		IntVector() : cSZ(0), SZ(QUOTA) { ar = new int[QUOTA]; };				          // default constructor
		IntVector(int el);														                            // 1 element constructor
		IntVector(int size, const int* ar);										                    // elements massive constructor
		IntVector(const IntVector&);											                        // copy constructor
		IntVector& operator =(const IntVector&);								                  // = overload
		std::ostream& print(std::ostream&, int a, int l) const;					          // output vector with given length
		friend std::ostream& operator <<(std::ostream&, const IntVector&);		    // << overload	
		IntVector& operator +=(const IntVector&);								                  // += overload
		void addEl(int el);														                            // including a new element in a vector
		void sort(int first, int last);											                      // quicksort vector
		int maxNum() const;														                            // finding maximum element
		~IntVector() { 	delete[] ar; };											                      // destructor

		//////////////////////////////////////////////////////////////////////////
		//	  	auxiliary methods and overloads at the request of the teacher	  //			
		//////////////////////////////////////////////////////////////////////////

		IntVector& const operator -();											                      // - overload
		friend IntVector const operator+(const IntVector& iv1, const IntVector& iv2);	// + overload
		int& operator[] (const int index);										                    // [] overload				
		IntVector& operator++();												                          // pre++ overload
		IntVector operator++(int);												                        // post++ overload

		int getArEl(int i) const { return ar[i]; }								                // getters
		int getCSz() const { return cSZ; }										                    // getters
		
	};


	template <class T>
	int getNum(T& a) {
		std::cin >> a;
		while (!std::cin.good()) {
			std::cout << "Error, try again" << std::endl;
			if (std::cin.eof())
				return -1;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		return 1;
	}
}
#endif

