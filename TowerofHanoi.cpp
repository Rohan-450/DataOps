#include<iostream>
using namespace std;

void tower_of_hanoi(int n, char source,char auxiliary,char target){
    if (n == 1){
        cout<<"Move disk 1 from "<<source<<" to "<<target<<endl;
        return;
    }  
    tower_of_hanoi(n - 1, source, target, auxiliary);
    cout<<"Move disk " <<n<<" from "<<source<<" to "<<target<<endl;
    tower_of_hanoi(n - 1, auxiliary, source, target);
}

int main(){
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}
