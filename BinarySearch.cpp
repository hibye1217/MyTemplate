template<class I>
I binSer(I l, I r, bool up){
	I st = l, ed = r;
	while (st+1 < ed){
		I mid = st+ed >> 1;
		if ( ckf(mid) ){ st = mid; }
		else{ ed = mid; }
	}
	if (!up){ return st; }
	else{ return ed; }
} // Approved (1654-37716922)

template<class I>
I binJmp(int x, bool up){
	I ans = 0;
	for (int b = x; b >= 0; b--){
		I bit = (I)1 << b;
		if ( ckf(ans+bit) ){ ans += bit; }
	}
	if (!up){ return ans; }
	else{ return ans+1; }
} // Approved (1654-37716998)
