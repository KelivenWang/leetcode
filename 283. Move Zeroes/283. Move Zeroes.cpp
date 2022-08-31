#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        if(nums.size()==1){
            cout<<nums[0];
            return;
        }

        int len = nums.size();
        int j = 0;
        int temp = 0;
        for(auto iter=nums.begin(); iter!=nums.end(); ){
            // iter overflow 遇到解決的方  reference https://blog.csdn.net/Vcrossover/article/details/106243627
            if(nums[j]==0){
                iter = nums.erase(iter);
                temp++;
            }else{
                iter++;
                j++;
            }
            
        }

        for(int i=0; i<temp; i++){
            nums.push_back(0);
        }

        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }cout<<endl;
    }
};

int main(){
    vector<int> nums = {0,0};
    Solution solution;

    solution.moveZeroes(nums);
    cout<<endl;
    return 0;
}
/**
 * @brief 更好的解法
 * 利用swap的方式 只要目前遇到0的話，把後面第一個非0的數字跟他交換
 *referenece https://ithelp.ithome.com.tw/articles/10276067
 * class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int j = 0;
       for(int i = 0; i < nums.size(); i++){
          if(nums[i] != 0)
          {
              swap(nums[i], nums[j++]);
          }
      }
  }
};
 * 
 */