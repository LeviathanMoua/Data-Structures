/*
Program name : MouaJustin_Homework4.cpp
Author       : Justin Moua
Professor    : Pu Cong
Course       : CS 3353 | Data Structures and Algorithms
Due Date         : 25 Mar. 2024
Description  : Refer to instructions provided by professor.
*/

#include <iostream>
#include <string>

int main() {


    std::cout << "\n==============================================================\n\nAssignment: Homework #4\nAuthor of Program: Justin moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";

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
        std::cout << "====\nMenu\n====\n\nHorizontal Axis (0), Vertical Axis (1), Start Discovery (2)\nExit Program (3)\n\nChoose: ";
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

            std::cout << "Performing Horizontal Axis option...";

            std::cout << std::endl << std::endl;
        }

        //Octal Conversion
        else if (strLHSUsrInp == "1") {

            std::cout << "Performing Vertical Axis option...";

            std::cout << std::endl << std::endl;
        }

        //Hexadecimal Conversion~~
        else if (strLHSUsrInp == "2") {

            std::cout << "Performing Start Discovery...";

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
