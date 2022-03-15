class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
       int n = s.size();
        int i = 0;
        stack<int> st;
        
        for(int i = 0;i<n;i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(!st.empty() and s[i] == ')')
            {
                st.pop();
            }
            else if(s[i] == ')')
            {
                s[i] = '*';
            }
        }
        
        while(!st.empty())
        {
            s[st.top()] = '*';
            st.pop();
        }
        
        string res;
        for(int i = 0;i<n;i++)
        {
            if(s[i]!='*')
            {
                res += s[i];
            }
        }
        
        return res;
    }
};