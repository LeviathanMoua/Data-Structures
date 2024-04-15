/*
Program name : Bonus_MouaJustin_Homework5.cpp
Author       : Justin Moua
Professor    : Pu Cong
Course       : CS 3353 | Data Structures and Algorithms
Due Date     : 17 Apr. 2024
Description  : Refer to instructions provided by professor.
*/

#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

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

    bool LHSisEmpty() {
        return strLHS.empty();
    }
    bool RHSisEmpty() {
        return strRHS.empty();
    }

    std::string getLHS() {
        return strLHS;
    }

    std::string getRHS() {
        return strRHS;
    }
};

template<class T>
class BSTNode {
public:
    BSTNode() {
        left = right = nullptr;
    }
    BSTNode(const T& e, BSTNode<T>* l = nullptr, BSTNode<T>* r = nullptr) {
        el = e; left = l; right = r;
    }
    T el;
    BSTNode<T>* left, * right;
};

template<class T>
class BST {
private:
    BSTNode<T>* root;

    //Insertion - Option 0
    BSTNode<T>* insert(BSTNode<T>* ptr, T value) {
        if (ptr == nullptr)
            return new BSTNode<T>(value);

        if (value < ptr->el)
            ptr->left = insert(ptr->left, value);
        else if (value > ptr->el)
            ptr->right = insert(ptr->right, value);

        return ptr;
    }

    //Search - Option 1
    bool search(BSTNode<T>* ptr, T value) {
        if (ptr == nullptr)
            return false;

        if (ptr->el == value)
            return true;
        else if (value < ptr->el)
            return search(ptr->left, value);
        else
            return search(ptr->right, value);
    }



public:
    BST() {
        root = nullptr;
    }

    // Insertion Constructor - Option 0
    void insert(T value) {
        root = insert(root, value);
    }

    // Search Constructor- Option 1
    bool search(T value) {
        return search(root, value);
    }

    // Breadth First Traversal - Option 2
    void breadthFirstTraversal() {
        if (root == nullptr)
            return;

        std::queue<BSTNode<T>*> ptrToBSTNodeQueue;
        ptrToBSTNodeQueue.push(root);

        while (!ptrToBSTNodeQueue.empty()) {
            BSTNode<T>* ptr = ptrToBSTNodeQueue.front();
            ptrToBSTNodeQueue.pop();
            std::cout << ptr->el << " ";

            if (ptr->left != nullptr)
                ptrToBSTNodeQueue.push(ptr->left);
            if (ptr->right != nullptr)
                ptrToBSTNodeQueue.push(ptr->right);
        }
    }

    //======================DEPTH FIRST TRAVERSAL FUNCTIONS=================DEPTH FIRST TRAVERSAL FUNCTIONS=================
    //DFT Preorder - Option 3
    void preorder(BSTNode<T>* ptr) {
        if (ptr != nullptr) {
            std::cout << ptr->el << " ";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }

    //Inorder - Option 4
    void inorder(BSTNode<T>* ptr) {
        if (ptr != nullptr) {
            inorder(ptr->left);
            std::cout << ptr->el << " ";
            inorder(ptr->right);
        }
    }

    //Postorder - Option 5
    void postorder(BSTNode<T>* ptr) {
        if (ptr != nullptr) {
            postorder(ptr->left);
            postorder(ptr->right);
            std::cout << ptr->el << " ";
        }
    }
    //======================DEPTH FIRST TRAVERSAL FUNCTIONS=================DEPTH FIRST TRAVERSAL FUNCTIONS=================

    //======================DEPTH FIRST TRAVERSAL CONSTRUCTORS=================DEPTH FIRST TRAVERSAL CONSTRUCTORS=================
    
    //DFT Preorder Constructor - Option 3
    void vdFnPreorderConstructor() {
        preorder(root);
    }

    //DFT Inorder Constructor - Option 4
    void vdFnInorderConstructor() {
        inorder(root);
    }

    //DFT Postorder Constructor - Option 5
    void vdFnPostorderConstructor() {
        postorder(root);
    }
    //======================DEPTH FIRST TRAVERSAL CONSTRUCTORS=================DEPTH FIRST TRAVERSAL CONSTRUCTORS=================

    //======================DELETION STARTS HERE======================DELETION STARTS HERE======================
    //Adjusted from the given code from the textbook 
    void deleteByMerging(BSTNode<T>*& node) {
        BSTNode<T>* tmp = node;
        if (node != nullptr) {
            if (!node->right)
                node = node->left;
            else if (node->left == nullptr)
                node = node->right;
            else {
                tmp = node->left;
                while (tmp->right != nullptr)
                    tmp = tmp->right;
                tmp->right = node->right;
                tmp = node;
                node = node->left;
            }
            delete tmp;
        }
    }

    //Adjusted from the given code from the textbook as we simply can't really use the search funciton
    void findAndDeleteByMerging(const T& el) {
        BSTNode<T>* node = root, * prev = nullptr; //starts off at root and shows what the previous was.
        while (node != nullptr) { //While we have not reached the end of the bst
            if (node->el == el) //If we find what we needed then break the while loop
                break;
            prev = node; //if while loop then we set prev = node so we can switch node 
            if (el < node->el) //checks if the value we are wanting to find is < what is on the left
                node = node->left;
            else //Vice versa of the code two lines above
                node = node->right;
        }
        //If we have founded the desired value to be deleted
        if (node != nullptr && node->el == el) {
            if (node == root)
                deleteByMerging(root);
            else if (prev->left == node)
                deleteByMerging(prev->left);
            else
                deleteByMerging(prev->right);
            std::cout << el << " was deleted.";
        }
        else if (root != nullptr) //If we have searched all of the BST
            std::cout << el << " is not in the tree";
        else
            std::cout << "The tree is empty";
    }


    //======================DELETION ENDS HERE======================DELETION ENDS HERE======================

};

int main() {

    std::cout << "\n==============================================================\n\nAssignment: Homework #5 (BONUS) \nAuthor of Program: Justin Moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";
    BST<int> tree;

    while (true) {
        std::string strWholeString;
        std::string strLHS;
        std::string strRHS;

        std::string strTempRHSEl; //Used to temporarily store an element of the original RHS input
        int intTempRHSEl; //Used to temporarily store strTempRHSEl. It takes the stoi of strTempRHSEl. 

        std::queue<int> myQueue; //Used for option 0. 

        classCheckUsrInp userInputProcessor; //Used to split the user's input in half. 

        std::cout << "Create (0), Search (1), Breadth-First Traversal (2)\nDepth - First Traversal : preorder(3), inorder(4), postorder(5)\nDelete(6), Exit Program(7)";
        std::cout << std::endl << std::endl;
        std::cout << "Choose? ";
        std::getline(std::cin, strWholeString);



        //std::cout << "Your entire string is: " << strWholeString; //DEBUGGER
        //std::cout << std::endl << std::endl; //DEBUGGER

        userInputProcessor.vdFnSplitUsrInp(strWholeString);

        //If the user's LHS and RHS is not empty
        if (!userInputProcessor.LHSisEmpty() && !userInputProcessor.RHSisEmpty()) {
            strLHS = userInputProcessor.getLHS();
            strRHS = userInputProcessor.getRHS();

            /* //Debugger
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
        //If the user's lhs is not empty but the rhs is empty
        else if (!userInputProcessor.LHSisEmpty() && userInputProcessor.RHSisEmpty()) {
            strLHS = userInputProcessor.getLHS();
        }

        //===============OPTION SELECTION STARTS HERE===============OPTION SELECTION STARTS HERE===============OPTION SELECTION STARTS HERE===============
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
            Note to self: I wouldn't need these 3 lines of code below if I could figure out
            why the else function in the for loop above is not executing for
             the last "element" of the string. For example,
            the for loop above does the following:
            Loop through strRHS which contains a string input of a list of numbers such as
            12 3 4. I wanted to put each number individually into a queue
            so I parsed through each CHARACTER in the string.
            I parse and concat the characters together with a temporary string
            variable until I reach a whitespace. Once the whitespace is reached,
            then I can turn that temp string into a temp int var
            then I can push the temp int var into the queue
            and reset both the temp variables.
            Unfortunately though, this does not work
            for when I have reached the last bit of concatenated characters.
            So instead I copy and pasted the same code and put it below.
            */

            //====================PUSHING USER INPUTTED LIST INTO QUEUE====================PUSHING USER INPUTTED LIST INTO QUEUE====================
            intTempRHSEl = std::stoi(strTempRHSEl); //Convert the concat string to a int
            myQueue.push(intTempRHSEl);
            strTempRHSEl = ""; //resets strTempRHSEl to grab new int

            //std::cout << "Your RHS in a queue: "; //used for debugging
            //std::cout << std::endl << std::endl; //used for debugging
            // pop elements from the queue and display them
            while (!myQueue.empty()) {
                //std::cout << "Dequeuing: " << myQueue.front() << std::endl; //used to debug and make sure that what is dequeueing is correct!

                tree.insert(myQueue.front()); //inserts what is in the fron tof hte queue to the tree

                myQueue.pop(); //pops the queue. 
            }
            //====================PUSHING USER INPUTTED LIST INTO QUEUE====================PUSHING USER INPUTTED LIST INTO QUEUE====================

            std::cout << std::endl;
        }
        else if (strLHS == "1") {
            int intRHS = std::stoi(strRHS);

            if (tree.search(intRHS)) {
                std::cout << "Value " << intRHS << " FOUNDED in the BST.";
            }
            else {
                std::cout << "Value " << intRHS << " NOT FOUNDED in the BST.";
            }
            std::cout << std::endl << std::endl << std::endl;

        }

        else if (strLHS == "2") {
            tree.breadthFirstTraversal();
            std::cout << std::endl << std::endl << std::endl;
        }

        else if (strLHS == "3") {
            tree.vdFnPreorderConstructor();
            std::cout << std::endl << std::endl << std::endl;
        }

        else if (strLHS == "4") {
            tree.vdFnInorderConstructor();
            std::cout << std::endl << std::endl << std::endl;
        }

        else if (strLHS == "5") {
            tree.vdFnPostorderConstructor();
            std::cout << std::endl << std::endl << std::endl;
        }
        else if (strLHS == "6") {
            int intRHS = std::stoi(strRHS);
            tree.findAndDeleteByMerging(intRHS);
            std::cout << std::endl << std::endl << std::endl;

        }
        else if (strLHS == "7") {
            std::cout << "You chose option #" << strLHS << " and thus the program will quit.";
            std::cout << std::endl << std::endl << std::endl;
            break;
        }
        //===============OPTION SELECTION ENDS HERE===============OPTION SELECTION ENDS HERE===============OPTION SELECTION ENDS HERE===============

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