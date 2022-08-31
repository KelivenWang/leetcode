#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
		return -1;
    }
};


int main(){
	Solution sol;
	int index = 0;
	cin>>index;

	vector<int> v = {-1,0,3,5,9,12};
	cout<<sol.search(v, index);

	return 0;

}
