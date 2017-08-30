#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date{

	private:
		int day;
		int month;
		int year;

	public:
		Date(int d, int m, int y);
		Date(Date& date);

		int getDay();
		void setDay(int d);
		int getMonth();
		void setMonth(int m);
		int getYear();
		void setYear(int y);

		int diference(Date& b);

		friend std::ostream& operator<< (std::ostream &d0, Date &d);

		/*friend std::ostream& operator>> (std::ostream &d0, Date &d);*/

		bool operator>(Date& b);

		bool operator==(Date& b);

		bool operator<(Date& b);
};

#endif