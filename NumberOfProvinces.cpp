#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &isVisited, int i, int j)
    {
        isVisited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // to add the adjacent neighbours of the given q.front()
            // row const and col-1 col+1
            if (col - 1 >= 0 && !isVisited[row][col - 1] && grid[row][col - 1] == '1')
            {
                isVisited[row][col - 1] = 1;
                q.push({row, col - 1});
            }

            if (col + 1 < m && !isVisited[row][col + 1] && grid[row][col + 1] == '1')
            {
                isVisited[row][col + 1] = 1;
                q.push({row, col + 1});
            }

            // col const and row-1 row+1

            if (row - 1 >= 0 && !isVisited[row - 1][col] && grid[row - 1][col] == '1')
            {
                isVisited[row - 1][col] = 1;
                q.push({row - 1, col});
            }

            if (row + 1 < n && !isVisited[row + 1][col] && grid[row + 1][col] == '1')
            {
                isVisited[row + 1][col] = 1;
                q.push({row + 1, col});
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> isVisited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!isVisited[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(grid, isVisited, i, j);
                }
            }
        }

        return cnt;
    }
};

int main()
{

    return 0;
}