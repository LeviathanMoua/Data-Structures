/*
Program name : MouaJustin_Homework4.cpp
Author       : Justin Moua
Professor    : Pu Cong
Course       : CS 3353 | Data Structures and Algorithms
Due Date     : 25 Mar. 2024
Description  : Refer to instructions provided by professor.
*/

#include <iostream>
#include <string>
#include <stack>
//#include <queue> //Ended up not needing this. 


/*Failed attempt at searching through.
void vdFnSearchDiscovery1(int** arr, int m, int n)
{   //i = rows
    //j = col
    //

    int intMaxCellSearch = (m + n) - 1;
    int intMinCellSearch;

    if (m > n)
        intMinCellSearch = m;
    else if (n > m)
        intMinCellSearch = n;
    else //This is if m = n
        intMinCellSearch = m;

    for (int i = 0; i < m; i++) {
        std::cout << arr[i][0] << " ";
        if (i == m - 1) {
            for (int j = 1; j < n; j++)
                std::cout << arr[i][j] << " ";
        }
    }


}
*/


void vdFnSearchDiscovery(int** Pt2Pt2Int_2DArr, std::stack<int>& stckIntDiscPath, int m, int n, int intMaxRows, int intMaxCols);

int main() {

    int intRows = 0, intCols = 0;
    std::cout << "\n==============================================================\n\nAssignment: Homework #4\nAuthor of Program: Justin moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";

    bool boolQuit = true;
    while (boolQuit) {

        std::string strUsrInp; //Used to store an entire line of input from the user.
        int intTest = 0;
        std::string strLHSUsrInp; //Stores the left hand side of input.
        std::string strRHSUsrInp; //Stores the right hand side of input. 


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

        //int intRHSUsrInp = std::stoi(strRHSUsrInp);
        //Horz. Axis
        if (strLHSUsrInp == "0" && intWhiteSpcLoc >= 0) {

            std::cout << "Performing Horizontal Axis option...";
            std::cout << std::endl << std::endl;

            //std::cout << "Enter the number of rows: "; //I don't actually need this. strRHSUsrInp already has their input. 
            intRows = std::stoi(strRHSUsrInp);

            std::cout << std::endl << std::endl;
        }

        //Vert. Axis
        else if (strLHSUsrInp == "1" && intWhiteSpcLoc >= 0) {

            std::cout << "Performing Vertical Axis option...";
            std::cout << std::endl << std::endl;

            //std::cout << "Enter the number of columns: "; //I don't actually need this. strRHSUsrInp already has their input. 
            intCols = std::stoi(strRHSUsrInp);

            std::cout << std::endl << std::endl;
        }

        //Start Discovery (For now as of 11 Mar. 2024 2:58 PM, it only creates a matrix)
        else if (strLHSUsrInp == "2" && intWhiteSpcLoc == -1) {

            std::cout << "Performing Start Discovery...";
            std::cout << std::endl;

            //=========================M x N ARRAY CREATION================M x N ARRAY CREATION================
            //Creates a pointer to pointer to integer
            //(pointer points to a pointer that points to an integer.)
            int** a2d = new int* [intRows]; //Memory allocation for rows

            for (int j = 0; j < intRows; j++) {
                a2d[j] = new int[intCols]; //Memory allocation for columns
            }

            //Creation of a m x n matrix
            for (int i = 0; i < intRows; i++) {
                for (int j = 0; j < intCols; j++) {
                    a2d[i][j] = (i * intCols + j) + 1;
                    //a2d[i][j] = (i + i) + (j+1); Failed Attempt.
                }
            }
            //=========================M x N ARRAY CREATION================M x N ARRAY CREATION================

            //=========================SEARCH DISCOVERY=======================SEARCH DISCOVERY=======================
            std::stack<int> stckIntDiscPath; //This works better instead of putting into function because it will be manipulated outside the scope of it

            //Parameters are (2D array, discovery path, current m location, current n location, max rows, max cols)
            vdFnSearchDiscovery(a2d, stckIntDiscPath, 0, 0, intRows, intCols); //This function outputs the array instead. As opposed to the test one below. 
            //=========================SEARCH DISCOVERY=======================SEARCH DISCOVERY=======================


            //Test if array is outputted correctly no matter the m x n dimensions.

            /*
            //Outputs string for debugging
            for (int i = 0; i < intRows; i++) {
                for (int j = 0; j < intCols; j++) {
                    std::cout << a2d[i][j] << " ";
                }
                std::cout << std::endl;
            }
            */



            std::cout << std::endl << std::endl;
        }
        //Invalid Input
        else {
            std::cout << "==============\nInvalid Input!\n==============\n\nPlease try again! You can only enter numbers from 0-3.";
            std::cout << std::endl << std::endl;
        }

        //Testing to see if intRows and intCols are global. 
        //std::cout << "Rows: " << intRows << std::endl << "Columns: " << intCols;
        //std::cout << std::endl;

    }

    std::cout << std::endl << std::endl;
    return 0;
}


void vdFnSearchDiscovery(int** Pt2Pt2Int_2DArr, std::stack<int>& stckIntDiscPath, int m, int n, int intMaxRows, int intMaxCols)
{


    stckIntDiscPath.push(Pt2Pt2Int_2DArr[m][n]); //Everytime the function is invoked, we want to push it into the stack from the main funciton. 

    //Depending on if the function being invoked has reached BOTTOM RIGHT no matter what matrices is given, 
    //it will then output the search discovery by creating a temporary stack and reversing it. 
    if (m == intMaxRows - 1 && n == intMaxCols - 1) {
        std::stack<int> stckTemp = stckIntDiscPath; //Created this since I don't want to get rid of what is actually in the stack we are using
        std::stack<int> stckRevTemp; //This should reverse stack I think. 
        //std::queue<int> qTemp; //Failed attempt at reversing stack. 

        //Reverses stack
        while (!stckTemp.empty()) {
            stckRevTemp.push(stckTemp.top()); //.top() instead of .pop() since .pop() doesn't go into .push(). .pop() doesn't return anything I think. 
            stckTemp.pop();
        }


        while (!stckRevTemp.empty()) {
            std::cout << stckRevTemp.top() << " ";
            stckRevTemp.pop();
        }

        std::cout << std::endl;
    }


    else {
        if (m + 1 < intMaxRows)
            //Downward path. Checks to see if we have reached the bottom. If so, move onwards to move right. 
            //In other cases however when the function goes back, it will just move right instead of reaching the bottom. 
            vdFnSearchDiscovery(Pt2Pt2Int_2DArr, stckIntDiscPath, m + 1, n, intMaxRows, intMaxCols);

        if (n + 1 < intMaxCols)
            //Rightward path movement. Checks to see if we have reached the rightmost part of the matrix. 
            //A bit of same reasoning as the one above. 
            vdFnSearchDiscovery(Pt2Pt2Int_2DArr, stckIntDiscPath, m, n + 1, intMaxRows, intMaxCols);

        if (m + 1 < intMaxRows && n + 1 < intMaxCols)
            //This moves diagonally and has a similar reasoning as the ones above. 
            vdFnSearchDiscovery(Pt2Pt2Int_2DArr, stckIntDiscPath, m + 1, n + 1, intMaxRows, intMaxCols);
    }

    // backtrack: remove the current cell from the stckIntDiscPath
    stckIntDiscPath.pop();
}

