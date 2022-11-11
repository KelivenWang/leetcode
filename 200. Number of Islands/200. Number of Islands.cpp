// reference https://blog.csdn.net/zhangpeterx/article/details/88997348
// DFS BFS graph 的經典題型
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int node_row = grid.size(); // 上下 4
        int node_column = grid[0].size(); // 左右 5
        int ans = 0;

        // 遍歷每個點找有1的位置
        for(int row=0; row<node_row; row++){
            for(int column=0; column<node_column; column++){
                if(grid[row][column]=='1'){
                    // 目前位置有島嶼 進入DFS尋找相連為1的點 (尋找整目前島嶼的邊界)
                    ans++;
                    dfs(grid,row,column);
                }
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<char>> &grid, int row, int column){

        int node_row = grid.size(); // 上下 4
        int node_column = grid[0].size(); // 左右 5

        // 把目前的位置改為0 表示成訪問過了
        grid[row][column] = '0';

        if((row-1>=0) && (grid[row-1][column]=='1')){

            dfs(grid,row-1,column);
        }
        if((row+1<node_row) && (grid[row+1][column]=='1')){

            dfs(grid,row+1,column);
        }
        if((column-1>=0) && (grid[row][column-1]=='1')){

            dfs(grid,row,column-1);
        }
        if((column+1<node_column) && (grid[row][column+1]=='1')){

            dfs(grid,row,column+1);
        }
    }
};

int main(){
/*
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/  
    vector<vector<char>> grid = 
    {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution solution;

    cout<<solution.numIslands(grid)<<endl;
    return 0;
}