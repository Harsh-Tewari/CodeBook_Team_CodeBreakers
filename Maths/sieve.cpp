vector<ll> sieve(int n)
{
	int *arr = new int[n + 1]();
	vector<ll> vect;
	for (int i = 2; i <= n; i++)
		if (arr[i] == 0)
		{
			vect.push_back(i);
			for (int j = 2 * i; j <= n; j += i)
				arr[j] = 1;
		}
	return vect;
}
