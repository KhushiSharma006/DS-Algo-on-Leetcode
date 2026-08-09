class MyQueue {
public:
    // using 2 stack: 
    stack<int> s1, s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        // push s1 in s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        // push x in s1
        s1.push(x);

        // push s2 to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    }
    
    int pop() {
        int ele = s1.top();
        s1.pop();
        return ele;
    }
    
    int peek() {
        return s1.top();
        
    }
    
    bool empty() {
        return s1.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */