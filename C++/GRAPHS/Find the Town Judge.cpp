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
