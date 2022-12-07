#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void bfs(vector<vector<char>>&grid , vector<vector<int>> & isVisited ,int i, int j){

        queue<pair<int,int>> node;
        node.push({i,j});
        int n = grid.size();
        int m = grid[0].size();
        while(!node.empty()){
            pair<int,int> top = node.front();
            node.pop();
            isVisited[top.first][top.second] = 1;

            // traverse its neighbours

            for(int r = -1 ; r<= 1 ; r++){
                int eRow = top.first;
                int eCol = top.second+r;
                if(!isVisited[eRow][eCol] && (0<= eCol && eCol < m) && grid[eRow][eCol]=='1'){
                    node.push({eRow,eCol});
                }
            }

            for(int c = -1 ; c<=1 ; c++){
                int eRow = top.first+c;
                int eCol = top.second;
                if(!isVisited[eRow][eCol] && (0<= eRow && eRow < n) && grid[eRow][eCol] == '1'){
                    node.push({eRow,eCol});
                }
            }
        }
    }



    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>>isVisited(n,vector<int>(m , 0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!isVisited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(grid,isVisited,i,j);
                }
            }
        }

        return cnt;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}



/*
    int row, col;
    
    int numIslands(vector<vector<char>>& grid) {
        int nLand = 0;
        row = grid.size();
        col = row? grid[0].size() : 0;
        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (grid[i][j] == '1') {
                    ++nLand;
                    bfs(grid, i, j);
                }
        return nLand;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        for (grid[i][j] = '0', q.emplace(i, j); !q.empty(); q.pop()) {
            i = q.front().first, j = q.front().second;
            if (i > 0     && grid[i-1][j] == '1') q.emplace(i-1, j), grid[i-1][j] = '0';
            if (i+1 < row && grid[i+1][j] == '1') q.emplace(i+1, j), grid[i+1][j] = '0';
            if (j > 0     && grid[i][j-1] == '1') q.emplace(i, j-1), grid[i][j-1] = '0';
            if (j+1 < col && grid[i][j+1] == '1') q.emplace(i, j+1), grid[i][j+1] = '0';
        }
    }


*/