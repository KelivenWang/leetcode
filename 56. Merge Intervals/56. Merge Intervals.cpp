#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return {};
        }

        sort(intervals.begin(),intervals.end());
        for(int i=0; i<intervals.size(); i++){
            for(int j=0; j<intervals.size(); j++){
                cout<<intervals[i][j]<<endl;
            }//cout<<endl;
        }
        return {};

    }
};

int main(){
    Solution solution;
    vector<vector<int> > test = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int> > getans;

    getans = solution.merge(test);
    return 0;
}