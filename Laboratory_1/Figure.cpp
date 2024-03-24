#include "Figure.h"

Figure::Figure(int count_of_points) {
    this->count_of_points = count_of_points;
    int x, y;
    for (int i = 0; i < count_of_points; i++) {
        std::cout << "Input coordinate (x ; y)" << std::endl;
        std::cin >> x;
        point_x.push_back(x);
        std::cin >> y;
        point_y.push_back(y);
    }
}

Figure::Figure(int count_of_points, std::vector<int>point_x, std::vector<int>point_y) {
    this->count_of_points = count_of_points;
    this->point_x = point_x;
    this->point_y = point_y;
}

void Figure::Out() {
    std::cout << std::endl;
    for (int i = 0; i < count_of_points; i++) {
        std::cout << "( " << point_x[i] << ";" << point_y[i] << " )" << std::endl;
    }
}

int Figure::Perimetr() {
    int perimetr = 0;
    for (int i = 0; i < count_of_points; i++) {
        int j = (i + 1) % count_of_points;
        perimetr += sqrt((point_x[i] - point_x[j]) * (point_x[i] - point_x[j]) + 
            (point_y[i] - point_y[j]) * (point_y[i] - point_y[j]));
    }
    return perimetr;
}

double Figure::Square() {
    double square = 0;
    double x_0 = point_x[0];
    double y_0 = point_y[0];
    double additional_x = 0, additional_y = 0;
    for (int i = 1; i < count_of_points; i++) {
        additional_x = point_x[i];
        additional_y = point_y[i];
        square = square + (x_0 + additional_x) * (additional_y - y_0);
        x_0 = additional_x;
        y_0 = additional_y;
    }
    square = square + (point_x[0] + additional_x) * (point_y[0] - additional_y);
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
        z = (point_x[j] - point_x[i]) * (point_y[k] - point_y[j]);
        z -= (point_y[j] - point_y[i]) * (point_x[k] - point_x[j]);
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
        switch (count_of_points){
        case 3:
            std::cout << "1. Isosceles\t  2. Rectangular\t  3. Equilateral\t" << std::endl;
            int item;
            std::cin >> item;
            switch (item) {
            case 1:
                if (sqrt(pow(point_x[0] - point_x[1], 2) + (pow(point_y[0] - point_y[1], 2))) == sqrt(pow(point_x[0] - point_x[2], 2) + (pow(point_y[0] - point_y[2], 2)))
                    || sqrt(pow(point_x[0] - point_x[1], 2) + (pow(point_y[0] - point_y[1], 2))) == sqrt(pow(point_x[1] - point_x[2], 2) + (pow(point_y[1] - point_y[2], 2)))
                    || sqrt(pow(point_x[0] - point_x[2], 2) + (pow(point_y[0] - point_y[2], 2))) == sqrt(pow(point_x[1] - point_x[2], 2) + (pow(point_y[1] - point_y[2], 2))))
                {
                    return true;
                }
                else {
                    return false;
                }
            case 2:
                if (sqrt(pow(point_x[0] - point_x[1], 2) + (pow(point_y[0] - point_y[1], 2))) + sqrt(pow(point_x[0] - point_x[2], 2) + (pow(point_y[0] - point_y[2], 2))) > sqrt(pow(point_x[1] - point_x[2], 2) + (pow(point_y[1] - point_y[2], 2)))) {
                    if (pow(sqrt(pow(point_x[1] - point_x[2], 2) + (pow(point_y[1] - point_y[2], 2))), 2) == pow(sqrt(pow(point_x[0] - point_x[1], 2) + (pow(point_y[0] - point_y[1], 2))), 2) + pow(sqrt(pow(point_x[0] - point_y[2], 2) + (pow(point_y[0] - point_y[2], 2))), 2)) {
                        return true;
                    }
                }
                if (sqrt(pow(point_x[0] - point_x[1], 2) + (pow(point_y[0] - point_y[1], 2))) + sqrt(pow(point_x[1] - point_x[2], 2) + (pow(point_y[1] - point_y[2], 2))) > sqrt(pow(point_x[0] - point_x[2], 2) + (pow(point_y[0] - point_y[2], 2)))) {
                    if (pow(sqrt(pow(point_x[0] - point_x[2], 2) + (pow(point_y[0] - point_y[2], 2))), 2) == pow(sqrt(pow(point_x[0] - point_x[1], 2) + (pow(point_y[0] - point_y[1], 2))), 2) + pow(sqrt(pow(point_x[1] - point_x[2], 2) + (pow(point_y[1] - point_y[2], 2))), 2)) {
                        return true;
                    }
                }
                if (sqrt(pow(point_x[0] - point_x[2], 2) + (pow(point_y[0] - point_y[2], 2))) + sqrt(pow(point_x[1] - point_x[2], 2) + (pow(point_y[1] - point_y[2], 2))) > sqrt(pow(point_x[0] - point_x[1], 2) + (pow(point_y[0] - point_y[1], 2)))) {
                    if (pow(sqrt(pow(point_x[0] - point_x[1], 2) + (pow(point_y[0] - point_y[1], 2))), 2) == pow(sqrt(pow(point_x[0] - point_x[2], 2) + (pow(point_y[0] - point_y[2], 2))), 2) + pow(sqrt(pow(point_x[1] - point_x[2], 2) + (pow(point_y[1] - point_y[2], 2))), 2)) {
                        return true;
                    }
                }
                else {
                    return false;
                }
            case 3:
                if (sqrt(pow(point_x[0] - point_x[1], 2) + (pow(point_y[0] - point_y[1], 2))) == sqrt(pow(point_x[0] - point_x[2], 2) + (pow(point_y[0] - point_y[2], 2))) && sqrt(pow(point_x[0] - point_x[2], 2) + (pow(point_y[0] - point_y[2], 2))) == sqrt(pow(point_x[1] - point_x[2], 2) + (pow(point_y[1] - point_y[2], 2))) && sqrt(pow(point_x[0] - point_x[1], 2) + (pow(point_y[0] - point_y[1], 2))) == sqrt(pow(point_x[1] - point_x[2], 2) + (pow(point_y[1] - point_y[2], 2)))) {
                    return true;
                }
                else {
                    return false;
                }
            }
        case 4:
            int b;
            float AB = ((point_x[0] - point_x[1]) * (point_x[0] - point_x[1]) + (point_y[0] - point_y[1]) * (point_y[0] - point_y[1]));
            float BC = ((point_x[1] - point_x[2]) * (point_x[1] - point_x[2]) + (point_y[1] - point_y[2]) * (point_y[1] - point_y[2]));
            float CD = ((point_x[2] - point_x[3]) * (point_x[2] - point_x[3]) + (point_y[2] - point_y[3]) * (point_y[2] - point_y[3]));
            float DA = ((point_x[3] - point_x[0]) * (point_x[3] - point_x[0]) + (point_y[3] - point_y[0]) * (point_y[3] - point_y[0]));
            float AC = ((point_x[0] - point_x[2]) * (point_x[0] - point_x[2]) + (point_y[0] - point_y[2]) * (point_y[0] - point_y[2]));
            float BD = ((point_x[1] - point_x[3]) * (point_x[1] - point_x[3]) + (point_y[1] - point_y[3]) * (point_y[1] - point_y[3]));
            std::cout << "1. Trapeze  2. Parallelogramr  3. Diamond  4. Rectangle  5. Square  6. Equilateral trapezoid  7. Deltoid " << std::endl;
            std::cin >> b;
            if (b == 1) {
                if (AB == CD && BC == DA) {
                    std::cout << "This is not Trapeze" << std::endl;
                    return false;
                }
                else
                    if (((point_x[0] - point_x[1]) * (point_y[2] - point_y[3])) == ((point_y[0] - point_y[1]) * (point_x[2] - point_x[3])) || ((point_x[0] - point_y[3]) * (point_y[1] - point_y[2])) == ((point_y[0] - point_y[3]) * (point_x[1] - point_x[2]))) {
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
                    if (((point_x[0] - point_x[1]) * (point_y[2] - point_y[3])) == ((point_y[0] - point_y[1]) * (point_x[2] - point_x[3]))) {
                        if (BC == DA) {
                            std::cout << "Is Equilateral trapezoid" << std::endl;
                            return true;
                        }
                        else {
                            std::cout << "This is not Equilateral trapezoid" << std::endl;
                            return false;
                        }
                    }
                    else if (((point_x[0] - point_y[3]) * (point_y[1] - point_y[2])) == ((point_y[0] - point_y[3]) * (point_x[1] - point_x[2]))) {
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
        if (Isconvex() == 1) {
            for (int i = 0; i < count_of_points; i++) {
                for (int j = i + 1; j < count_of_points; j++) {
                    if (i != count_of_points - 1) {
                        leStr.push_back(((point_x[i] - point_x[j]) * (point_x[i] - point_x[j]) + (point_y[i] - point_y[j]) * (point_y[i] - point_y[j])));
                    }
                    else if (i == count_of_points - 1) {
                        point_x[j] = point_x[0];
                        point_y[j] = point_x[0];
                        leStr.push_back(((point_x[j] - point_x[i]) * (point_x[j] - point_x[i]) + (point_y[j] - point_y[i]) * (point_y[j] - point_y[i])));
                    }
                }
            }
            float a = ((point_x[0] - point_x[1]) * (point_x[0] - point_x[1]) + (point_y[0] - point_y[1]) * (point_y[0] - point_y[1]));
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
    int item;
    std::cout << "1. Perimetr\t 2. Square\t 3. Checking Figure\t 4. Cheking_Convexity\t 5. Out" << std::endl;
    std::cin >> item;
    switch (item) {
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