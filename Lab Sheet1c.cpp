#include <iostream>
#include <cstdlib>
using namespace std;

class Circle{
	public:
		double radius;
		double compute_area(){
			return 3.14*radius*radius;
		}
};

int main(){
	Circle obj;
	obj.radius = 7.2;
	cout << "Radius is: " << obj.radius;
	cout << "Area is: " << obj.compute_area();
	
	return 0;
}
