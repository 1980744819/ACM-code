# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>
# include <ctime>
using namespace std;

# define REP_0(i, n) for (int i = 0; i < n; ++ i)
# define RST(a) memset (a, 0, sizeof (a))

typedef long long ll;

int next_int () {
	char c; int i;
	for (c = getchar (); c < '0' || c > '9'; c = getchar ());
	for (i = c - '0', c = getchar (); c >= '0' && c <= '9'; i = i * 10 + c - '0', c = getchar ());
	return i;
}

ll gcd (ll a, ll b) { return !b ? a : gcd (b, a % b); }
int pr (int a, int z, int p) { int s = 1; do { if (z & 1) s = 1ll * s * a % p; a = 1ll * a * a % p; } while (z >>= 1); return s; }

struct Matrix { ll a[2][2]; Matrix () { RST (a); } };



Matrix getI () { Matrix a; REP_0 (i, 2) a.a[i][i] = 1; return a; }
Matrix getA () {
	Matrix a;
	a.a[0][0] = 1;
	a.a[0][1] = 1;
	a.a[1][0] = 1;
	return a;
}

namespace Mat {
	int mod;

	Matrix operator* (const Matrix& a, const Matrix& b) {
		Matrix c;
		REP_0 (i, 2) REP_0 (k, 2) REP_0 (j, 2) c.a[i][j] += a.a[i][k] * b.a[k][j];
		REP_0 (i, 2) REP_0 (j, 2) c.a[i][j] %= mod;
		return c;
	}

	Matrix pr (Matrix a, int z) {
		Matrix s = getI ();
		do { if (z & 1) s = s * a; a = a * a; } while (z >>= 1);
		return s;
	}
}

int fib (int n, int mod) {
	if (n == 0) return 0;
	Mat::mod = mod;
	Matrix g = Mat::pr (getA (), n - 1);
	return g.a[0][0];
}

int legendre (int a, int p) { return pr (a, (p - 1) / 2, p) == 1 ? 1 : -1; }

vector <int> get_factor (int n) {
	vector <int> fac;
	for (int i = 1; i * i <= n; ++ i) if (n % i == 0) {
		fac.push_back (i);
		if (i * i != n) fac.push_back (n / i);
	}
	return fac;
}

int find_loop_prime (int p) {
	if (p == 2) return 3;
	if (p == 3) return 8;
	if (p == 5) return 20;

	int ans;
	vector <int> fac = legendre (5, p) == 1 ? get_factor (ans = p - 1) : get_factor (ans = 2 * (p + 1));
	for (int d=0;fac[d]!='\0';d++) if (fib (d, p) == 0 && fib (d + 1, p) == 1 && d < ans) ans = d;
	//printf ("!fp %d %d\n", p, ans);
	return ans;
}

int find_loop (int n) {
	vector <int> li;
	for (int i = 2; i * i <= n; ++ i) if (n % i == 0) {
		int res = find_loop_prime (i); n /= i;
		while (n % i == 0) n /= i, res *= i;
		li.push_back (res);
	}
	if (n != 1) li.push_back (find_loop_prime (n));
	ll ans = 1;
	//printf ("[");
	for (int d=0;li[d]!='\0';d++) ans = ans / gcd (ans, d) * d;//, printf ("%d ", d);
	//printf ("]\n");
	//	printf("!!!%d %d\n", n, ans);
	return ans;
}

int vis[1001000];

void helper0 () {
	while (true) {
		int mod;
		int t; scanf ("%d%d", &t, &mod);
		printf ("%d\n", fib (t, mod));
	}
}

void helper1 () {
	static bool vv[201000];
	int s, mod;
	scanf ("%d%d", &s, &mod);
	for (int x = fib (s, mod); !vv[x]; x = fib (x, mod))
		printf ("%d ", x), vv[x] = true;

}

int solve (const int x0, const int mod) {
	int cur, next = mod;

		vector <int> li;

		do {
			cur = next;
			li.push_back (cur);
			next = find_loop (cur);
		} while (next != cur);

		const int fin = li.back ();
		const int len = li.size ();

		REP_0 (i, fin) vis[i] = 0;

		for (int x = fib (x0 % fin, fin), id = 0; vis[x] == 0; x = fib (x, fin)) /*printf ("!%d ", x),*/ vis[x] = ++ id;
		//puts ("");

		int ans = -1;


		REP_0 (i, len) {
			//printf ("%d ", li[i]);
			int x = x0;
			for (int j = i; j >= 0; -- j) x = fib (x, li[j]);
			//printf ("!%d %d\n", i, x);
			if (x == x0 % mod) {
				ans = i + 1;
				break;
			}
		}

		//printf ("---\n");

		if (ans == -1) {
			REP_0 (i, fin) if (vis[i] != 0) {
				int x = i;
				//if (x == x0 % mod) printf ("vis%d(%d): ", i, vis[i]);
				for (auto it = li.rbegin (); it != li.rend (); ++ it) {
					x = fib (x, *it);

					//printf ("%d ", x);
				}
				//puts ("");
				if (x == x0 % mod) {
					if (ans == -1 || ans > len + vis[i]) {
						ans = len + vis[i];
					}
				}
			}
		}

		return ans;
}

void helper2 () {
	int mod;
	scanf ("%d", &mod);
	for (int i = 900000000; ; ++ i) {
		//if (solve (i, mod) >= 3000) printf ("%d %d\n", i, mod);
		if (solve (i, mod) >= 10) printf ("%d %d\n", i, mod);
		//if (i % 1000 == 0) printf ("proc(%d)\n", i);
	}
}

int main () {
	for (int T = next_int (); T; -- T) {
		const int x0 = next_int ();
		const int mod = next_int ();
		printf ("%d\n", solve (x0, mod));
		//printf ("!!(%d %d)\n", fib(fib (x0, 91200), mod), x0% mod);
	}
	//fprintf(stderr,"%.2f s\n",clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
