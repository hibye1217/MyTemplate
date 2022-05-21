ll factorial(int n){
	ll res = 1;
	for (int i = 1; i <= n; i++){ res *= i; }
	return res;
}