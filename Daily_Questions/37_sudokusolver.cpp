#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &board)
{
    cout << "Sudoku\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve(vector<vector<int>> &board,
           vector<vector<int>> grid,
           vector<int> rows,
           vector<int> cols,
           int i, int j)
{
    if (i == 8 && j == 8)
    {
        display(board);
        return;
    }
    if (board[i][j] != 0)
    {
        solve(board, grid, rows, cols, j == 8 ? i + 1 : i, j == 8 ? 0 : j + 1);
    }
    else
    {
        for (int num = 1; num <= 9; num++)
        {
            if (!(rows[i] & (1 << num)) && !(cols[j] & (1 << num)) && !(grid[i / 3][j / 3] & (1 << num)))
            {

                board[i][j] = num;
                rows[i] ^= (1 << num);
                cols[j] ^= (1 << num);
                grid[i / 3][j / 3] ^= (1 << num);
                solve(board, grid, rows, cols, j == 8 ? i + 1 : i, j == 8 ? 0 : j + 1);
                rows[i] ^= (1 << num);
                cols[j] ^= (1 << num);
                grid[i / 3][j / 3] ^= (1 << num);
                board[i][j] = 0;
            }
        }
    }
}

void solveSudoku(vector<vector<int>> &board)
{

    vector<int> rows(9, 0);
    vector<int> cols(9, 0);
    vector<vector<int>> grid(3, vector<int>(3, 0));

    // Preprocessing step
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            rows[i] |= (1 << board[i][j]);
            cols[j] |= (1 << board[i][j]);
            grid[i / 3][j / 3] |= (1 << board[i][j]);
        }
    }

    solve(board, grid, rows, cols, 0, 0);
}

int main()
{
    vector<vector<int>> board = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                                  {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                  {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                  {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                  {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                  {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                  {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                  {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                  {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    solveSudoku(board);

    return 0;
}