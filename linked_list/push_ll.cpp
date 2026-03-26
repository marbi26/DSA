#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class list{
    public:
    Node* head;
    Node* tail;

    list(){
        head = NULL;
        tail = NULL;
    }

    ~list(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode -> next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void insert_middle(int val, int pos){
        Node* newNode = new Node(val);

        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp == NULL){
                cout<<"INVALID POSITION\n";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front(){
        Node* temp = head;
        if(head == NULL){
            cout << "LL is Empty../n" << "Nothing can POP../n";
        }
        head = head->next;

        temp->next = NULL;
        delete temp;

    }

    void pop_back(){
        Node* temp = head;
        if(head == NULL){
            cout << "LL is Empty../n" << "Nothing can POP../n";
        }
        while(temp->next->next != NULL){
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete tail;
        tail = temp;
    }

    void printlist(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp -> data << "->";
            temp = temp -> next;
        }
        cout << "NULL\n";
    }
};

int main(){
    list ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printlist();
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.printlist();
    ll.insert_middle(1000,3);
    ll.push_front(10);
    ll.push_back(11);
    ll.printlist();
    ll.pop_front();
    ll.pop_back();
    ll.printlist();
    return 0;
}