// Calendar.cpp : Defines the entry point for the console application.
//Program for Calendar of 700 years(1700-2300) using an algorithm taught by one of my teachers.
//New comment in 2024: This was compiled in Vistual Studio of those days, for building a win32 console app.
#include<iostream>
#include<conio.h>
#include<process.h>

using namespace std;
int yearcode(int year);
int monthcode(int month);
void day(int a);
inline void monthcal(int month, int year);
inline void heading(char ch, int i) {
	int j;
	for (j = 0; j <= i; j++)
		cout << ch;
}
void main(void) {
	char ch, t(205);
	do {
		system("cls"); // clrscr(); in TC++
		register int i, date, year, month;
		heading(t, 79);
		cout << "\t\t\tCalendar of 700 years(1700-2300)\n";
		heading(t, 79);
		cout << "\n";
		cout << "Enter 1 for knowing the day of a specific date\nEnter 2 to view the calendar of any given month";
		cin >> i;
		if (i == 1) //OPTION 1
		{
			cout << "Enter date:(dd)";
			cin >> date;
			if (date > 31 || date < 1) //Condition for ambiguous date as input
			{
				cout << "\nPlease provide valid date.\t Press any key";
				getch();
				system("cls");
				main();
			}
			cout << "Enter month:(mm)";
			cin >> month;
			cout << "Enter year:(yyyy)";
			cin >> year;
			i = (date + monthcode(month) + yearcode(year));
			{
				((!(year % 100) ^ !(year % 400) ^ !(year % 4)) && (month == 1 || month == 2) ? --i : i); //Condition for leap years
			}
			i %= 7; //Removing multiples of 7
			cout << "\n" << date << "/" << month << "/" << year << " is ";
			day(i);
		} else if (i == 2) //OPTION 2
		{
			cout << "Enter month:(mm)";
			cin >> month;
			cout << "Enter year:(yyyy)";
			cin >> year;
			monthcal(month, year);
		}
		cout << "\nWould you like to try again (y/n)";
		ch = getch();
	} while (ch == 'y'); //ODD LOOP

	exit(0);
}
int yearcode(int year) {
	register int i, yearcode;
	i = (year / 100); // Century code
	switch (i) {
	case 17:
		i = 5;
		break;
	case 18:
		i = 3;
		break;
	case 19:
		i = 1;
		break;
	case 20:
		i = 0;
		break;
	case 21:
		i = -2;
		break;
	case 22:
		i = -4;
		break;
	case 23:
		i = -6;
		break;
	default:
		system("cls"); // clrscr(); in TC++
		cout << "\a\n\t\tPlease enter a year within the given range\a\a\a\a\nTry again,\a Press any key";
		getch();
		main();
	}
	yearcode = ((year % 100) % 28); //Removing multiples of 28 from last two digits of the given year
	yearcode += (yearcode / 4); //Deviding by 4 and adding the quotient to the last 2 digits
	yearcode += i; //Adding century code finally gives yearcode
	return yearcode;
}
int monthcode(int month) {
	register int i;
	switch (month) //list of month codes
	{
	case 1:
	case 10:
		i = 6;
		break;
	case 2:
	case 3:
	case 11:
		i = 2;
		break;
	case 4:
	case 7:
		i = 5;
		break;
	case 5:
		i = 0;
		break;
	case 6:
		i = 3;
		break;
	case 8:
		i = 1;
		break;
	case 9:
	case 12:
		i = 4;
		break;
	default:
		system("cls"); // clrscr(); in TC++
		cout << "\a\n\t\tPlease enter a valid number for a month\a\a\a\a\nTry again,\a Press any key";
		getch();
		main();
	}
	return i;
}

inline void day(int a) {
	switch (a) {
	case 1:
		cout << "Monday";
		break;
	case 2:
		cout << "Tuesday";
		break;
	case 3:
		cout << "Wednesday";
		break;
	case 4:
		cout << "Thursday";
		break;
	case 5:
		cout << "Friday";
		break;
	case 6:
		cout << "Saturday";
		break;
	case 0:
		cout << "Sunday";
		break;
	default:
		cout << "\a\a\a\n\nERROR!!!"; //Exceptional cases
	}
}
void monthcal(int month, int year) {
	int j, mon, c;
	j = 0;
	for (j = 0; j <= 6; j++) // For printing 7 days of week
	{
		day(j);
		cout << "  ";
	}
	j = 1;
	c = (j + monthcode(month) + yearcode(year)); // 1st day of any month
	{
		if ((!(year % 100) ^ !(year % 400) ^ !(year % 4)) && (month == 1 || month == 2)) //condition for leap year
			--c;
	}
	cout << "\n";
	switch (c % 7) //position of 1st date of month
	{
	case 0:
		break;
	case 1:
		cout << "\t";
		break;
	case 2:
		cout << "\t\t";
		break;
	case 3:
		cout << "\t\t\t";
		break;
	case 4:
		cout << "\t\t\t\t";
		break;
	case 5:
		cout << "\t\t\t\t\t";
		break;
	case 6:
		cout << "\t\t\t\t\t\t";
	}
	switch (month) //No. of days of months
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		mon = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		mon = 30;
		break;
	case 2:
		((!(year % 100) ^ !(year % 400) ^ !(year % 4)) ? mon = 29 : mon = 28); //Condition for February in leap years
	}
	j = 1;
	for (j = 1; j <= mon; j++) //Printing the month's calendar
	{
		cout << "     " << j << "\t";
		c++;
		if (!(c % 7))
			cout << "\n";
	}
}