#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        if(n==1){
            return true;
        }

        // 建立點和邊的關係圖
        // 所有點一開始預設還沒有訪問過
        vector<vector<int>> graph(n);
        vector<bool> visited(n,false);
        queue<int> q;

        for(int i=0; i<edges.size(); i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];

            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        
        // 做BFS
        int currNode,connect_with_currNode;
        q.push(source);
        while(!q.empty()){
            // 回傳頭的值
            currNode = q.front();

            for(int i=0; i<graph[currNode].size(); i++){
                // 取得和目前點相連的點
                connect_with_currNode = graph[currNode][i];
                
                if(!visited[connect_with_currNode]){
                    // 檢查此點是否被訪問過，沒有則加入到 queue 內，
                    // 並設為訪問過
                    q.push(connect_with_currNode);
                    visited[connect_with_currNode] = true;
                }
            }
            // 把目前的值移除
            q.pop();
        }

        if(visited[destination]){
            // 如果最後目的點有被訪問過，則有path
            return true;
        }else{
            return false;
        }
        return false;
    }
};


int main(){
/*
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
*/
    int n = 6;
    int source = 0;
    int destion = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4,},{4,3}};
    Solution solution;

    cout<<solution.validPath(n,edges,source,destion)<<endl;

    return 0;
}