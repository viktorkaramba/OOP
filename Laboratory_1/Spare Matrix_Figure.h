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
private:
    int row_count;
    int column_count;
    int* figures_in_row;
    Listp* figure_matrix;
public:
    Matrix(int row_count, int column_count);
    Matrix(int row_count, int column_count, std::vector<Figure> figures, std::vector<int> point_x, std::vector<int> point_y);
    ~Matrix();
    int Get_Row_Count();
    int Get_Column_Count();
    int* Get_Figures_In_Row();
    Listp* Get_Figure_Matrix();
    void Set_Row_Count(int row_count);
    void Set_Column_Count(int column_count);
    void Set_Figures_In_Row(int *figures_in_row);
    void Set_Figure_Matrix(Listp* figure_matrix);
    void Show_Matrix_Square();
    void Show_Matrix_Perimetr();
    void Show_Matrix_Convex();
    std::vector<double> Index_Search(int row_index, int column_index);
    std::vector<double> Value_Search(int value);
    int Value_By_Condition();
private:
    void InitializeMatrix(int row_count, int col_count);
    void InitializeFigureMatrix(int i, Figure& figure, int j, Listp& current_node);
};

