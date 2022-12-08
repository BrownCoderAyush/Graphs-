#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>isVisited(image.size() , vector<int>(image[0].size() , 0 ));
        int colMax = image[0].size();
        int rowMax = image.size();
        int oldColor = image[sr][sc];
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        while(!q.empty()){
            pair<int,int>temp=q.front();
            image[temp.first][temp.second] = color;
            
            q.pop();
            
            
            int trow = temp.first;
            int tcol = temp.second;
            isVisited[trow][tcol]=1;
            if(tcol-1>=0 && image[trow][tcol-1]==oldColor && !isVisited[trow][tcol-1]){
                q.push({trow,tcol-1});
            }
            if(tcol+1<colMax && image[trow][tcol+1] == oldColor  && !isVisited[trow][tcol+1]){
                q.push({trow,tcol+1});
            }
            if(trow-1>=0 && image[trow-1][tcol] == oldColor && !isVisited[trow-1][tcol]){
                q.push({trow-1,tcol});
            }
            
            if(trow+1<rowMax && image[trow+1][tcol]==oldColor && !isVisited[trow+1][tcol]){
                q.push({trow+1,tcol});
            }
        }
        
        
        
        
        return image;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
