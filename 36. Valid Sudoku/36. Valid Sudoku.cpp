#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int RowLength = board[0].size();
        int ColumanLength = board.size();

        if(isRowRule(board,RowLength,ColumanLength) && isColumnRule(board,RowLength,ColumanLength) && isSquare(board,RowLength,ColumanLength)){
            return true;
        }return false;
        
    }
private:
    bool isRowRule(vector<vector<char>> &board, int &RowLength, int &ColumnLength){
        vector<int> mapNumber(10,0);

        for(int i=0; i<ColumnLength; i++){
            for(int j=0; j<RowLength; j++){
                int node = board[i][j];

                if(node!= 46){
                    // ascii '.' => 46
                    // ascii '0' ~ '9' => 48~57
                    // check wheather have number or '.'
                    node = (node % 10) + 2; 
                    mapNumber[node]++;
                    if(mapNumber[node]>1){
                        return false;
                    }

                }
            }
            
        }return true;
    }

    bool isColumnRule(vector<vector<char>> &board, int &RowLength, int &ColumnLength){

    }

    bool isSquare(vector<vector<char>> &board, int &RowLength, int &ColumnLength){

    }
};

int main(){
    return 0;
}