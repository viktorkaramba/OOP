#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

class Figure {
private:
    std::vector<int>point_x;//������ ��� ���������� ���������� x
    std::vector<int>point_y;//������ ��� ���������� ���������� y
    int count_of_points;
public:
    Figure(int count_of_points;//����������� ������� ������
    Figure(int count_of_points, std::vector<int>point_x, std::vector<int>point_y);
    void Out();//����� ������ ������
    int Perimetr();//����� ������ ���������
    double Square();//����� ������ �����
    int Isconvex();//����� �������� �� ��������
    bool Checking_Figure();//����� �������� ������ 
    void Menu();//���� ��� ������ ������
};
