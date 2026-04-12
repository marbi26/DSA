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
bool isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            cout << "Cycle exists in Detect Part\n";
            return true;
        }
    }
    cout <<"Cycle doesn't exists\n";
    return false;
}

void remove_cycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            cout << "Cycle exists in Remove part\n";
            isCycle = true;
            break;
        }
    }
    if(! isCycle){
        cout <<"Cycle doesn't exists\n";
        return;
    }
    slow = head;
    if(slow == fast){
        while(fast -> next != slow){
            fast = fast-> next;
        }
        fast->next = NULL;
    }else{
        Node* prev = fast;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
    }
}
int main(){
    list ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next = ll.head;
    isCycle(ll.head);

    remove_cycle(ll.head);
    ll.printlist();
    return 0;
}