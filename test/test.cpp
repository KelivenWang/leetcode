// 作為趨勢考題區

#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int dfs(vector<string> &B, int row, int column,int sum, int total_row, int total_column){
    B[row][column] = '.';
    int all_row = total_row;
    int all_column = total_column;
    //int total = sum;
    
    if(row-1>=0 && B[row-1][column]=='#'){
        // 往下
        sum++;
        sum = dfs(B,row-1,column,sum,all_row,all_column);
    }
    if(row+1<all_row && B[row+1][column]=='#'){
        // 往上
        sum++;
        sum = dfs(B,row+1,column,sum,all_row,all_column);
    }
    if(column-1>=0 && B[row][column-1]=='#'){
        // 往左
        sum++;
        sum = dfs(B,row,column-1,sum,all_row,all_column);
    }
    if(column+1<all_column && B[row][column+1]=='#'){
        // 往右
        sum++;
        sum = dfs(B,row,column+1,sum,all_row,all_column);
    }
    
    return sum;
}

vector<int> solution(vector<string> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int row = 0;
    int column = 0;
    int sum = 0;
    int boat = 0;
    int total_row = B.size();
    int total_column = B[0].size();
    vector<int> ans = {0,0,0};

    for(int i=0; i<B.size(); i++){
        for(int j=0; j<B[i].size(); j++){
           if(B[i][j]=='#'){
            row = i;
            column = j;
            sum++;
            boat = dfs(B,row,column,sum,total_row,total_column);

            if(boat==1){ans[0]++;}
            if(boat==2){ans[1]++;}
            if(boat==3){ans[2]++;}
            sum = 0;
           }
        }  
    }

    
    return ans;
}

int main(){
    vector<string> B = {
    {"##."},
    {"#.#"},
    {".##"},
    };
    vector<int> ship;

    ship = solution(B);

    for(int i=0; i<ship.size(); i++){
        cout<<ship[i]<<" ";
    }cout<<endl;
}

/*
vector<char> B = {
    {'.','#','#','.','#'},
    {'#','.','#','.','.'},
    {'#','.','.','.','#'},
    {'#','.','#','#','.'}
    };
*/
//'.#..#', '##..#', '...#.'