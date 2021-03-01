#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

class Figure {
private:
    /*!
    Vector for coordinates Ox
    */
    std::vector<double>Ox;
    /*!
    Vector for coordinates Oy
    */
    std::vector<double>Oy;
    /*!
    Count of points
    */
    int count_of_points;
public:
    Figure(int Count_of_Points);
    Figure(int Count_of_Points, std::vector<double>OX, std::vector<double>OY);
    void Out();
    double Perimetr();
    double Square();
    int Isconvex();
    bool Checking_Figure();
    void Menu();
};
