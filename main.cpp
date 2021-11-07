#define _USE_MATH_DEFINES
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "C:\Users\User\source\repos\oop_lab3_3\Libary\IntVector.h"  

using namespace P3_1;

int main() {
    std::cout << "Hello, what do you want?" << std::endl;
    IntVector a;
    IntVector b;
        
    const char* msgs[] = { "0. Quit", "1. Create empty vector", "2. Create 1 element vector", "3. Create normal vector" };
    int d, m = 1;
    while (m) {
        for (int i = 0; i < 4; i++) {
            std::cout << msgs[i] << std::endl;
        }
        P3_1::getNum(d);

        switch (d) {
        case 0:
            std::cout << "Bye" << std::endl;
            return 0;                                                          // exit
        case 1: {
            IntVector c;  
            a = c;                                                             // default constructor
            m = 0;
            break;
        }
        case 2:
        {
            int el;
            std::cout << "Enter element: ";
            getNum(el);
            IntVector c(el);
            a = c;                                                             // 1 element constructor 
            m = 0;
            break;
        }
        case 3:
        {
            int s;
            std::cout << "How many elements you want to add?";
            getNum(s);
            int* els = new int[s];
            int el1;
            for (int i = 0; i < s; i++) {
                std::cout << "Enter element: ";
                getNum(el1);
                els[i] = el1;
            }
            try {
                IntVector c(s, els);  
                a = c;// elements massive constructor
                m = 0;
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
            break;
        }
        default:
            std::cout << "Error!" << std::endl;
            continue;
        }
    }

    int CV = 1;
    const char* msgs1[] = { "0. Quit", "1. Change vector", "2. Print vector", "3. Sum vectors",
    "4. Part of the vector", "5. Add element", "6. Sort vector", "7. Max element", "8. Add new vector" };

    while (1) {
        std::cout << std::endl << "Current vector is [" << CV << "], What do you want?" << std::endl;
        for (int i = 0; i < 9; i++) {
            std::cout << msgs1[i] << std::endl;
        }
        P3_1::getNum(d);

        switch (d) {
        case 0:
            std::cout << "Bye" << std::endl;
            return 0;                                                          // exit
        case 1:
        {  
            CV = -CV;
            continue;
        }
        case 2:
        {
            if(CV==1)
                std::cout << "Current vector elements: \n" << a;                // using overloaded <<
            else
                std::cout << "Current vector elements: \n" << b;

            continue;
        }
        case 3:
        {
            if (CV == 1)
                a += b;
            else
                b += a;
                                                                                // using overloaded +=
            std::cout << "Success" << std::endl;
            continue;
        }
        case 4:
        {
            int s;
            std::cout << "Enter start element: ";
            getNum(s);
            int l;
            std::cout << "Enter len: ";
            getNum(l);
            try {
                if(CV==1)
                    a.print(std::cout, s, l);                                   // print part of a vector with given length 
                else
                    b.print(std::cout, s, l);
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
            continue;
        }
        case 5:
        {
            int e;
            std::cout << "Enter element: ";
            getNum(e);
            if (CV == 1)
                a.addEl(e);
            else
                b.addEl(e);
            continue;
        }
        case 6:
        {
            try {
                if (CV == 1)
                    a.sort(0, a.getCSz() - 1);                                   // quicksort vector   
                else
                    b.sort(0, b.getCSz() - 1);
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
            std::cout << "Success" << std::endl;
            continue;
        }
        case 7:
        {
            try {
                if (CV == 1)
                    std::cout << "Max element in current vector: " << a.maxNum() << std::endl;
                else
                    std::cout << "Max element in current vector: " << b.maxNum() << std::endl;
            }                                                               // finding maximum element       
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
            continue;
        }
        case 8:
        {
            m = 1;
            while (m) {
                for (int i = 0; i < 4; i++) {
                    std::cout << msgs[i] << std::endl;
                }
                P3_1::getNum(d);

                switch (d) {
                case 0:
                    std::cout << "Bye" << std::endl;
                    return 0;                                                          // exit
                case 1: {
                    IntVector c;
                    b = c;                                                             // default constructor
                    m = 0;
                    break;
                }
                case 2:
                {
                    int el;
                    std::cout << "Enter element: ";
                    getNum(el);
                    IntVector c(el);
                    b = c;                                                             // 1 element constructor   
                    m = 0;
                    break;
                }
                case 3:
                {
                    int s;
                    std::cout << "How many elements you want to add?";
                    getNum(s);
                    int* els = new int[s];
                    int el1;
                    for (int i = 0; i < s; i++) {
                        std::cout << "Enter element: ";
                        getNum(el1);
                        els[i] = el1;
                    }
                    try {
                        IntVector c(s, els);
                        b = c;                                                         // elements massive constructor
                        m = 0;
                    }
                    catch (std::exception& ex) {
                        std::cout << ex.what() << std::endl;
                    }
                    break;
                }
                default:
                    std::cout << "Error!" << std::endl;
                    continue;
                }
            }
            continue;
        }
        default:
            std::cout << "Error!" << std::endl;
            continue;
        }
    }
    _CrtDumpMemoryLeaks();
    return 0;
}
