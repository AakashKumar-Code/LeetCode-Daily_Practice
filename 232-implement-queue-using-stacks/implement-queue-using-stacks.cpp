class MyQueue {
public:

    stack<int>input, output;

    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);        
    }
    
    int pop() {
        int top=-1;
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        if(!output.empty()){
            top=output.top();
            output.pop();
        }       
        return top;
    }
    
    int peek() {
        int top=-1;
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        if(!output.empty()){
            top=output.top();
        }       
        return top;
        
    }
    
    bool empty() {
        return (input.empty() && output.empty());
        
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