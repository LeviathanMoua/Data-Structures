/*
Program name : MouaJustin_Homework2.cpp
Author       : Justin Moua
Professor    : Pu Cong
Course       : CS 3353 | Data Structures and Algorithms
Date         : 11 February 2024
Description  : Refer to instructions provided by professor.
*/

#include <iostream>
#include <string>



//========================CLASSES====================================
class CharSLLNode {
public:
    CharSLLNode() {
        next = 0;
    }
    CharSLLNode(char el, CharSLLNode* ptr = 0) {
        info = el; next = ptr;
    }
    char info;
    CharSLLNode* next;
};

class CharSLList {
public:
    CharSLList() {
        head = tail = 0;
    }
    ~CharSLList();
    bool isEmpty() {
        return head == 0;
    }
    void addToHead(char);
    void addToTail(char);
    char  deleteFromHead();
    char  deleteFromTail();
    void deleteNode(char);
    bool isInList(char) const;
    void printAll() const;
private:
    CharSLLNode* head, * tail;
};

template<class T>
class DLLNode {
public:
    DLLNode() {
        next = prev = 0;
    }
    DLLNode(char el, DLLNode* n = 0, DLLNode* p = 0) {
        info = el; next = n; prev = p;
    }
    T info;
    DLLNode* next, * prev;
};

template<class T>
class DoublyLinkedList {
public:
    DoublyLinkedList() {
        head = tail = 0;
    }
    void addToDLLTail(const T&);
    T deleteFromDLLTail();
    ~DoublyLinkedList() {
        clear();
    }
    bool isEmpty() const {
        return head == 0;
    }
    void clear();
    void setToNull() {
        head = tail = 0;
    }
    void addToDLLHead(const T&);
    T deleteFromDLLHead();
    T& firstEl();
    T* find(const T&) const;
    bool isInList(const T& el) const;
    void deleteNode(const T& el);
    void printAll() const;

protected:
    DLLNode<T>* head, * tail;
};
//========================CLASSES====================================


int main()
{
    //============VAR DECL AND INITL. STARTS HERE=============VAR DECL AND INITL. STARTS HERE=============
    CharSLList sll;
    DoublyLinkedList<char> dll;

    int intUserInput = 0; //Used to check what function the user wants to perform. 
    //============VAR DECL AND INITL. ENDS HERE=============VAR DECL AND INITL. ENDS HERE

    //-> is used to access members of my class instead of using "."
    std::cout << "\n==============================================================\n\nAssignment: Homework #2\nAuthor of Program: Justin moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";

    while (intUserInput != 12) {

        std::string strUsrInp; //Used to store an entire line of input from the user. 
        std::string strLHSUsrInp; //Stores the left hand side of input 
        std::string strRHSUsrInp;


        std::cout << "====\nMenu\n====\n\nSLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)\nDLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)\nExit Program (12)\n\nChoose: ";
        std::getline(std::cin, strUsrInp);
        std::cout << std::endl;

        /*
        //==============Traverse the string and prints it entirely======================DEBUGGER
        for (int i = 0; i < strUsrInp.length(); i++) {
            // Print current character
            std::cout << strUsrInp[i];
        }
        std::cout << std::endl << std::endl;
        */

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


        //==========OPERATIONS START HERE==========OPERATIONS START HERE==========OPERATIONS START HERE==========OPERATIONS START HERE==========OPERATIONS START HERE
        //if whitespace was detected

        if ((intWhiteSpcLoc > 0) || ((intWhiteSpcLoc == -1) && (strLHSUsrInp == "0" || strLHSUsrInp == "1" || strLHSUsrInp == "4" || strLHSUsrInp == "6" || strLHSUsrInp == "7" || strLHSUsrInp == "10"))) {

            char charRHSUsrInp;

            if ((intWhiteSpcLoc != -1) && (strLHSUsrInp != "0" || strLHSUsrInp != "1" || strLHSUsrInp != "4" || strLHSUsrInp != "6" || strLHSUsrInp != "7" || strLHSUsrInp != "10")) {
                char charRHSUsrInp = strRHSUsrInp[0];
                //std::cout << "Whitespace detected. It is at location: " << intWhiteSpcLoc;
                //std::cout << std::endl << std::endl;

                //=========================SINGLY LINKED LIST BRANCHES========================
                //SLL Insert Heads - SLL IH(0)
                if (strLHSUsrInp == "0") {
                    std::cout << "SLL: Inserted Head";
                    std::cout << std::endl << std::endl;
                    sll.addToHead(charRHSUsrInp);
                }

                //SLL Insert Tail - SLL IH(1)
                else if (strLHSUsrInp == "1") {
                    std::cout << "SLL: Inserted Tail";
                    std::cout << std::endl << std::endl;
                    sll.addToTail(charRHSUsrInp);

                }

                //SLL Search and Delete SLL SD(4)
                else if (strLHSUsrInp == "4") {
                    std::cout << "SLL: Searched and deleted";
                    std::cout << std::endl << std::endl;
                    sll.deleteNode(charRHSUsrInp);
                }

                //=========================SINGLY LINKED LIST BRANCHES========================



                //=========================DOUBLY LINKED LIST BRANCHES========================
                //DLL Insert Head - DLL IH(6)
                else if (strLHSUsrInp == "6") {
                    std::cout << "DLL: Inserted Head";
                    std::cout << std::endl << std::endl;
                    dll.addToDLLHead(charRHSUsrInp);
                }

                //DLL Insert Tail - DLL IT(7)
                else if (strLHSUsrInp == "7") {
                    std::cout << "DLL: Inserted Tail";
                    std::cout << std::endl << std::endl;
                    dll.addToDLLTail(charRHSUsrInp);
                }

                //DLL Search and Delete - DLL SD(10)
                else if (strLHSUsrInp == "10") {
                    std::cout << "DLL: Search and Delete";
                    std::cout << std::endl << std::endl;
                    dll.deleteNode(charRHSUsrInp);
                }
                //=========================DOUBLY LINKED LIST BRANCHES========================
            }
            else {
                std::cout << "\n==============\nInvalid Input!\n==============\n\nYou either enterd 0, 1, 4, 6, 7, or 10 in which requires a right-handed side input.";
                std::cout << std::endl << std::endl;
            }
        }

        //If we receive an input that does not consist of a whitespice. AKA, request to print or delete something (that doesn't require a search for a node in the middle). 
        else if (intWhiteSpcLoc == -1) {
            //=========================SINGLY LINKED LIST BRANCHES========================

            //SLL Delete Head - SLL (2)
            if (strLHSUsrInp == "2") {
                if (sll.isEmpty()) {
                    std::cout << "SLL: List is empty!";
                    std::cout << std::endl << std::endl;
                }
                else {
                    std::cout << "SLL: Deleting Head";
                    std::cout << std::endl << std::endl;
                    sll.deleteFromHead();
                }
            }

            //SLL Delete Tail - SLL DT(3)
            else if (strLHSUsrInp == "3") {
                if (sll.isEmpty()) {
                    std::cout << "SLL: List is empty!";
                    std::cout << std::endl << std::endl;
                }
                else {
                    std::cout << "SLL: Delete Tails";
                    std::cout << std::endl << std::endl;
                    sll.deleteFromTail();
                }
            }

            //SLL Print - SLL PS(5)
            else if (strLHSUsrInp == "5") {
                //std::cout << "5 works";

                if (sll.isEmpty()) {
                    std::cout << "SLL: Empty list." << std::endl << std::endl;
                }
                else {
                    std::cout << "SLL printed: ";
                    sll.printAll();
                }


            }
            //=========================SINGLY LINKED LIST BRANCHES========================


            //=========================DOUBLY LINKED LIST BRANCHES========================

            //DLL Delete Head - DLL DH(8)
            else if (strLHSUsrInp == "8") {
                if (dll.isEmpty()) {
                    std::cout << "DLL: Empty list.";
                }
                else {
                    std::cout << "DLL: Deleting Head";
                    std::cout << std::endl << std::endl;
                    dll.deleteFromDLLHead();
                }
            }

            //DLL Delete Tail - DLL DT(9)
            else if (strLHSUsrInp == "9") {
                if (dll.isEmpty()) {
                    std::cout << "DLL: Empty list.";
                }
                else {
                    std::cout << "DLL: Deleting Tail";
                    std::cout << std::endl << std::endl;
                    dll.deleteFromDLLTail();
                }
            }

            //DLL Print - DLL PD (11)
            else if (strLHSUsrInp == "11") {
                if (dll.isEmpty()) {
                    std::cout << "DLL: Empty list.";
                    std::cout << std::endl << std::endl;
                }
                else {
                    std::cout << "DLL printed: ";
                    dll.printAll();
                    std::cout << std::endl << std::endl;
                }
            }
            //=========================DOUBLY LINKED LIST BRANCHES========================
            else {
                std::cout << "\n==============\nInvalid Input!\n==============\n\nYou either entered 2, 3, 5, 8, 9, or 11 which DO NOT require a right-hand sided input.";
                std::cout << std::endl << std::endl;
            }
        }
        else {
            std::cout << "==============\nInvalid input!\n==============\n\nPlease try again." << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}

//=========================SINGLE LINKED LIST FUNCTION========================

CharSLList::~CharSLList() {
    for (CharSLLNode* p; !isEmpty(); ) {
        p = head->next;
        delete head;
        head = p;
    }
}

void CharSLList::addToHead(char el) {
    CharSLLNode* tmp = new CharSLLNode(el);
    tmp->next = head;
    head = tmp;
    if (tail == 0)
        tail = head;
}

void CharSLList::addToTail(char el) {
    if (tail != 0) {
        tail->next = new CharSLLNode(el);
        tail = tail->next;
    }
    else head = tail = new CharSLLNode(el);
}

char CharSLList::deleteFromHead() {
    char el = head->info;
    CharSLLNode* tmp = head;
    if (head == tail)
        head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;
}

char CharSLList::deleteFromTail() {
    char el = tail->info;
    if (head == tail) {
        delete head;
        head = tail = 0;
    }
    else {
        CharSLLNode* tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next);
        delete tail;
        tail = tmp;
        tail->next = 0;
    }
    return el;
}

void CharSLList::deleteNode(char el) {
    if (head != 0)
        if (head == tail && el == head->info) {
            delete head;
            head = tail = 0;
        }
        else if (el == head->info) {
            CharSLLNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        else {
            CharSLLNode* pred, * tmp;
            for (pred = head, tmp = head->next;
                tmp != 0 && !(tmp->info == el);
                pred = pred->next, tmp = tmp->next);
            if (tmp != 0) {
                pred->next = tmp->next;
                if (tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }
}

bool CharSLList::isInList(char el) const {
    CharSLLNode* tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}

void CharSLList::printAll() const {
    for (CharSLLNode* tmp = head; tmp != 0; tmp = tmp->next)
        std::cout << tmp->info << " ";
    std::cout << std::endl << std::endl;
}
//=========================SINGLE LINKED LIST FUNCTION========================

//=========================DOUBLY LINKED LIST FUNCTION========================

template<class T>
void DoublyLinkedList<T>::addToDLLHead(const T& el) {
    if (head != 0) {
        head = new DLLNode<T>(el, head, 0);
        head->next->prev = head;
    }
    else head = tail = new DLLNode<T>(el);
}

template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el) {
    if (tail != 0) {
        tail = new DLLNode<T>(el, 0, tail);
        tail->prev->next = tail;
    }
    else head = tail = new DLLNode<T>(el);
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLHead() {
    T el = head->info;
    if (head == tail) { // if only one DLLNode on the list;
        delete head;
        head = tail = 0;
    }
    else {              // if more than one DLLNode in the list;
        head = head->next;
        delete head->prev;
        head->prev = 0;
    }
    return el;
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail() {
    T el = tail->info;
    if (head == tail) { // if only one DLLNode on the list;
        delete tail;
        head = tail = 0;
    }
    else {              // if more than one DLLNode in the list;
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    return el;
}

template <class T>
T* DoublyLinkedList<T>::find(const T& el) const {
    DLLNode<T>* tmp = head;
    for (; tmp != 0 && !(tmp->info == el);  // overloaded ==
        tmp = tmp->next);
    if (tmp == 0)
        return 0;
    else return &tmp->info;
}

template<class T>
T& DoublyLinkedList<T>::firstEl() {
    return head->info;
}

template<class T>
void DoublyLinkedList<T>::clear() {
    for (DLLNode<T>* tmp; head != 0; ) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

template<class T>
bool DoublyLinkedList<T>::isInList(const T& el) const {
    DLLNode<T>* tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}

template<class T>
void DoublyLinkedList<T>::deleteNode(const T& el) {
    DLLNode<T>* tmp = head;
    while (tmp != 0 && !(tmp->info == el)) { // Find the node
        tmp = tmp->next;
    }
    if (tmp == 0) {     //If Element not found
        std::cout << "DLL: There is no such node in the list!";
        std::cout << std::endl << std::endl;
    }
    else if (tmp == head) { // Element is at the head
        deleteFromDLLHead();
    }
    else if (tmp == tail) { // Element is at the tail
        deleteFromDLLTail();
    }
    else { // Element is in the middle
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
    }
}

template<class T>
void DoublyLinkedList<T>::printAll() const {
    for (DLLNode<T>* tmp = head; tmp != 0; tmp = tmp->next) {
        std::cout << tmp->info << " ";
    }
    std::cout << std::endl << std::endl;
}

//=========================DOUBLY LINKED LIST FUNCTION========================
