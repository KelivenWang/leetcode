#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int num = 0;
        int lengthdigits = digits.size();
        for(int i=lengthdigits-1; i>=0; i--){
            digits[i] = digits[i] + carry;
            if(i==lengthdigits-1){
                digits[i] = digits[i] + 1;
            }

            if(digits[i]<10){
                carry = 0;
            }

            if(digits[i]>=10){
                carry = digits[i] / 10;
                digits[i] = digits[i] % 10;
                if(i==0){
                    digits.insert(digits.begin(),carry);
                }
            }
        }
        return digits;
    }
};

int main(){
    vector<int> digits1 = {9};
    vector<int> digits2 = {4,3,2,1};
    vector<int> getans;
    Solution solution;
    getans = solution.plusOne(digits1);
    int lengthd1 = digits1.size();
    for(int i=0; i<lengthd1; i++){
        cout<<getans[i]<<" ";
    }
    cout<<endl;

    getans = solution.plusOne(digits2);
    int lengthd2 = digits2.size();
    for(int i=0; i<lengthd2; i++){
        cout<<getans[i]<<" ";
    }
    cout<<endl;
    return 0;
}