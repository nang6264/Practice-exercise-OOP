#include <iostream>
using namespace std;

// Day of month array
const int DayOfMonths[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

// check Leap Year 
bool IsLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	return false;
}

// Get number of days in month
int GetDayInMonth(int month, int year) {
	if (month == 2 && IsLeapYear(year)) {
		return 29;
	}
	return DayOfMonths[month];
}


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
		cout << "Input Date Error!" << endl;
	}
}

// Output date 
void CDate::OutputDate() {
	cout << "Date: " << Day << "/" << Month << "/" << Year << endl;
}

//Check if the date is valid 
bool CDate::CheckDate() {
	if (Year < 0 || Month < 1 || Month > 12 || Day < 1|| Day>GetDayInMonth(Month,Year)) {
		return false;
	}
	return true;	
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
	Year++;
	if (!InspectLeapYear() && Month == 2 && Day == 29) {
		this->Day = 28; 
	}
}

// Increase by one month 
CDate CDate::IncreaseMonth() {
	Month++;
	if (Month > 12) {
		Month = 1;
		IncreaseYear();
	}
	if (Day > GetDayInMonth(Month, Year)) {
		Day = GetDayInMonth(Month, Year);
	}
	return *this;
}

// Increase by one Day 
CDate CDate::IncreaseDay() {
	Day++;
	if (Day > GetDayInMonth(Month, Year)) {
		Day = 1;
		IncreaseMonth();
	}
	return *this;
}

// Decrease by one year
CDate CDate::DecreaseYear() {
	Year--;
	if (!InspectLeapYear() && Month == 2 && Day == 29) {
		this->Day = 28;
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
	if (Day > GetDayInMonth(Month, Year)) {
		Day = GetDayInMonth(Month, Year);
	}
	return *this;
	
}

// Decrase by one Day  
CDate CDate::DecreaseDay() {
	Day--;
	if (Day < 1) {
		DecreaseMonth();
		Day = GetDayInMonth(Month, Year);
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
	int TotalMonths = Month + n;
	if (TotalMonths > 12) {
		int TmpYear = TotalMonths / 12;
		Year += TmpYear;
		Month = TotalMonths - TmpYear * 12;
	}
	if (Day > GetDayInMonth(Month, Year)) {
		Day = GetDayInMonth(Month, Year);
	}
	return *this;
}

// Increase by n days 
CDate CDate::IncreaseDay(int n) {
	for (int i = 0; i < n; i++) {
		IncreaseDay();
	}
	return *this;

}

// Decrease by n years
CDate CDate::DecreaseYear(int n) {
	Year -= n;
	if (!InspectLeapYear() && Month == 2 && Day == 29) {
		this->Day = 28;
	}
	return *this;
	
}

// Decrease by n months
CDate CDate::DecreaseMonth(int n) {
	int TotalMonths = Month - n;
	if (TotalMonths < 1) {
		int TmpYear = (abs(TotalMonths) / 12) + 1;
		Year -= TmpYear;
		Month = TotalMonths + TmpYear * 12;	
		if (Month < 1) {
			Month += 12;
			Year--;
		}
	}
	else {
		this->Month = TotalMonths;
	}

	if (Day > GetDayInMonth(Month, Year)) {
		Day = GetDayInMonth(Month, Year);
	}
	return *this;
}

// Decrease by n days
CDate CDate::DecreaseDay(int n) {
	for (int i = 0; i < n; i++) {
		DecreaseDay();
	}
	return *this;
}

// Get date order in year
int CDate::DateOrderInYear() {
	int Order = 0;
	for (int i = 1; i < Month; i++) {
		Order += GetDayInMonth(i, Year);
	}
	Order += Day;
	return Order;
}

// Get week order in year
int CDate::WeekOrderInYear() {
	int DayOfYear = DateOrderInYear();
	int WeekOrder = DayOfYear / 7;
	if (DayOfYear % 7 != 0) {
		WeekOrder++;
	}
	return WeekOrder;
}

// Convert date
void CDate::ConvertDate() {
	const string MonthNames[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	cout  << MonthNames[Month] << " " << Day << ", " << Year << endl;
}

// Deduct date to date
int CDate::DeductDateToDate() {
	return 0; 
}

