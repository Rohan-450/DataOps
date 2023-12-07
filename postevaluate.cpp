#include<stack>
#include<iostream>
using namespace std;
int op1,op2;
int postfixeva(string s){
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9')
            st.push(s[i]-'0');
        else{
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();
            if(s[i]=='+')
                op1+=op2;
            else if(s[i]=='-')
                op1-=op2;
            else if(s[i]=='/')
                op1/=op2;
            else if(s[i]=='*')
                op1*=op2;
            else    
                op1^=op2;
        }
        st.push(op1);
    }
    return st.top();
}
int main(){
    cout<<"Enter a valid postfix expression"<<endl;
    string s;
    cin>>s;
    cout<<postfixeva(s)<<endl;
    return 0;
}
