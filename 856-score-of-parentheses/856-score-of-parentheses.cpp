class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        int count_paren = 0;
        int ans = 0;
        
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(')    
            {
                count_paren++;
            }
            else
            {
                count_paren--;      
                if(s[i-1] == '(')
                {
                    int z = pow(2,count_paren);
                    ans += max(1,z);
                }
            }
        }
        return ans;
    }
};