#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;

        if(intervals.empty()){
            return {};
        }

        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=0; i<intervals.size(); i++){
            for(int j=0; j<intervals[i].size(); j++){
                cout<<intervals[i][j]<<" ";
            }cout<<endl;
        }

        for(int i=0; i<intervals.size(); i++){
            if(start==intervals[i][0]){
                if(end<intervals[i][1]){
                    end = intervals[i][1];
                }
            }else{
                if(end<intervals[i][0]){
                    ans.push_back({start,end});
                    start = intervals[i][0];
                    end = intervals[i][1];
                }else if(end<intervals[i][1]){
                    end = intervals[i][1];
                }
            }

            if(i==intervals.size()-1){
                ans.push_back({start,end});
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    //vector<vector<int> > test = {{1,3},{2,6},{15,18},{8,10}};
    vector<vector<int> > test = {{1,4},{0,4}};
    vector<vector<int> > getans;

    getans = solution.merge(test);
    for(int i=0; i<getans.size(); i++){
        for(int j=0; j<getans[i].size(); j++){
            cout<<getans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}