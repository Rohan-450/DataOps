#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

class cll{
    private:
        node* head;
    public:
        cll(){
            head = NULL;
        }
        void ins_beg(int value);
        void ins_end(int value);
        void del_beg();
        void del_end();
        void del_value(int value);
        void display();
        void search(int value);
};

void cll::ins_beg(int value){
    node* new_node = new node;
    new_node->data = value;
    if(head == NULL){
        new_node->next = new_node;
        head = new_node;
        return;
    }
    node* temp = head;
    new_node->next = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = new_node;
    head = new_node;
    return;
}

void cll::ins_end(int value){
    node* new_node = new node;
    new_node->data = value;
    if(head == NULL){
        new_node->next = new_node;
        head = new_node;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    return;
}

void cll::display(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    while(temp != head);
}

void cll::del_beg(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }
    node* temp = head;
    node* temp2 = head;
    while(temp2->next != head){
        temp2 = temp2->next;
    }
    temp2->next = head->next;
    head = head->next;
    delete temp;
}

void cll::del_end(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    if(head->next == head){
        cll::del_beg();
        return;
    }
    node* temp = head;
    node* temp2 = NULL;
    while(temp->next != head){
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = head;
    delete temp;
    return;
}

void cll::del_value(int value){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    if(head->data == value){
        cll::del_beg();
        return;
    }
    node* temp = head->next;
    node* prev = head;
    while(temp->next != head){
        if(temp->data == value){
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if(temp->data == value){
        cll::del_end();
        return;
    }
    cout<<value<<" not found";
    return;
}

void cll::search(int value){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    do{
        if(temp->data == value){
            cout<<value<<" found";
            return;
        }
        temp = temp->next;
    }
    while(temp != head);
    cout<<value<<" not found";
    return;
}

int main(){

    cll list;
    int value,choice;

    cout<<"Menu\n";
    cout<<"1.)Insert from beginning\n";
    cout<<"2.)Insert from end\n";
    cout<<"3.)Delete from beginning\n";
    cout<<"4.)Delete from end\n";
    cout<<"5.)Delete value\n";
    cout<<"6.)Display from beginning\n";
    cout<<"7.)Search value\n";
    cout<<"0.)Exit\n";

    do{
        cout<<"\nEnter your choice:";
        cin>>choice;

        switch (choice){
            case 1:
                cout<<"Enter value:";
                cin>>value;
                list.ins_beg(value);
                break;

            case 2:
                cout<<"Enter value:";
                cin>>value;
                list.ins_end(value);
                break;

            case 3:
                list.del_beg();
                break;

            case 4:
                list.del_end();
                break;

            case 5:
                cout<<"Enter value:";
                cin>>value;
                list.del_value(value);
                break;

            case 6:
                list.display();
                break;

            case 7:
                cout<<"Enter value:";
                cin>>value;
                list.search(value);
                break;

            default:
                cout<<"Please enter correct option";
                break;
        }
    }
    while(choice != 0);

    return 0;
}