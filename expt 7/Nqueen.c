
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//board index --> row no , borad[index] --> col no at which queen is placed
int board[20], count;
int main()
{
    int n, i, j;
    void queen(int row, int n);

    printf(" - N Queens Problem Using Backtracking -");
    printf("\n\nEnter number of Queens:");
    scanf("%d", &n);
    queen(1, n);
    return 0;
}

// function for printing the solution
void print(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);

    for (i = 1; i <= n; ++i){
    //column indexes
        printf("\t%d", i);
    }

    for (i = 1; i <= n; ++i)
    {
        //row indexes
        printf("\n%d\t", i);
        for (j = 1; j <= n; ++j) // for nxn board
        {
            if (board[i] == j)
            // queen at i,j position
                printf("Q\t"); 
            else
                printf(".\t"); // empty slot
        }
    }

    printf("\n\n");
}

/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        // checking column cond.
        // if board[current_row] has value == current col .. not allowed
        if (board[i] == column)
            return 0;

        // check diagonal
        else if (abs(board[i] - column) == abs(i - row))
            return 0;
    }

    return 1; // all cond met
}

// function --> if postion locked .. place queen .. move to next
void queen(int row, int n)
{
    int column;
    for (column = 1; column <= n; ++column)

    {
        // printf("(%d-%d)\n" , row , column);
        if (place(row, column))
        {
            // printf("yes\n");

            // if all condition met .. place queen 
            board[row] = column; 
            // all rows handled ... print final board config
            if (row == n)        
                print(n);        
            else         
                // one row done .. move to next        
                queen(row + 1, n);
        }
    }
}
