#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
    private:
        int counter = 0;
        int temp1 = 0;
        int temp2 = 0;
        int temp3 = 0;
        // 該圓形原點到point的直線距離
        int CenterToPoint = 0;
        vector<int> ans;

    public:
        vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
            //cout<<"get in the function"<<endl;
            
            for(int i=0; i<queries.size(); i++){
                
                for(int j=0; j<points.size(); j++){

                    temp1 = abs(points[j][0] - queries[i][0]);
                    temp2 = abs(points[j][1] - queries[i][1]);
                    temp1 = temp1 * temp1;
                    temp2 = temp2 * temp2;
                    CenterToPoint = temp1 + temp2;
                    temp3 = queries[i][2] * queries[i][2];

                    if( CenterToPoint <= temp3){
                        counter++;
                    }
                    else{
                        // 點在該圓形的範圍外
                        // check next points
                    }
                }
                ans.push_back(counter);
                counter = 0;
            }
            return ans;
        }
};

int main(){
    Solution test1;
    vector< vector<int> > ans;
    vector< vector<int> > Points = { {1,3},
                                        {3,3},
                                        {5,3},
                                        {2,2} };

    vector< vector<int> > Queries = {    {2,3,1},
                                            {4,3,1},
                                            {1,1,2} };

    test1.countPoints(Points, Queries);
    system("Pause");
    return  0;
}

// 檢查每個點是否在每個圓形內
// 用 點到原點 的直線距離來判斷該點是否在目前此圓形的範圍內 小於等於半徑->成立
// 如果有->counts++ 如果沒有->檢查下一個點

