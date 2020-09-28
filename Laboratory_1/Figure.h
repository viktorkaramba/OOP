#pragma once

#include <iostream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

    class Figure {
    private:
        std::vector<int>Ox;
        std::vector<int>Oy;
        int n;
    public:
        Figure(int nn);
        void Out();
        double Perimetr();
        double Square();
        int Isconvex();
        bool Checking_Figure();
        void Menu();
    };
   