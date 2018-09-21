#include <cstdio>
#include <queue>
#include <string.h>

#define MAX 10001

using namespace std;

int MGraph[MAX][MAX];
int visit[MAX] = { 0 };

void InitGraph( int n ) {
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            MGraph[i][j] = 0;
}

void InsertEdge( int i, int j ) {
    MGraph[i][j] = 1;
    MGraph[j][i] = 1;
}

double BFS( int curNode, int n ) {
    queue<int> q;
    visit[curNode] = 1;
    q.push( curNode );

    int count = 1;
    for( int level = 0; level < 6; level++ ) {
        vector<int> vec;
        while( !q.empty() ) {
            int node = q.front();
            vec.push_back( node );
            q.pop();
        }
        for( int i = 0; i < vec.size(); i++ ) {
            int node = vec[i];
            for( int i = 1; i <= n; i++ ) {
                if( !visit[i] && MGraph[node][i] == 1 ) {
                    //printf( "%d ", i );
                    q.push( i );
                    visit[i] = 1;
                    count++;
                }
            }
        }

    }


    double rate = (double)count / (double)n;
    return rate * 100.0;
}

int main() {
    //freopen( "123.txt", "r", stdin );
    int N, E;
    scanf( "%d%d", &N, &E );

    InitGraph( N );

    int a, b;
    for( int i = 0; i < E; i++ ) {
        scanf( "%d%d", &a, &b );
        InsertEdge( a, b );
    }

    for( int i = 1; i <= N; i++ ) {
        memset( visit, 0, sizeof( visit[0] ) * ( N + 1 ) );
        //printf( "{ " );
        double r = BFS( i, N );
        //printf( "}  " );
        printf( "%d: %.2lf%%\n", i, r );
    }
    return 0;
}
