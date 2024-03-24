#include "Spare Matrix_Figure.h"

Matrix::Matrix(int row_count, int col_count) {
    InitializeMatrix(row_count, col_count);
    Listp current_node = NULL;
    for (int i = 0; i < row_count; i++) {
        figures_in_row[i] = 0;
        for (int j = 0; j < col_count; j++) {
            int point_count;
            std::cout << "Input count of point of figure" << std::endl;
            std::cin >> point_count;
            if (point_count >= 3) {
                figure_matrix[i] = new Node;//Якщо к-сть сторін в фігурі менше 3 то ми не зберігаєм її в матриці інакше а поле даних заносим значення
                int x, y;
                std::vector<Point> points;
                for (int k = 0; k < point_count; k++) {
                    std::cout << "Input coordinate (x; y)" << std::endl;
                    std::cin >> x >> y;
                    points.push_back(*new Point(x, y));
                }
                Figure figure(point_count, points);
                figure_matrix[i]->square = figure.Square();
                figure_matrix[i]->perimetr = figure.Perimetr();
                figure_matrix[i]->convex = figure.Isconvex();
                figure_matrix[i]->column_index = j;
                figure_matrix[i]->next = current_node;
                current_node = figure_matrix[i];
                figures_in_row[i]++;  //Масив що містить к-сть елементів в кожному рядку
            }
        }
    }
    std::cout << std::endl;
}

Matrix::Matrix(int row_count, int col_count, std::vector<Figure> figures, std::vector<int> point_x, std::vector<int> point_y) {
    InitializeMatrix(row_count, col_count);
    Listp current_node = NULL;
    int k = 0;
    int target_x = 0; int target_y = 0;
    int h = -1; int l = -1;
    for (int i = 0; i < row_count; i++) {
        figures_in_row[i] = 0;
        int row_index = i;
        for (int j = 0; j < col_count; j++) {
            int column_index = j;
            for (int r = 0; r < point_x.size(); r++) {
                if (row_index == point_x[r]) {
                    if (r != h) {
                        target_x = r;
                        break;
                    }
                }


            }
            for (int q = 0; q < point_y.size(); q++) {
                if (column_index == point_y[q]) {
                    if (q != l) {
                        target_y = q;
                        break;
                    }
                }

            }
            if (target_x == target_y) {
                figure_matrix[i] = new Node;
                figure_matrix[i]->square = figures[k].Square();
                figure_matrix[i]->perimetr = figures[k].Perimetr();
                figure_matrix[i]->convex = figures[k].Isconvex();
                figure_matrix[i]->column_index = j;
                figure_matrix[i]->next = current_node;
                current_node = figure_matrix[i];
                figures_in_row[i]++;//Масив що містить к-сть елементів в кожному рядку
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
    Listp current_node = NULL;
    for (int i = 0; i < row_count; i++) {
        current_node = figure_matrix[i];
        for (int j = 0; j < figures_in_row[i]; j++) {
            std::cout << current_node->square << " ";
            current_node = current_node->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Matrix::Show_Matrix_Perimetr() {
    std::cout << "Matrix of Perimeters" << std::endl;
    Listp current_node = NULL;
    for (int i = 0; i < row_count; i++) {
        current_node = figure_matrix[i];
        for (int j = 0; j < figures_in_row[i]; j++) {
            std::cout << current_node->perimetr << " ";
            current_node = current_node->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Matrix::Show_Matrix_Convex() {
    std::cout << "Matrix of Convex" << std::endl;
    Listp current_node = NULL;
    for (int i = 0; i < row_count; i++) {
        current_node = figure_matrix[i];
        for (int j = 0; j < figures_in_row[i]; j++) {
            std::cout << current_node->convex << " ";
            current_node = current_node->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<double> Matrix::Index_Search(int row, int column) {// Йдемо по не нульовим елементам і шукаємо значеня за заданим індексом
    Listp current_node = NULL;
    std::vector<double> value;
    for (int i = 0; i < row_count; i++) {
        current_node = figure_matrix[i];
        for (int j = 0; j < figures_in_row[i]; j++) {
            if (i == row && current_node->column_index == column) {
                value.push_back(current_node->square);
                value.push_back(current_node->perimetr);
                value.push_back(current_node->convex);
                return value;
            }
            else {
                current_node = current_node->next;
            }
        }
    }
    if (value.empty()) {
        std::cout << "There aren't any value  by this index" << std::endl;
    }
    std::cout << std::endl;
}

std::vector<double> Matrix::Value_Search(int value) {// Йдемо по не нульовим елементам і шукаємо іднекс за заданим значенням
    Listp current_node = NULL;
    std::vector<double> Index;
    for (int i = 0; i < row_count; i++) {
        current_node = figure_matrix[i];
        for (int j = 0; j < figures_in_row[i]; j++) {
            if (current_node->square == value) {
                Index.push_back(i);
                Index.push_back(current_node->column_index);
                return Index;
            }
            else {
                current_node = current_node->next;
            }
        }
    }
    if (Index.empty()) {
        std::cout << "There aren't any index by this value" << std::endl;
    }
    std::cout << std::endl;
}
int Matrix::Value_By_Condition() {//Шукаємо першу не опуклу фігуру 
    Listp current_node = NULL;
    int value = 0;
    for (int i = 0; i < row_count; i++) {
        current_node = figure_matrix[i];
        for (int j = 0; j < figures_in_row[i]; j++) {
            if (current_node->convex == -1) {
                value = current_node->square;
                return value;
            }
            else {
                current_node = current_node->next;
            }
        }
    }
    if (value == 0) {
        return 0;
    }
    std::cout << std::endl;
}

void Matrix::InitializeMatrix(int row_count, int col_count) {
    this->row_count = row_count;
    this->col_count = col_count;
    figure_matrix = new Listp[row_count];
    figures_in_row = new int[row_count];
}

Matrix::~Matrix() {
    delete[] figures_in_row;
    for (int i = 0; i < row_count; i++) {
        Listp current = figure_matrix[i];
        while (current != nullptr) {
            Listp next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] figure_matrix;
}