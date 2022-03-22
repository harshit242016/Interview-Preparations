class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string s(n,'a');
        k -= n;
        
        for(int i = n-1;i>=0;i--)
        {
            if(k>=26)
            {
                k-=25;
                s[i] = 'z';
            }
            else
            {
                s[i] = (char)k+'a';
                break;
            }
        }
        
        return s;
    }
};