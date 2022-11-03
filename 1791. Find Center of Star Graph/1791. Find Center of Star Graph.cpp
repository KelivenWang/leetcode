#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int ans = 0;
        int nums = 0;
        map<int,int> count; //init = 0
        int len = edges.size();

        for(int i=0; i<edges.size(); i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];

            count[n1]++;
            count[n2]++;
        }

        for(auto itor=count.begin(); itor!=count.end(); itor++){
            if(itor->second==len){
                return itor->first;
            }
        }

        return false;
        
    }
};

int main(){
/*
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
*/
    vector<vector<int>> edges = {{1,2},{2,3},{4,2}};
    Solution solution;
    
    cout<<solution.findCenter(edges)<<endl;
    return 0;
}