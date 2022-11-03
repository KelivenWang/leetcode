// reference https://clay-atlas.com/blog/2022/01/03/leetcode-997-find-the-town-judge/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // 建立每個點的indegree, outdegree => 
        // [[0,0]]
        // [[0,0]]
        vector<vector<int>> in_out(n, vector<int>(2, 0));
        // judge[in][out]的成立
        vector<int> judge({n-1, 0});
        
        
        for (int i=0; i<trust.size(); i++){
            // 計算每個點各自的indegree outdegree
            ++in_out[trust[i][0]-1][1]; // outdegree
            ++in_out[trust[i][1]-1][0]; // indegree
        }
        
        // Match
        for (int i=0; i<in_out.size(); i++){
            if (in_out[i] == judge){
                // 因為是從index 1開始
                return i + 1;
            }
        }
        
        return -1;
    }
};

int main(){
/*
Input: n = 2, trust = [[1,2]]
Output: 2
*/
    int n = 2;
    int n2 = 3;
    int n3 = 3;
    vector<vector<int>> trust = {{1,2}};
    vector<vector<int>> trust2 = {{1,3},{2,3}};
    vector<vector<int>> trust3 = {{1,3},{2,3},{3,1}};
    Solution solution;
    
    cout<<solution.findJudge(n,trust)<<endl;
    cout<<solution.findJudge(n2,trust2)<<endl;
    cout<<solution.findJudge(n3,trust3)<<endl;
    return 0;
}
