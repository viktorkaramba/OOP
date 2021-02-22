#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Spare Matrix_Figure.h"

TEST_CASE("Test 1") {
	Figure B(3, { 0, 0, 5 }, { 0, 2, 0 });
	CHECK((int)B.Perimetr() == 12);
	CHECK((int)B.Square() == 5);
	CHECK(B.Isconvex() == 1);
}

TEST_CASE("Test 2") {
	Figure B(4, { 2, 5, 3, 7 }, { 4, 8, 5, 2 });
	CHECK((int)B.Perimetr() == 18);
	CHECK((int)B.Square() == 4);
	CHECK(B.Isconvex() == -1);
}

TEST_CASE("Test 3") {
	Figure B(5, { 1, -3, 3,-2,-1 }, { 2, -2, 4,0, 3 });
	CHECK((int)B.Perimetr() == 25);
	CHECK((int)B.Square() == 2);
	CHECK(B.Isconvex() == -1);
}

TEST_CASE("Test 4") {
	Figure A(3, { 0, 0, 5 }, { 0, 2, 0 });
	Figure B(4, { 2, 5, 3, 7 }, { 4, 8, 5, 2 });
	Figure C(5, { 1, -3, 3,-2,-1 }, { 2, -2, 4,0, 3 });
	Matrix M1(2, 3, { A,B,C }, { 0,0,1 }, { 0, 1, 0 });
	std::vector<int> a = { 0,1 };
	std::vector<int> b = {4 ,18,-1 };
	CHECK(M1.Value_By_Condition() == 4);
	CHECK(M1.Value_Search(4)  == a);
	CHECK(M1.Index_Search(0, 1) == b);
}

