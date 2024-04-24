#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        vector<int> hitTable;
        hitTable.push_back(n);
        while(n){
            n = getNumber(n);
            if(n==1) return true;
            else{
                for(int i=0; i<hitTable.size(); i++){
                    if(n==hitTable[i]) return false; // 表示數字重複到了 會造成無限迴圈
                }
                hitTable.push_back(n);
            }
        }return false;
    }
private:
    int getNumber(int num){
        vector<int> nums;
        while(num){
            nums.push_back(num%10);
            num = num / 10;
        }
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i]*nums[i]);
        }return sum;
    }
};

int main(){
    Solution solution;
    int ans;
    ans = solution.isHappy(19);
    cout<<ans<<endl;
    ans = solution.isHappy(2);
    cout<<ans<<endl;
    return 0;
}