#include <iostream>
#include <cstdlib>
using namespace std;

class Circle{
	private:
		double radius;
	public:
		void compute_area(int r){
			radius = r;
			double area = 3.14*radius*radius;
			cout << "Radius is: " << radius;
			cout << "Area is: " << area;
		}
};

int main(){
	Circle obj;
	obj.compute_area(7.2);
	
	return 0;
}
