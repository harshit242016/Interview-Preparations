class FreqStack {
public:
    FreqStack() {
        
    }
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> freq_stack;
    
    int maxFreq = 0;
    
    void push(int val) 
    {
        freq[val] = freq[val] + 1;
        int temp = freq[val];
        if(maxFreq < temp)
        {
            maxFreq = temp;
        }
        freq_stack[temp].push(val);
    }
    
    int pop() 
    {
        int temp = freq_stack[maxFreq].top();
        freq_stack[maxFreq].pop();
        --freq[temp];
        if(freq_stack[maxFreq].size() == 0)
        {
            maxFreq--;
        }
        return temp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */