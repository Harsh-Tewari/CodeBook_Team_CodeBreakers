typedef pair<int,int> pt;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       priority_queue<pt,vector<pt>,greater<pt>> q;
       vector<int> vis(V,0);
       q.push({0,0});
       int sum = 0;
       while(!q.empty())
       {
           auto it = q.top();
           q.pop();
           int node = it.second;
           int wt = it.first;
           
           if(vis[node] == 1) continue;
           vis[node] = 1;
           sum += wt;
           for(auto nodes : adj[node]){
               int adjNode = nodes[0];
               int wtt = nodes[1];
               if(!vis[adjNode]){
                   q.push({wtt,adjNode});
               }
           }
       }
       return sum;
    }
