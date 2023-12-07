#include<iostream>
using namespace std;
struct Node{
  int coeff;
  int power;
  Node *next;
};
class polynomial{
  Node *front;
  public:
  polynomial(){
    front=NULL;
  }
  void enqueue(int,int);
  Node *getFront();
  void display();
};
Node *polynomial::getFront(){
  return front;
}
void polynomial::display(){
  if(front==NULL){
    cout<<"Empty"<<endl;
    return;
  }
  Node *temp=front;
  cout<<"Resultant Polynomial is: "<<endl;
  while(temp!=NULL){
    cout<<temp->coeff<<"x^"<<temp->power;
    temp=temp->next;
    if(temp!=NULL)
      cout<<" + ";
  }
  cout<<endl;
}
void polynomial::enqueue(int coeff,int power){
  Node *curr=new Node;
  curr->coeff=coeff;
  curr->power=power;
  curr->next=NULL;
  if(front==NULL || power<front->power){
    curr->next=front;
    front=curr;
  }
  else{
    Node *temp=front;
    while(temp->next!=NULL && temp->next->power<=power){
      temp=temp->next;
    }
    curr->next=temp->next;
    temp->next=curr;
  }
}
void addPolynomials(polynomial p1,polynomial p2,polynomial &p3){
  Node *temp1=p1.getFront();
  Node *temp2=p2.getFront();
  while(temp1!=NULL && temp2!=NULL){
    if(temp1->power==temp2->power){
      p3.enqueue(temp1->coeff+temp2->coeff,temp1->power);
      temp1=temp1->next;
      temp2=temp2->next;
    }
    else if(temp1->power>temp2->power){
      p3.enqueue(temp1->coeff,temp1->power);
      temp1=temp1->next;
    }
    else{
      p3.enqueue(temp2->coeff,temp2->power);
      temp2=temp2->next;
    }
  }
  while(temp1!=NULL){
    p3.enqueue(temp1->coeff,temp1->power);
    temp1=temp1->next;
  }
  while(temp2!=NULL){
    p3.enqueue(temp2->coeff,temp2->power);
    temp2=temp2->next;
  }
}
int main(){
  polynomial p1;
  int choice1;
  cout<<"1.Enqueue"<<endl;
  cout<<"2.Display"<<endl;
  cout<<"3.Exit"<<endl;
  cout<<"For Polynomial 1"<<endl;
  do{
    cout<<"Enter choice: ";
    cin>>choice1;
    switch(choice1){
      case 1:
      int coeff,power;
      cout<<"Enter coefficient: ";
      cin>>coeff;
      cout<<"Enter power: ";
      cin>>power;
      p1.enqueue(coeff,power);
      break;
      case 2:
      p1.display();
      break;
      case 3:
      break;
      default:
      cout<<"Invalid choice"<<endl;
    }
  }while(choice1!=3);
  cout<<"For Polynomial 2"<<endl;
  polynomial p2;
  int choice2;
  do{
    cout<<"Enter choice: ";
    cin>>choice2;
    switch(choice2){
      case 1:
      int coeff,power;
      cout<<"Enter coefficient: ";
      cin>>coeff;
      cout<<"Enter power: ";
      cin>>power;
      p2.enqueue(coeff,power);
      break;
      case 2:
      p2.display();
      break;
      case 3:
      break;
      default:
      cout<<"Invalid choice"<<endl;
    }
  }while(choice2!=3);
  polynomial p3;
  addPolynomials(p1,p2,p3);
  p3.display();
  return 0;
}
