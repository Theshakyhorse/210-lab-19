// COMSC-210 | Lab 19 | Alexander Sierra
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

const int NSIZE = 3, MSIZE = 4;

struct Node {
    double rating;
    string comment;
    Node *next;
};

class Movie{
private:
//private member variables
    string title;
    Node reviews;
public:
//setters and getters
    string getTitle() {return title;}
    void setTitle(string t) {title = t;}

    void print() {
        cout << "Movie: " << title << endl;
    }
};

void frontN(Node *&, Node *);
void output(Node *);
void deleteL(Node *&);

int main () {
    Node *head = nullptr;
    Node *newnode = nullptr;
    int choice = 0;

    for (int i = 0; i < NSIZE; i++) {
        newnode = new Node;
        cout << "Enter review rating 0.0-5.0:" << endl;
        cin >> newnode->rating;
        cout << "Enter review comment:" << endl;
        cin.ignore();
        getline(cin, newnode->comment);
        frontN(head, newnode);
    }
    return 0;
}