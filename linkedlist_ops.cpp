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
    bool search(int value);
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
    if(!head){
        cout<<"List is empty"<<endl;
        return;
    }
    Node *temp=head;
    head=head->next;
    delete temp;
    cout<<"Deleted from the beginning"<<endl;
}
void linkedlist::deleteFromEnd(){
    if(!head){
        cout<<"list is empty"<<endl;
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        cout<<"List deleted from end"<<endl;
        return;
    }
    Node *current=head;
    while(current->next->next!=NULL)
        current=current->next;
    delete current->next;
    current->next=NULL;
    cout<<"Deleted from end"<<endl;
}
void linkedlist::display(){
    if(head==NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
bool linkedlist::search(int value){
    Node *current=head;
    while(current!=NULL){
        if(current->data==value)
            return true;
        current=current->next;
    }
    return false;
}
void linkedlist::reverse(){
    Node *p=head,*q,*r=NULL;
    while(p!=NULL){
        q=p;
        p=p->next;
        q->next=r;
        r=q;
    }
    head=q;
}

