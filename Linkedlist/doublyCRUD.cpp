#include<iostream>
using namespace std;
//create node
class Node{
    public:
        int data;
        Node* next;
        Node* pre;

        //constructor
        Node(int value){
            this->data = value;
            this->next = NULL;
            this->pre = NULL;
        }
        ~Node(){
            int value = this->data;
            if(next != NULL){
                delete next;
                next = NULL;
            }
            cout << "deleted: " << value;
        }

};

//printing linked list
void printNodes(Node* head){
    
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


//find length of linkedl list
int getLength(Node* &head){

    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}


//inserting at head
void insertAtHead(Node* &tail, Node* &head, int data){
    //if linkedlist is empty
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(data);
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
}

//inserting at tail
void insertAtTail(Node* &tail, Node* &head, int data){
    //if linkedlist is empty
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(data);
        temp->pre = tail;
        tail->next = temp;
        tail = temp; 
    }
}

//inserting at middle
void insertAtMiddle(Node* &head, Node* &tail, int pos, int data){
    //insert at head, pos = 1
    if(pos == 1){
        insertAtHead(tail, head, data);
        return ;
    }

    Node* temp = head;
    int count = 1;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }
    //insert at end
    if(temp->next == NULL){
        insertAtTail(tail, head, data);
        return ;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->pre = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->pre = temp;
}
//deleting node
void deleteNodes(Node* &head, int position){
    //delete at head
    if(position == 1){
        Node* temp = head;
        temp->next->pre = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }else{
        //delete at middle or last
        Node* curr = head;
        Node* pre = NULL;
        int count = 1;
        while(count < position){
            pre = curr;
            curr = curr->next;
            count++;
        }

        curr->pre = NULL;
        pre->next = curr->next;
        curr->next = NULL;
        delete curr; 
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

  
    insertAtHead(tail, head, 11);
    printNodes(head);
    insertAtHead(tail, head, 10);
    printNodes(head);
    insertAtTail(tail, head, 55);
    printNodes(head);
    insertAtMiddle(head, tail, 1, 5);
    printNodes(head);
    insertAtMiddle(head, tail, 2, 51);
    printNodes(head);
    insertAtMiddle(head, tail, 6, 100);
    printNodes(head);
    deleteNodes(head, 1);
    cout << endl;
    printNodes(head);
    deleteNodes(head, 3);
    cout << endl;
    printNodes(head);
    deleteNodes(head, 4);
    cout << endl;
    printNodes(head);
    cout << getLength(head);
    return 0;
}