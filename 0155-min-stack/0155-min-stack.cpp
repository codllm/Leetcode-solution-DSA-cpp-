class MinStack {
public:
    stack<int>mainst;
    stack<int>minst;
    MinStack() {
        //idea bohot simple hai every elemnt k coressponding min elemnt bhi store kro stack mein

    }
    
    void push(int value) {

        if(mainst.empty())
        {
            mainst.push(value);
            minst.push(value);
            return;
        }

        if(minst.top()<value)
        {
            mainst.push(value);
            minst.push(minst.top());
            return;
        }
        mainst.push(value);
        minst.push(value);

        
    }
    
    void pop() {

        minst.pop();
        mainst.pop();
    }
    
    int top() {

        return mainst.top();    
    }
    
    int getMin() {

        return minst.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */