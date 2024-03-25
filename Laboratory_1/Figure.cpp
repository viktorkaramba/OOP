#include "Figure.h"

Figure::Figure(int count_of_points, AreaCalculationStrategy* areaStrategy) {
    this->count_of_points = count_of_points;
    this->areaStrategy = areaStrategy;
    int x, y;
    for (int i = 0; i < count_of_points; i++) {
        std::cout << "Input coordinate (x ; y)" << std::endl;
        std::cin >> x;
        std::cin >> y;
        Point point = *new Point(x, y);
        points.push_back(point);
    }
}

Figure::Figure(int count_of_points, std::vector<Point>points, AreaCalculationStrategy* areaStrategy) {
    this->count_of_points = count_of_points;
    this->points = points;
    this->areaStrategy = areaStrategy;
}

void Figure::Out() {
    std::cout << std::endl;
    for (int i = 0; i < count_of_points; i++) {
        std::cout << "( " << points[i].Get_X() << ";" << points[i].Get_Y() << " )" << std::endl;
    }
}

int Figure::Perimetr() {
    int perimetr = 0;
    for (int i = 0; i < count_of_points; i++) {
        int j = (i + 1) % count_of_points;
        perimetr += sqrt((points[i].Get_X() - points[j].Get_X()) * (points[i].Get_X() - points[j].Get_X()) +
            (points[i].Get_Y() - points[j].Get_Y()) * (points[i].Get_Y() - points[j].Get_Y()));
    }
    return perimetr;
}

double Figure::Square() {
    return areaStrategy->CalculateArea(points);
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
        z = (points[j].Get_X() - points[i].Get_X()) * (points[k].Get_X() - points[j].Get_Y());
        z -= (points[j].Get_Y() - points[i].Get_Y()) * (points[k].Get_X() - points[j].Get_X());
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
                if (sqrt(pow(points[0].Get_X() - points[1].Get_X(), 2) + (pow(points[0].Get_Y() - points[1].Get_Y(), 2))) == sqrt(pow(points[0].Get_X() - points[2].Get_X(), 2) + (pow(points[0].Get_Y() - points[2].Get_Y(), 2)))
                    || sqrt(pow(points[0].Get_X() - points[1].Get_X(), 2) + (pow(points[0].Get_Y() - points[1].Get_Y(), 2))) == sqrt(pow(points[1].Get_X() - points[2].Get_X(), 2) + (pow(points[1].Get_Y() - points[2].Get_Y(), 2)))
                    || sqrt(pow(points[0].Get_X() - points[2].Get_X(), 2) + (pow(points[0].Get_Y() - points[2].Get_Y(), 2))) == sqrt(pow(points[1].Get_X() - points[2].Get_X(), 2) + (pow(points[1].Get_Y() - points[2].Get_Y(), 2))))
                {
                    return true;
                }
                else {
                    return false;
                }
            case 2:
                if (sqrt(pow(points[0].Get_X() - points[1].Get_X(), 2) + (pow(points[0].Get_Y() - points[1].Get_Y(), 2))) + sqrt(pow(points[0].Get_X() - points[2].Get_X(), 2) + (pow(points[0].Get_Y() - points[2].Get_Y(), 2))) > sqrt(pow(points[1].Get_X() - points[2].Get_X(), 2) + (pow(points[1].Get_Y() - points[2].Get_Y(), 2)))) {
                    if (pow(sqrt(pow(points[1].Get_X() - points[2].Get_X(), 2) + (pow(points[1].Get_Y() - points[2].Get_Y(), 2))), 2) == pow(sqrt(pow(points[0].Get_X() - points[1].Get_X(), 2) + (pow(points[0].Get_Y() - points[1].Get_Y(), 2))), 2) + pow(sqrt(pow(points[0].Get_X() - points[2].Get_Y(), 2) + (pow(points[0].Get_Y() - points[2].Get_Y(), 2))), 2)) {
                        return true;
                    }
                }
                if (sqrt(pow(points[0].Get_X() - points[1].Get_X(), 2) + (pow(points[0].Get_Y() - points[1].Get_Y(), 2))) + sqrt(pow(points[1].Get_X() - points[2].Get_X(), 2) + (pow(points[1].Get_Y() - points[2].Get_Y(), 2))) > sqrt(pow(points[0].Get_X() - points[2].Get_X(), 2) + (pow(points[0].Get_Y() - points[2].Get_Y(), 2)))) {
                    if (pow(sqrt(pow(points[0].Get_X() - points[2].Get_X(), 2) + (pow(points[0].Get_Y() - points[2].Get_Y(), 2))), 2) == pow(sqrt(pow(points[0].Get_X() - points[1].Get_X(), 2) + (pow(points[0].Get_Y() - points[1].Get_Y(), 2))), 2) + pow(sqrt(pow(points[1].Get_X() - points[2].Get_X(), 2) + (pow(points[1].Get_Y() - points[2].Get_Y(), 2))), 2)) {
                        return true;
                    }
                }
                if (sqrt(pow(points[0].Get_X() - points[2].Get_X(), 2) + (pow(points[0].Get_Y() - points[2].Get_Y(), 2))) + sqrt(pow(points[1].Get_X() - points[2].Get_X(), 2) + (pow(points[1].Get_Y() - points[2].Get_Y(), 2))) > sqrt(pow(points[0].Get_X() - points[1].Get_X(), 2) + (pow(points[0].Get_Y() - points[1].Get_Y(), 2)))) {
                    if (pow(sqrt(pow(points[0].Get_X() - points[1].Get_X(), 2) + (pow(points[0].Get_Y() - points[1].Get_Y(), 2))), 2) == pow(sqrt(pow(points[0].Get_X() - points[2].Get_X(), 2) + (pow(points[0].Get_Y() - points[2].Get_Y(), 2))), 2) + pow(sqrt(pow(points[1].Get_X() - points[2].Get_X(), 2) + (pow(points[1].Get_Y() - points[2].Get_Y(), 2))), 2)) {
                        return true;
                    }
                }
                else {
                    return false;
                }
            case 3:
                if (sqrt(pow(points[0].Get_X() - points[1].Get_X(), 2) + (pow(points[0].Get_Y() - points[1].Get_Y(), 2))) == sqrt(pow(points[0].Get_X() - points[2].Get_X(), 2) + (pow(points[0].Get_Y() - points[2].Get_Y(), 2))) && sqrt(pow(points[0].Get_X() - points[2].Get_X(), 2) + (pow(points[0].Get_Y() - points[2].Get_Y(), 2))) == sqrt(pow(points[1].Get_X() - points[2].Get_X(), 2) + (pow(points[1].Get_Y() - points[2].Get_Y(), 2))) && sqrt(pow(points[0].Get_X() - points[1].Get_X(), 2) + (pow(points[0].Get_Y() - points[1].Get_Y(), 2))) == sqrt(pow(points[1].Get_X() - points[2].Get_X(), 2) + (pow(points[1].Get_Y() - points[2].Get_Y(), 2)))) {
                    return true;
                }
                else {
                    return false;
                }
            }
        case 4:
            int b;
            float AB = ((points[0].Get_X() - points[1].Get_X()) * (points[0].Get_X() - points[1].Get_X()) + (points[0].Get_Y() - points[1].Get_Y()) * (points[0].Get_Y() - points[1].Get_Y()));
            float BC = ((points[1].Get_X() - points[2].Get_X()) * (points[1].Get_X() - points[2].Get_X()) + (points[1].Get_Y() - points[2].Get_Y()) * (points[1].Get_Y() - points[2].Get_Y()));
            float CD = ((points[2].Get_X() - points[3].Get_X()) * (points[2].Get_X() - points[3].Get_X()) + (points[2].Get_Y() - points[3].Get_Y()) * (points[2].Get_Y() - points[3].Get_Y()));
            float DA = ((points[3].Get_X() - points[0].Get_X()) * (points[3].Get_X() - points[0].Get_X()) + (points[3].Get_Y() - points[0].Get_Y()) * (points[3].Get_Y() - points[0].Get_Y()));
            float AC = ((points[0].Get_X() - points[2].Get_X()) * (points[0].Get_X() - points[2].Get_X()) + (points[0].Get_Y() - points[2].Get_Y()) * (points[0].Get_Y() - points[2].Get_Y()));
            float BD = ((points[1].Get_X() - points[3].Get_X()) * (points[1].Get_X() - points[3].Get_X()) + (points[1].Get_Y() - points[3].Get_Y()) * (points[1].Get_Y() - points[3].Get_Y()));
            std::cout << "1. Trapeze  2. Parallelogramr  3. Diamond  4. Rectangle  5. Square  6. Equilateral trapezoid  7. Deltoid " << std::endl;
            std::cin >> b;
            if (b == 1) {
                if (AB == CD && BC == DA) {
                    std::cout << "This is not Trapeze" << std::endl;
                    return false;
                }
                else
                    if (((points[0].Get_X() - points[1].Get_X()) * (points[2].Get_Y() - points[3].Get_Y())) == ((points[0].Get_Y() - points[1].Get_Y()) * (points[2].Get_X() - points[3].Get_X())) || ((points[0].Get_X() - points[3].Get_Y()) * (points[1].Get_Y() - points[2].Get_Y())) == ((points[0].Get_Y() - points[3].Get_Y()) * (points[1].Get_X() - points[2].Get_X()))) {
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
                    if (((points[0].Get_X() - points[1].Get_X()) * (points[2].Get_Y() - points[3].Get_Y())) == ((points[0].Get_Y() - points[1].Get_Y()) * (points[2].Get_X() - points[3].Get_X()))) {
                        if (BC == DA) {
                            std::cout << "Is Equilateral trapezoid" << std::endl;
                            return true;
                        }
                        else {
                            std::cout << "This is not Equilateral trapezoid" << std::endl;
                            return false;
                        }
                    }
                    else if (((points[0].Get_X() - points[3].Get_Y()) * (points[1].Get_Y() - points[2].Get_Y())) == ((points[0].Get_Y() - points[3].Get_Y()) * (points[1].Get_X() - points[2].Get_X()))) {
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
                        leStr.push_back(((points[i].Get_X() - points[j].Get_X()) * (points[i].Get_X() - points[j].Get_X()) + (points[i].Get_Y() - points[j].Get_Y()) * (points[i].Get_Y() - points[j].Get_Y())));
                    }
                    else if (i == count_of_points - 1) {
                        points[j].Set_X(points[0].Get_X());
                        points[j].Set_Y(points[0].Get_X());
                        leStr.push_back(((points[j].Get_X() - points[i].Get_X()) * (points[j].Get_X() - points[i].Get_X()) + (points[j].Get_Y() - points[i].Get_Y()) * (points[j].Get_Y() - points[i].Get_Y())));
                    }
                }
            }
            float a = ((points[0].Get_X() - points[1].Get_X()) * (points[0].Get_X() - points[1].Get_X()) + (points[0].Get_Y() - points[1].Get_Y()) * (points[0].Get_Y() - points[1].Get_Y()));
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