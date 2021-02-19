#pragma once
#pragma once
#include <iostream>
#include <vector>
#include "Figure.h"

typedef struct Node {
    int index_of_column;
    double square;
    int perimetr;
    int convex;
    Node* next;
}Listn, * Listp;

struct Matrix {
    int c_of_rows;
    int c_of_columns;
    int* count_of_elements;
    Listp* matrix;
    std::vector<int> countofstr;
    Matrix(int C_of_Rows, int C_of_Columns);
    Matrix(int C_of_Rows, int C_of_Columns, std::vector<Figure> F, std::vector<int> N, std::vector<int> M);
    void Show_Matrix_Square();
    void Show_Matrix_Perimetr();
    void Show_Matrix_Convex();
    std::vector<double> Index_Search(int I_of_Row, int I_of_Column);
    std::vector<double> Value_Search(int value);
    int Value_By_Condition();
};

