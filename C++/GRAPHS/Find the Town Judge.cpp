#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> Indegree(N+1 , 0);
        vector<int> Outdegree(N+1 , 0);
        
        for(auto tmp : trust)
        {
            Outdegree[tmp[0]]++;
            
            Indegree[tmp[1]]++;
        }
        
        for(int i = 1; i <= N; i++)
        {
            if(Indegree[i] == N-1 && Outdegree[i] == 0)
                return i;
        }
        return -1;
    }
};

int main()
{
    int N;
    cout<<"Enter the value of N :- ";
    cin>>N;
    
    vector<int> trust(N);
    
    for(int i = 0; i < N; i++)
        cin>>trust[i];
    
    Solution obj;
    
    int ans = obj.findJudge(N, trust);
    
    cout<<ans;
    
}
