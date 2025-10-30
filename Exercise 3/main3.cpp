﻿#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define end  '\n'
using namespace std;
class CStudent {
private:
	string m_Name;
	string m_ID;
	vector<pair<string, pair<int, float>>> m_Subjects; // course code, credits, grade
public:

	CStudent();
	CStudent(string, string, vector<pair<string, pair<int, float>>>);
	CStudent(const CStudent&);
	friend ostream& operator<<(ostream&, CStudent&);
	friend istream& operator>>(istream&, CStudent&);
	float AverageGrade()const;
	bool  operator >(const CStudent&);
	bool  operator >=(const CStudent&);
	bool  operator ==(const CStudent&);
	bool  operator <(const CStudent&);
	bool  operator <=(const CStudent&);
	string getID() const;

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
	os << "Name: " << Stdent.m_Name << ", ID: " << Stdent.m_ID << end;
	for (auto subject : Stdent.m_Subjects) {
		os << "Course Code: " << subject.first << ", Credits: " << subject.second.first << ", Grade: " << subject.second.second << end;
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
		Stdent.m_Subjects.push_back({ code, {credits, grade} });
	}
	return is;
}

// average grade calculation
float CStudent::AverageGrade()const {
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
bool CStudent:: operator >(const CStudent& other)  {
	return this->AverageGrade() > other.AverageGrade();
}

// greater than or equal to operator
bool  CStudent::operator >=(const CStudent& other) {
	return this->AverageGrade() >= other.AverageGrade();
}

// equal to operator
bool CStudent:: operator ==(const CStudent& other) {
	return this->AverageGrade() == other.AverageGrade();
}

// less than operator
bool  CStudent::operator <(const CStudent& other) {
	return this->AverageGrade() < other.AverageGrade();
}

// less than or equal to operator
bool CStudent:: operator <=(const CStudent& other) {
	return this->AverageGrade() <= other.AverageGrade();
}

// get ID
string CStudent::getID() const {
	return m_ID;
}
class CListStudent {
private:
	CStudent* m_Student;
	int m_Amount;
public:
	void Input(); 
	void  Output();	
	CStudent FindMaxGPAStudent();
	CStudent FindMinGPAStudent();
	void SortAscending();
	void sortDescending();
	void DeleteStudent(string);
	CStudent FindStudent(string);
	void RankStudents();
	void DeleteList();
};

// input multi students
void CListStudent::Input() {
	cout << "Enter number of students: ";
	int n; 
	cin >> n; 
	m_Student = new CStudent[n];
	m_Amount = n;
	for (int i = 0; i < n; i++) {
		CStudent student = CStudent();
		cin >> student;
		m_Student[i] = student;
	}
}

// output multi students
void   CListStudent::Output() {
	cout << "List of Students: " << end;
	for (int i = 0; i < m_Amount; i++) {
		cout << m_Student[i];
	}
}

// find student with max GPA
CStudent  CListStudent::FindMaxGPAStudent() {
	if (m_Amount == 0) {
		throw runtime_error("No students in the list.");
	}
	CStudent maxGPAStudent = m_Student[0];
	for (int i = 1;i < m_Amount; i++) {
		if (m_Student[i].AverageGrade() > maxGPAStudent.AverageGrade()) {
			maxGPAStudent = m_Student[i];
		}
	}
	return maxGPAStudent;
}

// find student with min GPA
CStudent  CListStudent::FindMinGPAStudent() {
	if (m_Amount == 0) {
		throw runtime_error("No students in the list.");
	}
	CStudent minGPAStudent = m_Student[0];
	for (int i = 1;i < m_Amount; i++) {
		if (m_Student[i].AverageGrade() < minGPAStudent.AverageGrade()) {
			minGPAStudent = m_Student[i];
		}
	}
	return minGPAStudent;
}

// sort students in asceding by Average Grade
void  CListStudent::SortAscending() {
	if (m_Amount <= 1) return;
	sort(m_Student, m_Student + m_Amount, [](const CStudent& a, const CStudent& b) {return a.AverageGrade() < b.AverageGrade();
		});
}

// sort students in descending by Average Grade
void  CListStudent::sortDescending() {
	if (m_Amount <= 1) return;
	sort(m_Student, m_Student + m_Amount, [](const CStudent& a, const CStudent& b) {return a.AverageGrade() > b.AverageGrade();
		});
}

// delete student by ID
void  CListStudent::DeleteStudent(string ID) {
	if (m_Amount == 0) return;
	CStudent StudentToDelete = FindStudent(ID);
	if (StudentToDelete.getID() == "") { return; }
	else {
		CStudent* newStudentList = new CStudent[m_Amount - 1];
		int index = 0;
		for (int i = 0; i < m_Amount; i++) {
			if (m_Student[i].getID() != ID) {
				newStudentList[index] = m_Student[i];
				index++;
			}
		}
		delete[] m_Student;
		m_Student = newStudentList;
		m_Amount--;
	}
}

// find student by ID
CStudent  CListStudent::FindStudent(string ID) {
	if (m_Amount == 0) {
		throw runtime_error("No students in the list.");
	}
	CStudent result = CStudent();
	for (int i = 0; i < m_Amount; i++) {
		if (m_Student[i].getID() == ID) {
			return m_Student[i];
		}
	}
	return result;
}

// rank student by GPA
string rankOfStudent(float GPA) {
	if (GPA < 4.0)return "";
	if (4.0 <= GPA && GPA < 5)return "F";
	if (5.0 <= GPA && GPA < 6)return "E";
	if (6.0 <= GPA && GPA < 7)return "D";;
	if (7.0 <= GPA && GPA < 8)return "C";
	if (8.0 <= GPA && GPA < 9)return "B";
	if (9.0 <= GPA && GPA <= 10)return "A";
}

// rank student by Average Grade
void  CListStudent::RankStudents() {
	for (int i = 0; i < m_Amount; i++) {
		float GPA = m_Student[i].AverageGrade();
		string rank = rankOfStudent(GPA);
		cout << "Student ID: " << m_Student[i].getID() << ", GPA: " << GPA << ", Rank: " << rank << end;
	}
}

// delete student list
void CListStudent::DeleteList() {
	delete[] m_Student;
	m_Student = nullptr;
	m_Amount = 0;
}
int main() {
	ios::sync_with_stdio(false);
 
	/*freopen("input.txt", "r", stdin);  */ // cin đọc từ file
	//freopen("output.txt", "w", stdout); // cout ghi ra file
	CListStudent list;
	list.Input();
	list.Output();
	CStudent maxGPAStudent = list.FindMaxGPAStudent();
	cout << "Student with Max GPA: " << maxGPAStudent;
	CStudent minGPAStudent = list.FindMinGPAStudent();
	cout << "Student with Min GPA: " << minGPAStudent;
	list.SortAscending();
	cout << "Students sorted in Ascending order by GPA: " << end;
	list.Output();
	list.sortDescending();
	cout << "Students sorted in Descending order by GPA: " << end;
	list.Output();
	list.DeleteStudent("24120325");
	list.Output();
	list.RankStudents();
	list.DeleteList();
	return 0; 
}