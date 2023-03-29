#include<bits/stdc++.h>
using namespace std;
class DSU{
	public:
	vector<int> rank, parent, size;
	DSU(int n){
		rank.resize(n+1,0);
		parent.resize(n+1);
		size.resize(n+1);
		for(int i=0; i <= n; ++i){
		parent[i] = i;
		size[i] = 1;
	   }
	}

	int findParent(int node)
	{
		if(node==parent[node])
		return node;
		return parent[node] = findParent(parent[node]);
	}

	void UnionbyRank(int u, int v)
	{
		int ulp_u = findParent(u);
		int ulp_v = findParent(v);
		if(ulp_u == ulp_v) return;
		if(rank[ulp_u] < rank[ulp_v])
		parent[ulp_u] = ulp_v;
		else if(rank[ulp_v] < rank[ulp_u])
		parent[ulp_v] = ulp_u;
		else
		{
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}
	
	void UnionbySize(int u, int v)
	{
		int ulp_u = findParent(u);
		int ulp_v = findParent(v);
		if(ulp_u == ulp_v) return;
		if(size[ulp_u] < size[ulp_v])
		{
			size[ulp_v] += size[ulp_u];
			parent[ulp_u] = ulp_v;
		}
		else
		{
			size[ulp_u] += size[ulp_v];
			parent[ulp_v] = ulp_u;
		}
	}
};
