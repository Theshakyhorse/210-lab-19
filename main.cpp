// COMSC-210 | Lab 19 | Alexander Sierra
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

const int MN = 10, MX = 51;
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
    srand(time(0));
    Node *head = nullptr;
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    Node *newnode = nullptr;
    int choice = 0;
    int counter = 0;
    vector<Movie> movies_v;
    ifstream fin ("input.txt");
    string t;

    if (fin.good()){
        while (getline(fin, t)) {
            newnode = new Node;
            for (int i = 0; i < NSIZE; i++) {
                newnode->rating = (rand() % 51) / 10.0;
                getline(fin, newnode->comment);
                if (counter == 0){
                    frontN(head, newnode);
                }
            }
            Movie temp;
            temp.setTitle(t);
            movies_v.push_back(temp);
        }
    }
    else {cout << "Input file not found." << endl;}

    for (auto movie : movies_v) {
        movie.print();
    }

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

//adds node to head
void frontN(Node *&head, Node *newnode) {
    if(!head) {
        head = newnode;
        newnode->next=nullptr;
    }
    else {
        newnode->next=head;
        head = newnode;
    }
}

//outputs linked list
void output(Node *hd) {
    if (!hd) {
        cout << "empty list.\n";
        return;
    }

    int count = 1;
    double sum = 0;
    Node *current = hd;
    while (current) {
        cout << " > Review #" << count++ << ": ";
        cout << current->rating << ": " << current ->comment << endl;
        sum += current->rating;
        current = current->next;
    }
    cout << " > Average: " << sum/(count-1) << endl;
}

//deletes linked list
void deleteL(Node *&n) {
    Node *current = n;
    while (current) {
        n = current ->next;
        delete current;
        current = n;
    }
    n = nullptr;
}