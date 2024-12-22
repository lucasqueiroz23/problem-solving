class Solution {
public:

    bool rowIsValid(vector<char>& row) {
        for(int i = 0; i < row.size(); i++) {
            if(row[i] == '.') continue;
            for(int j = i + 1; j < row.size(); j++) {
                if(row[i] == row[j]) return false;
            }
        }
        return true;
    }

    bool columnIsValid(vector<vector<char>>& board, int columnIndex) {
        for(int i = 0; i < board.size(); i++) {
           if(board[i][columnIndex] == '.') continue; 
           for(int j = i + 1; j < board.size(); j++) {
              if(board[j][columnIndex] == board[i][columnIndex]) return false;
           }
        }
        return true;
    }

    bool boxIsValid(vector<vector<char>>& board, int firstRow, int firstColumn) {
        map<char,int> m;
        for(int i = firstRow; i <= firstRow + 2; i++) {
            for(int j = firstColumn; j <= firstColumn + 2; j++) {
                if(board[i][j] == '.') continue;
                if(!m[board[i][j]]) m[board[i][j]]++;
                else return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(auto row: board) {
            if(!rowIsValid(row)) return false;
        }

        for(int j = 0; j < board.size(); j++) {
            if(!columnIsValid(board, j)) return false;
        }

        for(int i = 0; i < board.size(); i += 3) {
            for(int j = 0; j < board.size(); j += 3) {
                if(!boxIsValid(board, i, j)) return false;
            }
        }
        
        return true;
    }
};
