#include <iostream>
#include <cstdlib>
using namespace std;

bool testSum(int a[], int n){
	int sum = 0;
	for (int i = 0; i<n; i++){
		sum +=a[i];	
	}
	return (sum%2) ==0;
}

int main(){
	int a[6] = {4,4,7,5,5,2};
	bool result = testSum(a,6);
	if (result){
		cout<<"Sum of all nos. is even.\n";
	}
	else {
		cout << " Sum of all nos. is odd. \n";
	}
	return EXIT_SUCCESS;
}
