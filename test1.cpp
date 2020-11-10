#include <iostream>
using namespace std;
int main(){
	//calculate 2^10
	int value=2;
	int pow=10;
	cout << value << "raised to the power of" << pow << ":\t";
	int res	=1;
	for(int cnt=1;cnt<=pow;++cnt)res*=value;
	cout << res <<endl;
}
