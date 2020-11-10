#include <iostream>
const char *st="The expense of spirit\n";
using namespace std;
int main(){
int len=0;

while(*st++) ++len;
	cout << "origin st:" << st << endl;
	st=st-len-1;
	cout << len << ";" << st;
return 0;
}
