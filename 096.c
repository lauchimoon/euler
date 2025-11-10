#include <stdio.h>
#include <ctype.h>

#define SIZE 9

void load_board(int board[SIZE][SIZE], FILE *f);
int solve(int board[SIZE][SIZE], int cell);
int is_valid(int board[SIZE][SIZE], int row, int col, int n);

int main()
{
    int sum = 0;
    int board[SIZE][SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    FILE *f = fopen("./resources/0096_sudoku.txt", "r");
    int n = 0;
    while (n < 50) {
        load_board(board, f);
        solve(board, 0);
        sum += 100*board[0][0] + 10*board[0][1] + board[0][2];
        ++n;
    }

    printf("%d\n", sum);
    fclose(f);
    return 0;
}

void load_board(int board[SIZE][SIZE], FILE *f)
{
    int c;
    char line[9];
    if (fgets(line, 9, f) == NULL)
        return;

    int row = 0, col = 0;
    while ((c = fgetc(f)) != 'G') {
        if (c == EOF)
            break;

        board[row][col++] = c - '0';
        if (c == '\n') {
            ++row;
            col = 0;
        }
    }
}

int solve(int board[SIZE][SIZE], int cell)
{
    if (cell == 81)
        return 1;

    const int i = cell/9;
    const int j = cell%9;
    if (board[i][j] != 0)
        return solve(board, cell + 1);

    for (int n = 1; n <= 9; ++n)
        if (is_valid(board, i, j, n)) {
            board[i][j] = n;
            if (solve(board, cell + 1))
                return 1;
            board[i][j] = 0;
        }

    return 0;
}

int is_valid(int board[SIZE][SIZE], int row, int col, int n)
{
    for (int i = 0; i < 9; ++i)
        if (board[i][col] == n || board[row][i] == n ||
            board[3*(row / 3) + i/3][3*(col/3) + i%3] == n)
            return 0;

    return 1;
}
