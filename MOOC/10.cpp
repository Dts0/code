#include <cstdio>
#include <cstdlib>
#include <queue>

#define MAX 10

using namespace std;

typedef struct {
    int index;
    int lchild;
    int rchild;
} Node;

Node node[MAX];
int isRoot[MAX] = { 0 };

int main() {
    //freopen( "123.txt", "r", stdin );
    int n;
    scanf( "%d", &n );
    char ch = getchar();
    for( int i = 0; i < n; i++ ) {
        char left, right;
        scanf( "%c %c", &left, &right );
        char ch = getchar();
        node[i].index = i;
        if( left != '-' ) {
            node[i].lchild = left - '0';
        }
        else {
            node[i].lchild = -1;
        }
        if( right != '-' ) {
            node[i].rchild = right - '0';
        }
        else {
            node[i].rchild = -1;
        }
    }

    //输出每个结点信息
    //for( int i = 0; i < n; i++ ) {
    //    printf( "%d %d\n", node[i].lchild, node[i].rchild );
    //}
    
    // 查找根节点
    for( int i = 0; i < n; i++ ) {
        int child;
        if( node[i].lchild != -1 ) {
            child = node[i].lchild;
            isRoot[child] = 1;
        }
        if( node[i].rchild != -1 ) {
            child = node[i].rchild;
            isRoot[child] = 1;
        }
    }

    //for( int i = 0; i < n; i++ ) {
    //    printf( "%d ", isRoot[i] );
    //}
    //printf( "\n" );
    
    // 查找树根
    int root = 0;
    for( int i = 0; i < n; i++ ) {
        if( isRoot[i] == 0 ) {
            root = i;
            break;
        }
    }

    //printf( "root: %d\n", root );
    // 层序遍历
    queue<Node> q;
    q.push( node[root] );

    int count = 0;
    while( !q.empty() ) {
        Node curNode = q.front();
        q.pop();
        if( curNode.lchild != -1 ) {
            int child = curNode.lchild;
            q.push( node[child] );
        }
        if( curNode.rchild != -1 ) {
            int child = curNode.rchild;
            q.push( node[child] );
        }
        if( curNode.lchild == -1 && curNode.rchild == -1 ) {
            if( count == 0 ) {
                printf( "%d", curNode.index );
                count = 1;
            }
            else {
                printf( " %d", curNode.index );
            }
        }
    }
    return 0;
}

