class Solution {
public:
    int longestDecomposition(string text) {
        string left_str = "";
        string right_str = "";
        int n = text.size();
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            left_str += text[i];
            right_str = text[n-i-1] + right_str;
            if(left_str == right_str)
            {
                count++;
                left_str = "";
                right_str = "";
            }
        }
        return count;
    }
};