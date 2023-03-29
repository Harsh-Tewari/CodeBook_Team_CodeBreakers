// fastest LIS Length Calculation
int n = v.size();
vector<int> a(1);
int ind = 0;
for (int i = 0; i < n; i++)
{
    ind = lower_bound(a.begin(), a.end() - 1, v[i]) - a.begin();
    if (ind == a.size() - 1)
    {
        a.push_back(0);
    }
    a[ind] = v[i];
}
return a.size() - 1;