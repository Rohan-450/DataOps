#include<iostream>
using namespace std;
#define MAX 5

class node{
    public:
        int data;
        node* next;
};

class queue{
    private:
        node* head;
        int count;
    public:
        queue(){
            head = NULL;
            count = 0;
        }
        void enqueue(int value);
        void dequeue();
        void display();
        void peek();
};

void queue::enqueue(int value){
    if(count < MAX){
        node* new_node = new node;
        new_node->data = value;
        if(head == NULL){
            new_node->next = NULL;
            head = new_node;
            count++;
            return;
        }
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
        count++;
        return;
    }
    else{
        cout<<"Queue overflow";
        return;
    }
}

void queue::dequeue(){
    if(count <= 0){
        cout<<"Queue underflow";
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    // count--;
    return;
}

void queue::display(){
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

void queue::peek(){
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    cout<<"Top element:"<<temp->data;
    return;
}

int main(){

    queue q;
    int value,choice;

    cout<<"Menu\n";
    cout<<"1.)Enqueue\n";
    cout<<"2.)Dequeue\n";
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
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                q.peek();
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