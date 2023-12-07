#include<iostream>
using namespace std;
#define MAXSIZE 1000
class queue{
    private:
        int arr[MAXSIZE];
        int front;
        int rear;
    public:
        queue();
        void enqueue(int);
        int dequeue();
        bool isEmpty();
        bool isFull();
        int peek();
        int getSize();
};
queue::queue(){
    front=-1;
    rear=-1;
}
void queue::enqueue(int value){
    if(isFull()){
        cout<<"Queue is Full"<<endl;
        return;
    }
    else{
        if(rear==-1){
            front++;
            rear++;
            arr[rear]=value;
            cout<<"Element inserted successfully"<<endl;
        }
        else{
             rear++;
             arr[rear]=value;
             cout<<"Element inserted successfully"<<endl;
        }
    }
}
int queue::dequeue(){
    if(isEmpty()){
        cout<<"Queue is Empty"<<endl;
        return 0;
    }
    else{
        int x=arr[front++];
        return x;
    }
}
bool queue::isEmpty(){
    if(front==rear)
        return true;
    else
        return false;
}
bool queue::isFull(){
    if(rear==MAXSIZE-1)
        return true;
    else
        return false;
}
int queue::peek(){
    if(!isEmpty())
        return arr[rear];
    else{
        cout<<"Queue is Empty"<<endl;
        return -1;
    }
}
int queue::getSize(){
    return ((rear-front)+1);
}
int main(){
    queue sc;
    int ch;
    do{
        cout<<"1.Enqueue"<<endl
            <<"2.Dequeue"<<endl
            <<"3.Is it Empty"<<endl
            <<"4.Is it Full"<<endl
            <<"5.Peek"<<endl
            <<"6.Size of Queue"<<endl
            <<"7.Exit"<<endl
            <<"Enter Choice"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                int data;
                cout<<"Enter Value"<<endl;
                cin>>data;
                sc.enqueue(data);
                break;
            case 2:
                cout<<sc.dequeue()<<endl;
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
