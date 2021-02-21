#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

class Figure {
private:
    std::vector<double>Ox;//������ ��� ���������� ���������� x
    std::vector<double>Oy;//������ ��� ���������� ���������� y
    int count_of_points;
public:
    Figure(int Count_of_Points);//����������� ������� ������
    Figure(int Count_of_Points, std::vector<double>OX, std::vector<double>OY);
    void Out();//����� ������ ������
    double Perimetr();//����� ������ ���������
    double Square();//����� ������ �����
    int Isconvex();//����� �������� �� ��������
    bool Checking_Figure();//����� �������� ������ 
    void Menu();//���� ��� ������ ������
};
