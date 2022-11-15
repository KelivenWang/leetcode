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
                mapNumber.clear();
                mapNumber.resize(10,0);
            }
            
        }return true;
    }

    bool isColumnRule(vector<vector<char>> &board, int &RowLength, int &ColumnLength){
        vector<int> mapNumber(10,0);

        for(int i=0; i<RowLength; i++){
            for(int j=0; j<ColumnLength; j++){
                int node = board[j][i];
                
                if(node != 46){
                    node = (node % 10) + 2;
                    mapNumber[node]++;
                    if(mapNumber[node]>1){
                        return false;
                    }
                }
            }
            mapNumber.clear();
            mapNumber.resize(10,0);
        }return true;
    }

    bool isSquare(vector<vector<char>> &board, int &RowLength, int &ColumnLength){
        vector<int> mapNumber(10,0);

        for(int i=0; i<ColumnLength-3; i=i+3){
            // get every square staring node
            // e.g. [00][03][06]
            //      [30][33][36]
            //      [60][63][66]
            for(int j=0; j<RowLength-3; j=j+3){
                for(int k=1; k<=3; k++){
                    int n1 = i;
                    int n2 = j;
                    int node = board[n1][n2];

                    if(node != 46){
                        node = (node % 10) + 2;
                        mapNumber[node]++;
                        if(mapNumber[node]>1){
                            return false;
                        }
                    }
                    n2++;
                }
                mapNumber.clear();
                mapNumber.resize(10,0);
            }
        }return true;
    }
};

int main(){

    vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    };

    Solution soluton;
    cout<<soluton.isValidSudoku(board)<<endl;

    system("pause");
    return 0;
}