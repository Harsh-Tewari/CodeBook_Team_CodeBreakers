void dfs(int i, vector<pair<int,int>> adj[], stack<int>&st, vector<int>&vis)
     {
         vis[i] = 1;
         for(auto node : adj[i])
         {
             auto v = node.first;
             if(!vis[v])
             {
                 dfs(v,adj,st,vis);
             }
         }
         st.push(i);
     }
  
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(auto it : edges)
        adj[it[0]].push_back({it[1],it[2]});
        stack<int> st;
        vector<int> vis(N,0);
        for(int i=0; i < N; ++i)
        {
            if(!vis[i])
            dfs(i,adj,st,vis);
        }
        
        vector<int> dist(N,1e9);
        dist[0] = 0;
        while(!st.empty())
        {
            auto node = st.top();
            st.pop();
            for(auto nodes : adj[node])
            {
                int v = nodes.first;
                int wt = nodes.second;
                if(dist[node] + wt < dist[v])
                dist[v] = dist[node] + wt;
            }
        }
        vector<int> ans(N);
        for(int i =0; i < dist.size(); ++i)
        {
            if(dist[i] == 1e9)
            ans[i] = -1;
            else
            ans[i] = dist[i];
        }
        return ans;
    }
