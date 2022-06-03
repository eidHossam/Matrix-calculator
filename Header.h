#pragma once
#include <iostream>
#include <cmath>
using namespace std;

void fill_matrix(double   m[][10], int  row, int col);

void addition(double  a[][10], double  b[][10], double z[][10], int rowNum, int colNum);

void subtraction(double  a[][10], double  b[][10], double z[][10], int rowNum, int colNum);

void multiply(double a[][10], double  b[][10], double z[][10], int rowNum, int colNum1, int colNum2);

void get_adj(double a[][10], double b[][10], int rowNum, int colNum);

double determinant(double a[][10], int rowNum);

void print_matrix(double  c[][10], int row, int col);
