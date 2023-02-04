#include <bits/stdc++.h>
using namespace std;

class Course{
private:
	vector<int>courseMarks;
public:
	string name;
	string IC;
	int numberOfStudents;
	int maxMarks;
	Course(string courseName = "", string ICName = "", int noStudents = 0, int MM = 0){
	name = courseName;
	IC = ICName;
	noStudents = numberOfStudents;
	maxMarks = MM;
 
	}
	vector<int> getMarks(){
		return courseMarks;
	}
	void setCourseMarks(vector<int>&v){
 		courseMarks = v;
	}
	bool evaluateAnswer(int givenAnswer, int expectedAnswer){
		return (givenAnswer ==expectedAnswer);	
	}
	bool evaluateAnswer(float givenAnswer, float expectedAnswer){
		return (givenAnswer ==expectedAnswer);	
	}
	bool evaluateAnswer(string givenAnswer, string expectedAnswer){
		return (givenAnswer ==expectedAnswer);	
	}
 
};
class Lab: public Course{
private:
	vector<int> labMarks;
public:
	Lab(Course* c){
		name = c->name;
		IC = c->IC;
		numberOfStudents = c->numberOfStudents;
		maxMarks = c->maxMarks;
		vector<int> cousemarks = c->getMarks();
		setCourseMarks(cousemarks);
	}
	void setLabMarks(vector<int>&v){
 		labMarks = v;
	}
	int countNC(int minMarks){
		int nc = 0;
		for (int i = 0; i<labMarks.size(); i++){
			if ((labMarks[i])+(getMarks()[i])<minMarks){
				nc++;
			}
		}
		return nc;
	}
};
void showOptions()
{
	cout
		<< "1:	Create Course\n"
		<< "2:	Add Course Marks\n"
		<< "3:	Add Lab Marks\n"
		<< "4:	Print Course Marks\n"
		<< "5:	EVALUATE ANSWER\n"
		<< "6:	Count NC\n"
		<< "7:	Exit\n";
}
void acceptCourseMarks(Course* c){
	vector<int> newMarks;
	for (int i = 0; i < c->numberOfStudents; i++){
		int currStudentMarks;
		cout << "Enter The marks for course for student number" << i+1;
		cin >> currStudentMarks;
		newMarks.push_back(currStudentMarks);
	}
	c->setCourseMarks(newMarks);
}
void acceptLabMarks(Lab* l){
	vector<int> newLabMarks;
	for (int i = 0; i < l->numberOfStudents; i++){
		int currStudentLabMarks;
		cout << "Enter The marks for course for student number" << i+1;
		cin >> currStudentLabMarks;
		newLabMarks.push_back(currStudentLabMarks);
	}
	l->setCourseMarks(newLabMarks);
}
void printMarks(vector<int> marks){
	for (int i = 0; i < marks.size(); i++){
		cout << "Marks for Student "<< i+1<< " is " << marks[i] << "\n";
	}
	return;
}
void printNC(Lab* l){
	int minMarks;
	cout << "Enter The min marks\n ";
	cin >> minMarks;
	cout<< "the Number of NCs are " <<  l->countNC(minMarks) << "\n";
	return;
}
void evaluteAnswer(Course* c){
	int expectedAnswer, givenAnswer;
	cout << "Enter expected answer and given Answer \n" ;
	cin >> expectedAnswer >> givenAnswer;
	cout << "The Result is " << c->evaluateAnswer(givenAnswer, expectedAnswer) << "\n";
	return;
}
int main(){
	Course *courseObject;
	int option;
	string courseName;
	string icname;
	int noOfStudents;
	int mm;
	Lab *labObject;
	
	while (1)
	{
		showOptions();
		cin >> option;
		switch (option)
		{
		case 1:
			if (!courseObject){
				cout << "Enter Course name, IC Name, No of Students, Maximum Marks\n";
				cin >> courseName >> icname >> noOfStudents >> mm;
				courseObject = new Course(courseName, icname, noOfStudents, mm);
				labObject = new Lab(courseObject);
			}
			else{
				cout << "A course is already created";
			}
			break;
		case 2:
			acceptCourseMarks(courseObject);
			break;
		case 3:
			acceptLabMarks(labObject);
			break;
		case 4:
			printMarks(courseObject->getMarks());
			break;
		case 5:
			evaluteAnswer(courseObject);
			break;
		case 6:
			printNC(labObject);
			break;
		case 7:
			return EXIT_SUCCESS;
		}
	}

}
