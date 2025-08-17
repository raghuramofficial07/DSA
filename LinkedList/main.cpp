#include <iostream>

class Node{
    public:
    
    int data;
    Node* next;
    
    Node(int value){
        data=value;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
    
    public:
    List(){
        head=tail=NULL;
    }
    void append(int value){
        Node* newnode = new Node(value);
        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    
    void Display(){
        Node* temp = head;
        while(temp != NULL){
            std::cout << temp->data << "->";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main(void){
    List ll;
    ll.append(5);
    ll.append(10);
    ll.append(15);
    ll.append(20);
    ll.Display();
}
