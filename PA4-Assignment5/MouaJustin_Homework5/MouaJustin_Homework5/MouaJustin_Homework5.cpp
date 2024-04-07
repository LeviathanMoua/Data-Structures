/*
Program name : MouaJustin_Homework5.cpp
Author       : Justin Moua
Professor    : Pu Cong
Course       : CS 3353 | Data Structures and Algorithms
Due Date     : 17 Apr. 2024
Description  : Refer to instructions provided by professor.
*/

#include <iostream>
#include <string>
#include <sstream>

class classCheckUsrInp {
private:
    std::string strLHS;
    std::string strRHS;

public:
    classCheckUsrInp(const std::string& input) {
        std::istringstream iss(input);
        iss >> strLHS >> strRHS; //if strRHS is empty, then it will be "".
    }

    bool LHSisEmpty() const {
        return strLHS.empty();
    }

    bool RHSisEmpty() const {
        return strRHS.empty();
    }

    std::string getLHS() const {
        return strLHS;
    }

    std::string getRHS() const {
        return strRHS;
    }
};

int main() {

    std::cout << "\n==============================================================\n\nAssignment: Homework #5\nAuthor of Program: Justin Moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";

    std::string strLHS;
    std::string strRHS;
    bool boolQuit = true;
    while (boolQuit) {

        std::string strUsrInp; //Used to store an entire line of input from the user.

        //Take user's input
        std::cout << "====\nMenu\n====\n\nCreate (0), Search (1), Breadth-First Traversal (2), Depth-First Traversal: preorder (3), inorder (4), postorder (5)\nExit Program (6)\n\nChoose: ";
        std::getline(std::cin, strUsrInp);
        std::cout << std::endl;

        classCheckUsrInp userInputChecker(strUsrInp);

        //if LHS and RHS is not empty.
        if (!userInputChecker.LHSisEmpty() && !userInputChecker.RHSisEmpty()) {
            strLHS = userInputChecker.getLHS();
            strRHS = userInputChecker.getRHS();
        }
        //if LHS is not empty but RHS is empty (strRHS will never be empty since iss takes in LHS firstly)
        else {
            strLHS = userInputChecker.getLHS();
        }


        //Option(0) Create
        if ((strLHS == "0") && (!userInputChecker.RHSisEmpty())) {
            std::cout << "Option " << strLHS << " has been selected";
            std::cout << std::endl;
        }
        //Option(1) Search
        else if ((strLHS == "1") && (!userInputChecker.RHSisEmpty())) {
            std::cout << "Option " << strLHS << " has been selected";
            std::cout << std::endl;
        }
        //Option(2) Breadth-First Traversal
        else if ((strLHS == "2" && userInputChecker.RHSisEmpty())) {
            std::cout << "Option " << strLHS << " has been selected.";
            std::cout << std::endl;
        }
        //Option(3) Depth-First Traversal: preorder
        else if ((strLHS == "3" && userInputChecker.RHSisEmpty())) {
            std::cout << "Option " << strLHS << " has been selected.";
            std::cout << std::endl;
        }
        //Option(4) Depth-First Traversal: inorder
        else if ((strLHS == "4" && userInputChecker.RHSisEmpty())) {
            std::cout << "Option " << strLHS << " has been selected.";
            std::cout << std::endl;
        }
        //Option(5) Depth-First Traversal: postorder
        else if ((strLHS == "5" && userInputChecker.RHSisEmpty())) {
            std::cout << "Option " << strLHS << " has been selected.";
            std::cout << std::endl;
        }
        //Option(6) Exit Program
        else if ((strLHS == "6" && userInputChecker.RHSisEmpty())) {
            std::cout << "Click enter to quit the program.";
            std::cout << std::endl;
            break;
        }
        // Invalid Input
        else {
            if ((strLHS < "0") || (strLHS > "6")) {
                std::cout << "==============\nInvalid Input!\n==============\n\nPlease try again! You can only enter numbers from 0-6.";
            }
            else if (userInputChecker.LHSisEmpty() && userInputChecker.RHSisEmpty()) {
                std::cout << "==============\nInvalid Input!\n==============\n\nPlease try again! Your input was empty.";

            }

            //For option 0 & 1 since they need a LHS and RHS input.
            else if (userInputChecker.RHSisEmpty()) {
                std::cout << "==============\nInvalid Input!\n==============\n\nPlease try again! Since you chose option " << strLHS << ". You need to have a right handed input that follows a whitespace. Example of correct input where x is another input typed by you: " << strLHS << " x";
            }

            //For options 2-6 since they DO NOT need a LHS and RHS input.
            else if (!userInputChecker.RHSisEmpty()) {
                std::cout << "==============\nInvalid Input!\n==============\n\nPlease try again! Since you chose option " << strLHS << ". You are not supposed to have a right-handed input that follows a whitespace. Example of correct input: " << strLHS;
            }
        }


        //Resets LHS and RHS of string (Maybe I don't need this because the scope of what LHS and RHS equals stays in the loop)
        //strLHS = "";
        //strRHS = "";

        std::cout << std::endl << std::endl;

    }

    std::cout << std::endl << std::endl;
    return 0;
}
