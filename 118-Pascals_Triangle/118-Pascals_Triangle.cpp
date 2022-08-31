// reference https://blog.csdn.net/qjh5606/article/details/81411424

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows<1){
            return {};
        }
        else{

            vector<vector<int>> ans;
            ans.resize(numRows);
            for(int i=0; i<numRows; i++){
                ans[i].resize(i+1);
            }

            ans[0][0] = 1;
            for(int i=1; i<numRows; i++){
                for(int j=0; j<ans[i].size(); j++){
                    if(j==0 || j==ans[i].size()-1){
                        ans[i][j] = 1;
                    }
                    else{
                        if(j-1>=0){
                            ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
                        }
                    }
                }
            }
            return ans;
        }
    }
};


int main(){
    int numrows = 5;
    Solution solution;
    vector<vector<int>> getans;

    getans = solution.generate(numrows);
    for(int i=0; i<numrows; i++){
        for(int j=0; j<getans[i].size(); j++){
            cout<<getans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<< endl;
    return 0;
}