#include <stdio.h>
#include <string.h>
#define N 500
#define INF 501
int g[N][N][2], dis[N + 1], known[N], pay[N];
int main() {
	int n, m, s, d, i, j, t1, t2, v;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			g[i][j][0] = INF;
			g[i][j][1] = INF;
		}
	}
	while (m--) {
		scanf("%d%d%d%d", &i, &j, &t1, &t2);
		g[i][j][0] = g[j][i][0] = t1;
		g[i][j][1] = g[j][i][1] = t2;
	}
	
	memset(known, 0, n*sizeof(int));
	for (j = 0;j < n;j++) {
		dis[j] = g[s][j][0];
		pay[j] = g[s][j][1];
	}
	dis[s] = 0;
	pay[s] = 0;
	dis[n] = INF;
	
	while (1) {
		v = n;
		for (i = 0;i < n;i++) {
			if (!known[i] && dis[i] < dis[v])
				v = i;
		}
		if (v == n) break;
		known[v] = 1;
		for (i = 0;i < n;i++) {
			if (!known[i] && g[v][i][0] < INF) {
				if (dis[v] + g[v][i][0] < dis[i]) {
					dis[i] = dis[v] + g[v][i][0];
					pay[i] = pay[v] + g[v][i][1];
				}
				else if (!known[i] && dis[v] + g[v][i][0] == dis[i] &&
					pay[v] + g[v][i][1] < pay[i]) {
					pay[i] = pay[v] + g[v][i][1];
				}
			}
		}
	}
	if(dis[d] < INF)
		printf("%d %d", dis[d], pay[d]);	
	return 0;
}

