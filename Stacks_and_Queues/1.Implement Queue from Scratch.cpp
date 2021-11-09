#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Queue{
    public:
    int front,rear,size,capacity;
    int* q;
    Queue(int c){
        size=0;
        capacity=c;
        q=new int[capacity];
        front=0;
        rear=0;
    }
    bool isFull(){
        return size==capacity;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(int ele){
        if(isFull()){
            cout<<"QUEUE IS FULL"<<endl;
            return;
        }
        q[rear]=ele;
        rear++;
        size++;
        
    }
    int peepfront(){
        if(isEmpty()){
           cout<<"QUEUE IS EMPTY"<<endl;
            return -1; 
        }
        return q[front];
    }
    int peeprear(){
        if(isEmpty()){
           cout<<"QUEUE IS EMPTY"<<endl;
            return -1; 
        }
        return q[rear-1];
    }
    void dequeue(){
        if(isEmpty()){
           cout<<"QUEUE IS EMPTY"<<endl;
            return; 
        }
       q[front]=0;
       front++;
       size--;
    }
    
};

int main() {
    // Write C++ code here
Queue q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    
    while(!q.isEmpty()){
        cout<<q.peepfront()<<" "<<q.peeprear()<<endl;
        q.dequeue();
    }

    return 0;
}
