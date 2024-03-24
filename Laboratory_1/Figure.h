#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

class Figure {
private:
    std::vector<int>point_x;//Вектор для збереження координатів x
    std::vector<int>point_y;//Вектор для збереження координатів y
    int count_of_points;
public:
    Figure(int count_of_points;//Конструктор задання фігури
    Figure(int count_of_points, std::vector<int>point_x, std::vector<int>point_y);
    void Out();//Метод виводу фігури
    int Perimetr();//Метод виводу периметра
    double Square();//Метод виводу площу
    int Isconvex();//Метод перевірки на опуклість
    bool Checking_Figure();//Метод перевірки фігури 
    void Menu();//Меню для вибору методів
};
