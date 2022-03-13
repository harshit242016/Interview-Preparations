class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(s[i]=='{')
            {
                st.push(s[i]);
            }
            else if(s[i]=='}')
            {
                if(st.empty())
                {
                    return false;
                }
                else
                {
                    char x = st.top();
                    st.pop();
                    if(x!='{')
                    {
                        return false;
                    }
                }
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    return false;
                }
                else
                {
                    char x = st.top();
                    st.pop();
                    if(x!='(')
                    {
                        return false;
                    }
                }
            }
            else if(s[i] == ']')
            {
                if(st.empty())
                {
                    return false;
                }
                else
                {
                    char x = st.top();
                    st.pop();
                    if(x!='[')
                    {
                        return false;
                    }
                }
            }
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};