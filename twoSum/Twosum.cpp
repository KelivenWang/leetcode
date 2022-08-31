#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
// map solution
// O(n)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<key, value> var
        // hashmap
        map<int, int> mapTable;
        vector<int> ans;
        int numSize = nums.size();
        int remain = 0;

        for(int i=0; i<numSize; i++){
            // let mapTable key=nums[i] and value=i
            // nums  [i,value]  [0,1] [1,2] [2,3] [3,4] [4,5]
            // mapTable [value,i] [0,0] [1,0] [2,1] [3,2] [4,3] [5,4]
            // mapTable{0 0 1 2 3 4}
            mapTable[nums[i]] = i;
        }

        for(int i=0; i<numSize; i++){
            // cause remain + nums[i] = target , that remain and nums[i] must in the mapTable
            remain =  target - nums[i];
            if(mapTable.count(remain) && mapTable[remain]!=i){
                // for nums[i] index
                ans.push_back(i);
                // for remain index
                ans.push_back(mapTable[remain]);
                return ans;
            }
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};

/*
//brust ans
// O(n^2)

class Solution1{
public:
    vector<int> twoSum(vector<int> &nums, int target){

        vector<int> ans;
        ans.clear();
        int numSize = nums.size();
        int sum = 0;

        for(int i=0; i<numSize; i++){
            for(int j=i+1; j<numSize; j++){
                sum = nums[i] + nums[j];
                if(sum == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
            ans.clear();
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};
*/
int main() {
	vector<int> nums{1,1,1,1,1,4,1,1,1,1,1,7,1,1,1,1,1};
	Solution sol;
	vector<int> Ans = sol.twoSum(nums, 11);

   for(int i=0; i<Ans.size(); i++){
    cout<<Ans[i]<<" ";
   }
	return 0;
}
