#include<iostream>
#include<vector>
#include <algorithm>
#include<list>
#include<unordered_map>
#include<map>
using namespace std;

// int binarySearch(vector<int> nums, int target){
//     int left = 0;
//     int right = nums.size() - 1 ;
//     while(left<=right){
//         int mid = (left+right) / 2 ;
//         if(nums[mid]==target){
//             return mid;
//         }else if(nums[mid]<target){
//             left = mid + 1;
//         }else{
//             // nums[mid]>target
//             right = mid - 1;
//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int> nums1 = {1,2,3};
//     for(int i=0; i<nums1.size(); i++){
//         cout<<nums1[i]<<endl;
//     }
//     return 0;
// }

// class inheritance constructor destructor
// public、protected、private、class預設為私人、struct預設Public
// class預設為私人指的是繼承時預設是 privated; struct預設Public指的是繼承時預設是 public

// friend、virtual function 相關宣告
// interface、巨集、delegate、console

// leetcode
// 寫個子函式做除法，但不能用"/"，限時五分鐘
// 要如何從unsorted list中找出前三大element並回傳index
// 如何將兩個list合併，並將裡面的元素從小排到大
// arrayList linkedlist 差異
// a[2][4], arr = {1,2,3,5,8,10,15,20} 考你 cout<<(a[1]+2)<<(([2+1]a)+1)

int divide(int num1, int num2){
        // 寫個子函式做除法，但不能用"/"，限時五分鐘
        // num1被除數  num2除數
        int sign = 1;
        if(num1<0 && num2>0){
            num1 = num1*-1;
            sign = -1;
        }
        if(num2<0 && num1>0){
            num2 = num2*-1;
            sign = -1;
        }

        int count = 0;
        while(num1>=num2){
            count++;
            num1 = num1 - num2;
        }return count*sign;
}

vector<int> getThreeNum(vector<int> &nums){
    // 要如何從unsorted list中找出前三大element並回傳index 有負數 正數 零
    vector<int> result;
    vector<int> index(nums.size(),0);
    for(int i=0; i<nums.size(); i++){
        index[i] = i;
    }
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]>nums[j]){
                swap(nums[i],nums[j]);
                swap(index[i],index[j]);
            }
        }
    }
    int cont = 3;
    int i = index.size() - 1;
    while(cont>0){
        result.push_back(index[i]);
        cont--;
        i--;
    }
    return result;
}

bool comparator(int first, int second)
{
    return first < second;
}
list<int> mearge(list<int> &nums1, list<int> &nums2){
    nums1.merge(nums2,comparator);
    return nums1;
}

int main(){
    int ans;
    ans = divide(29,3);
    cout<<ans<<endl;

    vector<int> nums = {1,-2,0,-1,1,2};
    vector<int> getans;
    getans = getThreeNum(nums);
    for(auto i : getans){
        cout<<i<<" ";
    }cout<<endl;

    list<int> nums1 = { 1, 70, 80 };
    list<int> nums2 = { 2, 3, 4 };
    list<int> getans2;
    getans2 = mearge(nums1,nums2);
    for(auto i : getans2){
        cout<<i<<" ";
    }cout<<endl;

    int arr[] = {1,2,3,5,8,10,15,20};
    cout<<(arr[1]+2)<<((arr[2+1])+1);


    return 0;
}