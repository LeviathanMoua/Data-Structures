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

    // Helper function for insertion
    BSTNode<T>* insert(BSTNode<T>* node, const T& value) {
        if (node == nullptr)
            return new BSTNode<T>(value);

        if (value < node->el)
            node->left = insert(node->left, value);
        else if (value > node->el)
            node->right = insert(node->right, value);

        return node;
    }

    // Helper function for searching
    bool search(BSTNode<T>* node, const T& value) {
        if (node == nullptr)
            return false;

        if (node->el == value)
            return true;
        else if (value < node->el)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    // Helper function for Preorder traversal
    void preorder(BSTNode<T>* node) {
        if (node != nullptr) {
            std::cout << node->el << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Helper function for Inorder traversal
    void inorder(BSTNode<T>* node) {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->el << " ";
            inorder(node->right);
        }
    }

    // Helper function for Postorder traversal
    void postorder(BSTNode<T>* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->el << " ";
        }
    }

public:
    BST() {
        root = nullptr;
    }

    // Insertion
    void insert(const T& value) {
        root = insert(root, value);
    }

    // Searching
    bool search(const T& value) {
        return search(root, value);
    }

    // Breadth First Traversal
    void breadthFirstTraversal() {
        if (root == nullptr)
            return;

        std::queue<BSTNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            BSTNode<T>* node = q.front();
            q.pop();
            std::cout << node->el << " ";

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }

    // Depth First Traversal (Preorder)
    void preorderTraversal() {
        preorder(root);
    }

    // Depth First Traversal (Inorder)
    void inorderTraversal() {
        inorder(root);
    }

    // Depth First Traversal (Postorder)
    void postorderTraversal() {
        postorder(root);
    }
};

int main() {

    std::cout << "\n==============================================================\n\nAssignment: Homework #5\nAuthor of Program: Justin Moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";
    BST<int> tree;

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
            //====================PUSHING USER INPUTTED LIST INTO QUEUE====================PUSHING USER INPUTTED LIST INTO QUEUE====================
            intTempRHSEl = std::stoi(strTempRHSEl); //Convert the concat string to a int
            myQueue.push(intTempRHSEl);
            strTempRHSEl = ""; //resets strTempRHSEl to grab new int

            std::cout << "Your RHS in a queue: ";
            std::cout << std::endl << std::endl;
            // pop elements from the queue and display them
            while (!myQueue.empty()) {
                std::cout << "Dequeuing: " << myQueue.front() << std::endl;

                tree.insert(myQueue.front());

                myQueue.pop();
            }
            //====================PUSHING USER INPUTTED LIST INTO QUEUE====================PUSHING USER INPUTTED LIST INTO QUEUE====================

            std::cout << std::endl << std::endl;
        }
        else if (strLHS == "1") {
            int intRHS = std::stoi(strRHS);

            if (tree.search(intRHS)) {
                std::cout << "Value " << intRHS << " found in the BST." << std::endl;
            }
            else {
                std::cout << "Value " << intRHS << " not found in the BST." << std::endl;
            }
            std::cout << std::endl << std::endl;
        

            //Use the queue to build a tree (might need to create an object of a Binary Tree instance or something)

        }

        else if (strLHS == "2") {
            tree.breadthFirstTraversal();
        }

        else if (strLHS == "3") {
            tree.preorderTraversal();
        }

        else if (strLHS == "4") {
            tree.inorderTraversal();
        }

        else if (strLHS == "5") {
            tree.postorderTraversal();
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
