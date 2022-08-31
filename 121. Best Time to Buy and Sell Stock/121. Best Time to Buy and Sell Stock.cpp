#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.empty()){
            return 0;
        }

        int buy = 100000;
        int profit = 0;

        for(int i=0; i<prices.size(); i++){
            if(prices[i]<buy){
                buy = prices[i];
            }
            if(profit<prices[i]-buy){
                profit = prices[i] - buy;
            }
        }
        
        if(profit>0){
            return profit;
        }
        else{
            return 0;
        }
    }
};

int main(){
    vector<int> price1 = {7,1,5,3,6,4};
    vector<int> price2 = {2,4,1};
    Solution solution;
    int getans;

    getans = solution.maxProfit(price1);
    cout<<getans<<endl;

    getans = solution.maxProfit(price2);
    cout<<getans<<endl;
    return 0;
}