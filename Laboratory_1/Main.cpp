#include "Spare Matrix_Figure.h"

int main() {
	Matrix A(2, 3);
	A.Show_Matrix_Square();
	A.Show_Matrix_Perimetr();
	A.Show_Matrix_Convex();
	for (int i = 0; i < A.Index_Search(0, 1).size(); i++) {
		std::cout << A.Index_Search(0, 1)[i] << " ";
		std::cout << std::endl;
	}
	std::cout << A.Value_By_Condition();
	std::cout << std::endl;
	for (int i = 0; i < A.Value_Search(8).size(); i++) {
		std::cout << A.Value_Search(8)[i] << " ";
		std::cout << std::endl;
	}
}