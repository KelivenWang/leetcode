// reference https://blog.csdn.net/fengkeyleaf/article/details/107058635
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int columnlength = matrix.size();

        for(int i=0; i<columnlength; i++){
            for(int j=i; j<columnlength-1-i; j++){
                int temp = matrix[i][j];
                
                matrix[i][j] = matrix[columnlength-1-j][i];
                matrix[columnlength-1-j][i] = matrix[columnlength-1-i][columnlength-1-j];
                matrix[columnlength-1-i][columnlength-1-j] = matrix[j][columnlength-1-i];
                matrix[j][columnlength-1-i] = temp;
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution solution;

    solution.rotate(matrix);
    int columnLength = matrix.size();
    int rowLength = matrix[0].size();
    for(int i=0; i<columnLength; i++){
        for(int j=0; j<rowLength; j++){
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
/*
解題想法
    其實就是畫出陣列中每個 index 內中的值，把原始和轉變之後的 index 相互對照一下並找出規律出來
    e.g. 根據 leetcode 第二個例子中 4×4 的陣列中
         根據外圈來看
         1. 00 -> 03 -> 33 -> 30 -> 00;
         2. 01 -> 13 -> 32 -> 20 -> 01;
         3. 02 -> 23 -> 31 -> 10 -> 02;

         根據內圈來看
         1. 11 -> 12 ->22 -> 21 -> 11;


        外圈3個會有三個規律
        1. [i][j] -> [i][n - 1] -> [n - 1][n - 1] -> [n - 1][j] -> [i][i]
        2. [i][j] -> [j][n - 1] -> [n - 1][n - 1 - j] -> [n - 1 - j][i] -> [i][i]
        3. [i][j] -> [i][n - 1 - j] -> [n - 1 - i][n - 1 - j] -> [n - 1 - j][j] -> [i][i] (適用內圈和外圈)
*/