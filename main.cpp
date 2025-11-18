
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    if (rows == 0) return 0;
    int cols = grid[0].size();

    int islands = 0;
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '1') {
                islands++;
                queue<pair<int,int>> q;
                q.push({r, c});
                grid[r][c] = '0';

                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    int rr = cur.first;
                    int cc = cur.second;

                    for (int k = 0; k < 4; k++) {
                        int nr = rr + dr[k];
                        int nc = cc + dc[k];

                        if (nr >= 0 && nr < rows &&
                            nc >= 0 && nc < cols &&
                            grid[nr][nc] == '1')
                        {
                            grid[nr][nc] = '0';
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }
    return islands;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> grid(R, vector<char>(C));

    for (int i = 0; i < R; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < C; j++) {
            grid[i][j] = row[j];
        }
    }

    cout << numIslands(grid);
    return 0;
}
