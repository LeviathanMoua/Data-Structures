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

/*
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
*/

int main(){

    //LLStack<int> tempTest;


    std::cout << "\n==============================================================\n\nAssignment: Homework #3\nAuthor of Program: Justin moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";

    bool boolQuit = true;
    while (boolQuit) {

        std::string strUsrInp; //Used to store an entire line of input from the user.
        int intTest = 0;
        std::string strLHSUsrInp; //Stores the left hand side of input 
        std::string strRHSUsrInp;

        //===========IMPORTANT=============IMPORTANT=============IMPORTANT==========
        //CREATE AN INPUT THAT GRABS LHS AND RHS
        //===========IMPORTANT=============IMPORTANT=============IMPORTANT==========

        //Take user's input
        std::cout << "====\nMenu\n====\n\nBinary (0), Octal (1), Hexadecimal (2)\nExit Program (3)\n\nChoose: ";
        std::getline(std::cin, strUsrInp);
        std::cout << std::endl;

        //=================TAKING USER INPUT STARTS HERE=================TAKING USER INPUT STARTS HERE=================TAKING USER INPUT STARTS HERE=================
        //==============CHECKS 4 WHITESPACE==========

        bool boolWhiteSpcDetec = false; //set to false if there is no white space. If there is white space, then it is true. 
        int intWhiteSpcLoc = -1; // if < 0, then there is no white space. >= 0 means there is white space in user's input. 
        //If input is not empty
        if (strUsrInp.length() > 0) {
            //Parse through array and check if there is a whitespace
            for (int i = 0; i < strUsrInp.length(); i++) {
                if (isspace(strUsrInp[i])) {
                    intWhiteSpcLoc = i;
                }
            }

            //QUITS THE PROGRAM 
            if (intWhiteSpcLoc == -1 && strUsrInp.length() == 2 && strUsrInp == "12") {
                std::cout << "Click enter to quit the program.";
                std::cout << std::endl;
                break;
            }

            //if whitespace is detected
            else if (intWhiteSpcLoc > 0) {
                //Grabs LHS of user input
                for (int i = 0; i < intWhiteSpcLoc; i++) {
                    strLHSUsrInp = strLHSUsrInp + strUsrInp[i];
                }

                //Grabs RHS of user input
                //int i = intWhiteSpcLoc +1 because int i = intWhiteSpcLoc would INCLUDE the whitespace.
                for (int i = intWhiteSpcLoc + 1; i < strUsrInp.length(); i++) {
                    strRHSUsrInp = strRHSUsrInp + strUsrInp[i];
                }

                //==============Outputs LHS and RHS of string========DEBUGGER
                /*
                std::cout << "LHS is: " << strLHSUsrInp;
                std::cout << std::endl;
                std::cout << "RHS is: " << strRHSUsrInp;
                std::cout << std::endl;
                */
            }
            //If no whitespace
            else if (intWhiteSpcLoc == -1) {
                //Grabs LHS of user input
                for (int i = 0; i < strUsrInp.length(); i++) {
                    strLHSUsrInp = strLHSUsrInp + strUsrInp[i];
                }
            }
        }
        //If input is empty
        else {
            std::cout << "==============\nInvalid input!\n==============\n\nPlease try again." << std::endl;
        }

        //=================TAKING USER INPUT ENDS HERE=================TAKING USER INPUT ENDS HERE=================TAKING USER INPUT ENDS HERE=================

        int intRHSUsrInp = std::stoi(strRHSUsrInp);
        //Binary Conversion
        if (strLHSUsrInp == "0") {

            //this works but note that it is in reverse. Need to concatonate. 
            //This converts decimal to binary. 
            while (intRHSUsrInp != 0) {
                std::cout << intRHSUsrInp % 2;


                intRHSUsrInp = intRHSUsrInp / 2;

            }

            std::cout << std::endl << std::endl;
        }
        
        //Octal Conversion
        else if (strLHSUsrInp == "1") {

            while (intRHSUsrInp != 0) {
                std::cout << intRHSUsrInp % 8;


                intRHSUsrInp = intRHSUsrInp / 8;

            }

            std::cout << std::endl << std::endl;
        }

        //Hexadecimal Conversion~~
        else if (strLHSUsrInp == "2") {

            while (intRHSUsrInp != 0) {


                if (intRHSUsrInp % 16 == 10) {
                    std::cout << "A";
                }
                else if (intRHSUsrInp % 16 == 11) {
                    std::cout << "B";
                }
                else if (intRHSUsrInp % 16 == 12) {
                    std::cout << "C";
                }
                else if (intRHSUsrInp % 16 == 13) {
                    std::cout << "D";
                }
                else if (intRHSUsrInp % 16 == 14) {
                    std::cout << "E";
                }
                else if (intRHSUsrInp % 16 == 15) {
                    std::cout << "F";
                }
                else {
                    std::cout << intRHSUsrInp % 16;
                }

                intRHSUsrInp = intRHSUsrInp / 16;

            }

            std::cout << std::endl << std::endl;
        }

        //Quit
        else if (strLHSUsrInp == "3") {
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
