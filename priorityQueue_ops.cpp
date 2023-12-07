#include<iostream>
using namespace std;
struct Node{
  int data;
  int priority;
  Node *next;
};
class PQ{
  Node *front;
  public:
  PQ(){
    front=NULL;
  }
  bool isEmpty(){
    return front==NULL;
  }
  void enqueue(){
    int data;
    int prior;
    cout<<"Enter data: ";
    cin>>data;
    cout<<"Enter priority: ";
    cin>>prior;
    Node *curr=new Node;
    curr->data=data;
    curr->priority=prior;
    curr->next=NULL;
    if(front==NULL || prior<front->priority){
      curr->next=front;
      front=curr;
    }
    else{
      Node *temp=front;
      while(temp->next!=NULL && temp->next->priority<=prior){
      temp=temp->next;
      }
      curr->next=temp->next;
      temp->next=curr;
    }
  }
  void dequeue(){
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
    }
    else{
      Node *temp=front;
      cout<<"Deleted element is: "<<temp->data<<endl;
      front=front->next;
      delete temp;
    }
  }
  void display(){
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
    }
    else{
      Node *temp=front;
      while(temp!=NULL){
      cout<<"Data: "<<temp->data<<" "<<"Priority: "<<temp->priority<<endl;
      temp=temp->next;
      }
      cout<<endl;
    }
  }
};
int main(){
  PQ pq;
  int ch;
  do{
    cout<<"1. Enqueue"<<endl;
    cout<<"2. Dequeue"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch){
      case 1: pq.enqueue();
            break;
      case 2: pq.dequeue();
            break;
      case 3: pq.display();
            break;
      case 4: exit(0);
            break;
      default: cout<<"Invalid choice"<<endl;
    }
  }while(1);
}
