class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()<0)
          return 0;
        int sum = nums[0];
        int max_sum = nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            if (sum < 0)
            {
                sum = 0;
            }
            sum = sum + nums[i];
            if (sum > max_sum)
            {
                max_sum = sum;
            }   
        }
        return max_sum;
    }
};
