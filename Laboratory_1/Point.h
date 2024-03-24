#pragma once
class Point
{
private:
	int x;
	int y;
public:
	Point(int x, int y) { this->x = x; this->y = y;}
	int Get_X();
	int Get_Y();
	void Set_X(int x);
	void Set_Y(int y);
};

