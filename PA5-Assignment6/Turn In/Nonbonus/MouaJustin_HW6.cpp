/*
Program name : MouaJustin_HW6.cpp
Author       : Justin Moua
Professor    : Pu Cong
Course       : CS 3353 | Data Structures and Algorithms
Due Date     : 1 May. 2024
Description  : Refer to instructions provided by professor.
*/

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <unordered_set> //Got this to store elements in a specific order. 
#include <unordered_map> //

//Creating node class
class Node {
public:
    char data;

    Node(char data) {
        this->data = data;
    }
};

class Graph {
    std::list<std::list<Node>> arrList; //instantiates a Linked lists that contains other linked lists

public:

    //=========GRAPH CREATION FUNCTIONS START HERE========GRAPH CREATION FUNCTIONS START HERE========GRAPH CREATION FUNCTIONS START HERE========
    // Add node to the graph
    void addNode(Node node) {
        std::list<Node> list;
        list.push_back(node);
        arrList.push_back(list);
    }

    // Add edge between source and destination
    void addEdge(int src, int dst) {
        auto autIterator = arrList.begin();
        std::advance(autIterator, src); //moves to where the amt of positions src reps
        std::list<Node>& currentList = *autIterator; //Used to grab list at the position the autIterator points to. Like say, arrList contains A, B, C, ... etc and it shows which one is chosen. 
        auto autDestIterator = arrList.begin(); 
        std::advance(autDestIterator, dst);
        Node dstNode = autDestIterator->front(); //Instantiates an object of Node and is set to the front of the destination iterator
        currentList.push_back(dstNode);
    }
    //=========GRAPH CREATION FUNCTIONS ENDS HERE========GRAPH CREATION FUNCTIONS ENDS HERE========GRAPH CREATION FUNCTIONS ENDS HERE========


    // Depth First Search
    void DFS(char start) {
        std::stack<Node> stack;
        std::unordered_set<char> visited;

        auto autIterator = arrList.begin();

        //while we haven't reached the end of arrList and we are not at the beginning again
        //basically the "for all vertices v"
        while (autIterator != arrList.end() && autIterator->front().data != start) {
            ++autIterator;
        }

        //If we've reached the end
        if (autIterator != arrList.end()) {
            stack.push(autIterator->front()); //pushes what we went to on the stack
            visited.insert(autIterator->front().data); //keeps track of what we visited. 
        }

        while (!stack.empty()) {
            Node current = stack.top();
            stack.pop();
            std::cout << current.data << " ";

            for (auto& neighbor : getNeighbors(current.data)) {
                if (visited.find(neighbor.data) == visited.end()) {
                    stack.push(neighbor);
                    visited.insert(neighbor.data);
                }
            }
        }
    }

    // Get autNeighbors of a node
    std::list<Node> getNeighbors(char node) {
        auto it = arrList.begin();
        while (it != arrList.end() && it->front().data != node) {
            ++it;
        }
        if (it != arrList.end()) {
            return std::list<Node>(std::next(it->begin()), it->end());
        }
        return std::list<Node>();
    }

    // Minimum Path Search (BFS)
    void minPath(char start, char end) {
        std::queue<Node> queue;
        std::unordered_set<char> visited;
        std::unordered_map<char, char> parent;

        auto it = arrList.begin();
        while (it != arrList.end() && it->front().data != start) {
            ++it;
        }
        if (it != arrList.end()) {
            queue.push(it->front());
            visited.insert(it->front().data);
            parent[start] = start;
        }

        //Goes through queue
        while (!queue.empty()) {
            Node current = queue.front(); //instantiates object of type node and sets it to front of queue Note to self: queue fifo
            queue.pop(); 

            if (current.data == end) //if we reached the end of the queue
                break;

            auto autNeighbors = getNeighbors(current.data); 
            //while we have not reached the end of autNeighbors.  
            for (auto it = autNeighbors.begin(); it != autNeighbors.end(); ++it) {
                auto& neighbor = *it;
                if (visited.find(neighbor.data) == visited.end()) {
                    queue.push(neighbor); //pushes neighbor into queue 
                    visited.insert(neighbor.data); //inserts into visited
                    parent[neighbor.data] = current.data;
                }
            }

        }

        std::stack<char> path;
        char node = end;
        while (node != start) {
            path.push(node);
            node = parent[node];
        }
        std::cout << start << " ";
        while (!path.empty()) {
            std::cout << path.top() << " ";
            path.pop();
        }
        std::cout << std::endl;
    }

    void print() {
        for (std::list<Node>& currentList : arrList) {
            for (Node& node : currentList) {
                std::cout << node.data << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {

    std::cout << "\n==============================================================\n\nAssignment: Homework #6\nAuthor of Program: Justin Moua\nProfessor: Pu Cong\nCourse: CS 3353 | Data Structures and Algorithms\n\n==============================================================\n\n";

    char charUsrInp;
    char charUsrStartInp, charUsrEndInp;

    Graph graph; //object instantiation of Graph class

    //============CREATION OF GRAPH STARTS HERE============CREATION OF GRAPH STARTS HERE============CREATION OF GRAPH STARTS HERE============
    graph.addNode(Node('A'));
    graph.addNode(Node('B'));
    graph.addNode(Node('C'));
    graph.addNode(Node('D'));
    graph.addNode(Node('E'));
    graph.addNode(Node('F'));
    graph.addNode(Node('G'));
    graph.addNode(Node('H'));
    graph.addNode(Node('I'));

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 1);
    graph.addEdge(2, 6);
    graph.addEdge(3, 2);
    graph.addEdge(3, 6);
    graph.addEdge(4, 2);
    graph.addEdge(4, 5);
    graph.addEdge(5, 2);
    graph.addEdge(5, 7);
    graph.addEdge(6, 5);
    graph.addEdge(6, 7);
    graph.addEdge(6, 8);
    graph.addEdge(7, 4);
    graph.addEdge(7, 8);
    graph.addEdge(8, 5);

    //DEBUGGER: 
    //graph.print();
    //============CREATION OF GRAPH ENDS HERE============CREATION OF GRAPH ENDS HERE============CREATION OF GRAPH ENDS HERE============


    //============USER'S INPUT OPERATION STARTS HERE==========USER'S INPUT OPERATION STARTS HERE==========USER'S INPUT OPERATION STARTS HERE==========
    while (true) {
        std::cout << "Depth-First Search (0), Minimum Path Search (1)\n";
        std::cout << "Exit Program (2)\n";
        std::cout << "Choose? ";
        std::cin >> charUsrInp;

        //DFS SEARCH
        if (charUsrInp == '0') {
            std::cin >> charUsrStartInp; //I realized reading through Stephen Prata's C++ that cin reads up to whitespace or so. So if user enters rhs this should work. 
            charUsrStartInp = std::toupper(charUsrStartInp);

            //std::cout << charUsrStartInp;
            if (charUsrStartInp == 'A' || charUsrStartInp == 'B' 
                || charUsrStartInp == 'C'  || charUsrStartInp == 'D' 
                || charUsrStartInp == 'E'  || charUsrStartInp == 'F' 
                || charUsrStartInp == 'G' || charUsrStartInp == 'H'
                || charUsrStartInp == 'I') {

                graph.DFS(charUsrStartInp);
                //std::cout << "success";

            }
            else {
                std::cout << std::endl;
                std::cout << "=============\nInvalid input\n=============\n\nPlease enter a letter from A to I." << std::endl;
                std::cout << std::endl;
            }

        }
        //MINIMUM PATH SEARCH
        else if (charUsrInp == '1') {
            std::cin >> charUsrStartInp; //same as the cin >> start from the first if statement. Makes code much cleaner
            charUsrStartInp = std::toupper(charUsrStartInp);

            std::cin >> charUsrEndInp;
            charUsrEndInp = std::toupper(charUsrEndInp);

            if ((charUsrStartInp == 'A' || charUsrStartInp == 'B'
                || charUsrStartInp == 'C' || charUsrStartInp == 'D'
                || charUsrStartInp == 'E' || charUsrStartInp == 'F'
                || charUsrStartInp == 'G' || charUsrStartInp == 'H'
                || charUsrStartInp == 'I' || charUsrEndInp == 'A') 
                && ( charUsrEndInp == 'B' || charUsrEndInp == 'C' 
                || charUsrEndInp == 'D' || charUsrEndInp == 'E' 
                || charUsrEndInp == 'F' || charUsrEndInp == 'G' 
                || charUsrEndInp == 'H' || charUsrEndInp == 'I')) {
                graph.minPath(charUsrStartInp, charUsrEndInp);
            }
            else {
                std::cout << std::endl;
                std::cout << "=============\nInvalid input\n=============\n\nPlease Try Again! One of your letters was not one of from A to I. " << std::endl;
                std::cout << std::endl;
            }

        }
        //BREAK
        else if (charUsrInp == '2') {
            break;
        }
        else {
            std::cout << "=============\nInvalid Input\n=============\n\nPlease try again!" << std::endl;
            std::cout << std::endl;
        }

        std::cout << std::endl << std::endl;
    }
    //============USER'S INPUT OPERATION ENDS HERE==========USER'S INPUT OPERATION ENDS HERE==========USER'S INPUT OPERATION ENDS HERE==========

    return 0;
}