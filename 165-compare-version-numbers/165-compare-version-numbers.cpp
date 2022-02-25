class Solution {
public:
    int compareVersion(string s1, string s2) 
    {
        int i = 0,j = 0;
        
        int n1 = s1.size();
        int n2 = s2.size();
        
        int x = 0, y = 0;
        while(i<n1 or j<n2)
        {
            while(i<n1 and s1[i]!='.')
            {
                x = (x * 10) + (s1[i]-'0');
                i++;
            }
            while(j<n2 and s2[j]!='.')
            {
                y = (y*10) + (s2[j]-'0');
                j++;
            }
            if(x<y)
            {
                return -1;
            }
            else if(x>y)
            {
                return 1;
            }
            else
            {
                x = 0,y = 0;
                i++;
                j++;
            }
        }
        
        return 0;
        
    }
};