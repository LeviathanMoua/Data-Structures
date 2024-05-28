
/*
Program name : MouaJustin_HW6_BONUS.cpp
Author       : Justin Moua
Professor    : Pu Cong
Course       : CS 3353 | Data Structures and Algorithms
Due Date     : 1 May 2024
Description  : Refer to instructions provided by professor.
*/


#include <iostream>
#include <sstream>
#include <vector>

template<class T>
void insertionsort(T data[], const int n) {
    for (int i = 1, j; i < n; i++) {
        T tmp = data[i];
        for (j = i; j > 0 && tmp < data[j - 1]; j--)
            data[j] = data[j - 1];
        data[j] = tmp;
    }
}

template<class T>
void selectionsort(T data[], const int n) {
    for (int i = 0, least, j; i < n - 1; i++) {
        for (j = i + 1, least = i; j < n; j++)
            if (data[j] < data[least])
                least = j;
        std::swap(data[least], data[i]);
    }
}

template<class T>
void bubblesort(T data[], const int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; --j)
            if (data[j] < data[j - 1])
                std::swap(data[j], data[j - 1]);
}

template<class T>
void Shellsort(T data[], const int n) {
    int i, j, hCnt, h;
    int increments[20], k;
    for (h = 1, i = 0; h < n; i++) {
        increments[i] = h;
        h = 3 * h + 1;
    }
    for (i--; i >= 0; i--) {
        h = increments[i];
        for (hCnt = h; hCnt < 2 * h; hCnt++) {
            for (j = hCnt; j < n; ) {
                T tmp = data[j];
                k = j;
                while (k - h >= 0 && tmp < data[k - h]) {
                    data[k] = data[k - h];
                    k -= h;
                }
                data[k] = tmp;
                j += h;
            }
        }
    }
}

template<class T>
void moveDown(T data[], int first, int last) {
    int largest = 2 * first + 1;
    while (largest <= last) {
        if (largest < last && data[largest] < data[largest + 1])
            largest++;

        if (data[first] < data[largest]) {
            std::swap(data[first], data[largest]);
            first = largest;
            largest = 2 * first + 1;
        }
        else largest = last + 1;
    }
}

// Utility function to print array
template<class T>
void fnPrint(T arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    const int MAX = 100;
    int arrUserInput[MAX];
    int intSize = 0;
    std::cout << "\n==============================================================\n\nAssignment: Homework #6 BONUS\nAuthor of Program: Justin Moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";

    while (true) {
        std::cout << "Input Data (0), Insertion Sort (1), Selection Sort (2), Bubble Sort (3), Shell Sort (4), Exit Program (5)" << std::endl;
        std::cout << "Choose? ";

        int intUsrInpOperation;
        std::cin >> intUsrInpOperation;

        switch (intUsrInpOperation) {
        //INPUT DATA aka option 0 
        case 0: {
            
            std::string strInp; //User input of numbers go into here
            std::getline(std::cin >> std::ws, strInp); //grabs user input
            std::istringstream iss(strInp);

            int num; 
            while (iss >> num) { //Used to read the int input and put it into arrUserInput for each element while it still reads iss
                                //basically a "read iss into num or input into num from iss kind of"
                arrUserInput[intSize++] = num;
            }
            fnPrint(arrUserInput, intSize);
            std::cout << std::endl << std::endl;
            break;
        }

        //INSERTION SORT aka option 1
        case 1:
            insertionsort(arrUserInput, intSize);
            fnPrint(arrUserInput, intSize);
            std::cout << std::endl << std::endl;
            break;

        //SELECTION SORT aka option 2
        case 2:
            selectionsort(arrUserInput, intSize);
            fnPrint(arrUserInput, intSize);
            std::cout << std::endl << std::endl;
            break;

        //BUBBLE SORT
        case 3:
            // Bubble Sort
            bubblesort(arrUserInput, intSize);
            fnPrint(arrUserInput, intSize);
            std::cout << std::endl << std::endl;
            break;

        //SHELL SORT
        case 4:
            Shellsort(arrUserInput, intSize);
            fnPrint(arrUserInput, intSize);
            std::cout << std::endl << std::endl;
            break;

        //QUIT PROGRAM
        case 5:
            std::cout << "You chose 5 and thus the program will quit!";
            std::cout << std::endl << std::endl << std::endl;
            return 0;

        //INVALID INPUT
        default:
            std::cout << "=============\nInvalid input\n=============\n\nPlease Try Again! You must enter a number from 0 to 5.";
            std::cout << std::endl << std::endl;
        }
    }

    return 0;
}
