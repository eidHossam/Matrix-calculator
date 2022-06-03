#include "Header.h"




void fill_matrix(double  m[][10], int row, int col)
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cin >> m[r][c];
        }
    }
}



void addition(double  a[][10], double  b[][10], double z[][10], int rowNum, int colNum)
{
    int r = 0, c = 0;
    for (int row = 0; row < rowNum; row++)
    {
        for (int col = 0; col < colNum; col++)
        {
            z[r][c] = 0;
            z[r][c] = a[row][col] + b[row][col];
            c++;
        }
        c = 0;
        r++;
    }
}


void subtraction(double  a[][10], double  b[][10], double z[][10], int rowNum, int colNum)
{
    int r = 0, c = 0;
    for (int row = 0; row < rowNum; row++)
    {
        for (int col = 0; col < colNum; col++)
        {
            z[r][c] = 0;
            z[r][c] = a[row][col] - b[row][col];
            c++;
        }
        c = 0;
        r++;
    }
}



void multiply(double  a[][10], double b[][10], double z[][10], int rowNum, int colNum1, int colNum2)
{
    int row2 = 0;
    for (int r3 = 0; r3 < rowNum; r3++)
    {
        for (int c3 = 0; c3 < colNum2; c3++)
        {
            z[r3][c3] = 0;
            for (int col1 = 0; col1 < colNum1; col1++, row2++)
            {
                z[r3][c3] += a[r3][col1] * b[row2][c3];
            }row2 = 0;
        }
    }
}




double  determinant(double  a[][10], int rowNum)
{
    double totSum = 0;
    int sign = 1;
    double matrix2[10][10];

    if (rowNum == 1)
        return a[0][0];

    else if (rowNum == 2)
        return ((a[0][0] * a[1][1]) - (a[0][1] * a[1][0]));

    else
    {
        for (int cMain = 0; cMain < rowNum; cMain++)
        {
            int r = 0;
            for (int row = 1; row < rowNum; row++)
            {
                int c = 0;
                for (int col = 0; col < rowNum; col++)
                {
                    if (col == cMain)
                        continue;

                    matrix2[r][c] = a[row][col];
                    c++;
                }
                r++;
            }
            totSum = totSum + (sign * determinant(matrix2, rowNum - 1) * a[0][cMain]);
            sign = -sign;
        }
    }
    return totSum;
}


void print_matrix(double  c[][10], int row, int col)
{
    for (int ro = 0; ro < row; ro++)
    {
        for (int co = 0; co < col; co++)
        {
            (round(c[ro][co]) == -0) ? cout << "0 " : cout << round(c[ro][co]) << " ";

            //cout << (c[ro][co]) << " ";
        }
        cout << "\n";
    }

}




void get_adj(double a[][10], double b[][10], int rowNum, int colNum)
{
    double tempmatrix[10][10];
   
    for (int new_matrix_row = 0; new_matrix_row < rowNum; new_matrix_row++)
    {
       int  sign = pow(-1, new_matrix_row);
        for (int new_matrix_col = 0; new_matrix_col < colNum; new_matrix_col++)
        {
            int temp_matrix_rows = 0;

            for (int main_matrix_rows = 0; main_matrix_rows < rowNum; main_matrix_rows++)
            {
                if (main_matrix_rows == new_matrix_row)
                {
                    continue;
                }
                else
                {
                    int temp_matrix_col = 0;
                    for (int main_matrix_col = 0; main_matrix_col < colNum; main_matrix_col++)
                    {
                        if (main_matrix_col == new_matrix_col)
                        {
                            continue;
                        }
                        else
                        {
                            tempmatrix[temp_matrix_rows][temp_matrix_col] = a[main_matrix_rows][main_matrix_col];
                            temp_matrix_col++;
                        }

                    }
                }

                temp_matrix_rows++;
            }
            b[new_matrix_row][new_matrix_col] = sign * determinant(tempmatrix, (rowNum - 1)); 
            sign *= -1;
        }

    }
    
    for (int j = 0; j < rowNum; j++)
    {
       
        for (int i = j + 1 ; i < rowNum; i++)
        {
            int swtch = 0;
            swtch = b[j][i];
            b[j][i] = b[i][j];
            b[i][j] = swtch;
        }
        
    }
   
   
}





