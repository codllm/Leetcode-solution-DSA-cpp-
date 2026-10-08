class CustomStack {
public:
    int index = -1;
    vector<int>stack;
    CustomStack(int maxSize) {
        stack.resize(maxSize);
    }
    
    void push(int x) {

        if(index >= (int)stack.size()-1) return;
        //stack full

        stack[++index] = x; 
    }
    
    int pop() {

        if(index == -1) return -1; //stack empty
        return stack[index--];   
    }
    
    void increment(int k, int val) {

        if(index == -1) return;
        //no element in the index so no increment

        for(int i=0;i<k && i<=index ; i++)
        {
            stack[i] = stack[i] + val;
        }  
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */