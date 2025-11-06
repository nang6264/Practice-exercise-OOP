#include<iostream>
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
	CMyTime & operator++();
	CMyTime  & operator--(int);
	CMyTime* operator+= (int);
	CMyTime operator-=(int);
	CMyTime* operator+= (const CMyTime&);
	CMyTime operator-=(const CMyTime&);
	bool * operator>(const CMyTime&);
    bool  operator<(const CMyTime&);
	bool* operator>=(const CMyTime&);
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
CMyTime::CMyTime(const CMyTime&other) {
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
CMyTime &CMyTime :: operator++() {
	++m_Second;
	if(m_Second >= 60) {
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
CMyTime &CMyTime:: operator--(int) {
	CMyTime temp = *this;
	--m_Second;
	if (m_Second < 0) {
		m_Minute--;
		m_Second = 59;
		if (m_Minute < 0) {
			m_Hour--;
			m_Minute = 59;
			if (m_Hour < 0) {
				m_Hour = 23;
			}
		}
	}
	return temp;
}
CMyTime* CMyTime:: operator+=(int s) {
	if (s > 24) {
		s = s % 24;
		m_Hour += s;
		if (m_Hour >= 24) {
			m_Hour = m_Hour % 24;
		}
	}
	else {
		m_Hour += s;
		if (m_Hour >= 24) {
			m_Hour = m_Hour % 24;
		}
	}
	return this;
}
CMyTime CMyTime:: operator-=(int s) {
	if (s > 24) {
		s = s % 24;
		m_Hour -= s;
		if (m_Hour < 0) {
			m_Hour = 24 + m_Hour;
		}
	}
	else {
		m_Hour -= s;
		if (m_Hour < 0) {
			m_Hour = 24 + m_Hour;
		}
	}
	return *this;
}
CMyTime* CMyTime::operator+=(const CMyTime& other) {
	m_Hour += other.m_Hour;
	m_Minute += other.m_Minute;
	m_Second += other.m_Second;
	if (m_Second >= 60) {
		m_Second = m_Second % 60;
		m_Minute++;
	}
	if (m_Minute >= 60) {
		m_Hour += m_Minute / 60;
		m_Minute = m_Minute % 60;
	}
	if (m_Hour >= 24) {
		m_Hour = m_Hour % 24;
	}
	return this;
}
CMyTime CMyTime ::operator-
