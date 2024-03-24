#include "Spare Matrix_Figure.h"

Matrix::Matrix(int row_count, int column_count) {
    InitializeMatrix(row_count, column_count);
    Listp current_node = NULL;
    for (int i = 0; i < row_count; i++) {
        figures_in_row[i] = 0;
        for (int j = 0; j < column_count; j++) {
            int point_count;
            std::cout << "Input count of point of figure" << std::endl;
            std::cin >> point_count;
            if (point_count >= 3) {
                figure_matrix[i] = new Node;//���� �-��� ����� � ����� ����� 3 �� �� �� ������� �� � ������� ������ � ���� ����� ������� ��������
                int x, y;
                std::vector<Point> points;
                for (int k = 0; k < point_count; k++) {
                    std::cout << "Input coordinate (x; y)" << std::endl;
                    std::cin >> x >> y;
                    points.push_back(*new Point(x, y));
                }
                Figure figure(point_count, points);
                InitializeFigureMatrix(i, figure, j, current_node);
            }
        }
    }
    std::cout << std::endl;
}

Matrix::Matrix(int row_count, int column_count, std::vector<Figure> figures, std::vector<int> point_x, std::vector<int> point_y) {
    InitializeMatrix(row_count, column_count);
    Listp current_node = NULL;
    int k = 0;
    int target_x = 0; int target_y = 0;
    int h = -1; int l = -1;
    for (int i = 0; i < row_count; i++) {
        figures_in_row[i] = 0;
        int row_index = i;
        for (int j = 0; j < column_count; j++) {
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
                InitializeFigureMatrix(i, figures[k], j, current_node);
                k++;
                h++;
                l++;
            }
        }
    }
    std::cout << std::endl;
}

int Matrix::Get_Row_Count() {
    return row_count;
}
int Matrix::Get_Column_Count() {
    return column_count;
}
int* Matrix::Get_Figures_In_Row() {
    return figures_in_row;
}
Listp* Matrix::Get_Figure_Matrix() {
    return figure_matrix;
}
void Matrix::Set_Row_Count(int row_count) {
    this->row_count = row_count;
}
void Matrix::Set_Column_Count(int column_count) {
    this->column_count = column_count;
}
void Matrix::Set_Figures_In_Row(int* figures_in_row) {
    this->figures_in_row = figures_in_row;
}
void Matrix::Set_Figure_Matrix(Listp* figure_matrix) {
    this->figure_matrix = figure_matrix;
}
void Matrix::InitializeFigureMatrix(int i, Figure& figure, int j, Listp& current_node)
{
    figure_matrix[i] = new Node;
    figure_matrix[i]->square = figure.Square();
    figure_matrix[i]->perimetr = figure.Perimetr();
    figure_matrix[i]->convex = figure.Isconvex();
    figure_matrix[i]->column_index = j;
    figure_matrix[i]->next = current_node;
    current_node = figure_matrix[i];
    figures_in_row[i]++;//����� �� ������ �-��� �������� � ������� �����
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

std::vector<double> Matrix::Index_Search(int row, int column) {// ����� �� �� �������� ��������� � ������ ������� �� ������� ��������
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

std::vector<double> Matrix::Value_Search(int value) {// ����� �� �� �������� ��������� � ������ ������ �� ������� ���������
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
int Matrix::Value_By_Condition() {//������ ����� �� ������ ������ 
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

void Matrix::InitializeMatrix(int row_count, int column_count) {
    Set_Row_Count(row_count);
    Set_Column_Count(column_count);
    figure_matrix = new Listp[row_count];
    figures_in_row = new int[row_count];
}

Matrix::~Matrix() {
    for (int i = 0; i < row_count; i++) {
        Listp current = figure_matrix[i];
        for (int j = 0; j < figures_in_row[i]; j++) {
            Listp temp = current;
            if (current->next != nullptr) {
                current = current->next;
            }
            delete temp;
        }
    }
    delete[] figures_in_row;
    delete[] figure_matrix;
}