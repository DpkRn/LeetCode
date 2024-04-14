class MyStack {
public:
    queue<int> q,temp;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        q.push(x);
         while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
    }
    
    int pop() {
        if(!q.empty()) {
            int x=q.front(); 
            q.pop();
            return x;
        }else return -1;
    }
    
    int top() {
        if(q.empty()) return -1;
        else return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */