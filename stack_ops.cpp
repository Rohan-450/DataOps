#include<iostream>
using namespace std;
#define MAXSIZE 1000
class stack{
    private:
        int arr[MAXSIZE];
        int top;
    public:
        stack();
        void push(int);
        int pop();
        bool isEmpty();
        bool isFull();
        int peek();
        int getSize();
};
stack::stack(){top=-1;}
void stack::push(int value){
    if(isFull()){
        cout<<"Stack is Full"<<endl;
        return;
    }
    else{
        top++;
        arr[top]=value;
        cout<<"Element inserted successfully"<<endl;
    }
}
int stack::pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
    else{
        int x=arr[top--];
        return x;
    }
}
bool stack::isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}
bool stack::isFull(){
    if(top==MAXSIZE-1)
        return true;
    else
        return false;
}
int stack::peek(){
    if(!isEmpty())
        return arr[top];
    else{
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
}
int stack::getSize(){
    return (top+1);
}
int main(){
    stack sc;
    int ch;
    do{
        cout<<"1.Push"<<endl
            <<"2.Pop"<<endl
            <<"3.Is it Empty"<<endl
            <<"4.Is it Full"<<endl
            <<"5.Peek"<<endl
            <<"6.Size of stack"<<endl
            <<"7.Exit"<<endl
            <<"Enter Choice"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                int data;
                cout<<"Enter Value"<<endl;
                cin>>data;
                sc.push(data);
                break;
            case 2:
                cout<<sc.pop()<<endl;
                break;
            case 3:
                cout<<sc.isEmpty()<<endl;
                break;
            case 4:
                cout<<sc.isFull()<<endl;
                break;
            case 5:
                cout<<sc.peek()<<endl;
                break;
            case 6:
                cout<<sc.getSize()<<endl;
                break;
            case 7:
                exit(0);
                break;
            default:
                cout<<"Wrong Choice"<<endl;
        }
    }while(1);
}
