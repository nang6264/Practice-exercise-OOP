#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<vector>
#include<windows.h>
#include <conio.h>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<fstream>

using namespace std;
class CDate
{
private:
	int Day;
	int Month;
	int Year;
public:
	CDate();
	CDate(const CDate&);
	CDate(int, int, int);
	~CDate() = default;

	friend ostream& operator<<(ostream&, const CDate&);
	friend istream& operator>>(istream&, CDate&);
	bool operator == (const CDate&) const;
	bool operator < (const CDate&) const;
	int getDay() const {}
	int getMonth() const {}
	int getYear() const {}

	/*void InputDate();
	void OutputDate();
	bool CheckDate();
	bool InspectLeapYear();
	CDate IncreaseYear();
	CDate IncreaseMonth();
	CDate IncreaseDay();
	CDate DecreaseYear();
	CDate DecreaseMonth();
	CDate DecreaseDay();
	CDate IncreaseYear(int);
	CDate IncreaseMonth(int);
	CDate IncreaseDay(int);
	CDate DecreaseYear(int);
	CDate DecreaseMonth(int);
	CDate DecreaseDay(int);
	int DateOrderInYear();
	int WeekOrderInYear();
	void ConvertDate();
	int DeductDateToDate();*/

};

CDate::CDate()
{
	Day = Month = Year = 0;
}

CDate::CDate(const CDate& other) : Day(other.Day), Month(other.Month), Year(other.Year)
{
}

CDate::CDate(int d, int m, int y) : Day(d), Month(m), Year(y)
{
}

istream& operator >> (istream& is, CDate& a)
{
	string s;
	if (!(is >> s)) return is;
	a.Day = stoi(s.substr(0, 2));
	a.Month = stoi(s.substr(3, 2));
	a.Year = stoi(s.substr(6, 4));
	return is;
}

ostream& operator << (ostream& os, const CDate& a)
{
	os << setfill('0') << setw(2) << a.Day << "/" << setw(2) << a.Month << "/" << setw(4) << a.Year;
	return os;
}

bool CDate::operator == (const CDate& other) const
{
	return (other.Day == Day && other.Month == Month && other.Year == Year);
}

bool CDate::operator < (const CDate& other) const
{
	if (Year != other.Year)
		return Year < other.Year;
	if (Month != other.Month)
		return Month < other.Month;
	return Day < other.Day;
}

int CDate::getDay() const { return Day; }
int CDate::getMonth() const { return Month; }
int CDate::getYear() const { return Year; }
class CTime {
private:
	int m_Hour;
	int m_Minute;
	int m_Second;
public:
	CTime();
	CTime(int, int, int);
	CTime(const CTime&);
	friend ostream& operator<<(ostream&, const CTime&);
	friend istream& operator>>(istream&, CTime&);
	CTime& operator++();
	CTime operator--(int);
	CTime& operator+= (int);
	CTime& operator-=(int);
	CTime operator+ (const CTime&);
	CTime operator-(const CTime&);
	bool operator>(const CTime&);
	bool  operator<(const CTime&);
	bool operator>=(const CTime&);
	bool operator<=(const CTime&);
	bool operator==(const CTime&);
	int getHour() const { }
	int getMinute() const { }
	int getSecond() const { }
};
CTime::CTime() {
	m_Hour = 0;
	m_Minute = 0;
	m_Second = 0;
}
CTime::CTime(int h, int m, int s) {
	m_Hour = h;
	m_Minute = m;
	m_Second = s;
}
CTime::CTime(const CTime& other) {
	m_Hour = other.m_Hour;
	m_Minute = other.m_Minute;
	m_Second = other.m_Second;

}
ostream& operator << (ostream& os, const CTime& t)
{
	os << setfill('0') << setw(2) << t.m_Hour << ":" << setw(2) << t.m_Minute << ":" << setw(2) << t.m_Second;
	return os;
}
istream& operator >> (istream& is, CTime& t)
{
	string s;
	if (!(is >> s)) return is;
	t.m_Hour = stoi(s.substr(0, 2));
	t.m_Minute = stoi(s.substr(3, 2));
	t.m_Second = stoi(s.substr(6, 2));
	return is;
}
bool CTime:: operator>(const CTime& other) {
	if (m_Hour > other.m_Hour) {
		return true;
	}
	else if (m_Hour == other.m_Hour && m_Minute > other.m_Minute) {
		return true;
	}
	else if (m_Hour == other.m_Hour && m_Minute == other.m_Minute && m_Second > other.m_Second) {
		return true;
	}
	else {
		return false;
	}

}
bool CTime:: operator<(const CTime& other) {
	if (m_Hour < other.m_Hour) {
		return true;
	}
	else if (m_Hour == other.m_Hour && m_Minute < other.m_Minute) {
		return true;
	}
	else if (m_Hour == other.m_Hour && m_Minute == other.m_Minute && m_Second < other.m_Second) {
		return true;
	}
	else {
		return false;
	}
}
bool CTime:: operator>=(const CTime& other) {
	return *this > other || *this == other;
}
bool CTime:: operator<=(const CTime& other) {
	return *this < other || *this == other;
}
bool CTime:: operator==(const CTime& other) {
	if (m_Hour == other.m_Hour && m_Minute == other.m_Minute && m_Second == other.m_Second) {
		return true;
	}
	else {
		return false;
	}
}
int CTime::getHour() const { return m_Hour; }
int CTime::getMinute() const { return m_Minute; }
int CTime::getSecond() const { return m_Second; }

class CMessage {
private: 
	string m_Number;
	int  m_Vote;
	CDate m_Date;
	CTime m_Time;
public:
	CMessage();
	CMessage(const CMessage&);
	CMessage(string&, string&, CDate&, CTime&);
	~CMessage() = default;
	friend ostream& operator<<(ostream&, const CMessage&);
	friend istream& operator>>(istream&, CMessage&);
	int getVote() const {}
	string getNumber() const {}
	CDate getDate() const {}
	CTime getTime() const {}
 };

CMessage::CMessage() : m_Number(""), m_Vote(), m_Date(), m_Time()
{
}

CMessage::CMessage(const CMessage& other) : m_Number(other.m_Number), m_Vote(other.m_Vote), m_Date(other.m_Date), m_Time(other.m_Time)
{
}

ostream& operator<<(ostream& os, const CMessage& mes) {
	os << "Number: " << mes.m_Number << ", Vote: " << mes.m_Vote << ", Date: " << mes.m_Date << ", Time: " << mes.m_Time;
	return os;
}
istream& operator>>(istream& is, CMessage& mes) {
	is >> mes.m_Number >> mes.m_Vote >> mes.m_Date >> mes.m_Time;
	return is;
}
int CMessage::getVote() const { return m_Vote; }
string CMessage ::getNumber() const { return m_Number; }
CDate CMessage::getDate() const { return m_Date; }
CTime CMessage::getTime() const { return m_Time; }

class CListMessage {
private:
	CMessage *m_Message;
	int m_Amount;
public:
	~CListMessage();
	CListMessage();
	friend ostream& operator<<(ostream&, const CListMessage&);
	friend istream& operator>>(istream&, CListMessage&); 
	void GetMostVoteCode();
	string  GetMostActivePhone();
	CDate GetPeakMessageDay();
	CTime GetPeakVotingTime();
	void Top10();
};

CListMessage::~CListMessage() {
	delete[] m_Message;
}
CListMessage::CListMessage() :m_Message(nullptr), m_Amount(0) {}
ostream& operator<<(ostream& os, const CListMessage& list) {
	for (int i = 0; i < list.m_Amount; i++) {
		os << list.m_Message[i] << endl;
	}
	return os;
}

istream& operator>>(istream& is, CListMessage& list) {
	cout << "Enter amount of messages: ";
	is >> list.m_Amount;
	if (list.m_Message != nullptr) {
		delete[] list.m_Message;
		list.m_Message = nullptr;
	}
	list.m_Message = new CMessage[list.m_Amount];
	for (int i = 0; i < list.m_Amount; i++) {
		cout << "Enter message " << i + 1 << ": ";
		is >> list.m_Message[i];
	}
	return is;
}


void CListMessage::GetMostVoteCode() {
	unordered_map<int, int> voteCount;
	for (int i = 0; i < m_Amount; i++) {
		voteCount[m_Message[i].getVote()]++;
	}
	int maxVote = 0;
	for (const auto& pair : voteCount) {
		if (pair.second > maxVote) {
			maxVote = pair.second;
		}
	}
	ofstream outFile("OUTPUT.TXT");
	if (outFile.is_open()) {

		for (const auto& pair : voteCount) {
			if (pair.second == maxVote) {
				outFile << "Ma so: " << pair.first << endl;
			}
		}
		outFile << "So luot binh chon: " << maxVote << endl;

		outFile.close();
		cout << "\nDa ghi ket qua ra file OUTPUT.TXT\n";
	}
	else {
		cout << "Khong the mo file OUTPUT.TXT de ghi.\n";
	}

}

string CListMessage::GetMostActivePhone() {
	unordered_map<string, int>ActivePhoneCount;
	for (int i = 0;i < m_Amount; i++) {
		ActivePhoneCount[m_Message[i].getNumber()]++;
	}
	int maxActive = 0;
	string mostActivePhone = m_Message[0].getNumber();
	for (const auto& pair : ActivePhoneCount) {
		if (pair.second > maxActive) {
			maxActive = pair.second;
			mostActivePhone = pair.first;
		}
	}
	return mostActivePhone;
}


CDate CListMessage::GetPeakMessageDay() {
	unordered_map<CDate, int>dateCount;
	for (int i = 0;i < m_Amount;i++) {
		dateCount[m_Message[i].getDate()]++;
	}
	int maxDate = 0;
	CDate peakDate = m_Message[0].getDate();
	for (const auto& pair : dateCount) {
		if (pair.second > maxDate) {
			maxDate = pair.second;
			peakDate = pair.first;
		}
	}
	return peakDate;
}

CTime CListMessage::GetPeakVotingTime() {
	unordered_map<CTime, int>timeCount;
	for (int i = 0;i < m_Amount;i++) {
		timeCount[m_Message[i].getTime()]++;
	}
	int maxTime = 0;
	CTime peakTime = m_Message[0].getTime();
	for (const auto& pair : timeCount) {
		if (pair.second > maxTime) {
			maxTime = pair.second;
			peakTime = pair.first;
		}
	}
	return peakTime;
}

void CListMessage::Top10() {
	unordered_map<int, int> voteCount;
	for (int i = 0; i < m_Amount; i++) {
		voteCount[m_Message[i].getVote()]++;
	}
	vector<pair<int, int>> voteVector(voteCount.begin(), voteCount.end());
	sort(voteVector.begin(), voteVector.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; });
	cout << "Top 10:" << endl;
	for (int i = 0; i < 10 && i < voteVector.size(); i++) {
		cout << "Ma so: " << voteVector[i].first << ", So luot binh chon: " << voteVector[i].second << endl;
	}
}
