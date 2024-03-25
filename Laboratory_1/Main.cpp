#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Point.h"
#include "Spare Matrix_Figure.h"

TEST_CASE("Test 1") {
	std::vector<Point>points;
	points.push_back(*new Point(0, 0));
	points.push_back(*new Point(0, 2));
	points.push_back(*new Point(5, 0));
	Figure B(3, points, new HeronAreaCalculationStrategy());
	std::cout << B.Square();
	CHECK(B.Perimetr() == 12);
	CHECK(int(B.Square()) == 5);
	CHECK(B.Isconvex() == 1);
}
TEST_CASE("Test 2") {
	std::vector<Point>points;
	points.push_back(*new Point(2, 4));
	points.push_back(*new Point(5, 8));
	points.push_back(*new Point(3, 5));
	points.push_back(*new Point(7, 2));
	Figure B(4, points, new BaseAreaCalculationStrategy());
	CHECK(B.Perimetr() == 18);
	CHECK(B.Square() == 4);
	CHECK(B.Isconvex() == -1);
}
TEST_CASE("Test 3") {
	std::vector<Point>points;
	points.push_back(*new Point(1, 2));
	points.push_back(*new Point(-3, -2));
	points.push_back(*new Point(3, 4));
	points.push_back(*new Point(-2, 0));
	points.push_back(*new Point(-1, 3));
	Figure B(5, points, new BaseAreaCalculationStrategy());
	CHECK(B.Perimetr() == 24);
	CHECK(B.Square() == 2.5);
	CHECK(B.Isconvex() == -1);
}
TEST_CASE("Test 4") {
	std::vector<Point>pointsA;
	pointsA.push_back(*new Point(0, 0));
	pointsA.push_back(*new Point(0, 2));
	pointsA.push_back(*new Point(5, 0));
	std::vector<Point>pointsB;
	pointsB.push_back(*new Point(2, 4));
	pointsB.push_back(*new Point(5, 8));
	pointsB.push_back(*new Point(3, 5));
	pointsB.push_back(*new Point(7, 2));
	std::vector<Point>pointsC;
	pointsC.push_back(*new Point(1, 2));
	pointsC.push_back(*new Point(-3, -2));
	pointsC.push_back(*new Point(3, 4));
	pointsC.push_back(*new Point(-2, 0));
	pointsC.push_back(*new Point(-1, 3));
	Figure A(3, pointsA, new BaseAreaCalculationStrategy());
	Figure B(4, pointsB, new BaseAreaCalculationStrategy());
	Figure C(5, pointsC, new BaseAreaCalculationStrategy());
	Matrix M1(2, 3, { A,B,C }, { 0,0,1 }, { 0, 1, 0 });
	std::vector<double> a = { 0,1 };
	std::vector<double> b = { 4 ,18,-1 };
	CHECK(M1.Value_By_Condition() == 4);
	CHECK(M1.Value_Search(4) == a);
	CHECK(M1.Index_Search(0, 1) == b);
}
TEST_CASE("Test 5(new) Check SumMatrix ") {
	std::vector<Point>pointsA;
	pointsA.push_back(*new Point(0, 0));
	pointsA.push_back(*new Point(0, 2));
	pointsA.push_back(*new Point(5, 0));
	std::vector<Point>pointsB;
	pointsB.push_back(*new Point(1, 1));
	pointsB.push_back(*new Point(2, 3));
	pointsB.push_back(*new Point(4, 1));
	pointsB.push_back(*new Point(5, 3));
	std::vector<Point>pointsC;
	pointsC.push_back(*new Point(1, 2));
	pointsC.push_back(*new Point(-3, -2));
	pointsC.push_back(*new Point(3, 4));
	pointsC.push_back(*new Point(-2, 0));
	pointsC.push_back(*new Point(-1, 3));
	Figure A(3, pointsA, new BaseAreaCalculationStrategy());
	Figure B(4,pointsB, new BaseAreaCalculationStrategy());
	Figure C(5, pointsC, new BaseAreaCalculationStrategy());
	Matrix M1(2, 3, { A,C,B }, { 0,1,1 }, { 0, 1, 2 });
	Matrix M2(2, 3, { A,B,C }, { 0,1,1 }, { 0, 1, 2 });
	Matrix M3;
	M3.SumMatrix(M1, M2);
	CHECK(M3.Get_Figure_Matrix()[0]->square == 10);
	CHECK(M3.Get_Figure_Matrix()[0]->column_index == 0);
}
TEST_CASE("Test 6(new) Check SumMatrix ") {
	std::vector<Point>pointsA;
	pointsA.push_back(*new Point(1, 1));
	pointsA.push_back(*new Point(3, 5));
	pointsA.push_back(*new Point(5, 2));
	std::vector<Point>pointsB;
	pointsB.push_back(*new Point(1, 1));
	pointsB.push_back(*new Point(2, 3));
	pointsB.push_back(*new Point(4, 1));
	pointsB.push_back(*new Point(5, 3));
	std::vector<Point>pointsC;
	pointsC.push_back(*new Point(1, 2));
	pointsC.push_back(*new Point(-3, -2));
	pointsC.push_back(*new Point(3, 4));
	pointsC.push_back(*new Point(-2, 0));
	pointsC.push_back(*new Point(-1, 3));
	Figure A(3, pointsA, new BaseAreaCalculationStrategy());
	Figure B(4, pointsB, new BaseAreaCalculationStrategy());
	Figure C(5, pointsC, new BaseAreaCalculationStrategy());
	Matrix M1(2, 3, { A,C,B }, { 0,1,1 }, { 0, 0, 1 });
	Matrix M2(2, 3, { A,B,C }, { 1,1,1 }, { 0, 1, 2 });
	Matrix M3;
	M3.SumMatrix(M1, M2);
	CHECK(M3.Get_Figure_Matrix()[0]->square == 14);
}
TEST_CASE("Test 8(new) Check MultiplyVector") {
	std::vector<Point>pointsA;
	pointsA.push_back(*new Point(0, 0));
	pointsA.push_back(*new Point(0, 2));
	pointsA.push_back(*new Point(5, 0));
	std::vector<Point>pointsB;
	pointsB.push_back(*new Point(1, 1));
	pointsB.push_back(*new Point(2, 3));
	pointsB.push_back(*new Point(4, 1));
	pointsB.push_back(*new Point(5, 3));
	std::vector<Point>pointsC;
	pointsC.push_back(*new Point(1, 2));
	pointsC.push_back(*new Point(-3, -2));
	pointsC.push_back(*new Point(3, 4));
	pointsC.push_back(*new Point(-2, 0));
	pointsC.push_back(*new Point(-1, 3));
	Figure A(3, pointsA, new BaseAreaCalculationStrategy());
	Figure B(4, pointsB, new BaseAreaCalculationStrategy());
	Figure C(5, pointsC, new BaseAreaCalculationStrategy());
	Matrix M1(2, 3, { A,C,B }, { 0,1,1 }, { 0, 1, 2 });
	Matrix M3;
	M3.MultiplyVector(M1, { 1,2,3 });
	CHECK(M3.Get_Figure_Matrix()[0]->square == 5);
	CHECK(M3.Get_Figure_Matrix()[1]->square == 0);
}
TEST_CASE("Test 9(new) Check MultiplyVector") {
	std::vector<Point>pointsA;
	pointsA.push_back(*new Point(1, 1));
	pointsA.push_back(*new Point(3, 5));
	pointsA.push_back(*new Point(5, 2));
	std::vector<Point>pointsB;
	pointsB.push_back(*new Point(1, 1));
	pointsB.push_back(*new Point(2, 3));
	pointsB.push_back(*new Point(4, 1));
	pointsB.push_back(*new Point(5, 3));
	std::vector<Point>pointsC;
	pointsC.push_back(*new Point(1, 2));
	pointsC.push_back(*new Point(-3, -2));
	pointsC.push_back(*new Point(3, 4));
	pointsC.push_back(*new Point(-2, 0));
	pointsC.push_back(*new Point(-1, 3));
	Figure A(3, pointsA, new BaseAreaCalculationStrategy());
	Figure B(4, pointsB, new BaseAreaCalculationStrategy());
	Figure C(5, pointsC, new BaseAreaCalculationStrategy());
	Matrix M1(2, 3, { A,C,B }, { 1,1,1 }, { 0, 1, 2 });
	Matrix M3;
	std::vector<double> a = { 12,25 };
	M3.MultiplyVector(M1, { 3, 2, 1 });
	CHECK(M3.Get_Figure_Matrix()[0]->square == 21);
	CHECK((int)M3.Get_Figure_Matrix()[1]->square == 5);
}