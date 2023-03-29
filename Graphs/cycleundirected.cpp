bool cycle(int N, vector<int> adj[],int vis[]){
        queue<pair<int,int>> q;
        vis[N] = 1;
        q.push({N,-1});
        while(!q.empty()){
            auto node = q.front().first;
            auto parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(parent != it)
                return true;
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i < V; ++i){
            if(!vis[i]){            
                if(cycle(i,adj,vis))
                    return true;
            }
        }
        return false;
    }
