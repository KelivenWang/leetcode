#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesLen = prices.size();
        int profit=0;
        for(int i=1; i<pricesLen; i++){
            if(prices[i]-prices[i-1]>0){
                // 有賺錢，把所得的利益加起((分開加 相當於一次加)
                profit+=(prices[i]-prices[i-1]);
            }
        }return profit;
    }
};

int main(){
    Solution solution;
    vector<int> prices = {1,2,3,4,5};
    int Ans = solution.maxProfit(prices);
    cout<<Ans<<endl;

    return 0;
}

// reference https://anj910.medium.com/leetcode-122-best-time-to-buy-and-sell-stock-ii-%E4%B8%AD%E6%96%87-351a7d384ef5