#include "Spare Matrix_Figure.h"

Matrix::Matrix()
{
    InitializeMatrix(0, 0);
    Listp current_node = NULL;
    for (int i = 0; i < row_count; i++) {
        figures_in_row[i] = 0;
        current_node = NULL;
        for (int j = 0; j < column_count; j++) {
            figure_matrix[i] = new Node;
            figure_matrix[i]->square = 0;
            figure_matrix[i]->perimetr = 0;
            figure_matrix[i]->convex = 0;
            figure_matrix[i]->column_index = j;
            figure_matrix[i]->next = current_node;
            current_node = figure_matrix[i];
            figures_in_row[i] = figures_in_row[i] + 1;

        }
    }
}

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
                figure_matrix[i] = new Node;//Якщо к-сть сторін в фігурі менше 3 то ми не зберігаєм її в матриці інакше а поле даних заносим значення
                int x, y;
                std::vector<Point> points;
                for (int k = 0; k < point_count; k++) {
                    std::cout << "Input coordinate (x; y)" << std::endl;
                    std::cin >> x >> y;
                    points.push_back(*new Point(x, y));
                }
                Figure figure(point_count, points, new BaseAreaCalculationStrategy());
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
void Matrix::SumMatrix(Matrix matrix_1, Matrix matrix_2)
{
    InitializeMatrix(matrix_1.Get_Row_Count(), matrix_1.Get_Column_Count());
    Listp matrix_1_node = NULL,  matrix_2_node = NULL,  additional__node_1 = NULL, 
        additional_node_2 = NULL, additional_node_3 = NULL, additional_node_4 = NULL,
        additional_node_5 = NULL; Listp additional_node_6 = NULL;
    for (int i = 0; i < Get_Row_Count(); i++)
    {
        figures_in_row[i] = 0;
        additional__node_1 = NULL; additional_node_3 = NULL; matrix_1_node = NULL; matrix_2_node = NULL; additional_node_5 = NULL; additional_node_6 = NULL; additional_node_4 = NULL;
        if (matrix_1.figures_in_row[i] == 0 && matrix_2.figures_in_row[i] == 0) {
            continue;
        }
        else if (matrix_1.figures_in_row[i] != 0 && matrix_2.figures_in_row[i] == 0) {
            additional__node_1 = matrix_1.figure_matrix[i];
            while (additional__node_1) {
                additional_node_3 = additional__node_1->next;
                additional__node_1->next = additional_node_5;
                additional_node_5 = additional__node_1;
                additional__node_1 = additional_node_3;
            }
            matrix_1_node = additional_node_5;
            matrix_1.figure_matrix[i] = additional_node_5;
            additional_node_2 = NULL;
            while (matrix_1_node) {
                InitializeListpMatrix(i, matrix_1_node, additional_node_2);
            }
            continue;
        }
        else if (matrix_1.figures_in_row[i] == 0 && matrix_2.figures_in_row[i] != 0) {
            additional__node_1 = matrix_2.figure_matrix[i];
            while (additional__node_1) {
                additional_node_3 = additional__node_1->next;
                additional__node_1->next = additional_node_5;
                additional_node_5 = additional__node_1;
                additional__node_1 = additional_node_3;
            }
            matrix_2_node = additional_node_5;
            matrix_2.figure_matrix[i] = additional_node_5;
            additional_node_2 = NULL;
            while (matrix_2_node) {
                InitializeListpMatrix(i, matrix_2_node, additional_node_2);
            }
            continue;
        }
        else {
            additional__node_1 = matrix_1.figure_matrix[i];
            while (additional__node_1) {
                additional_node_3 = additional__node_1->next;
                additional__node_1->next = additional_node_5;
                additional_node_5 = additional__node_1;
                additional__node_1 = additional_node_3;
            }
            additional_node_3 = NULL;
            additional_node_4 = matrix_2.figure_matrix[i];
            while (additional_node_4) {
                additional_node_3 = additional_node_4->next;
                additional_node_4->next = additional_node_6;
                additional_node_6 = additional_node_4;
                additional_node_4 = additional_node_3;
            }
            matrix_1_node = additional_node_5;
            matrix_2_node = additional_node_6;
            matrix_1.figure_matrix[i] = additional_node_5;
            matrix_2.figure_matrix[i] = additional_node_6;
            additional_node_2 = NULL;
            while (matrix_1_node && matrix_2_node) {
                if (matrix_1_node->column_index == matrix_2_node->column_index) {
                    figure_matrix[i] = new Node;
                    figure_matrix[i]->column_index = matrix_1_node->column_index;
                    figure_matrix[i]->perimetr = matrix_1_node->perimetr + matrix_2_node->perimetr;
                    figure_matrix[i]->square = matrix_1_node->square + matrix_2_node->square;
                    figure_matrix[i]->convex = matrix_1_node->convex;
                    figure_matrix[i]->next = additional_node_2;
                    additional_node_2 = figure_matrix[i];
                    matrix_1_node = matrix_1_node->next;
                    matrix_2_node = matrix_2_node->next;
                    figures_in_row[i]++;
                }
                else if (matrix_1_node->column_index < matrix_2_node->column_index) {
                    InitializeListpMatrix(i, matrix_1_node, additional_node_2);
                }
                else {
                    InitializeListpMatrix(i, matrix_2_node, additional_node_2);
                }
            }
        }
    }
}
void Matrix::MultiplyVector(Matrix matrix_1, std::vector<int> vector)
{
    InitializeMatrix(matrix_1.Get_Row_Count(), matrix_1.Get_Column_Count());
    Listp additional__node_1 = NULL, additional__node_2 = NULL, additional__node_3 = NULL, additional__node_4 = NULL;
    Listp additional__node_5 = NULL; Listp additional__node_6 = NULL; Listp additional__node_7 = NULL; Listp additional__node_8 = NULL;
    int N = 0;
    for (int i = 0; i < row_count; i++)
    {
        figures_in_row[i] = 0;
        additional__node_2 = NULL;
        figure_matrix[i] = new Node;
        figure_matrix[i]->next = additional__node_2;
        additional__node_2 = figure_matrix[i];
        figures_in_row[i]++;
        additional__node_1 = NULL; additional__node_3 = NULL; additional__node_5 = NULL; additional__node_6 = NULL; additional__node_7 = NULL;
        if (matrix_1.Get_Figures_In_Row()[i] == 0) {
            int t = 0;
            for (int h = 0; h < vector.size(); h++) {
                if (t == 0) {
                    InitializeVectorMatrix(i, vector, h);
                    t++;
                    continue;
                }
                else {
                    InitializeVectorMatrix(i, vector, h);
                    continue;
                }
            }

        }
        else {
            additional__node_1 = matrix_1.Get_Figure_Matrix()[i];
            while (additional__node_1) {
                additional__node_3 = additional__node_1->next;
                additional__node_1->next = additional__node_7;
                additional__node_7 = additional__node_1;
                additional__node_1 = additional__node_3;
            }
            additional__node_5 = additional__node_7;
            matrix_1.Get_Figure_Matrix()[i] = additional__node_7;
            N = 0;
            while (additional__node_5) {
                for (int f = 0; f < vector.size(); f++) {
                    if (additional__node_5 == NULL) {
                        break;
                    }
                    else {
                        if (additional__node_5->column_index == f) {
                            if (N == 0) {
                                InitializeNodeVectorMatrix(i, additional__node_5, vector, f);
                                N++;
                                continue;
                            }
                            else {
                                InitializeNodeVectorMatrix(i, additional__node_5, vector, f);
                                continue;
                            }
                        }
                        else if (additional__node_5->column_index > f) {
                            if (N == 0) {
                                figure_matrix[i]->column_index = f;
                                figure_matrix[i]->perimetr = vector[f];
                                figure_matrix[i]->square = vector[f];
                                N++;
                                continue;

                            }
                            else {
                                figure_matrix[i]->column_index = f;
                                figure_matrix[i]->perimetr += vector[f];
                                figure_matrix[i]->square += vector[f];
                                continue;
                            }
                        }
                        else {
                            if (N == 0) {
                                InitializeNodeMatrix(i, additional__node_5);
                                N++;
                                continue;

                            }
                            else {
                                InitializeNodeMatrix(i, additional__node_5);
                                continue;
                            }
                        }
                    }
                }
            }

        }
    }
}
void Matrix::InitializeNodeVectorMatrix(int i, Listp& additional__node_5, std::vector<int>& vector, int f)
{
    figure_matrix[i]->column_index = additional__node_5->column_index;
    figure_matrix[i]->perimetr = additional__node_5->perimetr * vector[f];
    figure_matrix[i]->square = additional__node_5->square * vector[f];
    figure_matrix[i]->convex = additional__node_5->convex;
    additional__node_5 = additional__node_5->next;
}
void Matrix::InitializeNodeMatrix(int i, const Listp& additional__node_5)
{
    figure_matrix[i]->column_index = additional__node_5->column_index;
    figure_matrix[i]->perimetr = additional__node_5->perimetr;
    figure_matrix[i]->square = additional__node_5->square;
    figure_matrix[i]->convex = additional__node_5->convex;
}
void Matrix::InitializeVectorMatrix(int i, std::vector<int>& vector, int h)
{
    figure_matrix[i]->column_index = 1;
    figure_matrix[i]->perimetr = vector[h];
    figure_matrix[i]->square = vector[h];
    figure_matrix[i]->convex = vector[h];
}
void Matrix::InitializeMatrix(int row_count, int column_count) {
    Set_Row_Count(row_count);
    Set_Column_Count(column_count);
    figure_matrix = new Listp[row_count];
    figures_in_row = new int[row_count];
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
    figures_in_row[i]++;//Масив що містить к-сть елементів в кожному рядку
}
void Matrix::InitializeListpMatrix(int i, Listp& figure, Listp& current_node)
{
    figure_matrix[i] = new Node;
    figure_matrix[i]->square = figure->square;
    figure_matrix[i]->perimetr = figure->perimetr;
    figure_matrix[i]->convex = figure->convex;
    figure_matrix[i]->column_index = figure->column_index;
    figure_matrix[i]->next = current_node;
    current_node = figure_matrix[i];
    figures_in_row[i]++;//Масив що містить к-сть елементів в кожному рядку
    figure = figure->next;
}