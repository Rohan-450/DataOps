#include<stack>
#include<iostream>
using namespace std;
char infix[100],postfix[100];
int precedence(char x){
    if(x=='^')
        return 3;
    if(x=='*'|| x=='/')
        return 2;
    if(x=='+'|| x=='-')
        return 1;
    return -1;
}
int isOperand(char ch){
    return (ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9');
}
int isOperator(char ch){
    if(ch=='*'|| ch=='/')
        return 1;
    else if(ch=='+'|| ch=='-')
        return 1;
    else
        return 0;
}
void infixtopostfix(){
    int i=0,j=0;
    stack<int> s;
    while(infix[i]!='\0'){
        char ch=infix[i];
        if(isOperand(ch))
            postfix[j++]=ch;
        else if(ch=='(')
            s.push(ch);
        else if(ch==')'){
            while(s.top()!='('){
                postfix[j++]=s.top();
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(ch)){
            while(!s.empty() && s.top()!='(' && precedence(ch)<=precedence(s.top())){
                postfix[j++]=s.top();
                s.pop();
            }
            s.push(ch);
        }
        else{
            cout<<"Invalid Expression"<<endl;
            exit(1);
        }
        i++;
    }
    while(!s.empty()){
        postfix[j++]=s.top();
        s.pop();
    }
    postfix[j]='\0';
}
int main(){
    cout<<"Enter an infix expression"<<endl;
    cin>>infix;
    infixtopostfix();
    cout<<"Postfix Expression:"<<postfix<<endl;
    return 0;
}