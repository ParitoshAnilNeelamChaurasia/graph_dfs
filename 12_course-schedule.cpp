// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    int n ;

    bool topological_sort(unordered_map<int,vector<int>> &mp , int numCourses , vector<int> &indegree)
    {
        queue<int>q ;

        int count = 0 ;

        for(int i = 0 ; i < numCourses ; ++i)
        {
            if(indegree[i] == 0)
            {
                q.push(i) ;
                count++ ;
            }
        }

        while(!q.empty())
        {
            int curr = q.front() ;
            q.pop() ;

            for(int &v : mp[curr])
            {
                indegree[v]-- ;

                if(indegree[v] == 0)
                {
                    count++ ;
                    q.push(v) ;
                }
            }
        }

        // cycle didn't present
        if(count == numCourses)
        {
            return true ;
        }

        // cycle present
        return false ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = prerequisites.size() ;

        unordered_map<int,vector<int>> mp ;

        vector<int> indegree(numCourses,0) ;

        for(int i = 0 ; i < n ; ++i)
        {
            int a = prerequisites[i][0] ;
            int b = prerequisites[i][1] ;
            
            // b --->>> a
            mp[b].push_back(a) ;

            indegree[a]++ ;
        }

        // if cycle present -> return false

        return topological_sort(mp , numCourses , indegree) ;
    }
};
