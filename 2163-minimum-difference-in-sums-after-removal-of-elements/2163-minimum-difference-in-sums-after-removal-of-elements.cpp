typedef long long ll;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        
        ll n = nums.size()/3;
        
        priority_queue<int,vector<int>,greater<>> small(begin(nums)+2*n,end(nums));
        priority_queue<int> large(nums.begin(),nums.begin()+n);
        
        ll l_sum = accumulate(begin(nums),begin(nums)+n,0LL);
        ll r_sum = accumulate(begin(nums)+2*n,end(nums),0LL);
        
        vector<ll> v(n+1,0);
        
        for(int i = n;i<=2*n;i++)
        {
            v[i-n] = l_sum;
            if(large.top() > nums[i])
            {
                l_sum += (nums[i] - large.top());
                large.pop();
                large.push(nums[i]);
            }
        }
        
        for(int i = 2*n-1;i>=n-1;i--)
        {
            v[i-n+1] -= r_sum;
            if(small.top() < nums[i])
            {
                r_sum += (nums[i] - small.top());
                small.pop();
                small.push(nums[i]);
            }
        }
        for(int i = 0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return *min_element(begin(v),end(v));
    }
};