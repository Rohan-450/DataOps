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
    cout<<"Inserted "<<value<<" at the beginning"<<endl;
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
    cout<<"Inserted "<<value<<" at the end"<<endl;
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
void linkedlist::bubbleSort(){
  if(head==NULL)
    return;
  int swapped;
  Node *current;
  Node *last=NULL;
  do{
    swapped=0;
    current=head;
    while(current->next!=last){
      if(current->data<current->next->data){
        int temp=current->data;
        current->data=current->next->data;
        current->next->data=temp;
        swapped=1;
      }
      current=current->next;
    }
    last=current;
  }while(swapped);
}
void linkedlist::deleteItem(int value){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  if(head->data==value){
    Node *temp=head;
    head=head->next;
    delete temp;
    return;
  }
  Node *current=head;
  while(current->next!=NULL){
    if(current->next->data==value){
      Node *temp=current->next;
      current->next=current->next->next;
      delete temp;
      return;
    }
    current=current->next;
  }
}
int main(){
  linkedlist list;
  int ch,data;
  do{
    cout<<"1.Insert at beginning"<<endl;
    cout<<"2.Insert at end"<<endl;
    cout<<"3.Delete from beginning"<<endl;
    cout<<"4.Delete from end"<<endl;
    cout<<"5.Display"<<endl;
    cout<<"6.Search"<<endl;
    cout<<"7.Reverse"<<endl;
    cout<<"8.Delete Item"<<endl;
    cout<<"9.Bubble Sort"<<endl;
    cout<<"10.Exit"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>ch;
    switch(ch){
      case 1:
      cout<<"Enter data"<<endl;
      cin>>data;
      list.insertAtBeginning(data);
      break;
      case 2:
      cout<<"Enter data"<<endl;
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
      list.display();
      break;
      case 6:
      cout<<"Enter data"<<endl;
      cin>>data;
      if(list.search(data))
        cout<<"Found"<<endl;
      else
        cout<<"Not Found"<<endl;
      break;
      case 7:
      list.reverse();
      break;
      case 8:
      cout<<"Enter data"<<endl;
      cin>>data;
      list.deleteItem(data);
      break;
      case 9:
      list.bubbleSort();
      break;
      case 10:
      exit(0);
      break;
      default:
      cout<<"Invalid choice"<<endl;
    }
  }while(1);
  return 0;
}

