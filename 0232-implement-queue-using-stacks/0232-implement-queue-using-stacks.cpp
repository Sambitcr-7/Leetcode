class MyQueue {
private:
    // create stack, one is to store the val and 
    // second one is used to rearrange the val stored in first stack
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // move every val of stack s1 to stack s2 
        while(!s1.empty()) {
            int ele = s1.top();

            s2.push(ele);
            s1.pop();
        }

        // when s1 get's empty put the curr val in it, after that push all s2 val in s1
        s1.push(x);
        while(!s2.empty()) {
            int ele = s2.top();
            s1.push(ele);
            s2.pop();
        }

    }
    
    int pop() {
        int val = s1.top();
        s1.pop();

        return val;
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