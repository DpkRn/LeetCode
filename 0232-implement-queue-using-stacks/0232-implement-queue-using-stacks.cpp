//push(), Pop(), top() -> O(N)
class MyQueue {
public:
    stack<int> input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(input.size()+output.size()==0) return -1;
        if(output.empty()){
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int x=output.top();
        output.pop();
        return x;
        
        
    }
    
    int peek() {
         if(!output.empty()){
            return output.top();
        }else{
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
      return input.size()+output.size()==0;
    }
};
/*
O(N) push()
O(1) pop(), top()
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

*/

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */