#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans = 0;

        sort(points.begin(), points.end());

        for (int i = 1; i < points.size(); i++) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }

        return ans;
    }
};

int main(){
    Solution test1;
    int answer = 0;
    vector<vector<int> > testpatern = {{8,7},
                                        {9,9},
                                        {7,4},
                                        {9,7}};

    answer = test1.maxWidthOfVerticalArea(testpatern);
    cout<<answer<<endl;
    cout<<"system pause"<<endl;
    system("pause");
}


/*
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        vector<vector<int> > P;
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                P[i][j] = points[i][j];
            }
        }
        cout<<"hhhhh:"<<endl;
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<points.size(); j++){
                cout<<P[i][j]<<endl;
            }
        }
        system("pause");
        //sort(points.begin(), points.end(), test);
        return 3;
    }
};
*/

