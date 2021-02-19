#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
class Figure {
private:
    std::vector<int>Ox;//Вектор для збереження координатів x
    std::vector<int>Oy;//Вектор для збереження координатів y
    int count_of_points;
public:
    Figure(int Count_of_Points);//Конструктор задання фігури
    Figure(int Count_of_Points, std::vector<int>OX, std::vector<int>OY);
    void Out();//Метод виводу фігури
    int Perimetr();//Метод виводу периметра
    double Square();//Метод виводу площу
    int Isconvex();//Метод перевірки на опуклість
    bool Checking_Figure();//Метод перевірки фігури 
    void Menu();//Меню для вибору методів
};
