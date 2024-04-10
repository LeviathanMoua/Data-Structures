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
#include <queue>
class classCheckUsrInp {

private:
    std::string strLHS;
    std::string strRHS;

public:
    classCheckUsrInp() {
        strLHS = "";
        strRHS = "";
    }
    void vdFnSplitUsrInp(std::string inputStr) {
        int intTempEl = 0;
        //std::string strLHS; //This is what was causing me the issue! It created a local variant
        //std::string strRHS;
        //Checks to see if the string is empty or not. 
        if (inputStr.length() != 0) {

            
            // Iterate through the string until a space is found or EOL.
            while (true) {
                if (inputStr[intTempEl] == ' ' || inputStr[intTempEl] == '\0') {
                    break;
                }
                else {
                    strLHS = strLHS + inputStr[intTempEl];
                    //std::cout << inputStr[intTempEl]; //Used to check if strLHS was properly founded. DEBUGGER
                    intTempEl++;
                }

            }
            //std::cout << std::endl; //Delete this after debugging
        }

        intTempEl++; //This is to skip the whitespace that it stopped on. DO NOT DELETE. THIS IS NECESSARY

        //Checks to see if there is a RHS by checking if
        //intTempEl's value matches the max length of the entire input string. 
        if (intTempEl != inputStr.length()) {
            //Starts at the place it left and ends when it reaches the end of the string. 
            while (intTempEl < inputStr.size()) {
                strRHS = strRHS + inputStr[intTempEl];
                //std::cout << inputStr[intTempEl]; //Used to check if strRHS was properly founded. DEBUGGER
                intTempEl++;
            }
            std::cout << std::endl; //Delete this after debugging
        }
        //std::cout << "strLHS is: " << strLHS << std::endl;
        //std::cout << "strRHS is: " << strRHS << std::endl;
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

    //Maybe this is where I will put the BST Tree object so that it's scope is the entire main function. 

    while (true) {
        std::string strWholeString;
        std::string strLHS;
        std::string strRHS;

        std::string strTempRHSEl; //Used to temporarily store an element of the original RHS input
        int intTempRHSEl; //Used to temporarily store strTempRHSEl. It takes the stoi of strTempRHSEl. 

        std::queue<int> myQueue; //Used for option 0. 

        classCheckUsrInp userInputProcessor; //Used to split the user's input in half. 

        std::cout << "Create (0), Search (1), Breadth-First Traversal (2)\nDepth - First Traversal : preorder(3), inorder(4), postorder(5)\nExit Program(6)";
        std::cout << std::endl << std::endl;
        std::cout << "Choose? ";
        std::getline(std::cin, strWholeString);
        std::cout << std::endl;


        //std::cout << "Your entire string is: " << strWholeString; //DEBUGGER
        //std::cout << std::endl << std::endl; //DEBUGGER

        userInputProcessor.vdFnSplitUsrInp(strWholeString);

        if (!userInputProcessor.LHSisEmpty() && !userInputProcessor.RHSisEmpty()) {
            strLHS = userInputProcessor.getLHS();
            strRHS = userInputProcessor.getRHS();

            /*
            std::cout << "LHS of your string is: " << strLHS;
            std::cout << std::endl << std::endl;

            std::cout << "RHS of your string is: ";

            //This for loop makes sure that the class we implemented is properly working and splitting the input.
            for (int i = 0; i < strRHS.size(); i++) {
                if (i == strRHS.size() - 1) {
                    std::cout << strRHS[i] << ".";
                }
                else {
                    std::cout << strRHS[i] << ",";
                }
            }
            */
        }
        else if (!userInputProcessor.LHSisEmpty() && userInputProcessor.RHSisEmpty()) {
            strLHS = userInputProcessor.getLHS();
        }


        if (strLHS == "0") {
            //Create a temp string for RHS
            //Concatonate the string with whatever 
            for (int i = 0; i < strRHS.size(); i++) {

                //If whitespace is note reached
                if (strRHS[i] != ' ') {
                    strTempRHSEl = strTempRHSEl + strRHS[i]; //Concats elements of RHS together not including whitespace
                }

                //when whitespace reached or EOS is reached
                else {
                    intTempRHSEl = std::stoi(strTempRHSEl); //Convert the concat string to a 
                    myQueue.push(intTempRHSEl);
                    strTempRHSEl = ""; //resets strTempRHSEl to grab new int
                }

            }
            /*
            //I wouldn't need these 3 lines of code below if I could figure out
            //why the else function in the for loop above is not executing for
            // the last "element" of the string. For example,
            //the for loop above does the following:
            //Loop through strRHS which contains a string input of a list of numbers such as
            //12 3 4. I wanted to put each number individually into a queue
            //so I parsed through each CHARACTER in the string.
            //I parse and concat the characters together with a temporary string
            //variable until I reach a whitespace. Once the whitespace is reached,
            //then I can turn that temp string into a temp int var
            //then I can push the temp int var into the queue
            //and reset both the temp variables.
            //Unfortunately though, this does not work
            //for when I have reached the last bit of concatenated characters.
            //So instead I copy and pasted the same code and put it below.
            */
            intTempRHSEl = std::stoi(strTempRHSEl); //Convert the concat string to a int
            myQueue.push(intTempRHSEl);
            strTempRHSEl = ""; //resets strTempRHSEl to grab new int

            std::cout << "Your RHS in a queue: ";
            std::cout << std::endl << std::endl;
            // Dequeue elements from the queue and display them
            while (!myQueue.empty()) {
                std::cout << "Dequeuing: " << myQueue.front() << std::endl;
                myQueue.pop();
            }

            std::cout << std::endl << std::endl;
        }
        else if (strLHS == "1") {
            //====================PUSHING USER INPUTTED LIST INTO QUEUE====================PUSHING USER INPUTTED LIST INTO QUEUE====================
            intTempRHSEl = std::stoi(strRHS); //Convert the concat string to a 
            myQueue.push(intTempRHSEl);
            std::cout << "You chose option #" << strLHS;
            std::cout << std::endl;

            while (!myQueue.empty()) {
                std::cout << "Dequeuing: " << myQueue.front() << std::endl;
                myQueue.pop();
            }
            std::cout << std::endl << std::endl;
            //====================PUSHING USER INPUTTED LIST INTO QUEUE====================PUSHING USER INPUTTED LIST INTO QUEUE====================
        

            //Use the queue to build a tree (might need to create an object of a Binary Tree instance or something)

        }

        else if (strLHS == "2") {
            std::cout << "You chose option #" << strLHS;
            std::cout << std::endl;
        }

        else if (strLHS == "3") {
            std::cout << "You chose option #" << strLHS;
            std::cout << std::endl;
        }

        else if (strLHS == "4") {
            std::cout << "You chose option #" << strLHS;
            std::cout << std::endl;
        }

        else if (strLHS == "5") {
            std::cout << "You chose option #" << strLHS;
            std::cout << std::endl;
        }

        else if (strLHS == "6") {
            std::cout << "You chose option #" << strLHS << " and thus the program will quit.";
            std::cout << std::endl;
            break;
        }

        /*
        //These were created for me to refresh on empty strings. I wanted to check and see if these could recognize
        //"" or '\0'. are for pure empty inputs.
        if (strWholeString.empty()) {
            std::cout << ".empty() says your string is empty!: " << strWholeString;
            std::cout << std::endl;
        }


        if (strWholeString == "") {
            std::cout << "strWholeString == "" says your string is empty!: " << strWholeString;
            std::cout << std::endl;
        }

        if (strWholeString[0] == '\0') {
            std::cout << "strWholeString[0] == '\\0' says your string is empty!: " << strWholeString;
            std::cout << std::endl;
        }

        if (strWholeString != " ") {
            std::cout << "strWholeString == " " says your string IS NOT empty!: " << strWholeString;
            std::cout << std::endl;
        }
        */
    }

    return 0;
}
