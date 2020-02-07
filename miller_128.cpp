#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

// modular multiplication to numbers up to 10^18 in O(1)
// __int128 is a well accepted gcc extension also compatible with clang
inline ll mul(ll a, ll b, ll c)
{
	__int128(a)*b%c;
}

// modular exponatiation in O(log(n))
inline ll power(ll a, ll b, ll c)
{
	ll res = 1;
	while (b > 0) {

		if (b&1) {

			res = mul(res, a, c);
		}
		a = mul(a, a, c);
		b /= 2;
	}
	return res;
}

// miller-rabin strong pseudoprimality test in complexity O(log(n))
// returns false if n is composite
// returns true if n is prime or strong pseudoprime in base a
bool witness(ll n, ll d, ll s, ll a)
{
	ll x = power(a, d, n);
	ll y;

	// pass trought all a^(d*2^k) mod n ( 0 <= k <= s )
	while (s--) {

		y = mul(x, x, n);

		// if y is equal to 1 it must have been a square of -1 or 1 mod n to be prime
		// if not the number is composite
		if (y == 1 and x != 1 and x != n-1) return false;

		x = y;
	}
	// if a^(d*2^s) != 1 mod n than n is not prime
	// a^(n-1) = 1 mod n for every n prime (fermats little theorem)
	if (y != 1) return false;

	// if the number is not confirmed composite return that it is either a prime
	// or strong pseudoprime in base a
	return true;
}

// all numbers up to 10^18 are confirmed composite if these bases are used
// if numbers are up to 10^9 use primes_small to confirm compositeness
ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
ll primes_small[] = {2, 3, 5, 7, 11};

// ckeck primality up to 10^18 in O(log(n)*k)
// to numbers up to 10^18, testing all 9 prime numbers smaller or equal to 23 suffices
bool is_prime(ll n)
{
	// trivial cases
	if (n == 2 or n == 3) return true;
	if (n < 2 or n%2 == 0 or n%3 == 0) return false;

	// calculate d = biggest odd number divisor of n-1
	// s = number of the biggest power of two that divides n-1
	// such that n-1 = d*2^s (d odd)
	// __builtin_ctzll returns expoent of biggest power of two that divides n-1
	ll s = __builtin_ctzll(n-1);
	ll d = (n-1)>>s;

	// check primality with the 13 bases
	for (ll p : primes) {

		if (p == n) return true;

		// if composite returns false
		if (!witness(n, d, s, p)) return false;
	}

	// after the iterations all remaining numbers are prime
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while (t--) {

		ll x;
		cin >> x;

		if (is_prime(x)) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}
