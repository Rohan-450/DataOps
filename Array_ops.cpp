#include<iostream>
using namespace std;
#define MAX 100

class Array{
    private:
        int ar[MAX];
        int size;
    public:
        Array(){
            size = 0;
        }
        void initialize_array(int a[],int s){
            if(size > MAX){
                cout<<"Maximum limit crossed";
                return;
            }
            for(int i=0;i<s;i++){
                ar[i] = a[i];
            }
            size = s;
            cout<<"Array initialized";
            return;
        }
        void insert_element(int x,int k){
            if(k<=0 || k>size+1){
                cout<<"Invalid index";
                return;
            }
            for(int i=size;i>=k-1;i--){
                ar[i+1] = ar[i];
            }
            ar[k-1] = x;
            size++;
            return;
        }
        void update_element(int x,int k){
            if(k<=0 || k>size+1){
                cout<<"Invalid index";
                return;
            }
            ar[k-1] = x;
            return;
        }
        int search_element(int x){
            for(int i=0;i<size;i++){
                if(ar[i]==x){
                    return i;
                }
            }
            return -1;
        }
        void remove_element(int x){
            int l = search_element(x);
            if(l==-1){
                cout<<"Element not found";
                return;
            }
            for(int i=l;i<size;i++){
                ar[i] = ar[i+1];
            }
            size--;
            return;
        }
        void display_array(){
            if(size==0){
                cout<<"Array is empty";
                return;
            }
            for(int i=0;i<size;i++){
                cout<<ar[i]<<" ";
            }
            return;
        }
};



int main(){
    Array arr;
    int a[100],s,choice,x,k,p;
    cout<<"Enter size of array:";
    cin>>s;
    cout<<"Initialize the array:";
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    arr.initialize_array(a,s);

    do{
        cout<<"\nMenu\n";
        cout<<"1.)Insert element\n";
        cout<<"2.)Update element\n";
        cout<<"3.)Search element\n";
        cout<<"4.)Remove element\n";
        cout<<"5.)Display\n";
        cout<<"0.)Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to insert:";
                cin>>x;
                cout<<"Enter position to insert:";
                cin>>k;
                arr.insert_element(x,k);
                break;
            case 2:
                cout<<"Enter element to update:";
                cin>>x;
                cout<<"Enter position to update:";
                cin>>k;
                arr.update_element(x,k);
                break;
            case 3:
                cout<<"Enter element to search:";
                cin>>x;
                p = arr.search_element(x);
                if (p == -1){
                    cout<<x<<" not found";
                }
                else{
                    cout<<x<<" found at position "<<p+1;
                }
                break;
            case 4:
                cout<<"Enter element to remove:";
                cin>>x;
                arr.remove_element(x);
                break;
            case 5:
                arr.display_array();
                break;
            case 0:
                cout<<"Exiting...";
                break;
            default:
                cout<<"Invalid choice";
                break;
        }
    }
    while(choice!=0);


    return 0;
}