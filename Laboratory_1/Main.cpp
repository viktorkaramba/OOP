#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Point.h"
#include "Spare Matrix_Figure.h"


TEST_CASE("Test 1") {
	std::vector<Point>points;
	points.push_back(*new Point(0, 0));
	points.push_back(*new Point(0, 2));
	points.push_back(*new Point(5, 0));
	Figure B(3, points);
	CHECK(B.Perimetr() == 12);
	CHECK(B.Square() == 5);
	CHECK(B.Isconvex() == 1);
}
TEST_CASE("Test 2") {
	std::vector<Point>points;
	points.push_back(*new Point(2, 4));
	points.push_back(*new Point(5, 8));
	points.push_back(*new Point(3, 5));
	points.push_back(*new Point(7, 2));
	Figure B(4, points);
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
	Figure B(5, points);
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
	Figure A(3, pointsA);
	Figure B(4, pointsB);
	Figure C(5, pointsC);
	Matrix M1(2, 3, { A,B,C }, { 0,0,1 }, { 0, 1, 0 });
	std::vector<double> a = { 0,1 };
	std::vector<double> b = { 4 ,18,-1 };
	CHECK(M1.Value_By_Condition() == 4);
	CHECK(M1.Value_Search(4) == a);
	CHECK(M1.Index_Search(0, 1) == b);
}