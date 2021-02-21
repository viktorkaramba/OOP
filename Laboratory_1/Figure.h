#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

class Figure {
private:
    std::vector<double>Ox;//Вектор для збереження координатів x
    std::vector<double>Oy;//Вектор для збереження координатів y
    int count_of_points;
public:
    Figure(int Count_of_Points);//Конструктор задання фігури
    Figure(int Count_of_Points, std::vector<double>OX, std::vector<double>OY);
    void Out();//Метод виводу фігури
    double Perimetr();//Метод виводу периметра
    double Square();//Метод виводу площу
    int Isconvex();//Метод перевірки на опуклість
    bool Checking_Figure();//Метод перевірки фігури 
    void Menu();//Меню для вибору методів
};
