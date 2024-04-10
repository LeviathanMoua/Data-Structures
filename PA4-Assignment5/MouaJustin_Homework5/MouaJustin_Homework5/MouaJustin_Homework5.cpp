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

        // Iterate through the string until a space is found
        while (inputStr[intTempEl] != ' ') {
            strLHS = strLHS + inputStr[intTempEl];
            //std::cout << inputStr[intTempEl]; //Used to check if strRHS was properly founded. DEBUGGER
            intTempEl++;
        }

        intTempEl++; //This is to skip the whitespace that it stopped on. Hopefully it works!

        //Starts at the place it left and ends when it reaches the end of the string. 
        while (intTempEl < inputStr.size()) {
            strRHS = strRHS + inputStr[intTempEl];
            //std::cout << inputStr[intTempEl]; //Used to check if strRHS was properly founded. DEBUGGER
            intTempEl++;
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

/*
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
*/

int main() {

    std::cout << "\n==============================================================\n\nAssignment: Homework #5\nAuthor of Program: Justin Moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";

    std::string strWholeString;
    std::string strLHS;
    std::string strRHS;

    std::string strTempRHSEl;
    int intTempRHSEl;

    classCheckUsrInp userInputProcessor;

    std::cout << "Enter your input here: ";
    std::getline(std::cin, strWholeString);
    std::cout << std::endl;

    std::cout << "Your entire string is: " << strWholeString;
    std::cout << std::endl << std::endl;

    userInputProcessor.vdFnSplitUsrInp(strWholeString);
    strLHS = userInputProcessor.getLHS();
    strRHS = userInputProcessor.getRHS();



    
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
    

    //Create a temp string for RHS
    //Concatonate the string with whatever 
    int arr[3];//Will need to delete this after I implement a queue
    int arrTemp = 0; //Will need to delete this after I implement a queue
    for (int i = 0; i < strRHS.size(); i++) {

        //If whitespace is note reached
        if (strRHS[i] != ' ') {
            strTempRHSEl = strTempRHSEl + strRHS[i]; //Concats elements of RHS together not including whitespace
        }

        //when whitespace reached or EOS is reached
        else {
            intTempRHSEl = std::stoi(strTempRHSEl); //Convert the concat string to a int 
            arr[arrTemp] = intTempRHSEl;//Inputs int into a queue since it is FIFO. //Will need to delete this after I implement a queue
            arrTemp = arrTemp + 1; //Will need to delete this after I implement a queue
            strTempRHSEl = ""; //resets strTempRHSEl to grab new int
        }

    }

    intTempRHSEl = std::stoi(strTempRHSEl); //Convert the concat string to a int
    arr[arrTemp] = intTempRHSEl;//Inputs int into a queue since it is FIFO. //Will need to delete this after I implement a queue
    arrTemp = arrTemp + 1; //Will need to delete this after I implement a queue
    strTempRHSEl = ""; //resets strTempRHSEl to grab new int

    //prints out the array just to make sure that it's correct. //Will need to delete this after I implement a queue
    std::cout << "arrTemp size: " << arrTemp;
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "arr[" << i << "]: " << arr[i];
        std::cout << std::endl;
    }

    std::cout << std::endl;

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
    return 0;
}
