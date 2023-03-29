int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    for(int i=0; i < nums.size(); ++i){
	        v.push_back({nums[i],i});
	    }
	    
	    sort(begin(v), end(v));
	    
	    int count = 0;
	    for(int i=0; i< nums.size(); ++i){
	        if(v[i].second == i)
	        continue;
	        else
	        {
	            int ind = v[i].second;
	            pair<int,int> temp = v[ind];
	            v[ind] = v[i];
	            v[i] = temp;
	            i--;
	            count++;
	        }
	    }
	    return count++;
	}
