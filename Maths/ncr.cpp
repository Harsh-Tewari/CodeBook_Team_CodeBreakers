LL ncrp(LL n, LL r, LL p)
{
	LL C[r + 1];
	memset(C, 0, sizeof(C));
	C[0] = 1;
	for (LL i = 1; i <= n; i++)
	{
		for (LL j = min(i, r); j > 0; j--)
			C[j] = (C[j] + C[j - 1]) % p;
	}
	return C[r];
}
LL ncrpl(LL n, LL r, LL p)
{
	if (r == 0)
		return 1;
	int ni = n % p, ri = r % p;
	return (ncrpl(n / p, r / p, p) * ncrp(ni, ri, p)) % p;
}
