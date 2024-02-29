/*
Program name : MouaJustin_Homework3.cpp
Author       : Justin Moua
Professor    : Pu Cong
Course       : CS 3353 | Data Structures and Algorithms
Date         : 4 Mayebruary 2024
Description  : Refer to instructions provided by professor.
*/

#include <iostream>
#include <string>

//**********************  genListStack.h  *************************
//     generic stack defined as a doubly linked list

#ifndef LL_STACK
#define LL_STACK

#include <list>

template<class T>
class LLStack {
public:
    LLStack() {
    }
    void clear() {
        lst.clear();
    }
    bool isEmpty() const {
        return lst.empty();
    }
    T& topEl() {
        return lst.back();
    }
    T pop() {
        T el = lst.back();
        lst.pop_back();
        return el;
    }
    void push(const T& el) {
        lst.push_back(el);
    }
private:
    list<T> lst;
};

#endif


int main(){

    LLStack<std::string> tempTest;


    std::cout << "\n==============================================================\n\nAssignment: Homework #3\nAuthor of Program: Justin moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";

    bool boolQuit = true;
    while (boolQuit) {

        std::string strUsrInp; //Used to store an entire line of input from the user.

        //Take user's input
        std::cout << "====\nMenu\n====\n\nBinary (0), Octal (1), Hexadecimal (2)\nExit Program (3)\n\nChoose: ";
        std::getline(std::cin, strUsrInp);
        std::cout << std::endl;

        //Binary Conversion
        if (strUsrInp == "0") {
            std::cout << "Performing Binary Conversion! (This is just a spacer. Delete after implementing the respective function)";
            std::cout << std::endl << std::endl;
        }
        
        //Octal Conversion
        else if (strUsrInp == "1") {
            std::cout << "Performing Octal Conversion! (This is just a spacer. Delete after implementing the respective function)";
            std::cout << std::endl << std::endl;
        }

        //Hexadecimal Conversion
        else if (strUsrInp == "2") {
            std::cout << "Performing Hexadecimal Conversion! (This is just a spacer. Delete after implementing the respective function)";
            std::cout << std::endl << std::endl;
        }

        //Quit
        else if (strUsrInp == "3") {
            break;
        }

        //Invalid Input
        else {
            std::cout << "==============\nInvalid Input!\n==============\n\nPlease try again! You can only enter numbers from 0-3.";
            std::cout << std::endl << std::endl;
        }

    }

    std::cout << std::endl << std::endl;
    return 0;
}
