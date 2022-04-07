/// type
using ll = long long;
using ld = long double;
using ull = unsigned long long;

/// pair
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;

using cpl = complex<ld>;

/// vector
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

/// Some Mathematical Constants
/* C++20
const ld pi = numbers::pi;
const ld e = numbers::e;
*/
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2*pi;
const ld e = 2.718281828459045;
const ld eps = 1e-15;

/// Faster!
#pragma GCC optimize("Ofast")

/// Modulars
const ll mod = 1e9 + 7;
const ll mod = 998244353;

/// Movements
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}; /// ^ > v <
const int ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}; /// ^ ^> > >v v v< < <^
const int ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}; /// ^> >^ >v v> v< <v <^ ^<

/// Random
mt19937 gen(time(NULL));
uniform_int_distribution<int> rng(a, b); // a <= x <= b
int nxt = rng(gen);