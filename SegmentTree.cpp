template<class I>
class SegTree{ public: SegTree(){}
	int n, nn; vector<I> seg;
	SegTree(int n): n(n){
		nn = 1; while (nn < n){ nn <<= 1; }
		seg.resize(nn*2, 0);
	}
	void upd(int pos, I val){ pos += nn-1;
		seg[pos] = val; pos >>= 1;
		while (pos > 0){
			seg[pos] = seg[pos<<1] + seg[pos<<1|1]; pos >>= 1;
		}
	}
	I qry(int st, int ed){ st += nn-1; ed += nn-1;
		I res = 0;
		while (st <= ed){
			if (st & 1){ res += seg[st]; st += 1; }
			if (~ed & 1){ res += seg[ed]; ed -= 1; }
			if (st > ed){ break; }
			st >>= 1; ed >>= 1;
		}
		return res;
	}
}; // Approved (2042-37715686)

template<class I>
class RecSegTree{ public: RecSegTree(){}
	int n, nn; vector<I> seg;
	RecSegTree(int n): n(n){
		nn = 1; while (nn < n){ nn <<= 1; }
		seg.resize(nn*2, 0);
	}
	void upd(int ni, int ns, int ne, int pos, I val){
		if (pos < ns || ne < pos){ return; }
		if (ns == ne){ seg[ni] = val; return; }
		int mid = ns+ne >> 1;
		upd(ni<<1, ns, mid, pos, val); upd(ni<<1|1, mid+1, ne, pos, val);
		seg[ni] = seg[ni<<1] + seg[ni<<1|1];
	}
	void upd(int pos, I val){ return upd(1, 1, nn, pos, val); }
	I qry(int ni, int ns, int ne, int st, int ed){
		if (ed < ns || ne < st){ return 0; }
		if (st <= ns && ne <= ed){ return seg[ni]; }
		int mid = ns+ne >> 1;
		return qry(ni<<1, ns, mid, st, ed) + qry(ni<<1|1, mid+1, ne, st, ed);
	}
	I qry(int st, int ed){ return qry(1, 1, nn, st, ed); }
}; // Approved (2042-37715783)

template<class I>
class LazySegTree{ public: LazySegTree(){}
	int n, nn; vector<I> seg, laz;
	LazySegTree(int n): n(n){
		nn = 1; while (nn < n){ nn <<= 1; }
		seg.resize(nn*2, 0); laz.resize(nn*2, 0);
	}
	void pro(int ni, int ns, int ne){
		seg[ni] += laz[ni]*(ne-ns+1);
		if (ns != ne){
			laz[ni<<1] += laz[ni];
			laz[ni<<1|1] += laz[ni];
		}
		laz[ni] = 0;
	}
	void upd(int ni, int ns, int ne, int st, int ed, I val){
		pro(ni, ns, ne);
		if (ed < ns || ne < st){ return; }
		if (st <= ns && ne <= ed){ laz[ni] += val; pro(ni, ns, ne); return; }
		int mid = ns+ne >> 1;
		upd(ni<<1, ns, mid, st, ed, val); upd(ni<<1|1, mid+1, ne, st, ed, val);
		seg[ni] = seg[ni<<1] + seg[ni<<1|1];
	}
	void upd(int st, int ed, I val){ return upd(1, 1, nn, st, ed, val); }
	I qry(int ni, int ns, int ne, int st, int ed){
		pro(ni, ns, ne);
		if (ed < ns || ne < st){ return 0; }
		if (st <= ns && ne <= ed){ return seg[ni]; }
		int mid = ns+ne >> 1;
		return qry(ni<<1, ns, mid, st, ed) + qry(ni<<1|1, mid+1, ne, st, ed);
	}
	I qry(int st, int ed){ return qry(1, 1, nn, st, ed); }
}; // Approved (10999-37715904)
