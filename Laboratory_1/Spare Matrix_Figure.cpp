#include "Spare Matrix_Figure.h"

Matrix::Matrix(int nt, int t) {
    nn = nt;
    mm = t;
    int n;
    Listp p = NULL, o = NULL, r = NULL;
    m = new Listp[nn];
    s = new int[nn];
    for (int i = 0; i < nn; i++) {
        s[i] = 0;
        for (int j = 0; j < mm; j++) {
            std::cout << "Input count of point of figure" << std::endl;
            std::cin >> n;
            if (n >= 3) {
                m[i] = new Node;//Якщо к-сть сторін в фігурі менше 3 то ми не зберігаєм її в матриці інакше а поле даних заносим значення
                int a;
                int b;
                std::vector<int>X;
                std::vector<int>Y;
                for (int i = 0; i < n; i++) {
                    std::cout << "Input coordinate (x ; y)" << std::endl;
                    std::cin >> a;
                    X.push_back(a);
                    std::cin >> b;
                    Y.push_back(b);
                }
                Figure A(n, X, Y);
                m[i]->square = A.Square();
                m[i]->perimetr = A.Perimetr();
                m[i]->convex = A.Isconvex();
                m[i]->nj = j;
                m[i]->next = p;
                p = m[i];
                s[i] = s[i] + 1;//Масив що містить к-сть елементів в кожному рядку
            }
        }
    }
    std::cout << std::endl;
}
Matrix::Matrix(int nt, int t, std::vector<Figure> F1, std::vector<int> R, std::vector<int> S) {
    nn = nt;
    mm = t;
    int n;
    int k = 0;
    Listp p = NULL, o = NULL, r = NULL;
    m = new Listp[nn];
    s = new int[nn];
    int y = 0; int w = 0;
    int h = -1; int l = -1;
    for (int i = 0; i < nn; i++) {
        s[i] = 0;
        int rad = i;
        for (int j = 0; j < mm; j++) {
            int st = j;
            for (int r = 0; r < R.size(); r++) {
                if (rad == R[r]) {
                    if (r != h) {
                        y = r;
                        break;
                    }
                }


            }
            for (int q = 0; q < S.size(); q++) {
                if (st == S[q]) {
                    if (q != l) {
                        w = q;
                        break;
                    }
                }

            }



            if (y == w) {
                m[i] = new Node;
                m[i]->square = F1[k].Square();
                m[i]->perimetr = F1[k].Perimetr();
                m[i]->convex = F1[k].Isconvex();
                m[i]->nj = j;
                m[i]->next = p;
                p = m[i];
                s[i] = s[i] + 1;//Масив що містить к-сть елементів в кожному рядку
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
    for (int i = 0; i < nn; i++) {
        p = m[i];
        for (int j = 0; j < s[i]; j++) {
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
    for (int i = 0; i < nn; i++) {
        p = m[i];
        for (int j = 0; j < s[i]; j++) {
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
    for (int i = 0; i < nn; i++) {
        p = m[i];
        for (int j = 0; j < s[i]; j++) {
            std::cout << p->convex << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
std::vector<double> Matrix::Index_Search(int rd, int st) {// Йдемо по не нульовим елементам і шукаємо значеня за заданим індексом
    Listp p = NULL;
    std::vector<double> value;
    for (int i = 0; i < nn; i++) {
        p = m[i];
        for (int j = 0; j < s[i]; j++) {
            if (i == rd && p->nj == st) {
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

std::vector<double> Matrix::Value_Search(int value) {// Йдемо по не нульовим елементам і шукаємо іднекс за заданим значенням
    Listp p = NULL;
    std::vector<double> Index;
    for (int i = 0; i < nn; i++) {
        p = m[i];
        for (int j = 0; j < s[i]; j++) {
            if (p->square == value) {
                Index.push_back(i);
                Index.push_back(p->nj);
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
    for (int i = 0; i < nn; i++) {
        p = m[i];
        for (int j = 0; j < s[i]; j++) {
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