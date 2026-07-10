class CustomStack {
public:
    int index = -1;
    vector<int> st;

    CustomStack(int maxSize) {
        st.resize(maxSize);
        //size created
    }
    
    void push(int x) {

        if(index >= (int)st.size()-1) return;

        st[++index] = x; 
        //index increse after insertion
    }
    
    int pop() {

        if(index == -1) return -1;//stack empty

        return st[index--];   
    }
    
    void increment(int k, int val) {

        if(index == -1) return; //empty

        for(int i=0; i<k && i<=index; i++)
        {
            st[i] += val;
        }  
    }
};