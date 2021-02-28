#pragma once
#include <iostream>
#include <vector>
#include "Figure.h"

typedef struct Node {
    int index_of_column;
    double square;
    double perimetr;
    int convex;
    Node* next;
}Listn, * Listp;


struct Matrix {
    int c_of_rows;
    int c_of_columns;
    int* count_of_elements;
    Listp* matrix;
    Matrix();
    Matrix(int C_of_Rows, int C_of_Columns);
    Matrix(int C_of_Rows, int C_of_Columns, std::vector<Figure> Figures, std::vector<int> Rows, std::vector<int> Columns);
    void Show_Matrix_Square();
    void Show_Matrix_Perimetr();
    void Show_Matrix_Convex();
    std::vector<int> Index_Search(int I_of_Row, int I_of_Column);
    std::vector<int> Value_Search(double value);
    int Value_By_Condition();
    void SumMatrix( Matrix M1,  Matrix M2, int C_of_Rows, int C_of_Columns);
    void MultiplyVector(Matrix M1, std::vector<int> vector, int C_of_Rows, int C_of_Columns);
};

