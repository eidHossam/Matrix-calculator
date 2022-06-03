#include <iostream>
#include "Header.h"
#include <cmath>

using namespace std;







int main()
{
    double matrix1[10][10], matrix2[10][10], matrix3[10][10],matrix4[10][10];
    int r1, c1, r2, c2;
    double det = 0;
    int operation = 0;

    cout << "Please enter dimensions of Matrix A:\n";
    cin >> r1 >> c1;

    cout << "Please enter dimensions of Matrix B:\n";
    cin >> r2 >> c2;

    cout << "Please enter values of Matrix A:\n";
    fill_matrix(matrix1, r1, c1);

    cout << "Please enter values of Matrix B:\n";
    fill_matrix(matrix2, r2, c2);


    cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
    cin >> operation;

    while (operation != 7)
    {
        switch (operation)
        {
        case 1:
            if (r1 == r2 && c1 == c2)
            {
                addition(matrix1, matrix2, matrix3, r1, c1);
                print_matrix(matrix3, r1, c1);
                break;

            }
            else {
                cout << "The operation you chose is invalid for the given matrices.\n";
                break;
            }

        case 2:
            if (r1 == r2 && c1 == c2)
            {
                subtraction(matrix1, matrix2, matrix3, r1, c1);
                print_matrix(matrix3, r1, c1);
                break;

            }
            else {
                cout << "The operation you chose is invalid for the given matrices.\n";
                break;
            }

        case 3:
            if (c1 == r2)
            {
                multiply(matrix1, matrix2, matrix3, r1, c1, c2);
                print_matrix(matrix3, r1, c2);
                break;

            }
            else {
                cout << "The operation you chose is invalid for the given matrices.\n";
                break;
            }
        case 4: 

            det = determinant(matrix2, r2);

            if (det == 0 || r2 != c2)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
                break;
            }
            else
            {
                det = 1 / det;
                // cout << det << endl;

                get_adj(matrix2, matrix3, r2, c2);

                //print_matrix(matrix3, r2, c2);

                for (int i = 0; i < r2; i++)
                {
                    for (int j = 0; j < c2; j++)
                    {

                        matrix3[i][j] = (matrix3[i][j] * det);
                    }
                }

                //print_matrix(matrix3, r2, c2);

                multiply(matrix1, matrix3, matrix4, r1, c1, c2);

               print_matrix(matrix4, r1, c2);

                break;
            }


        case 5:
            if (r1 == c1)
            {
                cout << determinant(matrix1, r1) << endl;
                break;
            }

            else {
                cout << "The operation you chose is invalid for the given matrices.\n";
                break;
            }

        case 6:
            if (r2 == c2)
            {
                cout << determinant(matrix2, r2) << endl;
                break;
            }

            else {
                cout << "The operation you chose is invalid for the given matrices.\n";
                break;
            }

        default:
            cout << "The operation you chose is invalid for the given matrices.\n";
        }

        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
        cin >> operation;

    }

    cout << "Thank you!";

    return 0;
}







