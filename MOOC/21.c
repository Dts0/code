#include <stdio.h>
#define Max 10000
int g[100][100];
int main() {
	int n, m, w, i, j, k, maxl, minl = Max;
	scanf("%d %d\n", &n, &m);
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++)
			g[i][j] = Max;
	}
	while (m--) {
		scanf("%d %d %d\n", &i, &j, &w);
		g[i-1][j-1] = w;
		g[j-1][i-1] = w;
	}
	for (k = 0;k < n;k++) {
		for (i = 0;i < n;i++) {
			for (j = 0;j < n;j++) {
				if (g[i][k] + g[k][j] < g[i][j])
					g[i][j] = g[i][k] + g[k][j];
			}
		}
	}	
	for (i = 0;i < n;i++) {
		maxl = 0;
		for (j = 0;j < n;j++) {
			if (i != j && g[i][j]>maxl)
				maxl = g[i][j];
			if (maxl >= Max) break;
		}	
		if (maxl < minl) {
			k = i + 1;
			minl = maxl;
		}
	}
	if (minl < Max) printf("%d %d", k, minl);
	else printf("0");
	return 0;
}
