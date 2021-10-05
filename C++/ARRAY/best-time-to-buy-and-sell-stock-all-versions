//LEETCODE

// 121. Best Time to Buy and Sell Stock I :

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int profit = 0;
        for(int i = 0 ; i < prices.size() ; i++)
        {
            min_price = min(min_price,prices[i]);
            profit = max(profit , prices[i] - min_price);
        }
        return profit;
    }
};


////////////////////////////////////////////////////////////////////////
// 122. Best Time to Buy and Sell Stock II :

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int net_profit = 0;
        for(int i = 1 ; i < prices.size() ; i++)
        {
            if(prices[i] > prices[i-1])
            {
                net_profit += prices[i] - prices[i-1];
            }
        }
        return net_profit;
        
    }
};

//////////////////////////////////////////////////////////////////////// 
// 123. Best Time to Buy and Sell Stock III :

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price1 = INT_MAX;
        int profit1 = 0;
        int min_price2 = INT_MAX;
        int profit2 = 0;
        for(int i = 0 ; i < prices.size() ; i++)
        {
            min_price1 = min(min_price1,prices[i]);
            profit1 = max(profit1,prices[i] - min_price1);
            min_price2 = min(min_price2,prices[i]-profit1);
            profit2 = max(profit2,prices[i] - min_price2);
            
        }
        return profit2;
        
    }
};


//////////////////////////////////////////////////////////////////////// 
// 188. Best Time to Buy and Sell Stock IV :

class Solution {
public:
    int help(vector<int>& prices)
    {
        int net_profit = 0;
        for(int i = 1 ; i < prices.size() ; i++)
        {
            if(prices[i] > prices[i-1])
            {
                net_profit += prices[i] - prices[i-1];
            }
        }
        return net_profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        if(k<=0||prices.size() <=0)
        {
            return 0;
        }
        if(k>prices.size()/2)
        {
            return help(prices);
        }
        
        
        
        int min_price[k];
        int max_profit[k];
        for(int i = 0 ; i < k ; i++)
        {
            min_price[i] = INT_MAX;
            max_profit[i] = 0;
        }
        for(int i = 0 ; i < prices.size() ; i++)
        {
            for(int j = 0 ; j < k ; j++)
            {
                min_price[j] = min(min_price[j],prices[i]-(j>0?max_profit[j-1]:0));
                max_profit[j] = max(max_profit[j],prices[i] - min_price[j]);
            }
              
        }
        return max_profit[k-1];
        
        
    }
};

//////////////////////////////////////////////////////////////////////// 
// 309. Best Time to Buy and Sell Stock with Cooldown :

//Below code will give TLE :

class Solution{
public:
    int help(int i , vector<int>& prices , int bag)
    {
        if(i >= prices.size())
        {
            return 0;
        }

        if(bag == 1)
        {
            int opt2 = prices[i] + help(i+2,prices,0);
            int opt3 = help(i+1,prices,1);
            return max(opt2,opt3);
        }
        else
        {
            int opt1 = -prices[i] + help(i+1,prices,1);
            int opt3 = help(i+1,prices,0);
            return max(opt1,opt3);
        }
    }
    int maxProfit(vector<int>& prices)
    {
        return help(0,prices,0);
    }
};

// Modified Code : Conversion of recursion into top down dynamic programming (memoization)

class Solution{
public:
    int help(int i , vector<int>& prices , int bag ,vector<vector<int>>& dp)
    {
        if(i >= prices.size())
        {
            return 0;
        }
        if(dp[i][bag] != -1)
        {
            return dp[i][bag];
        }

        if(bag == 1)
        {
            int opt2 = prices[i] + help(i+2,prices,0,dp);
            int opt3 = help(i+1,prices,1,dp);
            return dp[i][bag] = max(opt2,opt3);
        }
        else
        {
            int opt1 = -prices[i] + help(i+1,prices,1,dp);
            int opt3 = help(i+1,prices,0,dp);
            return dp[i][bag] = max(opt1,opt3);
        }
    }
    int maxProfit(vector<int>& prices)
    {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return help(0,prices,0,dp);
    }
};

//////////////////////////////////////////////////////////////////////// 
// 714. Best Time to Buy and Sell Stock with Transaction Fee

class Solution{
public:
    int maxProfit(vector<int>& prices,int fee)
    {
        vector<vector<int>> dp(prices.size(),vector<int> (2,0));
        dp[0][0] = -(prices[0]+fee);
        for(int i = 1 ; i < prices.size() ; i++)
        {
            dp[i][0] = max(dp[i-1][0] , dp[i-1][1] - (prices[i] + fee));
            dp[i][1] = max(dp[i-1][0] + prices[i] , dp[i-1][1]);
        }
        return dp[prices.size()-1][1];
    }
};
