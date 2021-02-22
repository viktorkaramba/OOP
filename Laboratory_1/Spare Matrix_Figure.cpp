#include "Spare Matrix_Figure.h"

Matrix::Matrix(int C_of_Rows, int C_of_Columns) {
    c_of_rows = C_of_Rows;
    c_of_columns = C_of_Columns;
    int n;
    Listp p = NULL, o = NULL, r = NULL;
    matrix = new Listp[c_of_rows];
    count_of_elements = new int[c_of_rows];
    for (int i = 0; i < c_of_rows; i++) {
        count_of_elements[i] = 0;
        p = NULL;
        for (int j = 0; j < c_of_columns; j++) {
            std::cout << "Input count of point of figure" << std::endl;
            std::cin >> n;
            if (n >= 3) {//Якщо к-сть сторін в фігурі менше 3 то ми не зберігаєм її в матриці інакше а поле даних заносим значення
                double Oxx;
                double Oyy;
                std::vector<double>X;
                std::vector<double>Y;
                for (int i = 0; i < n; i++) {
                    std::cout << "Input coordinate (x ; y)" << std::endl;
                    std::cin >> Oxx;
                    X.push_back(Oxx);
                    std::cin >> Oyy;
                    Y.push_back(Oyy);
                }
                Figure  A(n, X, Y);
                matrix[i] = new Node;
                matrix[i]->square = A.Square();
                matrix[i]->perimetr = A.Perimetr();
                matrix[i]->convex = A.Isconvex();
                matrix[i]->index_of_column = j;
                matrix[i]->next = p;
                p = matrix[i];
                count_of_elements[i] = count_of_elements[i] + 1;//Масив що містить к-сть елементів в кожному рядку
            }
        }
    }
    std::cout << std::endl;
}
Matrix::Matrix(int C_of_Rows, int C_of_Columns, std::vector<Figure> Figures, std::vector<int> Rows, std::vector<int> Columns) {
    c_of_rows = C_of_Rows;
    c_of_columns = C_of_Columns;
    int k = 0;
    Listp p = NULL, o = NULL, r = NULL;
    matrix = new Listp[c_of_rows];
    count_of_elements = new int[c_of_rows];
    int y = 0; int w = 0;int h = 0; int l = 0;
    for (int i = 0; i < c_of_rows; i++) {
        int row = i;
        count_of_elements[i] = 0;
        p = NULL;
        for (int j = 0; j < c_of_columns; j++) {
            int column = j;
            for (int r = 0; r < Rows.size(); r++) {
                if (row == Rows[r] ) {
                    if (r < h ) {
                        continue;
                    }
                    else if (r == h) {
                        y = r;
                        break;
                    }
                }
                else {
                    y = 0;
                    continue;
                }
            }
            for (int q = 0; q < Columns.size(); q++) {
                if (column == Columns[q]) {
                    if (q < l ) {
                        continue;
                    }
                    else if (q == l) {
                        w = q;
                        break;
                    }
                }
                else {
                    w = 1;
                    continue;
                }
            }
            if (y == w) {
                matrix[i] = new Node;
                matrix[i]->square = Figures[k].Square();
                matrix[i]->perimetr = Figures[k].Perimetr();
                matrix[i]->convex = Figures[k].Isconvex();
                matrix[i]->index_of_column = j;
                matrix[i]->next = p;
                p = matrix[i];
                count_of_elements[i] = count_of_elements[i] + 1;//Масив що містить к-сть елементів в кожному рядку
                k++;
                h++;
                l++;
                
            }
           
        }
    }
    std::cout << std::endl;
}
void Matrix::Show_Matrix_Square() {
    std::cout << "Matrix of Squares" << std::endl;
    Listp p = NULL;
    int n = 0;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
        while (p) {
            std::cout << p->square << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Matrix::Show_Matrix_Perimetr() {
    std::cout << "Matrix of Perimeters" << std::endl;
    Listp p = NULL;
    int n = 0;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
        while(p) {
            std::cout << p->perimetr << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Matrix::Show_Matrix_Convex() {
    std::cout << "Matrix of Convex" << std::endl;
    Listp p = NULL;
    int n = 0;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
        while (p) {
            std::cout << p->convex << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
std::vector<int> Matrix::Index_Search(int I_of_Row, int I_of_Column) {// Йдемо по не нульовим елементам і шукаємо значеня за заданим індексом
    Listp p = NULL;
    std::vector<int> value;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
        for (int j = 0; j < count_of_elements[i]; j++) {
            if (i == I_of_Row && p->index_of_column == I_of_Column) {
                value.push_back(p->square);
                value.push_back(p->perimetr);
                value.push_back(p->convex);
                return value;
            }
            else {
                p = p->next;
            }
        }
    }
    if (value.empty()) {
        std::cout << "There aren't any value  by this index" << std::endl;
    }
    std::cout << std::endl;
}
std::vector<int> Matrix::Value_Search(double value) {// Йдемо по не нульовим елементам і шукаємо іднекс за заданим значенням
    Listp p = NULL;
    std::vector<int> Index;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
        for (int j = 0; j < count_of_elements[i]; j++) {
            if ((int)p->square == value) {
                Index.push_back(i);
                Index.push_back(p->index_of_column);
                return Index;
            }
            else {
                p = p->next;
            }
        }
    }
    if (Index.empty()) {
        std::cout << "There aren't any index by this value" << std::endl;
    }
    std::cout << std::endl;
}
int Matrix::Value_By_Condition() {//Шукаємо першу не опуклу фігуру 
    Listp p = NULL;
    int value = 0;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
        for (int j = 0; j < count_of_elements[i]; j++) {
            if (p->convex == -1) {
                value = p->square;
                return value;
            }
            else {
                p = p->next;
            }
        }
    }
    if (value == 0) {
        return 0;
    }
    std::cout << std::endl;
}
