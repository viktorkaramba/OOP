#pragma once
#pragma once
#include <iostream>
#include <vector>
#include "Figure.h"

typedef struct Node {
    int column_index;
    double square;
    int perimetr;
    int convex;
    Node* next;
}Listn, * Listp;

struct Matrix {
    int row_count;
    int col_count;
    int* figures_in_row;
    Listp* figure_matrix;
    std::vector<int> count_of_str;
    Matrix(int row_count, int col_count);
    Matrix(int row_count, int col_count, std::vector<Figure> figures, std::vector<int> point_x, std::vector<int> point_y);
    void Show_Matrix_Square();
    void Show_Matrix_Perimetr();
    void Show_Matrix_Convex();
    std::vector<double> Index_Search(int row_index, int column_index);
    std::vector<double> Value_Search(int value);
    int Value_By_Condition();
    void InitializeMatrix(int row_count, int col_count);
    ~Matrix();
};

