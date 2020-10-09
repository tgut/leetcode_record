#include "iostream"
#include "queue"
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int size = user_queue.size();
        if(size ==0 )
            user_queue.push(x);
        else{   
            user_queue.push(x);
            while(size--){
               int val;
               val = user_queue.front();
               user_queue.pop();
               user_queue.push(val);
           }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val;
        val = user_queue.front();//it's last element is user_queue.back()
        user_queue.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        // int val;
        return user_queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return user_queue.empty();
    }
    private:
        queue<int> user_queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main(){
    MyStack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(6);
    int i= 0;
    while(!a.empty()){
        cout<< i++ <<":" <<a.top() <<endl;
        a.pop();
    }
    return 0;
}