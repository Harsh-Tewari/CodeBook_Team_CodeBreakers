void extendgcd(ll a, ll b, ll *v)
{
	if (b == 0)
	{
		v[0] = 1;
		v[1] = 0;
		v[2] = a;
		return;
	}
	extendgcd(b, a % b, v);
	ll x = v[1];
	v[1] = v[0] - v[1] * (a / b);
	v[0] = x;
	return;
} // pass an arry of size1 3
