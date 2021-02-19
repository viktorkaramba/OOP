#include "Figure.h"
Figure::Figure(int Count_of_Points) {
    count_of_points = Count_of_Points;
    int Oxx;
    int Oyy;
    for (int i = 0; i < count_of_points; i++) {
        std::cout << "Input coordinate (x ; y)" << std::endl;
        std::cin >> Oxx;
        Ox.push_back(Oxx);
        std::cin >> Oyy;
        Oy.push_back(Oyy);
    }
}
Figure::Figure(int Count_of_Points, std::vector<int>OX, std::vector<int>OY) {
    count_of_points = Count_of_Points;
    Ox = OX;
    Oy = OY;
}
void Figure::Out() {
    std::cout << std::endl;
    for (int i = 0; i < count_of_points; i++) {
        std::cout << "( " << Ox[i] << ";" << Oy[i] << " )" << std::endl;
    }
}
int Figure::Perimetr() {
    int perimetr = 0;
    for (int i = 0; i < count_of_points; i++) {
        int j = (i + 1) % count_of_points;
        perimetr += sqrt((Ox[i] - Ox[j]) * (Ox[i] - Ox[j]) + (Oy[i] - Oy[j]) * (Oy[i] - Oy[j]));
    }
    return perimetr;
}
double Figure::Square() {
    double square = 0;
    double x1 = Ox[0];
    double y1 = Oy[0];
    double x2 = 0, y2 = 0;
    for (int i = 1; i < count_of_points; i++) {
        x2 = Ox[i];
        y2 = Oy[i];
        square = square + (x1 + x2) * (y2 - y1);
        x1 = x2;
        y1 = y2;
    }
    square = square + (Ox[0] + x2) * (Oy[0] - y2);
    return abs(square) / 2;
}
int Figure::Isconvex() {
    if (count_of_points < 3)
        return 0;
    int i, j, k;
    int flag = 0;
    float z;
    for (i = 0; i < count_of_points; i++) {
        j = (i + 1) % count_of_points;
        k = (i + 2) % count_of_points;
        z = (Ox[j] - Ox[i]) * (Oy[k] - Oy[j]);
        z -= (Oy[j] - Oy[i]) * (Ox[k] - Ox[j]);
        if (z < 0)
            flag |= 1;
        else if (z > 0)
            flag |= 2;
        if (flag == 3)
            return -1;
    }
    if (flag != 0)
        return 1;
    else
        return 0;
}
bool Figure::Checking_Figure() {
    if (count_of_points <= 4) {
        switch (count_of_points) {
        case 3:
            std::cout << "1. Isosceles\t  2. Rectangular\t  3. Equilateral\t" << std::endl;
            int a;
            std::cin >> a;
            switch (a) {
            case 1:
                if (sqrt(pow(Ox[0] - Ox[1], 2) + (pow(Oy[0] - Oy[1], 2))) == sqrt(pow(Ox[0] - Ox[2], 2) + (pow(Oy[0] - Oy[2], 2)))
                    || sqrt(pow(Ox[0] - Ox[1], 2) + (pow(Oy[0] - Oy[1], 2))) == sqrt(pow(Ox[1] - Ox[2], 2) + (pow(Oy[1] - Oy[2], 2)))
                    || sqrt(pow(Ox[0] - Ox[2], 2) + (pow(Oy[0] - Oy[2], 2))) == sqrt(pow(Ox[1] - Ox[2], 2) + (pow(Oy[1] - Oy[2], 2))))
                {
                    return true;
                }
                else {
                    return false;
                }
            case 2:
                if (sqrt(pow(Ox[0] - Ox[1], 2) + (pow(Oy[0] - Oy[1], 2))) + sqrt(pow(Ox[0] - Ox[2], 2) + (pow(Oy[0] - Oy[2], 2))) > sqrt(pow(Ox[1] - Ox[2], 2) + (pow(Oy[1] - Oy[2], 2)))) {
                    if (pow(sqrt(pow(Ox[1] - Ox[2], 2) + (pow(Oy[1] - Oy[2], 2))), 2) == pow(sqrt(pow(Ox[0] - Ox[1], 2) + (pow(Oy[0] - Oy[1], 2))), 2) + pow(sqrt(pow(Ox[0] - Ox[2], 2) + (pow(Oy[0] - Oy[2], 2))), 2)) {
                        return true;
                    }
                }
                if (sqrt(pow(Ox[0] - Ox[1], 2) + (pow(Oy[0] - Oy[1], 2))) + sqrt(pow(Ox[1] - Ox[2], 2) + (pow(Oy[1] - Oy[2], 2))) > sqrt(pow(Ox[0] - Ox[2], 2) + (pow(Oy[0] - Oy[2], 2)))) {
                    if (pow(sqrt(pow(Ox[0] - Ox[2], 2) + (pow(Oy[0] - Oy[2], 2))), 2) == pow(sqrt(pow(Ox[0] - Ox[1], 2) + (pow(Oy[0] - Oy[1], 2))), 2) + pow(sqrt(pow(Ox[1] - Ox[2], 2) + (pow(Oy[1] - Oy[2], 2))), 2)) {
                        return true;
                    }
                }
                if (sqrt(pow(Ox[0] - Ox[2], 2) + (pow(Oy[0] - Oy[2], 2))) + sqrt(pow(Ox[1] - Ox[2], 2) + (pow(Oy[1] - Oy[2], 2))) > sqrt(pow(Ox[0] - Ox[1], 2) + (pow(Oy[0] - Oy[1], 2)))) {
                    if (pow(sqrt(pow(Ox[0] - Ox[1], 2) + (pow(Oy[0] - Oy[1], 2))), 2) == pow(sqrt(pow(Ox[0] - Ox[2], 2) + (pow(Oy[0] - Oy[2], 2))), 2) + pow(sqrt(pow(Ox[1] - Ox[2], 2) + (pow(Oy[1] - Oy[2], 2))), 2)) {
                        return true;
                    }
                }
                else {
                    return false;
                }
            case 3:
                if (sqrt(pow(Ox[0] - Ox[1], 2) + (pow(Oy[0] - Oy[1], 2))) == sqrt(pow(Ox[0] - Ox[2], 2) + (pow(Oy[0] - Oy[2], 2))) && sqrt(pow(Ox[0] - Ox[2], 2) + (pow(Oy[0] - Oy[2], 2))) == sqrt(pow(Ox[1] - Ox[2], 2) + (pow(Oy[1] - Oy[2], 2))) && sqrt(pow(Ox[0] - Ox[1], 2) + (pow(Oy[0] - Oy[1], 2))) == sqrt(pow(Ox[1] - Ox[2], 2) + (pow(Oy[1] - Oy[2], 2)))) {
                    return true;
                }
                else {
                    return false;
                }
            }
        case 4:
            int b;
            float AB = ((Ox[0] - Ox[1]) * (Ox[0] - Ox[1]) + (Oy[0] - Oy[1]) * (Oy[0] - Oy[1]));
            float BC = ((Ox[1] - Ox[2]) * (Ox[1] - Ox[2]) + (Oy[1] - Oy[2]) * (Oy[1] - Oy[2]));
            float CD = ((Ox[2] - Ox[3]) * (Ox[2] - Ox[3]) + (Oy[2] - Oy[3]) * (Oy[2] - Oy[3]));
            float DA = ((Ox[3] - Ox[0]) * (Ox[3] - Ox[0]) + (Oy[3] - Oy[0]) * (Oy[3] - Oy[0]));
            float AC = ((Ox[0] - Ox[2]) * (Ox[0] - Ox[2]) + (Oy[0] - Oy[2]) * (Oy[0] - Oy[2]));
            float BD = ((Ox[1] - Ox[3]) * (Ox[1] - Ox[3]) + (Oy[1] - Oy[3]) * (Oy[1] - Oy[3]));
            std::cout << "1. Trapeze  2. Parallelogramr  3. Diamond  4. Rectangle  5. Square  6. Equilateral trapezoid  7. Deltoid " << std::endl;
            std::cin >> b;
            if (b == 1) {
                if (AB == CD && BC == DA) {
                    std::cout << "This is not Trapeze" << std::endl;
                    return false;
                }
                else
                    if (((Ox[0] - Ox[1]) * (Oy[2] - Oy[3])) == ((Oy[0] - Oy[1]) * (Ox[2] - Ox[3])) || ((Ox[0] - Oy[3]) * (Oy[1] - Oy[2])) == ((Oy[0] - Oy[3]) * (Ox[1] - Ox[2]))) {
                        std::cout << "Is Trapeze" << std::endl;
                        return true;
                    }
                    else {
                        std::cout << "This is not Trapeze" << std::endl;
                        return false;
                    }
            }
            if (b == 2) {
                if (AB == CD && BC == DA) {
                    if (AB == BC) {
                        std::cout << "This is not Parallelogramr" << std::endl;
                        return false;
                    }
                    else
                        if (AC == BD) {
                            std::cout << "This is not Parallelogramr" << std::endl;
                            return false;
                        }
                        else {
                            std::cout << "Is Parallelogramr" << std::endl;
                            return true;
                        }
                }
                else if ((AB == CD && BC != DA) || (AB != CD && BC != DA) || (AB != CD && BC == DA)) {
                    std::cout << "This is not Parallelogramr" << std::endl;
                    return false;
                }
            }
            if (b == 3) {
                if (AB == CD && BC == DA) {
                    if (AB == BC) {
                        if (AC == BD) {
                            std::cout << "This is not Diamond" << std::endl;
                            return false;
                        }
                        else {
                            std::cout << "Is Diamond" << std::endl;
                            return true;
                        }
                    }
                    else {
                        std::cout << "This is not Diamond" << std::endl;
                        return true;
                    }
                }
                else if ((AB == CD && BC != DA) || (AB != CD && BC != DA) || (AB != CD && BC == DA)) {
                    std::cout << "This is not Diamond" << std::endl;
                    return false;
                }
            }
            if (b == 4) {
                if (AB == CD && BC == DA) {
                    if (AB == BC) {
                        std::cout << "This is not Rectangle" << std::endl;
                        return false;
                    }
                    else
                        if (AC == BD) {
                            std::cout << "Is Rectangle" << std::endl;
                            return true;
                        }
                }
                else if (AB == CD && BC != DA || AB != CD && BC != DA || AB != CD && BC == DA) {
                    std::cout << "This is not Rectangle" << std::endl;
                    return false;
                }
            }
            if (b == 5) {
                if (AB == CD && BC == DA) {
                    if (AB == BC) {
                        if (AC == BD) {
                            std::cout << "Is Square" << std::endl;
                            return true;
                        }
                        else {
                            std::cout << "This is not Square" << std::endl;
                            return false;
                        }
                    }
                    else {
                        std::cout << "This is not Square" << std::endl;
                        return false;
                    }
                }
                else if (AB == CD && BC != DA || AB != CD && BC != DA || AB != CD && BC == DA) {
                    std::cout << "This is not Square" << std::endl;
                    return false;
                }
            }
            if (b == 6) {
                if (AB == CD && BC == DA) {
                    std::cout << "This is not Equilateral trapezoid" << std::endl;
                    return false;
                }
                else
                    if (((Ox[0] - Ox[1]) * (Oy[2] - Oy[3])) == ((Oy[0] - Oy[1]) * (Ox[2] - Ox[3]))) {
                        if (BC == DA) {
                            std::cout << "Is Equilateral trapezoid" << std::endl;
                            return true;
                        }
                        else {
                            std::cout << "This is not Equilateral trapezoid" << std::endl;
                            return false;
                        }
                    }
                    else if (((Ox[0] - Oy[3]) * (Oy[1] - Oy[2])) == ((Oy[0] - Oy[3]) * (Ox[1] - Ox[2]))) {
                        if (AB == CD) {
                            std::cout << "Is Equilateral trapezoid" << std::endl;
                            return true;
                        }
                        else {
                            std::cout << "This is not Equilateral trapezoid" << std::endl;
                            return false;
                        }
                    }
                    else {
                        std::cout << "This is not Equilateral trapezoid" << std::endl;
                        return false;
                    }

            }
            if (b == 7) {
                if (AB == BC && DA == CD && AB != DA && AB != CD && BC != DA && BC != CD) {
                    std::cout << "Is Deltoid" << std::endl;
                    return true;
                }
                else {
                    std::cout << "This is not Deltoid" << std::endl;
                    return false;
                }
            }
        }
    }
    else if (count_of_points > 4) {
        std::vector<int> leStr(count_of_points);
        std::vector<int> leStr1;
        if (Isconvex() == 1) {
            for (int i = 0; i < count_of_points; i++) {
                for (int j = i + 1; j < count_of_points; j++) {
                    if (i != count_of_points - 1) {
                        leStr.push_back(((Ox[i] - Ox[j]) * (Ox[i] - Ox[j]) + (Oy[i] - Oy[j]) * (Oy[i] - Oy[j])));
                    }
                    else if (i == count_of_points - 1) {
                        Ox[j] = Ox[0];
                        Oy[j] = Ox[0];
                        leStr.push_back(((Ox[j] - Ox[i]) * (Ox[j] - Ox[i]) + (Oy[j] - Oy[i]) * (Oy[j] - Oy[i])));
                    }
                }
            }
            float a = ((Ox[0] - Ox[1]) * (Ox[0] - Ox[1]) + (Oy[0] - Oy[1]) * (Oy[0] - Oy[1]));
            int counter = 0;
            for (int j = 0; j < leStr.size(); j++) {
                if (a == leStr[j]) {
                    counter++;
                }
            }
            if (counter == count_of_points) {
                std::cout << "This is regular polygon" << std::endl;
                return true;
            }
            else {
                std::cout << "This is not regular polygon" << std::endl;
                return false;
            }
        }
        else {
            std::cout << "This is not regular polygon" << std::endl;
            return false;
        }
    }
}
void Figure::Menu() {
    int number;
    std::cout << "1. Perimetr\t 2. Square\t 3. Checking Figure\t 4. Cheking_Convexity\t 5. Out" << std::endl;
    std::cin >> number;
    switch (number) {
    case 1:
        std::cout << Perimetr();
        std::cout << std::endl;
        Menu();
    case 2:
        std::cout << Square();
        std::cout << std::endl;
        Menu();
    case 3:
        std::cout << Checking_Figure();
        std::cout << std::endl;
        Menu();
    case 4:
        std::cout << Isconvex();
        std::cout << std::endl;
        Menu();
    case 5:
        Out();
        std::cout << std::endl;
        Menu();
    }
}