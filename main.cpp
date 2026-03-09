// COMSC-210 | Lab 19 | Alexander Sierra
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

const int MN = 10, MX = 50;
const int NSIZE = 3;

struct Node {
    double rating;
    string comment;
    Node *next;
};

void frontN(Node *&, Node *);
void output(Node *);
void deleteL(Node *&);

class Movie{
private:
//private member variables
    string title;
    Node *reviews;
public:
//setters and getters
    string getTitle() {return title;}
    void setTitle(string t) {title = t;}
    Node getReviews() {return *reviews;}
    void setReviews(Node *r) {reviews=r;}

    void print() {
        cout << "Movie: " << title << endl;
        output(reviews);
    }
};

int main () {
    srand(time(0));
    //declarations
    Node *head = nullptr;
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    Node *head3 = nullptr;
    Node *newnode = nullptr;
    int counter = 0;
    vector<Movie> movies_v;
    ifstream fin ("input.txt");
    string t;

    //getting data from text file
    if (fin.good()){
        while (getline(fin, t)) {
            for (int i = 0; i < NSIZE; i++) {
                newnode = new Node;
                newnode->rating = (rand() % (MX-MN+1)+MN) / 10.0;
                getline(fin, newnode->comment);
                if (counter == 0) {frontN(head, newnode);}
                if (counter == 1) {frontN(head1, newnode);}
                if (counter == 2) {frontN(head2, newnode);}
                if (counter == 3) {frontN(head3, newnode);}
            }
            Movie temp;
            temp.setTitle(t);
            if (counter == 0) {temp.setReviews(head);}
            if (counter == 1) {temp.setReviews(head1);}
            if (counter == 2) {temp.setReviews(head2);}
            if (counter == 3) {temp.setReviews(head3);}
            movies_v.push_back(temp);
            counter++;
        }
    }
    else {cout << "Input file not found." << endl;}

    //outputs data
    for (auto movie : movies_v) {
        movie.print();
    }
    deleteL(head);
    deleteL(head1);
    deleteL(head2);
    deleteL(head3);

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