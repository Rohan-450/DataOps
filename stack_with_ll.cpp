#include<iostream>
using namespace std;
#define MAX 5

class node{
    public:
        int data;
        node* next;
};

class stack{
    private:
        node* head;
        int count;
    public:
        stack(){
            head = NULL;
            count = 0;
        }
        void push(int value);
        void pop();
        void display();
        void peek();
};

void stack::push(int value){
    if(count<MAX){
        node* new_node = new node;
        new_node->data = value;
        new_node->next = head;
        head = new_node;
        count++;
    }
    else{
        cout<<"Stack overflow";
        return;
    }
}

void stack::pop(){
    if(count <= 0){
        cout<<"Stack underflow";
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    count--;
    return;
}

void stack::display(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}

void stack::peek(){
    if(head == NULL){
        cout<<"Empty stack";
        return;
    }
    cout<<"Top element:"<<head->data;
    return;
}

int main(){

    stack s;
    int value,choice;

    cout<<"Menu\n";
    cout<<"1.)Push\n";
    cout<<"2.)Pop\n";
    cout<<"3.)Display\n";
    cout<<"4.)Peek\n";
    cout<<"0.)Exit\n";

    do{
        cout<<"\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value:";
                cin>>value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                s.peek();
                break;

            case 0:
                cout<<"Exiting program....";
                break;

            default:
                cout<<"Please enter correct option";
                break;
        }
    }
    while(choice != 0);

    return 0;
}