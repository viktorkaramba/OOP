#include <vector>
#include <stdexcept>
#include <cmath>
#include "Point.h"

// Інтерфейс стратегії для обчислення площі фігури
class AreaCalculationStrategy {
public:
    virtual double CalculateArea(std::vector<Point>points) const = 0;
    virtual ~AreaCalculationStrategy() = default;
};

class BaseAreaCalculationStrategy : public AreaCalculationStrategy {
public:
    double CalculateArea(std::vector<Point>points) const override {
        double square = 0;
        double x_0 = points[0].Get_X();
        double y_0 = points[0].Get_Y();
        double additional_x = 0, additional_y = 0;
        for (int i = 1; i < points.size(); i++) {
            additional_x = points[i].Get_X();
            additional_y = points[i].Get_Y();
            square = square + (x_0 + additional_x) * (additional_y - y_0);
            x_0 = additional_x;
            y_0 = additional_y;
        }
        square = square + (points[0].Get_X() + additional_x) * (points[0].Get_Y() - additional_y);
        return abs(square) / 2;
    }
};

class GaussAreaCalculationStrategy : public AreaCalculationStrategy {
public:
    double CalculateArea(std::vector<Point>points) const override {
        int n = points.size();
        double area = 0.0;

        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            area += points[i].Get_X() * points[j].Get_Y() - points[j].Get_X() * points[i].Get_Y();
        }

        area *= 0.5;
        return std::abs(area);
    }
};

class HeronAreaCalculationStrategy : public AreaCalculationStrategy {
public:
    double CalculateArea(std::vector<Point>points) const override {
        double a = distance(points[0].Get_X(), points[0].Get_Y(), points[1].Get_X(), points[1].Get_Y());
        double b = distance(points[1].Get_X(), points[1].Get_Y(), points[2].Get_X(), points[2].Get_Y());
        double c = distance(points[2].Get_X(), points[2].Get_Y(), points[0].Get_X(), points[0].Get_Y());

        double s = 0.5 * (a + b + c);

        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

private:
    double distance(int x1, int y1, int x2, int y2) const {
        return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    }
};
