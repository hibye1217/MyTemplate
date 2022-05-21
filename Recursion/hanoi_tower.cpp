vector<pi2> res;
void hanoi_tower(int n, int st, int ed){ int mid = 6 - (st+ed);
	if (n == 1){ res.push_back({st, ed}); return; }
	hanoi_tower(n-1, st, mid);
	res.push_back({st, ed});
	hanoi_tower(n-1, mid, ed);
}