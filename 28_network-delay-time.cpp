// https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<pair<int,int>>> adj ;

        for(auto &vec : times)
        {
            int u = vec[0] ;
            int v = vec[1] ;
            int w = vec[2] ;

            adj[u].push_back({v,w}) ;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq ;


        vector<int> res(n+1 , INT_MAX) ;

        pq.push({0,k}) ;

        res[k] = 0 ;

        while(!pq.empty())
        {
            int d = pq.top().first ;
            int node = pq.top().second ;
            pq.pop() ;

            for(auto &v : adj[node])
            {
                int adj_node = v.first ;
                int dis = v.second ;

                if(d + dis < res[adj_node])
                {
                    res[adj_node] = d + dis ;
                    pq.push({d+dis , adj_node}) ;
                }
            }
        }
        int ans = INT_MIN ;

        for(int i = 1 ; i <= n; ++i)
        {
            ans = max(ans, res[i]) ;
        }

        if(ans == INT_MAX)
        {
            return -1 ;
        }

        return ans ;


    }
};
