class MyQueue {
public:

    stack<int>st1, st2;
    bool isRev;

    MyQueue() {
        isRev=1;
        
    }
    
    void push(int x) {
        if(isRev==1){
            st1.push(x);
        }else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st1=st2;
            stack<int>st;
            st2=st;
            st1.push(x);
            isRev=1;
        }       
    }
    
    int pop() {
        if(st1.empty()) return -1;
        if(isRev==0){
            int top=st1.top();
            st1.pop();
            return top;
        }else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st1=st2;
            stack<int>st;
            st2=st;
            int top=st1.top();
            st1.pop();
            isRev=0;
            return top;
        }       
    }
    
    int peek() {
        if(st1.empty()) return -1;
        if(isRev==0){
            int top=st1.top();
            return top;
        }else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st1=st2;
            stack<int>st;
            st2=st;
            int top=st1.top();
            isRev=0;
            return top;
        }         
    }
    
    bool empty() {
        return st1.empty();        
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