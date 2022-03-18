class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastIdx(128,0); //vector of size 128
        for(int i = 0 ; i < n ;i++){
            lastIdx[s[i]] = i;
        }
        vector<bool> seen(128, false); // size 128
        stack<char> st;
        
        for(int i = 0 ;i < n ; i++){
            int curr = s[i];
            if(seen[curr]) continue;
            while(!st.empty() and st.top() > curr and i < lastIdx[st.top()]){
                seen[st.top()] =  false;
                st.pop();
            }
            st.push(curr);
            seen[curr] = true;
        }
        string ans ="";
        while(!st.empty()){
            ans = st.top() + ans; // now no need to reverse
            st.pop();
        }
        return ans;
    }
};