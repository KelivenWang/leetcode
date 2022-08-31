#include <iostream>
#include <vector>
using namespace std;

class SubrectangleQueries {
public:
    vector<vector<int>> rect;

    // 二維陣列宣告
    SubrectangleQueries( vector< vector<int> > & rectangle) {
        rect = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i)
            for (int j = col1; j <= col2; ++j)
                rect[i][j] = newValue;
    }

    int getValue(int row, int col) {
        return rect[row][col];
    }
};

int main(){

    vector< vector<int> > testdata = {
                                        {1,1,1},
                                        {2,2,2},
                                        {3,3,3}
                                      };

    SubrectangleQueries subrectangleQueries = SubrectangleQueries(testdata);

    cout<<subrectangleQueries.getValue(0, 0)<<endl; // return 1
    subrectangleQueries.updateSubrectangle(0, 0, 2, 2, 100);
    cout<<subrectangleQueries.getValue(0, 0)<<endl; // return 100
    cout<<subrectangleQueries.getValue(2, 2)<<endl; // return 100
    subrectangleQueries.updateSubrectangle(1, 1, 2, 2, 20);
    cout<<subrectangleQueries.getValue(2, 2)<<endl; // return 20
}
