/*
Author: Thanh Le, Vitor Miranda, Ritvik Mandyam

This is Date Class Functions
*/
#include "Date.h"

#include<string>
#include<iostream>


// Default constructor
Date::Date() {};

// Constructor to initiallize day, month and year 
Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
};


// Function to get day, month and year
// get day of month
int Date::getDay() {
	return day;
}
// get month of year
int Date::getMonth() {
	return month;
}

// get year 
int Date::getYear() {
	return year;
}


// Functions to set day, month and year
// set day of month
void Date::setDay(int d) {
	if (d < 1 || d > 31) {
		std::cout << "Date must be from 1 to 31" << std::endl;
	
	}
	else {
		day = d;
	}
}

// set month of year
void Date::setMonth(int m) {
	if (m < 1 || m > 12) {
		std::cout << "Month must be from 1 to 12" << std::endl;
		
	}
	else {
		month = m;
	}
}

// set year 
void Date::setYear(int y) {
	if (y < 1900) {
		std::cout << "Year must be greater than 1900" << std::endl;
		
	}
	else {
		year = y;
	}
}

// Function to show day, month and year in format dd/mm/yyyy
string Date::toString() {
	// Convert day, month and year to String and then show them in format dd/mm/yyy
	string dateString = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	return dateString;
}