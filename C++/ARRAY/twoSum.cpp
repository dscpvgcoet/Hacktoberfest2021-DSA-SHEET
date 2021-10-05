///   TWO SUM   ///


// Solution 1 :
// Time Compexity : O(n^2)
// Space Compexity : O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i  = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                if((nums[i] + nums[j]) == target)
                {
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};

////////////////////////////////////////////////////////////////////////////
// Solution 2 :
// Time Compexity : O(n)
// Space Compexity : O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i = 0 ; i < n ; i++)
        {
            int x = nums[i];
            int y = target - x;
            if(m.find(y) != m.end())
            {
                return {i,m[y]};
            }
            m[nums[i]] = i;
        }
        return {-1,-1};
    }
};

////////////////////////////////////////////////////////////////////////////
//Solution 3 : (This is best when array is sorted)
// Time Compexity : O(nlogn)   //Due to sorting
// Space Compexity : O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i = 0 ; i < n ; i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int start = 0 , end = n - 1;
        while(start < end)
        {
            int sum = v[start].first + v[end].first;
            if(sum == target)
            {
                return {v[start].second,v[end].second};
            }
            else if (sum > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return {-1,-1};
    }
};
