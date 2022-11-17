#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;

    void permuation(vector<int> &nums, int i, int &numsLength){
        
        if(i==numsLength-1){
            ans.push_back(nums);
            return;
        }

        for(int j=i; j<numsLength; j++){
            swap(nums[i],nums[j]); // 兩兩交換
            permuation(nums,i+1,numsLength);
            swap(nums[i],nums[j]); // 換回來
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int numsLength = nums.size();
        permuation(nums,0,numsLength);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> getans;
    Solution solution;

    getans = solution.permute(nums);

    int row = getans[0].size();
    int columan = getans.size();

    for(int i=0; i<columan; i++){
        for(int j=0; j<row; j++){
            cout<<getans[i][j];
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}