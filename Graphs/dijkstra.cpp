vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,S});
        vector<int> dist(V,1e9);
        dist[S] = 0;
        while(!q.empty())
        {
            auto distance = q.top().first;
            auto node = q.top().second;
            q.pop();
            
            for(auto nodes : adj[node])
            {
                int adjNode = nodes[0];
                int wt = nodes[1];
                if(distance + wt < dist[adjNode])
                {
                    dist[adjNode] = distance + wt;
                    q.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
