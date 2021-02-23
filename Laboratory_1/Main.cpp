#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Spare Matrix_Figure.h"

TEST_CASE("Test 1 (old) Check Figure function") {
	Figure B(3, { 0, 0, 5 }, { 0, 2, 0 });
	CHECK((int)B.Perimetr() == 12);
	CHECK((int)B.Square() == 5);
	CHECK(B.Isconvex() == 1);
}

TEST_CASE("Test 2 (old) Check Figure function") {
	Figure B(4, { 2, 5, 3, 7 }, { 4, 8, 5, 2 });
	CHECK((int)B.Perimetr() == 18);
	CHECK((int)B.Square() == 4);
	CHECK(B.Isconvex() == -1);
}

TEST_CASE("Test 3 (old) Check Figure function") {
	Figure B(5, { 1, -3, 3,-2,-1 }, { 2, -2, 4,0, 3 });
	CHECK((int)B.Perimetr() == 25);
	CHECK((int)B.Square() == 2);
	CHECK(B.Isconvex() == -1);
}

TEST_CASE("Test 4(old) Check Matrix function") {
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
TEST_CASE("Test 5(new) Check SumMatrix ") {
	Figure A(3, { 0, 0, 5 }, { 0, 2, 0 });
	Figure B(4, { 2, 5, 3, 7 }, { 4, 8, 5, 2 });
	Figure C(5, { 1, -3, 3,-2,-1 }, { 2, -2, 4,0, 3 });
	Matrix M1(2, 3, { A,C,B }, { 0,1,1 }, { 0, 1, 2 });
	Matrix M2(2, 3, { A,B,C }, { 0,1,1 }, { 0, 1, 2 });
	Matrix M3;
	M3.SumMatrix(M1.matrix, M2.matrix, 2, 3);
	CHECK(M3.matrix[0]->square == 10);
}
TEST_CASE("Test 6(new) Check SumMatrix ") {
	Figure A(3, { 1, 3, 5 }, { 1, 5, 2 });
	Figure B(4, { 0, 0, 5, 5 }, { 0, 5, 0, 5 });
	Figure C(5, { 1, -3, 3,-2,-1 }, { 2, -2, 4,0, 3 });
	Matrix M1(2, 3, { A,C,B }, { 0,1,1 }, { 0, 0, 1 });
	Matrix M2(2, 3, { A,B,C }, { 0,1,1 }, { 0, 0, 1 });
	Matrix M3;
	M3.SumMatrix(M1.matrix, M2.matrix, 2, 3);
	CHECK(M3.matrix[0]->square == 14);
}
TEST_CASE("Test 7(new) Check MultiplyVector") {
	Figure A(3, { 0, 0, 5 }, { 0, 2, 0 });
	Figure B(4, { 2, 5, 3, 7 }, { 4, 8, 5, 2 });
	Figure C(5, { 1, -3, 3,-2,-1 }, { 2, -2, 4,0, 3 });
	Matrix M1(2, 3, { A,C,B }, { 0,1,1 }, { 0, 1, 2 });
	Matrix M3;
	M3.MultiplyVector(M1.matrix, { 1,2,3 }, 2, 3);
	CHECK(M3.matrix[1]->square == 18);
}
TEST_CASE("Test 8(new) Check MultiplyVector") {
	Figure A(3, { 1, 3, 5 }, { 1, 5, 2 });
	Figure B(4, { 0, 0, 5, 5 }, { 0, 5, 0, 5 });
	Figure C(5, { 1, -3, 3,-2,-1 }, { 2, -2, 4,0, 3 });
	Matrix M1(2, 3, { A,C,B }, { 0,1,1 }, { 0, 0, 1 });
	Matrix M3;
	M3.MultiplyVector(M1.matrix, { 3, 2, 1 }, 2, 3);
	CHECK(M3.matrix[0]->square == 21);
}
