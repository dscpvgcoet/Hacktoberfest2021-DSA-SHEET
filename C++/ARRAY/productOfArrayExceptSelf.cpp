class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        int right = 1;
        vector<int> product;
        
        for(int i = 0; i < nums.size(); i++)
        {
            product.push_back(left);
            left *= nums[i]; 
        }
        
        for(int i = nums.size() -1; i > -1; i--)
        {
            product[i] = (right*product[i]);  // left * right
            right *= nums[i];             
        }
        return product;
    }
};
