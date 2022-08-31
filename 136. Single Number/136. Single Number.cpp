#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> twice; // map<key, value>
        if(nums.size()==1){
            return nums[0];
        }
        
        int min = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<min){
                min = nums[i];
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(twice.find(nums[i])->second){
                twice[nums[i]] = 2;
            }
            else{
                // 第一次出現在map中
                twice[nums[i]] = 1;
            }
        }

        // 这条语句定义了一个名为iter的变量，它的数据类型是由map<int,int>定义的iterator类型
        // reference https://blog.csdn.net/baidu_39486224/article/details/85627178
        for(map<int,int>::iterator it=twice.begin(); it!=twice.end(); it++){
            // 用value找key
            if(it->second==1){
                return it->first;
            }
        }
        // 例外狀況
        return -1;
    }
};

int main(){
    vector<int> num1 = {-336,513,-560,-481,-174,101,-997,40,-527,-784,-283,-336,513,-560,-481,-174,101,-997,40,-527,-784,-283,354};
    vector<int> num2 = {4,1,2,1,2};
    vector<int> num3 = {1};
    Solution solution;
    int getans;

    getans = solution.singleNumber(num1);
    cout<<getans<<endl;

    getans = solution.singleNumber(num2);
    cout<<getans<<endl;

    getans = solution.singleNumber(num3);
    cout<<getans<<endl;
    return 0;
}