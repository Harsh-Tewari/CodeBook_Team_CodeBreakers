vector<int> t[4 * MAXN];

void build(int a[], int v, int tl, int tr)
{
	if (tl == tr)
	{
		t[v] = vector<int>(1, a[tl]);
	}
	else
	{
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(),back_inserter(t[v]));
	}
}
