class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
         
        //create a adjancy list
        vector<int>adj[n];

        for(int i=0;i<relations.size();i++)
        {
            //convertthem into 0 baswd indexing 
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }

        vector<int>InDeg(n,0);
        for(int i=0;i<n;i++)
        for(int j=0;j<adj[i].size();j++)
        InDeg[adj[i][j]]++;

        queue<int>q;
        for(int i=0;i<n;i++)
        if(!InDeg[i])
        q.push(i);


        //maximum time to complete previous course
        vector<int>CourseTime(n,0);

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

           for(int j=0;j<adj[node].size();j++)
           {
           InDeg[adj[node][j]]--;
           if(!InDeg[adj[node][j]])
           q.push(adj[node][j]);
           
            //maximum time to complete previous course + present course time
            CourseTime[adj[node][j]]=max(CourseTime[adj[node][j]], CourseTime[node]+time[node]);

          }
        }

        int ans=0;
         for(int i=0;i<n;i++)
         {
            ans=max(ans,CourseTime[i]+time[i]);
         }

         return ans;

    }
};