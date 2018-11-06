#include "Poly.h"
int main()
{
	int arr1[] = { 1,2,3,0,5,6};
	int arr2[] = { 8,4,1,5,5,6,2,5};
	int arr[] = { 0,0,0,0,0,0,0,0 };
	Poly myPoly1(5, arr1);
	myPoly1.show();
	Poly myPoly2(7, arr2);
	myPoly2.show();
	Poly myPoly(7, arr);
	myPoly.add(myPoly1, myPoly2, myPoly);
	myPoly.show();
	return 0;
}