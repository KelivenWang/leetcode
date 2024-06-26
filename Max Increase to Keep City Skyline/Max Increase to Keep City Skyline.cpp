#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline( vector<vector<int> >& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<int> row(m, 0), col(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res += min(row[i] - grid[i][j], col[j] - grid[i][j]);
            }
        }
        return res;
    }
};

int main(){
    Solution ans;
    int getans;
    vector<vector<int> > pattern = {{3,0,8,4},
                                    {2,4,5,7},
                                    {9,2,6,3},
                                    {0,3,1,0}};

    getans = ans.maxIncreaseKeepingSkyline(pattern);
    cout<<getans<<endl;
    system("pause");
}
