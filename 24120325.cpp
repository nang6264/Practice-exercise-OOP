#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>


using namespace std;

class CDate {
	private:
	int m_Day;
	int m_Month;
	int m_Year;
public:
	CDate() {}
	CDate(int day, int month, int year) : m_Day(day), m_Month(month), m_Year(year) {}
	friend ostream& operator<<(ostream& os, const CDate& date) {
		os << date.m_Day << "/" << date.m_Month << "/" << date.m_Year;
	}
	friend istream& operator>>(istream& is, CDate& date) { // nhap du lieu tu file  dang: 03/01/2006
		string str;
		is >> str;
		date.m_Day = stoi(str.substr(0, 2));
		date.m_Month = stoi(str.substr(3, 2));
		date.m_Year = stoi(str.substr(6, 4));
		return is;
	}
};
void Trim(string& s) {
	if (!s.empty() && s[0] == ' ') s.erase(0, 1);
}
class CCatologue {
private:
	string m_ID; // ma tai lieu
	string m_Title; // tieu de tai lieu
	string m_Author; // tac gia
	int m_Count; // so lan muon
public:
	CCatologue() : m_ID(""), m_Title(""), m_Author(""), m_Count(0) {}
	virtual ~CCatologue() {}
	void setID(const string& id) { m_ID = id; }
	string getID() const { return m_ID; }
	string getAuthor() {
		return m_Author;
	}
	virtual void Input(stringstream &ss) {
		string tempCount;
		getline(ss, m_Title, ',');
		Trim(m_Title);
		getline(ss, m_Author, ',');
		Trim(m_Author);
		getline(ss, tempCount, ',');
		Trim(tempCount);
		m_Count = stoi(tempCount);
	}
	virtual int GetYear() = 0;
	virtual string GetType() = 0;
	virtual void Output(ostream& os) {
		os << "ID: " << m_ID << ", Title: " << m_Title << ", Author: " << m_Author << ", Count: " << m_Count;
	}

};
class CPaper: public CCatologue {
private:
	string m_Journal; // ten tap chi
	int m_Year; // nam xuat ban
};
class CBook: public CCatologue {
	string m_Publisher; // nha xuat ban
	int m_Year; // nam xuat ban
	int m_Version; // phien ban
};
class CThesis : public CCatologue {
	string m_School; // truong dai hoc
	int m_Year; // nam bao ve
	string m_FAculty; // khoa
};
