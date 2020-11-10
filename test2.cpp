#include <iostream>
using namespace std;
int foobar(int *pi){
	*pi=1024;
	return *pi;
}
int main(){
	int *pi2=new int;
	int ival=foobar(pi2);
	cout << ival << endl;
	return 0;
}
