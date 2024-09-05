// https://leetcode.com/problems/course-schedule-ii/description/

class Solution
{
public:
    vector<int> bfs(unordered_map<int, vector<int>> &mp, int numCourses, vector<int> &indegree)
    {
        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            // Decrease the indegree of all neighbors
            for (int &v : mp[curr])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // If the size of the result is equal to numCourses, it means there is no cycle
        if (ans.size() == numCourses)
        {
            return ans;
        }

        // Cycle detected, return an empty vector
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> mp;
        vector<int> indegree(numCourses, 0);

        // Build the adjacency list and calculate the indegree of each course
        for (const auto &prerequisite : prerequisites)
        {
            int a = prerequisite[0];
            int b = prerequisite[1];
            mp[b].push_back(a); // b -> a (to take course `a`, you must complete course `b`)
            indegree[a]++;
        }

        // Perform BFS (Kahn's Algorithm) to find the topological order
        return bfs(mp, numCourses, indegree);
    }
};
