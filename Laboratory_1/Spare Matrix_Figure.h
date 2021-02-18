#pragma once
#pragma once
#include <iostream>
#include <vector>
#include "Figure.h"

typedef struct Node {
    int nj;
    double square;
    int perimetr;
    int convex;
    Node* next;
}Listn, * Listp;

struct Matrix {
    int nn;
    int mm;
    int* s;
    Listp* m;
    std::vector<int> countofstr;
    Matrix(int nt, int t);
    Matrix(int nt, int t, std::vector<Figure> F, std::vector<int> N, std::vector<int> M);
    void Show_Matrix_Square();
    void Show_Matrix_Perimetr();
    void Show_Matrix_Convex();
    std::vector<double> Index_Search(int rd, int st);
    std::vector<double> Value_Search(int value);
    int Value_By_Condition();
};

