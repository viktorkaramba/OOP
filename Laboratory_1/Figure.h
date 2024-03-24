#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "Point.h"

class Figure {
private:
    std::vector<Point>points;//Вектор для збереження координатів
    int count_of_points;
public:
    Figure(int count_of_points);//Конструктор задання фігури
    Figure(int count_of_points, std::vector<Point>points);
    void Out();//Метод виводу фігури
    int Perimetr();//Метод виводу периметра
    double Square();//Метод виводу площу
    int Isconvex();//Метод перевірки на опуклість
    bool Checking_Figure();//Метод перевірки фігури 
    void Menu();//Меню для вибору методів
};
