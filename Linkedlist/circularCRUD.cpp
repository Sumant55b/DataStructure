#include<iostream>
using namespace std;

//create a node
class Node{
public:
    int data;
    Node* next;

    //Constructor 
    Node(int value){
        data = value;
        next = NULL;    
    }
    
    //Destructor
    ~Node(){
        int value = data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Deleted: " << value << endl;
    }
};

//insert node
void insertNode(Node* &tail, int element, int data){
    
    //Assuming the element is present in the list 
    if(tail == NULL){
        //empty list
        Node* temp = new Node(data);
        temp->next = temp;
        tail = temp;
    }else{
        //non-empty list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next; 
        }

        //element dound and curr represent that element's node
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

//deleting node
void deleteNode(Node* &tail, int value){
    //empty list
    if(tail == NULL){
        cout << "List is empty, Please check again.";
        return ;
    }else{
        //non-empty list
        
        Node* pre = tail;
        Node* curr = tail->next;
        
        while(value != curr->data){
            pre = curr;
            curr = curr->next;
        }

        pre->next = curr->next;
        //if only one node is present
        if(curr == pre){
            tail = NULL;
        }
        //greater than 2 node
        else if(tail = curr){
            tail = pre->next;
        }
        curr->next = NULL;
        delete curr;
    }
}

//printing list
void printNode(Node* tail){
    Node* temp = tail;

    if(tail == NULL){
        cout << "List is Empty.";
        return;
    }
    do {
        cout << tail->data << " ";
        tail = tail->next;
    }
    while(tail != temp);
    cout << endl;
}
int main(){
    Node* tail = NULL;

    insertNode(tail, 5, 10);
    printNode(tail);
    insertNode(tail, 10, 20);
    printNode(tail);
    insertNode(tail, 20, 30);
    printNode(tail);
    insertNode(tail, 30, 40);
    printNode(tail);
    insertNode(tail, 20, 25);
    printNode(tail);
    insertNode(tail, 10, 15);
    printNode(tail);
    insertNode(tail, 40, 50);
    printNode(tail);

    deleteNode(tail, 10);
    printNode(tail); 
    return 0;
}
