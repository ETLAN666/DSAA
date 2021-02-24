/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include<cmath>
using namespace std;
const int maax = 400;
const int INF = 0x3f3f3f3f;
const int moves[4][2]{ {-1,0},{0,-1},{0,1},{1,0} };
struct grip
{
    int x, y;
    double v, t;
    bool operator<(const grip& b) const
    {
        return (t == b.t) ? v<b.v : t>b.t;
    }
};
int n, m, h[maax][maax];
double time_request[maax][maax];
bool visited[maax][maax];
priority_queue<grip> path;

inline void init() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            //依次读入各个位置的高度，同时将t置为最大
            scanf("%d", &h[i][j]);
            time_request[i][j] = INF;
        }
    }
    //讲访问数组全部置为false
    for (auto& vi : visited) {
        for (bool& j : vi) {
            j = false;
        }
    }

    time_request[1][1] = 0;
    grip current;
    current.x = 1;
    current.y = 1;
    current.v = 1;
    current.t = 0;
    path.push(current);
}

int main()
{
    init();
    while (!path.empty())
    {
        grip current = path.top();
        path.pop();
        if (visited[current.x][current.y])
            continue;
        visited[current.x][current.y] = 1;
        for (auto move : moves)
        {
            //若移动方式错误或移出场地，则不考虑
            if (move[0] * move[1] != 0 || current.x + move[0] < 1 ||
                current.y + move[1] < 1 || current.x + move[0] > n || current.y + move[1] > m)
                continue;
            if ((time_request[current.x][current.y] < INF) &&
                (current.t + double(1) / ((double)current.v) <
                    time_request[current.x + move[0]][current.y + move[1]]))
            {
                time_request[current.x + move[0]][current.y + move[1]] = current.t + double(1) / ((double)current.v);
                grip em;
                em.x = current.x + move[0];
                em.y = current.y + move[1];
                em.v = current.v * pow(2, h[current.x][current.y] - h[current.x + move[0]][current.y + move[1]]);
                em.t = time_request[current.x + move[0]][current.y + move[1]];
                path.push(em);
            }
        }
    }
    printf("%.2f\n", time_request[n][m]);
}
*/