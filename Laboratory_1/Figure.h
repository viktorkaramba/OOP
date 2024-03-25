#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "Point.h"
#include "AreaStrategy.h"

class Figure {
private:
    std::vector<Point>points;//������ ��� ���������� ����������
    int count_of_points;
    AreaCalculationStrategy* areaStrategy;
public:
    Figure(int count_of_points, AreaCalculationStrategy* areaStrategy);//����������� ������� ������
    Figure(int count_of_points, std::vector<Point>points,AreaCalculationStrategy* areaStrategy);
    void Out();//����� ������ ������
    int Perimetr();//����� ������ ���������
    double Square();//����� ������ �����
    int Isconvex();//����� �������� �� ��������
    bool Checking_Figure();//����� �������� ������ 
    void Menu();//���� ��� ������ ������
};
