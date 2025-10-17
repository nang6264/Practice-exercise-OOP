#include <iostream>
using namespace std;
class CDate
{
private:
	int day;
	int month;
	int year;
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
	cout << "Input Day: ";
	cin >> day;
	cout << "Input Month: ";
	cin >> month;
	cout << "Input Year: ";
	cin >> year;
	if (!CheckDate()) {
		cout << "Error!" << endl;
	}
}

// Output date 
void CDate::OutputDate() {
	cout << "Date: " << day << "/" << month << "/" << year << endl;
}

//Check if the date is valid 
bool CDate::CheckDate() {
	if (year < 0 || month < 1 || month>12 || day < 1 || day>31) {
		return false;
	}
	else {
		if (month == 2) {
			if (InspectLeapYear()) {
				if (day > 29) {
					return false;
				}
				else {
					return true;
				}

			}
			else {
				if (day > 28) {
					return false;
				}
				else {
					return true;
				}
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30) {
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
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}

}

// Increase by one year 
CDate CDate::IncreaseYear() {
	if (InspectLeapYear() && month == 2 && day == 29) {
		this->year++;
		this->day--;
	}
	else {
		this->year++;
	}
	return *this;
}

// Increase by one month 
CDate CDate::IncreaseMonth() {
	this->month++;
	if (month > 12) {
		month = 1;
		IncreaseYear();
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
		this->day--;
	}

	if (InspectLeapYear() && month == 2 && day > 29) {
		this->day = 29;
	}
	else if (month == 2 && day > 28) {
		this->day = 28;
	}

	return *this;

}

// Increase by one day
CDate CDate::IncreaseDay() {
	day++;
	if (!CheckDate()) {
		day = 1;
		IncreaseMonth();
	}
	return *this;
}

// Decrease by one year
CDate CDate::DecreaseYear() {
	if (InspectLeapYear() && month == 2 && day == 29) {
		year--;
		day--;
	}
	else {
		year--;
	}
	return *this;

}

// Decrease by one month
CDate CDate::DecreaseMonth() {
	month--;
	if (month < 1) {
		month = 12;
		DecreaseYear();
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
		day--;
	}
	if (InspectLeapYear() && month == 2 && day > 29) {
		day = 29;
	}
	else if (month == 2 && day > 28) {
		day = 28;
	}
	return *this;
}

// Decrase by one day 
CDate CDate::DecreaseDay() {
	day--;
	if (day < 1) {
		DecreaseMonth();
		if (month == 2) {
			if (InspectLeapYear()) {
				day = 29;
			}
			else {
				day = 28;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			day = 30;
		}
		else {
			day = 31;
		}
	}
	return *this;
}

// Increase by n years
CDate CDate::IncreaseYear(int n) {
	year += n;
	if (!InspectLeapYear() && month == 2 && day == 29) {
		day--;
	}
	return *this;
}

// Increase by n months
CDate CDate::IncreaseMonth(int n) {
	if (n > 12) {
		int tmp = n / 12;
		IncreaseYear(tmp);
		month += n - tmp * 12;
	}
	else {
		month += n;
	}
	if (month > 12) {
		IncreaseYear();
		month -= 12;

	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
		this->day--;
	}

	if (InspectLeapYear() && month == 2 && day > 29) {
		this->day = 29;
	}
	else if (month == 2 && day > 28) {
		this->day = 28;
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
			day += d2;
			if ((month == 4 || month == 6 || month == 9 || month == 11) & day > 30) {
				month++;
				day -= 30;
			}
			else if (InspectLeapYear() && month == 2 && day > 29) {
				month++;
				day -= 29;
			}
			else if (month == 2 && day > 28) {
				month++;
				day -= 28;
			}
			else if (day > 31) {
				month++;
				day -= 31;
			}

		}

	}
	return *this;

}

// Decrease by n years
CDate CDate::DecreaseYear(int  n) {
	year -= n;
	if (!InspectLeapYear() && month == 2 && day == 29) {
		day--;
	}
	return *this;
}
CDate CDate::DecreaseMonth(int n) {
	if (n > 12) {
		int y = n / 12;
		year -= y;
		int m = n - y * 12;
		month -= m;
		if (month < 1) {
			year--;

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