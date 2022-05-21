char console[6570][6570];
void sierpinski_carpet(int n, int yst, int xst){ int yed = yst+n, xed = xst+n;
	if (n == 1){ console[yst][xst] = '*'; return; }
	int m = n/3;
	int y1 = yst, y2 = yst+m, y3 = yed-m, y4 = yed;
	int x1 = xst, x2 = xst+m, x3 = xed-m, x4 = xed;
	sierpinski_carpet(m, y1, x1); sierpinski_carpet(m, y1, x2); sierpinski_carpet(m, y1, x3);
	sierpinski_carpet(m, y2, x1);                               sierpinski_carpet(m, y2, x3);
	sierpinski_carpet(m, y3, x1); sierpinski_carpet(m, y3, x2); sierpinski_carpet(m, y3, x3);
}