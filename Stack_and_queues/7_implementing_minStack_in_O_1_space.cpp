class MinStack {
    private:
    stack<long>s;
    long minE;
public:
    MinStack() {
        
    }
    
    //this is the answer for leetcode problem

// i have done explicit conversion becoz there are some test cases that have "val" values around INT_MAX,
// so i have used long for stack and minE, but before returning i am again converting it them to int becoz 
//they require answer in integer
    
    void push(int val) {
        if(s.empty()){
            s.push(val); 
            minE=val;
        }
        else if(val>=minE)s.push(val);
        else{
            s.push(2*(long)val-minE);
            minE=val;
        }
    }
    
    void pop() {
        if(!s.empty()){
            if(s.top()<minE){
                minE=2*minE-s.top();
                s.pop();
            }
            else{
                s.pop();
            }
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        else{
            if(s.top()<minE){
                return (int)minE;
            }
            else{
                return s.top();
            }
        }
    }
    
    int getMin() {
        if(s.empty())return -1;
        else return (int)minE;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */