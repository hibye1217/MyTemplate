bool primality_N(int x){
	if (x == 1){ return 0; }
    for (int i = 2; i < x; i++){ if (x%i == 0){ return 0; } }
    return 1;
}

bool primality_sqrtN(ll x){
	if (x == 1){ return 0; }
    for (ll i = 2; i*i <= x; i++){ if (x%i == 0){ return 0; } }
    return 1;
}

vector<char> eratosthenes(int n){
	vector<char> res(n, 1);
	res[0] = res[1] = 0;
	for (int i = 2; i <= n; i++){
		if (!res[i]){ continue; }
		for (int j = i+i; j <= n; j+=i){ res[j] = 0; }
	}
	return res;
}

vector<ll> factorize(ll x){
	vector<ll> res;
	for (ll i = 2; i*i <= x; i++){
		while (x%i == 0){ res.push_back(i); x /= i; }
	}
	if (x != 1){ res.push_back(x); }
	return res;
}