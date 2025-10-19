#include <iostream>
using namespace std;
class CDate
{
private:
	int Day;
	int Month;
	int Year;
public:
	void InputDate();
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
	int DeductDateToDate();

};


// Input date
void CDate::InputDate() {
	cout << "Input Day : ";
	cin >> Day;
	cout << "Input Month: ";
	cin >> Month;
	cout << "Input Year: ";
	cin >> Year;
	if (!CheckDate()) {
		cout << "Error!" << endl;
	}
}

// Output date 
void CDate::OutputDate() {
	cout << "Date: " << Day << "/" << Month << "/" << Year << endl;
}

//Check if the date is valid 
bool CDate::CheckDate() {
	if (Year < 0 || Month < 1 || Month>12 || Day < 1 || Day >31) {
		return false;
	}
	else {
		if (Month == 2) {
			if (InspectLeapYear()) {
				if (Day > 29) {
					return false;
				}
				else {
					return true;
				}

			}
			else {
				if (Day > 28) {
					return false;
				}
				else {
					return true;
				}
			}
		}
		else if (Month == 4 || Month == 6 || Month == 9 || Month == 11) {
			if (Day > 30) {
				return false;
			}
			else {
				return true;
			}
		}
		else {
			return true;
		}
	}

}

// Check if the year is a leap year 
bool CDate::InspectLeapYear() {
	if (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}

}

// Increase by one year 
CDate CDate::IncreaseYear() {
	if (InspectLeapYear() && Month == 2 && Day == 29) {
		this->Year++;
		this->Day--;
	}
	else {
		this->Year++;
	}
	return *this;
}

// Increase by one month 
CDate CDate::IncreaseMonth() {
	this->Month++;
	if (Month > 12) {
		Month = 1;
		IncreaseYear();
	}
	if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day == 31) {
		this->Day--;
	}

	if (InspectLeapYear() && Month == 2 && Day > 29) {
		this->Day = 29;
	}
	else if (Month == 2 && Day > 28) {
		this->Day = 28;
	}

	return *this;

}

// Increase by one Day 
CDate CDate::IncreaseDay() {
	Day++;
	if (!CheckDate()) {
		Day = 1;
		IncreaseMonth();
	}
	return *this;
}

// Decrease by one year
CDate CDate::DecreaseYear() {
	if (InspectLeapYear() && Month == 2 && Day == 29) {
		Year--;
		Day--;
	}
	else {
		Year--;
	}
	return *this;

}

// Decrease by one month
CDate CDate::DecreaseMonth() {
	Month--;
	if (Month < 1) {
		Month = 12;
		DecreaseYear();
	}
	if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day == 31) {
		Day--;
	}
	if (InspectLeapYear() && Month == 2 && Day > 29) {
		Day = 29;
	}
	else if (Month == 2 && Day > 28) {
		Day = 28;
	}
	return *this;
}

// Decrase by one Day  
CDate CDate::DecreaseDay() {
	Day--;
	if (Day < 1) {
		DecreaseMonth();
		if (Month == 2) {
			if (InspectLeapYear()) {
				Day = 29;
			}
			else {
				Day = 28;
			}
		}
		if (Month == 4 || Month == 6 || Month == 9 || Month == 11) {
			Day = 30;
		}
		else {
			Day = 31;
		}
	}
	return *this;
}

// Increase by n years
CDate CDate::IncreaseYear(int n) {
	Year += n;
	if (!InspectLeapYear() && Month == 2 && Day == 29) {
		Day--;
	}
	return *this;
}

// Increase by n months
CDate CDate::IncreaseMonth(int n) {
	if (n > 12) {
		int tmp = n / 12;
		IncreaseYear(tmp);
		Month += n - tmp * 12;
	}
	else {
		Month += n;
	}
	if (Month > 12) {
		IncreaseYear();
		Month -= 12;

	}
	if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) && Day == 31) {
		this->Day--;
	}

	if (InspectLeapYear() && Month == 2 && Day > 29) {
		this->Day = 29;
	}
	else if (Month == 2 && Day > 28) {
		this->Day = 28;
	}

	return *this;
}

// Increase by n days 
CDate CDate::IncreaseDay(int  n) {
	if (n > 365) {
		int y = n / 365;
		IncreaseYear(y);
		int d1 = n - y * 365;
		if (d1 > 31) {
			int m = d1 / 31;
			IncreaseMonth(m);
			int d2 = d1 - m * 30;
			Day += d2;
			if ((Month == 4 || Month == 6 || Month == 9 || Month == 11) & Day > 30) {
				Month++;
				Day -= 30;
			}
			else if (InspectLeapYear() && Month == 2 && Day > 29) {
				Month++;
				Day -= 29;
			}
			else if (Month == 2 && Day > 28) {
				Month++;
				Day -= 28;
			}
			else if (Day > 31) {
				Month++;
				Day -= 31;
			}

		}

	}
	return *this;

}

// Decrease by n years
CDate CDate::DecreaseYear(int  n) {
	Year -= n;
	if (!InspectLeapYear() && Month == 2 && Day == 29) {
		Day--;
	}
	return *this;
}
CDate CDate::DecreaseMonth(int n) {
	if (n > 12) {
		int y = n / 12;
		Year -= y;
		int m = n - y * 12;
		Month -= m;
		if (Month < 1) {
			Year--;

		}
	}
	return *this;



}
CDate CDate::DecreaseDay(int) {

}
int CDate::DateOrderInYear() {

}
int CDate::WeekOrderInYear() {

}
void CDate::ConvertDate() {

}

int CDate::DeductDateToDate() {

}
