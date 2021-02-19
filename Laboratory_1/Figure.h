#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
class Figure {
private:
    std::vector<int>Ox;//������ ��� ���������� ���������� x
    std::vector<int>Oy;//������ ��� ���������� ���������� y
    int count_of_points;
public:
    Figure(int Count_of_Points);//����������� ������� ������
    Figure(int Count_of_Points, std::vector<int>OX, std::vector<int>OY);
    void Out();//����� ������ ������
    int Perimetr();//����� ������ ���������
    double Square();//����� ������ �����
    int Isconvex();//����� �������� �� ��������
    bool Checking_Figure();//����� �������� ������ 
    void Menu();//���� ��� ������ ������
};
