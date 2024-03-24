#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "Point.h"

class Figure {
private:
    std::vector<Point>points;//������ ��� ���������� ����������
    int count_of_points;
public:
    Figure(int count_of_points);//����������� ������� ������
    Figure(int count_of_points, std::vector<Point>points);
    void Out();//����� ������ ������
    int Perimetr();//����� ������ ���������
    double Square();//����� ������ �����
    int Isconvex();//����� �������� �� ��������
    bool Checking_Figure();//����� �������� ������ 
    void Menu();//���� ��� ������ ������
};
