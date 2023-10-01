#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class linkedlist{
    Node *head;
    public:
    linkedlist(){
        head=NULL;
    }
    ~linkedlist(){
        while(head!=NULL){
            Node *temp=head;
            head=head->next;
            delete(temp);
        }
    }
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void deleteFromBeginning();
    void deleteFromEnd();
    void display();
    void search(int value);
    void reverse();
    void deleteItem(int);
    void bubbleSort();
};
void linkedlist::insertAtBeginning(int value){
    Node *newnode=new Node(value);
    newnode->next=head;
    head=newnode;
    cout<<"Inserted"<<value<<"at the beginning";
}
void linkedlist::insertAtEnd(int value){
    Node *newnode=new Node(value);
    if(!head){
        head=newnode;
    }
    else{
        Node *current=head;
        while(current->next)
            current=current->next;
        current->next=newnode;
    }
    cout<<"Inserted"<<value<<"at the end";
}
void linkedlist::deleteFromBeginning(){
    
}

