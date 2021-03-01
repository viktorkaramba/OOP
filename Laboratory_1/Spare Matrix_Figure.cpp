#include "Spare Matrix_Figure.h"

/*! 
\code 
Matrix::Matrix()
{
    c_of_rows = 0;
    c_of_columns = 0;
    Listp p = NULL;
    matrix = new Listp[c_of_rows];
    count_of_elements = new int[c_of_rows];
    for (int i = 0; i < c_of_rows; i++) {
        count_of_elements[i] = 0;
        p = NULL;
        for (int j = 0; j < c_of_columns; j++) {
                matrix[i] = new Node;
                matrix[i]->square = 0;
                matrix[i]->perimetr = 0;
                matrix[i]->convex = 0;
                matrix[i]->index_of_column = j;
                matrix[i]->next = p;
                p = matrix[i];
                count_of_elements[i] = count_of_elements[i] + 1;

        }
    }
}

\endcode
*/
Matrix::Matrix() /*!  Constructor by default  */
{
    c_of_rows = 0;
    c_of_columns = 0;
    Listp p = NULL;
    matrix = new Listp[c_of_rows];
    count_of_elements = new int[c_of_rows];
    for (int i = 0; i < c_of_rows; i++) {
        count_of_elements[i] = 0;
        p = NULL;
        for (int j = 0; j < c_of_columns; j++) {
                matrix[i] = new Node;
                matrix[i]->square = 0;
                matrix[i]->perimetr = 0;
                matrix[i]->convex = 0;
                matrix[i]->index_of_column = j;
                matrix[i]->next = p;
                p = matrix[i];
                count_of_elements[i] = count_of_elements[i] + 1; 
            
        }
    }
}
/*!
\param[in] C_of_Rows input parametr
\param[in] C_of_Columns input parametr

*/
/*!
\code
Matrix::Matrix(int C_of_Rows, int C_of_Columns) {
{
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
            if (n >= 3) {
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
                count_of_elements[i] = count_of_elements[i] + 1;
            }
        }
    }
}

\endcode
*/
/*!
Constructor with two parametrs
*/
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
            if (n >= 3) {
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
                count_of_elements[i] = count_of_elements[i] + 1;
            }
        }
    }
}

/*!
\param[in] C_of_Rows input parametr
\param[in] C_of_Columns input parametr
\param[in] Figures input parametr
\param[in] Rows input parametr
\param[in] Columns input parametr
*/
/*!
\code
Matrix::Matrix(int C_of_Rows, int C_of_Columns, std::vector<Figure> Figures, std::vector<int> Rows, std::vector<int> Columns) {
{
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
                    y = -2;
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
                    w = -1;
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
                count_of_elements[i] = count_of_elements[i] + 1;
                k++;
                h++;
                l++;
            }
           
        }
    }
}
}

\endcode
*/
/*!
Constructor with three parametrs
*/
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
                    y = -2;
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
                    w = -1;
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
                count_of_elements[i] = count_of_elements[i] + 1;
                k++;
                h++;
                l++;
                
            }
           
        }
    }
}

/*!
\code
void Matrix::Show_Matrix_Square() 
{
    std::cout << "Matrix of Squares" << std::endl;
    Listp p = NULL;
    int n = 0;
    for (int i = 0; i < c_of_rows; i++) {
        if (count_of_elements[i] == 0) {
            continue;
        }
        else {
            p = matrix[i];
            while (p) {
                std::cout << p->square << " ";
                p = p->next;
            }
            std::cout << std::endl;
        }
    }
}
\endcode
*/
/*!
Function for show on console matrix of perimetrs
*/

void Matrix::Show_Matrix_Square() {
    std::cout << "Matrix of Squares" << std::endl;
    Listp p = NULL;
    int n = 0;
    for (int i = 0; i < c_of_rows; i++) {
        if (count_of_elements[i] == 0) {
            continue;
        }
        else {
            p = matrix[i];
            while (p) {
                std::cout << p->square << " ";
                p = p->next;
            }
            std::cout << std::endl;
        }
        
    }
}

/*!
Function for show on console matrix of squares
*/
void Matrix::Show_Matrix_Perimetr() {
    std::cout << "Matrix of Perimeters" << std::endl;
    Listp p = NULL;
    int n = 0;
    for (int i = 0; i < c_of_rows; i++) {
        if (count_of_elements[i] == 0) {
            continue;
        }
        else {
            p = matrix[i];
            while (p) {
                std::cout << p->perimetr << " ";
                p = p->next;
            }
            std::cout << std::endl;
        }
       
    }
}
/*!
Function for show on console matrix of convex
*/
void Matrix::Show_Matrix_Convex() {
    std::cout << "Matrix of Convex" << std::endl;
    Listp p = NULL;
    int n = 0;
    for (int i = 0; i < c_of_rows; i++) {
        if (count_of_elements[i] == 0) {
            continue;
        }
        else {
            p = matrix[i];
            while (p) {
                std::cout << p->convex << " ";
                p = p->next;
            }
            std::cout << std::endl;
        }
    }
}
/*!
\param[in] I_of_Rows input parametr(index for row)
\param[in] I_of_Columns input parametr(index for column)
\param[out] value output parametr
*/
/*!
\code
std::vector<int> Matrix::Index_Search(int I_of_Row, int I_of_Column) {
{
     Listp p = NULL;
    std::vector<int> value;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
       while(p) {
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
}

\endcode
*/
/*!
Function for searching value by index
*/
std::vector<int> Matrix::Index_Search(int I_of_Row, int I_of_Column) {/*! …демо по не нульовим елементам ≥ шукаЇмо значен€ за заданим ≥ндексом*/
    Listp p = NULL;
    std::vector<int> value;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
       while(p) {
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
}
/*!
\param[in] value input parametr
\param[out] Index output parametr
*/
/*!
\code
std::vector<int> Matrix::Value_Search(double value) {
{
      Listp p = NULL;
    std::vector<int> Index;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
        while (p) {
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
}

\endcode
*/
/*!
Function for searching indexes by value
*/
std::vector<int> Matrix::Value_Search(double value) {
    Listp p = NULL;
    std::vector<int> Index;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
        while (p) {
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
}
/*!
\param[out] value output parametr
*/
/*!
\code
int Matrix::Value_By_Condition() {
{
    Listp p = NULL;
    int value = 0;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
        while(p) {
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
}

\endcode
*/
/*!
Function for searching value by condition(first not convex figure)
*/
int Matrix::Value_By_Condition() {
    Listp p = NULL;
    int value = 0;
    for (int i = 0; i < c_of_rows; i++) {
        p = matrix[i];
        while(p) {
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
   
}
/*!
\param[in] M1 input parametr
\param[in] M2 input parametr
\param[in] C_of_Rows input parametr
\param[in] C_of_Columns input parametr
\param[out] Sum output parametr 
*/
/*!
\code
void Matrix::SumMatrix(Matrix M1, Matrix M2, int C_of_Rows, int C_of_Columns)
{
    c_of_rows = C_of_Rows;
    c_of_columns = C_of_Columns;
    Listp p = NULL, p1 = NULL, pc = NULL, pp = NULL;
    Listp pa = NULL;Listp pb = NULL;Listp p2 = NULL;Listp p3 = NULL;
    matrix = new Listp[c_of_rows];
    count_of_elements = new int[c_of_rows];
    for (int i = 0; i < c_of_rows; i++) 
    {
        count_of_elements[i] = 0;
        p = NULL; pc = NULL; pa = NULL; pb = NULL; p2 = NULL; p3 = NULL; pp = NULL;
        if (M1.count_of_elements[i] == 0 && M2.count_of_elements[i] == 0) {
            continue;
        }
        else if (M1.count_of_elements[i] != 0 && M2.count_of_elements[i] == 0) {
            p = M1.matrix[i];
            while (p) {
                pc = p->next;
                p->next = p2;
                p2 = p;
                p = pc;
            }
            pa = p2;
            M1.matrix[i] = p2;
            p1 = NULL;
            while (pa) {
                matrix[i] = new Node;
                matrix[i]->index_of_column = pa->index_of_column;
                matrix[i]->perimetr = pa->perimetr;
                matrix[i]->square = pa->square;
                matrix[i]->convex = pa->convex;
                matrix[i]->next = p1;
                p1 = matrix[i];
                pa = pa->next;
                count_of_elements[i] = count_of_elements[i] + 1;
            }
            continue;
        }
        else if (M1.count_of_elements[i] == 0 && M2.count_of_elements[i] != 0) {
            p = M2.matrix[i];
            while (p) {
                pc = p->next;
                p->next = p2;
                p2 = p;
                p = pc;
            }
            pb = p2;
            M2.matrix[i] = p2;
            p1 = NULL;
            while (pb) {
                matrix[i] = new Node;
                matrix[i]->index_of_column = pb->index_of_column;
                matrix[i]->perimetr = pb->perimetr;
                matrix[i]->square = pb->square;
                matrix[i]->convex = pb->convex;
                matrix[i]->next = p1;
                p1 = matrix[i];
                pb = pb->next;
                count_of_elements[i] = count_of_elements[i] + 1;
            }
            continue;
        }
        else {
            p = M1.matrix[i];
            while (p) {
                pc = p->next;
                p->next = p2;
                p2 = p;
                p = pc;
            }
            pc = NULL;
            pp = M2.matrix[i];
            while (pp) {
                pc = pp->next;
                pp->next = p3;
                p3 = pp;
                pp = pc;
            }
            pa = p2;
            pb = p3;
            M1.matrix[i] = p2;
            M2.matrix[i] = p3;
            p1 = NULL;
            while (pa && pb) { 
                if (pa->index_of_column == pb->index_of_column) {
                    matrix[i] = new Node;
                    matrix[i]->index_of_column = pa->index_of_column;
                    matrix[i]->perimetr = pa->perimetr + pb->perimetr;
                    matrix[i]->square = pa->square + pb->square;
                    matrix[i]->convex = pa->convex;
                    matrix[i]->next = p1;
                    p1 = matrix[i];
                    pa = pa->next;
                    pb = pb->next;
                    count_of_elements[i] = count_of_elements[i] + 1;
                }
                else if (pa->index_of_column < pb->index_of_column) {
                    matrix[i] = new Node;
                    matrix[i]->index_of_column = pa->index_of_column;
                    matrix[i]->perimetr = pa->perimetr;
                    matrix[i]->square = pa->square;
                    matrix[i]->convex = pa->convex;
                    matrix[i]->next = p1;
                    p1 = matrix[i];
                    pa = pa->next;
                    count_of_elements[i] = count_of_elements[i] + 1;
                }
                else {
                    matrix[i] = new Node;
                    matrix[i]->index_of_column = pb->index_of_column;
                    matrix[i]->perimetr = pb->perimetr;
                    matrix[i]->square = pb->square;
                    matrix[i]->convex = pb->convex;
                    matrix[i]->next = p1;
                    p1 = matrix[i];
                    pb = pb->next;
                    count_of_elements[i] = count_of_elements[i] + 1;
                }
            }
        }
    }
}

\endcode
*/
/*!
Function for adding two sparse matrices
*/
void Matrix::SumMatrix(Matrix M1, Matrix M2, int C_of_Rows, int C_of_Columns)
{
    c_of_rows = C_of_Rows;
    c_of_columns = C_of_Columns;
    Listp p = NULL, p1 = NULL, pc = NULL, pp = NULL;
    Listp pa = NULL;Listp pb = NULL;Listp p2 = NULL;Listp p3 = NULL;
    matrix = new Listp[c_of_rows];
    count_of_elements = new int[c_of_rows];
    for (int i = 0; i < c_of_rows; i++) 
    {
        count_of_elements[i] = 0;
        p = NULL; pc = NULL; pa = NULL; pb = NULL; p2 = NULL; p3 = NULL; pp = NULL;
        if (M1.count_of_elements[i] == 0 && M2.count_of_elements[i] == 0) {
            continue;
        }
        else if (M1.count_of_elements[i] != 0 && M2.count_of_elements[i] == 0) {
            p = M1.matrix[i];
            while (p) {
                pc = p->next;
                p->next = p2;
                p2 = p;
                p = pc;
            }
            pa = p2;
            M1.matrix[i] = p2;
            p1 = NULL;
            while (pa) {
                matrix[i] = new Node;
                matrix[i]->index_of_column = pa->index_of_column;
                matrix[i]->perimetr = pa->perimetr;
                matrix[i]->square = pa->square;
                matrix[i]->convex = pa->convex;
                matrix[i]->next = p1;
                p1 = matrix[i];
                pa = pa->next;
                count_of_elements[i] = count_of_elements[i] + 1;
            }
            continue;
        }
        else if (M1.count_of_elements[i] == 0 && M2.count_of_elements[i] != 0) {
            p = M2.matrix[i];
            while (p) {
                pc = p->next;
                p->next = p2;
                p2 = p;
                p = pc;
            }
            pb = p2;
            M2.matrix[i] = p2;
            p1 = NULL;
            while (pb) {
                matrix[i] = new Node;
                matrix[i]->index_of_column = pb->index_of_column;
                matrix[i]->perimetr = pb->perimetr;
                matrix[i]->square = pb->square;
                matrix[i]->convex = pb->convex;
                matrix[i]->next = p1;
                p1 = matrix[i];
                pb = pb->next;
                count_of_elements[i] = count_of_elements[i] + 1;
            }
            continue;
        }
        else {
            p = M1.matrix[i];
            while (p) {
                pc = p->next;
                p->next = p2;
                p2 = p;
                p = pc;
            }
            pc = NULL;
            pp = M2.matrix[i];
            while (pp) {
                pc = pp->next;
                pp->next = p3;
                p3 = pp;
                pp = pc;
            }
            pa = p2;
            pb = p3;
            M1.matrix[i] = p2;
            M2.matrix[i] = p3;
            p1 = NULL;
            while (pa && pb) {
                if (pa->index_of_column == pb->index_of_column) {
                    matrix[i] = new Node;
                    matrix[i]->index_of_column = pa->index_of_column;
                    matrix[i]->perimetr = pa->perimetr + pb->perimetr;
                    matrix[i]->square = pa->square + pb->square;
                    matrix[i]->convex = pa->convex;
                    matrix[i]->next = p1;
                    p1 = matrix[i];
                    pa = pa->next;
                    pb = pb->next;
                    count_of_elements[i] = count_of_elements[i] + 1;
                }
                else if (pa->index_of_column < pb->index_of_column) {
                    matrix[i] = new Node;
                    matrix[i]->index_of_column = pa->index_of_column;
                    matrix[i]->perimetr = pa->perimetr;
                    matrix[i]->square = pa->square;
                    matrix[i]->convex = pa->convex;
                    matrix[i]->next = p1;
                    p1 = matrix[i];
                    pa = pa->next;
                    count_of_elements[i] = count_of_elements[i] + 1;
                }
                else {
                    matrix[i] = new Node;
                    matrix[i]->index_of_column = pb->index_of_column;
                    matrix[i]->perimetr = pb->perimetr;
                    matrix[i]->square = pb->square;
                    matrix[i]->convex = pb->convex;
                    matrix[i]->next = p1;
                    p1 = matrix[i];
                    pb = pb->next;
                    count_of_elements[i] = count_of_elements[i] + 1;
                }
            }
        }
    }
}

/*!
\param[in] M1 input parametr
\param[in] vector input parametr
\param[in] C_of_Rows input parametr
\param[in] C_of_Columns input parametr
\param[out] Product output parametr
*/
/*!
\code
void Matrix::MultiplyVector(Matrix M1, std::vector<int> vector, int C_of_Rows, int C_of_Columns)
{
     c_of_rows = C_of_Rows;
    c_of_columns = C_of_Columns;
    Listp p = NULL, p1 = NULL, pc = NULL, pp = NULL;
    Listp pa = NULL; Listp pb = NULL; Listp p2 = NULL; Listp p3 = NULL;
    matrix = new Listp[c_of_rows];
    count_of_elements = new int[c_of_rows];
    int N = 0;
    for (int i = 0; i < c_of_rows; i++) //переб≥р р€дк≥в
    {
        count_of_elements[i] = 0;
        p1 = NULL;
        matrix[i] = new Node;
        matrix[i]->next = p1;
        p1 = matrix[i];
        count_of_elements[i] = count_of_elements[i] + 1;
        p = NULL; pc = NULL; pa = NULL; pb = NULL; p2 = NULL;
        if (M1.count_of_elements[i] == 0) { 
            int t = 0;
                for (int h = 0; h < vector.size(); h++) {
                if (t == 0) {
                    matrix[i]->index_of_column = 1;
                    matrix[i]->perimetr = vector[h];
                    matrix[i]->square = vector[h];
                    matrix[i]->convex = vector[h];
                    t++;
                    continue;
                }
                else {
                     matrix[i]->index_of_column = 1;
                     matrix[i]->perimetr += vector[h];
                     matrix[i]->square += vector[h];
                     matrix[i]->convex += vector[h];
                     continue;
                }
            }
          
        }
        else {
            p = M1.matrix[i];
            while (p) {
                pc = p->next;
                p->next = p2;
                p2 = p;
                p = pc;
            }
            pa = p2;
            M1.matrix[i] = p2;
            N = 0;
            while (pa) {
                for (int f = 0; f < vector.size(); f++) {
                    if (pa == NULL) {
                        break;
                    }
                    else {
                        if (pa->index_of_column == f) {
                            if (N == 0) {
                                matrix[i]->index_of_column = pa->index_of_column;
                                matrix[i]->perimetr = pa->perimetr * vector[f];
                                matrix[i]->square = pa->square * vector[f];
                                matrix[i]->convex = pa->convex;
                                pa = pa->next;
                                N++;
                                continue;
                            }
                            else {
                                matrix[i]->index_of_column = pa->index_of_column;
                                matrix[i]->perimetr += pa->perimetr * vector[f];
                                matrix[i]->square += pa->square * vector[f];
                                matrix[i]->convex = pa->convex;
                                pa = pa->next;
                                continue;
                            }
                        }
                        else if (pa->index_of_column > f) {
                            if (N == 0) {
                                matrix[i]->index_of_column = f;
                                matrix[i]->perimetr = vector[f];
                                matrix[i]->square = vector[f];
                                matrix[i]->convex;
                                N++;
                                continue;

                            }
                            else {
                                matrix[i]->index_of_column = f;
                                matrix[i]->perimetr += vector[f];
                                matrix[i]->square += vector[f];
                                matrix[i]->convex;
                                continue;
                            }
                        }
                        else {
                            if (N == 0) {
                                matrix[i]->index_of_column = pa->index_of_column;
                                matrix[i]->perimetr = pa->perimetr;
                                matrix[i]->square = pa->square;
                                matrix[i]->convex = pa->convex;
                                N++;
                                continue;

                            }
                            else {
                                matrix[i]->index_of_column = pa->index_of_column;
                                matrix[i]->perimetr += pa->perimetr;
                                matrix[i]->square += pa->square;
                                matrix[i]->convex = pa->convex;
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
}

\endcode
*/
/*!
Function for multiply matrix on vector
*/
void Matrix::MultiplyVector(Matrix M1, std::vector<int> vector, int C_of_Rows, int C_of_Columns)
{
    c_of_rows = C_of_Rows;
    c_of_columns = C_of_Columns;
    Listp p = NULL, p1 = NULL, pc = NULL, pp = NULL;
    Listp pa = NULL; Listp pb = NULL; Listp p2 = NULL; Listp p3 = NULL;
    matrix = new Listp[c_of_rows];
    count_of_elements = new int[c_of_rows];
    int N = 0;
    for (int i = 0; i < c_of_rows; i++) 
    {
        count_of_elements[i] = 0;
        p1 = NULL;
        matrix[i] = new Node;
        matrix[i]->next = p1;
        p1 = matrix[i];
        count_of_elements[i] = count_of_elements[i] + 1;
        p = NULL; pc = NULL; pa = NULL; pb = NULL; p2 = NULL;
        if (M1.count_of_elements[i] == 0) { 
            int t = 0;
                for (int h = 0; h < vector.size(); h++) {
                if (t == 0) {
                    matrix[i]->index_of_column = 1;
                    matrix[i]->perimetr = vector[h];
                    matrix[i]->square = vector[h];
                    matrix[i]->convex = vector[h];
                    t++;
                    continue;
                }
                else {
                     matrix[i]->index_of_column = 1;
                     matrix[i]->perimetr += vector[h];
                     matrix[i]->square += vector[h];
                     matrix[i]->convex += vector[h];
                     continue;
                }
            }
          
        }
        else {
            p = M1.matrix[i];
            while (p) {
                pc = p->next;
                p->next = p2;
                p2 = p;
                p = pc;
            }
            pa = p2;
            M1.matrix[i] = p2;
            N = 0;
            while (pa) {
                for (int f = 0; f < vector.size(); f++) {
                    if (pa == NULL) {
                        break;
                    }
                    else {
                        if (pa->index_of_column == f) {
                            if (N == 0) {
                                matrix[i]->index_of_column = pa->index_of_column;
                                matrix[i]->perimetr = pa->perimetr * vector[f];
                                matrix[i]->square = pa->square * vector[f];
                                matrix[i]->convex = pa->convex;
                                pa = pa->next;
                                N++;
                                continue;
                            }
                            else {
                                matrix[i]->index_of_column = pa->index_of_column;
                                matrix[i]->perimetr += pa->perimetr * vector[f];
                                matrix[i]->square += pa->square * vector[f];
                                matrix[i]->convex = pa->convex;
                                pa = pa->next;
                                continue;
                            }
                        }
                        else if (pa->index_of_column > f) {
                            if (N == 0) {
                                matrix[i]->index_of_column = f;
                                matrix[i]->perimetr = vector[f];
                                matrix[i]->square = vector[f];
                                matrix[i]->convex;
                                N++;
                                continue;

                            }
                            else {
                                matrix[i]->index_of_column = f;
                                matrix[i]->perimetr += vector[f];
                                matrix[i]->square += vector[f];
                                matrix[i]->convex;
                                continue;
                            }
                        }
                        else {
                            if (N == 0) {
                                matrix[i]->index_of_column = pa->index_of_column;
                                matrix[i]->perimetr = pa->perimetr;
                                matrix[i]->square = pa->square;
                                matrix[i]->convex = pa->convex;
                                N++;
                                continue;

                            }
                            else {
                                matrix[i]->index_of_column = pa->index_of_column;
                                matrix[i]->perimetr += pa->perimetr;
                                matrix[i]->square += pa->square;
                                matrix[i]->convex = pa->convex;
                                continue;
                            }
                        }
                    }
                }
            }

        }
    }
}
