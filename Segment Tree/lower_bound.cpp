// for a given value x find the smallest i in the range of l-r whose value of a[i] > x
int get_first(int v, int lv, int rv, int l, int r, int x)
{
	if (lv > r || rv < l)
		return -1;
	if (l <= lv && rv <= r)
	{
		if (t[v] <= x)
			return -1;
		while (lv != rv)
		{
			int mid = lv + (rv - lv) / 2;
			if (t[2 * v] > x)
			{
				v = 2 * v;
				rv = mid;
			}
			else
			{
				v = 2 * v + 1;
				lv = mid + 1;
			}
		}
		return lv;
	}

	int mid = lv + (rv - lv) / 2;
	int rs = get_first(2 * v, lv, mid, l, r, x);
	if (rs != -1)
		return rs;
	return get_first(2 * v + 1, mid + 1, rv, l, r, x);
}
