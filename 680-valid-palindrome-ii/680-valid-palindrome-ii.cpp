class Solution {
public:
    bool validPalindrome(string s) 
    { if(s.length() == 0) return false;
		
    int i = 0, j = s.length()-1;
    while(i < j && s[i] == s[j]) 
    {
        i++; j--;
    }
    if(i >= j) 
        return true;
		
    int i1 = i, j1 = j-1; 
    while(i1 < j1 && s[i1] == s[j1]) 
    {
        i1++; j1--;
    }
     
    if(i1 >= j1) 
        return true;
		
    int i2 = i+1, j2 = j;
    while(i2 < j2 && s[i2] == s[j2]) 
    {
        i2++; j2--;
    }
     
    return i2 >= j2;
    }
    
};