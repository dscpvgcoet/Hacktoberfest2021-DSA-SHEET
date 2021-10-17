// 169. Majority Element Solution

class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int majorityElement(vector<int>& nums) {
        int maxcount=0;
        int major;
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto it:mp)
        {
            maxcount = max(maxcount,it.second);
            if(maxcount==it.second)
                major = it.first;
        }
        return major;
    }
};