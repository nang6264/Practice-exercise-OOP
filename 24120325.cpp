#include<iostream>
#include<string>
#include<vector>
using namespace std;
class CStudent {
	private:
		string m_Name;
		string m_ID;
		vector<pair<string, pair<int, float>>> m_Subjects; // course code, credits, grade
public:
	
	CStudent() {};
	CStudent(string, string, vector<pair<string, pair<int, float>>>) {};
	CStudent(const CStudent&) {};
	friend ostream& operator<<(ostream& , CStudent&);
	friend istream& operator>>(istream& , CStudent&);
	float AverageGrade();
	bool  operator >(const CStudent&);
	bool  operator >=(const CStudent&);
	bool  operator ==(const CStudent&);
	bool  operator <(const CStudent&);
	bool  operator <=(const CStudent&);
};
// copy constructor
CStudent::CStudent() {
	m_Name = "";
	m_ID = "";
	m_Subjects.clear();
}

// default constructor
CStudent::CStudent(string Name, string ID, vector<pair<string, pair<int, float>>> Subjects) {
	m_Name = Name;
	m_ID = ID;
	m_Subjects = Subjects;
}

// constructor with parameters
CStudent::CStudent(const CStudent& other) {
	m_Name = other.m_Name;
	m_ID = other.m_ID;
	m_Subjects = other.m_Subjects;
}

//output operator
ostream& operator<<(ostream& os, CStudent& Stdent) {
	os << "Name: " << Stdent.m_Name << ", ID: " << Stdent.m_ID << endl;
	for (auto subject : Stdent.m_Subjects) {
		os << "Course Code: " << subject.first << ", Credits: " << subject.second.first << ", Grade: " << subject.second.second << endl;
	}
	return os;
 }

//input operator
istream& operator>>(istream& is, CStudent& Stdent) {
	cout << "Enter Name: ";
	is >> Stdent.m_Name;
	cout << "Enter ID: ";
	is >> Stdent.m_ID;
	int n;
	cout << "Enter number of subjects: ";
	is >> n;
	Stdent.m_Subjects.clear();
	for (int i = 0; i < n; i++) {
		string code;
		int credits;
		float grade;
		cout << "Enter Course Code: ";
		is >> code;
		cout << "Enter Credits: ";
		is >> credits;
		cout << "Enter Grade: ";
		is >> grade;
		Stdent.m_Subjects.push_back(make_pair(code, make_pair(credits, grade)));
	}
	return is;
}

// average grade calculation
float CStudent::AverageGrade() {
	float totalScore = 0;
	float totalCredits = 0;
	for (auto subject : m_Subjects) {
		totalScore += subject.second.first * subject.second.second;
		totalCredits += subject.second.first;
	}
	if (m_Subjects.size() == 0) return 0;
	return totalScore / totalCredits;

}

// comparison operators based on average grade
bool CStudent:: operator >(const CStudent&other){
	return this->AverageGrade() > other.AverageGrade();
}

// greater than or equal to operator
bool  CStudent::operator >=(const CStudent&other){
}

// equal to operator
bool CStudent:: operator ==(const CStudent& other) {
}

// less than operator
bool  CStudent::operator <(const CStudent& other) {

}

// less than or equal to operator
bool CStudent:: operator <=(const CStudent&) {

}


class CListStudent {
private: 
	CStudent* m_Student;
	int m_Amount;
public:

};
