
#include<iostream>
#include<iomanip>
#include<vector>
#include<windows.h>
#include <conio.h>
using namespace std;
class CMyTime {
private:
	int m_Hour;
	int m_Minute;
	int m_Second;
public:
	CMyTime();
	CMyTime(int, int, int);
	CMyTime(const CMyTime&);
	friend ostream& operator<<(ostream&, const CMyTime&);
	friend istream& operator>>(istream&, CMyTime&);
	CMyTime& operator++();
	CMyTime operator--(int);
	CMyTime& operator+= (int);
	CMyTime& operator-=(int);
	CMyTime operator+ (const CMyTime&);
	CMyTime operator-(const CMyTime&);
	bool operator>(const CMyTime&);
	bool  operator<(const CMyTime&);
	bool operator>=(const CMyTime&);
	bool operator<=(const CMyTime&);
	bool operator==(const CMyTime&);
	void ShowTime();
	void CountDown();
	void Stopwatch();

	//int getHour() const;
	//int getMinute() const;
	//int getSecond() const;

};
CMyTime::CMyTime() {
	m_Hour = 0;
	m_Minute = 0;
	m_Second = 0;
}
CMyTime::CMyTime(int h, int m, int s) {
	m_Hour = h;
	m_Minute = m;
	m_Second = s;
}
CMyTime::CMyTime(const CMyTime& other) {
	m_Hour = other.m_Hour;
	m_Minute = other.m_Minute;
	m_Second = other.m_Second;

}
ostream& operator<<(ostream& os, const CMyTime& time) {
	os << time.m_Hour << ":" << time.m_Minute << ":" << time.m_Second;
	return os;
}
istream& operator>>(istream& is, CMyTime& time) {
	is >> time.m_Hour >> time.m_Minute >> time.m_Second;
	return is;
}
CMyTime& CMyTime :: operator++() {
	m_Second++;
	if (m_Second >= 60) {
		m_Minute++;
		m_Second = 0;
		if (m_Minute >= 60) {
			m_Hour++;
			m_Minute = 0;
			if (m_Hour >= 24) {
				m_Hour = 0;
			}
		}
	}
	return *this;
}
CMyTime CMyTime:: operator--(int) {
	CMyTime temp = *this;
	m_Minute--;
	if (m_Minute < 0) {
		m_Hour--;
		m_Minute = 59;
		if (m_Hour < 0) {
			m_Hour = 23;
		}
	}
	return temp;
}


CMyTime &CMyTime:: operator+=(int s) {
	if (s > 0) {
		m_Hour += s;
	}
	return *this;
}
CMyTime& CMyTime:: operator-=(int s) {
	if (s > 0) {
		m_Hour -= s;
	}
	return *this;
}
CMyTime CMyTime::operator+(const CMyTime& other) {
	CMyTime result;
	result.m_Second = m_Second + other.m_Second;
	result.m_Minute = m_Minute + other.m_Minute;
	result.m_Hour = m_Hour + other.m_Hour;
	if (result.m_Second >= 60) {
		result.m_Minute++;
		result.m_Second = result.m_Second - 60;
	}
	if (result.m_Minute >= 60) {
		result.m_Hour++;
		result.m_Minute = result.m_Minute - 60;
	}
	return result;	
}
CMyTime CMyTime::operator-(const CMyTime& other) {
	CMyTime result;
	result.m_Second = m_Second - other.m_Second;
	result.m_Minute = m_Minute - other.m_Minute;
	result.m_Hour = m_Hour - other.m_Hour;
	if (result.m_Second < 0) {
		result.m_Minute--;
		result.m_Second = result.m_Second + 60;
	}
	if (result.m_Minute < 0) {
		result.m_Hour--;
		result.m_Minute = result.m_Minute + 60;
	}
	return result;

}
bool CMyTime:: operator>(const CMyTime& other) {
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
bool CMyTime:: operator<(const CMyTime& other) {
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
bool CMyTime:: operator>=(const CMyTime& other) {
	return *this > other || *this == other;
}
bool CMyTime:: operator<=(const CMyTime& other) {
	return *this < other || *this == other;
}
bool CMyTime:: operator==(const CMyTime& other) {
	if (m_Hour == other.m_Hour && m_Minute == other.m_Minute && m_Second == other.m_Second) {
		return true;
	}
	else {
		return false;
	}
}
//int CMyTime::getHour() const {
//	return m_Hour;
//}
//int CMyTime::getMinute() const {
//	return m_Minute;
//}
//int CMyTime::getSecond() const {
//	return m_Second;
//}
void CMyTime::ShowTime() {
	while (true) {
		system("cls");
		cout << setw(2) << setfill('0') << m_Hour << ":" << setfill('0') << m_Minute << ":" << setfill('0') << m_Second;
		Sleep(1000);
		m_Second++;
		if (m_Second == 60) {
			m_Second = 0;
			m_Minute++;
		}
		if (m_Minute == 60) {
			m_Minute = 0;
			m_Hour++;
		}
		if (m_Hour == 24) {
			m_Hour = 0;
		}

	}
}
void CMyTime::CountDown() {
	bool pause = false;
	while (m_Hour > 0 || m_Minute > 0 || m_Second > 0) {
		system("cls");
		cout << setw(2) << setfill('0') << m_Hour << ":" << setfill('0') << m_Minute << ":" << setfill('0') << m_Second;
		Sleep(1000);
		if (_kbhit()) {
			char key = _getch();
			if (key == ' ')pause = true;
			if (key == 13) pause = false;
		}
		if (!pause) {
			Sleep(1000);
			m_Second--;
			if (m_Second < 0) {
				m_Second = 59;
				m_Minute--;
			}
			if (m_Minute < 0) {
				m_Minute = 59;
				m_Hour--;
			}
		}
		
		if (m_Hour == 0 && m_Minute == 0 && m_Second == 0) {
			break;
		}
	}
	system("cls");
	cout << "00:00:00" << endl;
}
void CMyTime::Stopwatch() {
	m_Hour = 0;
	m_Minute = 0;
	m_Second = 0;
	bool running = false;
	vector<string>lapList;
	while (true) {
		system("cls");
		cout << setw(2) << setfill('0') << m_Hour << ":" << setfill('0') << m_Minute << ":" << setfill('0') << m_Second << endl;
		if (_kbhit()) {
			char key = _getch();
			if (key == 's') running = true;
			if (key == 'p') running = false;
			if (key == 'r')running = true;
			if (key == 'l') {
				char buf[20];
				sprintf(buf, "%02d:%02d:%02d",m_Hour,m_Minute,m_Second);
				lapList.push_back(string(buf));
			}
			if (key == 't') {
				running = false;
				break;
			}
			if (key == 27) {
				m_Hour = 0;
				m_Minute = 0;
				m_Second = 0;
				lapList.clear();
				break;
			}
		}
		if (running) {
			Sleep(1000);
			m_Second++;
			if (m_Second == 60) {
				m_Second = 0;
				m_Minute++;
			}
			if (m_Minute == 60) {
				m_Minute = 0;
				m_Hour++;
			}
		}
	}
	cout << "Tong thoi gian: " << setw(2) << setfill('0') << m_Hour << ":"
		<< setfill('0') << m_Minute << ":" << setfill('0') << m_Second << endl;
	for (const auto& lap : lapList) {
		cout << "Lap: " << lap << endl;
	}

}