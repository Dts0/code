#include "iostream"
#include "math.h"
using namespace std;
int n, m;
#define MINLEN 42.5
struct Pointer {
    int x;
    int y;
}p[101];
bool answer = false; /* 记录007能否安全逃生~~ */
bool visited[101] = {false}; /* 判断当前点是否被访问过 */

bool isSave(int x) { /* 判断从当前点能否跳到岸上 */
    if ((p[x].x - m <= -50) || (p[x].x + m >= 50) || (p[x].y - m <= -50) || (p[x].y + m >= 50))
        return true;
    return false;
}

bool jump(int x, int y) { /* 判断2个点距离是否在跳跃能力内 */
        int p1 = pow(p[x].x - p[y].x, 2);
        int p2 = pow(p[x].y - p[y].y, 2);
        int r = m * m;
        if (p1 + p2 <= r)
            return true;
        return false;
}

bool firstJump(int x) {  /* 当007处于孤岛时 第一次可以选择跳的鳄鱼 因为第一次判断能否跳跃的计算方法与后面dfs不相同 所以要单独写 */
    int p1 = pow(p[x].x , 2);
    int p2 = pow(p[x].y , 2);
    int r = (m+7.5) * (m+7.5);
    if (p1 + p2 <= r) {
        return true;
    }
    return false;
}
bool dfs(int x) { /* 深搜 */
    visited[x] = true;
    if (isSave(x)) {
        answer = true;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && jump(x, i)) /* 没访问过 并且在跳跃能力之内 */
        {
            answer = dfs(i);
            if (answer == true)
                break;
        }
    }
    return answer;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    if (m >= MINLEN) { /* 可以直接从孤岛上提到岸上 直接输出 */
        cout << "Yes" << endl;
        return 0;
    }
        for (int i = 0; i < n; i++) {
            if (firstJump(i) && !visited[i]) { /* 如果第一次能够跳的 并且之前没有访问过的节点 则深搜该节点 */
                if (dfs(i))
                    break;
            }
        }
        if (answer == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return 0;
}
