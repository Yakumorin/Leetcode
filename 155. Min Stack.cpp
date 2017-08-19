class MinStack {
    vector<int> s1, s2;
public:
    
    void push(int x) {
        if(s2.empty() || x <= getMin()) s2.push_back(x);
        s1.push_back(x);
    }
    
    void pop() {
        if(s1.back() == s2.back()) s2.pop_back();
        s1.pop_back();
    }
    
    int top() {
        return s1.back();
    }
    
    int getMin() {
        return s2.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
