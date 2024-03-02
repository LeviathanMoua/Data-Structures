/*
Program name : MouaJustin_Homework3.cpp
Author       : Justin Moua
Professor    : Pu Cong
Course       : CS 3353 | Data Structures and Algorithms
Date         : 4 May 2024
Description  : Refer to instructions provided by professor.
*/

#include <iostream>
#include <string>
#include <list>

//Generic stack, primarily will be using STRING in main func.
template<class T>
class LLStack {
public:
    LLStack() {
    }
    void clear() {
        genList.clear();
    }
    bool isEmpty() const {
        return genList.empty();
    }
    T& topEl() {
        return genList.back();
    }
    T pop() {
        T el = genList.back();
        genList.pop_back();
        return el;
    }
    void push(const T& el) {
        genList.push_back(el);
    }
private:
    std::list<T> genList;
};


int main(){

    LLStack<std::string> strLLStack;


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
            if (intWhiteSpcLoc == -1 && strUsrInp.length() == 1 && strUsrInp == "3") {
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

            //push into stack
            while (intRHSUsrInp != 0) {
                //std::cout << intRHSUsrInp % 2
                //Creates temporary string to grab the modulos result and push into the stack.
                std::string strTemp = std::to_string(intRHSUsrInp % 2);
                strLLStack.push(strTemp);

                intRHSUsrInp = intRHSUsrInp / 2;
            }

            //pops the stack
            while (strLLStack.isEmpty() == false) {
                std::cout << strLLStack.pop() << " ";
            }
            std::cout << std::endl << std::endl;
        }
        
        //Octal Conversion
        else if (strLHSUsrInp == "1") {

            //push into stack
            while (intRHSUsrInp != 0) {
                //std::cout << intRHSUsrInp % 8;
                //Creates temporary string to grab the modulos result and push into the stack.
                std::string strTemp = std::to_string(intRHSUsrInp % 8);
                strLLStack.push(strTemp);

                intRHSUsrInp = intRHSUsrInp / 8;

            }
            //pop stack
            while (strLLStack.isEmpty() == false) {
                std::cout << strLLStack.pop() << " ";
            }
            std::cout << std::endl << std::endl;
        }

        //Hexadecimal Conversion~~
        else if (strLHSUsrInp == "2") {

            //PUSH
            while (intRHSUsrInp != 0) {

                //First 6 if statements checks for chars A-F since they are equivalent to the numbers resulted from performing a modulous. 
                if (intRHSUsrInp % 16 == 10) {
                    strLLStack.push("A");
                    //std::cout << "A";
                }
                else if (intRHSUsrInp % 16 == 11) {
                    strLLStack.push("B");
                    //std::cout << "B";
                }
                else if (intRHSUsrInp % 16 == 12) {
                    strLLStack.push("C");
                    //std::cout << "C";
                }
                else if (intRHSUsrInp % 16 == 13) {
                    strLLStack.push("D");
                    //std::cout << "D";
                }
                else if (intRHSUsrInp % 16 == 14) {
                    strLLStack.push("E");
                    //std::cout << "E";
                }
                else if (intRHSUsrInp % 16 == 15) {
                    strLLStack.push("F");
                    //std::cout << "F";
                }
                //Otherwise if 0-9, push no need to push any letters. 
                else {
                    std::string strTemp = std::to_string(intRHSUsrInp % 16);
                    strLLStack.push(strTemp);
                }

                intRHSUsrInp = intRHSUsrInp / 16;

            }

            //POP
            while (strLLStack.isEmpty() == false) {
                std::cout << strLLStack.pop() << " ";
            }

            std::cout << std::endl << std::endl;
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
