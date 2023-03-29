ll mod_add(ll a, ll b, ll m)
{
	a = a % m;
	b = b % m;
	return (((a + b) % m) + m) % m;
}

ll mod_mul(ll a, ll b, ll m)
{
	a = a % m;
	b = b % m;
	return (((a * b) % m) + m) % m;
}

ll mod_sub(ll a, ll b, ll m)
{
	a = a % m;
	b = b % m;
	return (((a - b) % m) + m) % m;
}

ll mod_div(ll a, ll b, ll m)
{
	a = a % m;
	b = b % m;
	return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime ma

ll mminv(ll a, ll b)
{
	ll arr[3];
	extendgcd(a, b, arr);
	return arr[0];
} // for non prime b

ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
