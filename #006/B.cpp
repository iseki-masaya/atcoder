#include <iostream>
 
int main(int argc, const char * argv[])
{
    int column,row;
    std::cin >> column;
    std::cin >> row;
    column = 2*column;
    row = row + 1;
    
    char matrix[row][column];
    
    //to ignore EOF 
    std::cin.get();
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = std::cin.get();
        }
    }
 
    //to ignore EOF
    column = column - 1;
    //to ignore leader postion
    row = row -1;
    
    int leaderPos;
    
    //find position of 'o'
    for (int i = 0; i < column; i++) {
        if(matrix[row][i] == 'o')
            leaderPos = i;
    }
    
    //search horizontal lines
    for (int i = 0; i < row; i++) {
        if (leaderPos) {
            if (matrix[(row - 1) - i][leaderPos - 1] == '-') { 
                leaderPos -=2;
            } else if (matrix[(row - 1) - i][leaderPos + 1] == '-') {
                leaderPos +=2;
            }
        } else {
            if (matrix[(row - 1) - i][leaderPos + 1] == '-') 
                leaderPos +=2;
        }
    }
    
    //optimize value
    leaderPos = (leaderPos/2) + 1;
    std::cout << leaderPos << '\n';
    return 0;
}
