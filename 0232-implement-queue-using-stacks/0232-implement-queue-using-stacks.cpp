class MyQueue {
public:
    stack<int> st,temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
         while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        if(!st.empty()){
            int x=st.top();
            st.pop();
            return x;
        }else return -1;
    }
    
    int peek() {
        if(st.empty()) return -1;
        else return st.top();
    }
    
    bool empty() {
        return st.empty();
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