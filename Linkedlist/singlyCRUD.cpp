#include<iostream>
using namespace std;
//creating a node 
class Node{
public:
    int data;
    Node* next;

    //constructor 
    Node(int value){
        this->data = value;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //deleting
        if(this->next != NULL){
            delete next;    
            this->next = NULL;
        }
        cout << "\nMemory is free for this data: " << value;
    }
};

//inserting at head
void insertAtHead(Node* &head, Node* &tail, int data){
    //empty linkedlist
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp; 
        tail = temp; 
    }else{
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}

//inserting at tail
void insertAtTail(Node* &head, Node* &tail, int data){
    //empty linkedlist
    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp; 
        tail = temp; 
    }else{
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}

//inserting at middle
void insertAtMiddle(Node* &head, Node* &tail, int position, int data){
    //if position is first
    if(position == 1){
        insertAtHead(head, tail, data);
        return;
    }

    //counting node
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }

    //if position is last
    if(temp->next == NULL){
        insertAtTail(head, tail, data);
        return;
    }
    //create a node
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

//Deletion node
void deleteNode(Node* &head, int position){
    //deleting first node 
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete(temp);
    }else{
        //deleting middle or last node
        Node* current = head;
        Node* previous = NULL;

        int count = 1;
        while(count < position){
            previous = current;
            current = current->next;
            count++;
        }
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }

}

// printing nodes
void printNode(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " "; 
        temp = temp->next;
    }
    cout << endl;
} 


int main(){
    Node* head = NULL;
    Node* tail = NULL;

//inserting
    //inserting at head
    printNode(head);
    insertAtHead(head, tail, 67);
    printNode(head);
    insertAtHead(head, tail, 65);
    printNode(head);

    //inserting at end/tail
    insertAtTail(head, tail, 99);
    printNode(head);
    insertAtTail(head, tail, 10);
    printNode(head);

    //inserting at middle
    insertAtMiddle(head, tail, 4, 75);
    printNode(head);
    insertAtMiddle(head, tail, 1, 72);
    printNode(head);
    insertAtMiddle(head, tail, 7, 100);
    printNode(head);

//deleting
    //deleting at head
    deleteNode(head, 1);
    cout << endl;
    printNode(head);

    //deleting at middle
    deleteNode(head, 2);
    cout << endl;
    printNode(head);

    //deleting at end/tail
    deleteNode(head, 5);
    cout << endl;
    printNode(head);
    cout << "Head data is: " << head->data << endl;
    cout << "Tail data is: " << tail->data;
    
    return 0;
}