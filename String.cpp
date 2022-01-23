/// [KMP] Knuth-Morris-Prett
vector<int> jmp, ans;
void setJmp(string s){ int sl = s.size();
	jmp.resize(sl);
	int j = 0;
	for (int i = 1; i < sl; i++){
		while (j != 0){
			if (s[i] == s[j]){ break; }
			else{ j = jmp[j-1]; }
		}
		if (s[i] == s[j]){
			j += 1; jmp[i] = j;
		}
	}
}
void kmp(string s1, string s2){ int l1 = s1.size(), l2 = s2.size();
	setJmp(s2);
	int j = 0;
	for (int i = 0; i < l1; i++){
		while (j != 0){
			if (s1[i] == s2[j]){ break; }
			else{ j = jmp[j-1]; }
		}
		if (s1[i] == s2[j]){
			if (j == l2-1){ ans.push_back(i-j+1); j = jmp[j]; }
			else{ j += 1; }
		}
	}
} // Approved [BOj-1786-37987234]

/// [SFA-LCP] Suffix Array & Longest Common Prefix Array
vector<int> pos; int sl, k;
bool cmpSA(int s1, int s2){
	if (pos[s1] != pos[s2]){ return pos[s1] < pos[s2]; }
	int ss1 = s1+k, ss2 = s2+k;
	if (ss1 >= sl || ss2 >= sl){ return ss1 > ss2; }
	return pos[ss1] < pos[ss2];
}
void SA_LCP(vector<int>& sa, vector<int>& lcp, string str){
	sl = str.size();
	sa.resize(sl); pos.resize(sl);
	for (int i = 0; i < sl; i++){ sa[i] = i; pos[i] = str[i]; }
	for (k = 1; ; k *= 2){
		sort(all(sa), cmpSA);
		vector<int> res(sl, 0);
		for (int ri = 1; ri < sl; ri++){
			res[ri] = res[ri-1];
			if ( cmpSA(sa[ri-1], sa[ri]) ){ res[ri] += 1; }
		}
		for (int ri = 0; ri < sl; ri++){
			pos[ sa[ri] ] = res[ri];
		}
		if (res[sl-1] == sl-1){ break; }
	}

	k = 0;
	for (int si = 0; si < sl; si++){
		k -= 1; if (k < 0){ k = 0; }
		int r1 = pos[si], r2 = pos[si]-1;
		if (r2 < 0){ continue; }
		int s1 = sa[r1], s2 = sa[r2];
		while (s1+k < sl && s2+k < sl){
			if (str[s1+k] == str[s2+k]){ k += 1; }
			else{ break; }
		}
		lcp[ pos[si] ] = k;
	}
}
