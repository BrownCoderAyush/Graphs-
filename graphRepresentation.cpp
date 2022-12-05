#include<iostream>
#include <vector>
using namespace std;


// ways of representing graphs matrix and list 

void addEdge2(vector<int>*arr , int x , int y ){
    arr[x].push_back(y);
    arr[y].push_back(x);

}
void addEdge(vector<pair<int,int>> arr[] , int x , int y , int m){
    arr[x].push_back({y,m});
    arr[y].push_back({x,m});
}
int main(int argc, char const *argv[])
{
    int v , u;
    cin>>v>>u;
    cout<<v<<u;
/*
    // adjacency matrix 
    int arr[v+1][v+1];
    while(u--){
        int x , y;
        cin>>x>>y;
        arr[x][y]=1;
        arr[y][x]=1;
    }
*/


    // adjacency list 
  
    vector<int> arr[v+1];
    
   for(int i = 0 ; i <u ; i++){
        
        int x , y;   
        cin>>x>>y;
        addEdge2(arr,x,y);      
    }

    for(int i = 0 ; i < v+1 ; i++){
        cout<<"head = "<<i<<" ";   
        for(int j = 0 ; j < arr[i].size() ; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    // adjacency weight matrix
/*
    vector<pair<int,int>> arr[v+1];

    while(u--){
        int x , y , m;
        cin>>x>>y>>m;
        addEdge(arr,x,y,m);
    }

    for(int i = 0 ; i < v+1 ; i++){
        cout<<"head - "<<i<<" ";
        for(int j = 0 ; j < arr[i].size() ; j++){
            cout<<"{"<<arr[i][j].first<<","<<arr[i][j].second<<"}";
        }
        cout<<endl;
    }
*/
    return 0;
}