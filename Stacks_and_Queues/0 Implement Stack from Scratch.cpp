// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
    int maxsize;
    vector<int> stk;
    int curr;
    public:
    Stack(int mxsiz){
        maxsize=mxsiz;
        curr=-1;
    }
    int size(){
        return stk.size();
    }
    int isEmpty(){
        return stk.size()==0;
    }
    int top(){
        if(isEmpty()){
            return -1;
        }
        return stk[size()-1];
    }
    void push(int ele){
        curr++;
        if(curr==maxsize){
            cout<<"STACK OVERFLOW"<<endl;
            return;
        }
        stk.push_back(ele);
    }
    void pop(){
        if(isEmpty()){
            cout<<"STACK IS EMPTY"<<endl;
            return;
        }
        stk.pop_back();
        curr--;
    }
};

int main() {
    Stack s(5);
    s.push(1);
     s.push(2);
      s.push(3);
       s.push(4);
        s.push(5);
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
