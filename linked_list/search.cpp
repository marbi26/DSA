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
            cout << "LL is Empty..\n" << "Nothing can POP..\n";
        }
        head = head->next;

        temp->next = NULL;
        delete temp;

    }

    void pop_back(){
        Node* temp = head;
        if(head == NULL){
            cout << "LL is Empty..\n" << "Nothing can POP..\n";
        }
        while(temp->next->next != NULL){
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete tail;
        tail = temp;
    }
    int searchItr(int key){
        Node* temp = head;
        if(head == NULL){
            cout << "LL is Empty..\n" << "Nothing can searched..\n";
        }
        int idx = 0;
        while(temp != NULL){
            if(temp->data == key){
                //cout << "key:" << key << " at index: " << idx << endl;
                return idx;
            }
            temp = temp ->next;
            idx++;
        }
        return -1;
    }

    int helper(Node* temp, int key){
        if(temp == NULL){
            return -1;
        }

        if(temp -> data == key){
            return 0;
        }

        int idx = helper(temp->next, key);
        if(idx == -1){
            return -1;
        }
        return idx+1;
    }

    int searchRec(int key){
        return helper(head,key);
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
    ll.push_front(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printlist();
    int r1 = ll.searchRec(3);
    cout << "key:3 at index: " << r1 << endl; 
    int r2 = ll.searchRec(50);
    cout << "key:50 at index: " << r2 << endl; 
    return 0;
}