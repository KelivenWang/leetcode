#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
    private:
        vector<int> ans;
        vector<int> temp1;
        int stepCount = 0;

    public:
        vector<int> minOperations(string boxes){
            for(int i=0; i<boxes.length(); i++){
                boxes[i] =  boxes[i] - 48;
                temp1.push_back(boxes[i]);
            }

            for(int i=0; i<temp1.size(); i++){
                for(int j=0; j<temp1.size(); j++){
                    if(temp1[j] == 1){
                        stepCount = stepCount + abs(i-j);
                    }
                }
                ans.push_back(stepCount);
                stepCount = 0;
            }
            return ans;
        }
};

int main(){

    string testdata = "001011";
    Solution test1;
    vector<int> test2;
    test2 = test1.minOperations(testdata);
    for(int i=0; i<test2.size(); i++){
        cout<<test2[i]<<' ';
    }
    cout<<endl;
    system("pause");
    return 0;
}

