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
	Course(string courseName, string ICName, int noStudents, int MM){
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

int main(){}
