#include <iostream>
using namespace std;
#include"Header.h"

int main() {
	employee e1("0001", "6110183801886", "12/04/2017", 30000, 5000);
	employee e2("0065", "6110183808686", "15/08/2015", 14000, 5080);
	employee e3("0421", "6110183017386", "23/11/2020", 54000, 7500);

	LinkdList l1;
	l1.insert(e1);
	l1.insert(e3);
	l1.insert(e2);

	l1.print();
	return 0;
}