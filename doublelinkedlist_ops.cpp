#include <iostream>
using namespace std;
class Node{
public:
  int data;
  Node *prev;
  Node *next;
  Node(int val){
    data=val;
    prev=NULL;
    next=NULL;
  }
};
class dlinkedlist{
  Node *head;
  public:
  dlinkedlist(){
    head=NULL;
  }
  void insertAtBeginning(int);
  void insertAtEnd(int);
  void deleteFromBeginning();
  void deleteFromEnd();
  void deleteItem(int);
  void display();
};
void dlinkedlist::insertAtBeginning(int value){
  Node *curr=new Node(value);
  curr->data=value;
  curr->prev=NULL;
  curr->next=head;
  if(head!=NULL){
    head->prev=curr;
  }
  head=curr;
  return;
}
void dlinkedlist::insertAtEnd(int value){
  Node *curr=new Node(value);
  curr->data=value;
  curr->next=NULL;
  if(head==NULL){
    curr->prev=NULL;
    head=curr;
    return;
  }
  Node *temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=curr;
  curr->prev=temp;
  return;
}
void dlinkedlist::deleteFromBeginning(){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node *temp=head;
  head=head->next;
  if(head!=NULL){ 
    head->prev=NULL;
  }
  delete temp;
}
void dlinkedlist::deleteFromEnd(){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node *temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  if(temp->prev!=NULL){
    temp->prev->next=NULL;
  }
  else{
    head=NULL;
  }
  delete temp;
}
void dlinkedlist::deleteItem(int value){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node *temp=head;
  while(temp->data!=value){
    temp=temp->next;
  }
  if(temp->prev!=NULL){
    temp->prev->next=temp->next;
  }
  else{
    head=temp->next;
  }
  if(temp->next!=NULL){
    temp->next->prev=temp->prev;
  }
  delete temp;
}
void dlinkedlist::display(){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node *temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
int main(){
  dlinkedlist list;
  int ch,data;
  do{
    cout<<"1. Insert at beginning"<<endl;
    cout<<"2. Insert at end"<<endl;
    cout<<"3. Delete from beginning"<<endl;
    cout<<"4. Delete from end"<<endl;
    cout<<"5. Delete item"<<endl;
    cout<<"6. Display"<<endl;
    cout<<"7. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch){
      case 1:
      cout<<"Enter data: ";
      cin>>data;
      list.insertAtBeginning(data);
      break;
      case 2:
      cout<<"Enter data: ";
      cin>>data;
      list.insertAtEnd(data);
      break;
      case 3:
      list.deleteFromBeginning();
      break;
      case 4:
      list.deleteFromEnd();
      break;
      case 5:
      cout<<"Enter data: ";
      cin>>data;
      list.deleteItem(data);
      break;
      case 6:
      list.display();
      break;
      case 7:
      exit(0);
      break;
      default:
      cout<<"Invalid choice"<<endl;
    }
  }while(1);
  return 0;
}
