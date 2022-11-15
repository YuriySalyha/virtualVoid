#pragma warning (disable: 4996)
#include "DateTime.h"
#include <ctime>
#include "ConsoleLogger.h"
#include <cstring>
#include <string>
#include <iostream>
#include<iomanip>
#include<stdexcept>
using namespace std;

class Number
{
public:
	int value;
	Number operator+(const Number& second)
	{
		StatickLogger::logger.Log("operator+ const Number&");
		return Number{ this->value + second.value };
	}

	Number& operator=(const int& input) {
		StatickLogger::logger.Log("operator= const int&");
		this->value = input;
		return *this;
	}
	Number& operator=(const double& input) {
		StatickLogger::logger.Log("operator= const double&");
		this->value = (int)input;
		return *this;
	}
};

std::ostream& operator<<(std::ostream& output, const Number& input)
{
	StatickLogger::logger.Log("operator<<");
	output << "Number: " << input.value << "\n";
	return output;
}

std::istream& operator>>(std::istream& input, Number& output) {
	StatickLogger::logger.Log("operator>>");
	input >> output.value;
	return input;
}

void DateTime::changeTimeZone(int offset) {
	StatickLogger::logger.Log("changeTimeZone");
	if (offset > 13 || offset < -14) {
		cout << "Wrong Time Zone";
		return;
	}
	this->hours = this->hours - currentTimeZone + offset;
	this->currentTimeZone = offset;
};

int DateTime::getTimeZone() {
	StatickLogger::logger.Log("getTimeZone");
	return this->currentTimeZone;
}

DateTime::DateTime()
{
	day = 1;
	month = 1;
	year = 1;
	hours = 0;
	minutes = 0;
	seconds = 0;
}


DateTime::DateTime(int day, int month, int year)
{
	StatickLogger::logger.Log("DateTime constructor");
	this->day = day;
	this->month = month;
	this->year = year;
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

DateTime::DateTime(int day, int month, int year,
	int hours, int minutes, int seconds)
{
	StatickLogger::logger.Log("DateTime constructor");
	this->day = day;
	this->month = month;
	this->year = year;
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

DateTime DateTime::now(bool isInLog)
{
	
	if (!isInLog) {
		StatickLogger::logger.Log("now");
	}
	time_t now = time(0);
	tm* tmNow = gmtime(&now);

	DateTime output;

	output.day = tmNow->tm_mday;
	output.month = tmNow->tm_mon + 1;
	output.year = tmNow->tm_year + 1900;
	output.hours = tmNow->tm_hour + output.currentTimeZone;
	output.minutes = tmNow->tm_min;
	output.seconds = tmNow->tm_sec;
	return output;
}

char* DateTime::toString(bool isInLog)
{
	if (!isInLog) {
		StatickLogger::logger.Log("toString");
	}
	char* output = new char[128];
	std::strcpy(output, std::to_string(day).c_str());
	std::strcat(output, "/");
	std::strcat(output, std::to_string(month).c_str());
	std::strcat(output, "/");
	std::strcat(output, std::to_string(year).c_str());
	std::strcat(output, " ");
	std::strcat(output, std::to_string(hours).c_str());
	std::strcat(output, ":");
	std::strcat(output, std::to_string(minutes).c_str());
	std::strcat(output, ":");
	std::strcat(output, std::to_string(seconds).c_str());
	return output;
}

DateTime DateTime::addSeconds(int seconds)
{
	StatickLogger::logger.Log("addSeconds");
	this->seconds += seconds;
	return DateTime();
}

DateTime DateTime::addMinutes(int minutes)
{
	StatickLogger::logger.Log("addMinutes");
	this->minutes += minutes;
	return DateTime();
}

DateTime DateTime::addHours(int hours)
{
	StatickLogger::logger.Log("addHours");
	this->hours += hours;
	return DateTime();
}

DateTime DateTime::addDays(int day)
{
	StatickLogger::logger.Log("addDays");
	this->day += day;
	return DateTime();
}

DateTime DateTime::addMonth(int month)
{
	StatickLogger::logger.Log("addMonth");
	this->month += month;
	return DateTime();
}

DateTime DateTime::addYears(int year)
{
	StatickLogger::logger.Log("addYears");
	this->year += year;
	return DateTime();
}

long DateTime::totalSeconds() const {
	StatickLogger::logger.Log("totalSeconds");
	return this->seconds + (60 * (this->minutes + (this->hours * 60)));
}

long DateTime::totalMinutes() {
	StatickLogger::logger.Log("totalMinutes");
	return this->minutes + (this->hours * 60);
}

long DateTime::totalDays() const {
	StatickLogger::logger.Log("totalDays");
	long output = ((year / 4) * 366) + ((year - (year / 4)) * 365);
	for (int i = 0; i < month; i++) {
		output += monthDays[i];
	}
	return output + day;
}

long DateTime::totalMonth() {
	StatickLogger::logger.Log("totalMonth");
	return this->month + (12 * this->year);
}


DateTime DateTime::max(DateTime input) {
	StatickLogger::logger.Log("max");
	if (input.totalDays() > totalDays()) {
		return input;
	}
	else if (input.totalDays() < totalDays()) {
		return DateTime();
	}
	if (totalSeconds() < input.totalSeconds()) {
		return input;
	}
	else
	{
		return DateTime();
	}
}

DateTime DateTime::min(DateTime input) {
	StatickLogger::logger.Log("min");
	DateTime time = DateTime::max(input);
	if (time.totalSeconds() == totalSeconds()) {
		return input;
	}
	return time;
}
DateTime& DateTime::operator-(const DateTime& input) {
	StatickLogger::logger.Log("operator-");
	DateTime time = DateTime::max(input);
	DateTime biggerTime;
	DateTime smallerTime;

	if (time.totalSeconds() == totalSeconds()) {
		DateTime biggerTime = time;
		DateTime smallerTime = input;
	}
	else
	{
		DateTime biggerTime = input;
		DateTime smallerTime = time;
	}
	time.seconds = biggerTime.seconds - smallerTime.seconds;
	if (time.seconds < 0) {
		biggerTime.minutes--;
		time.seconds += 60;
	}
	time.minutes = biggerTime.minutes - smallerTime.minutes;
	if (time.minutes < 0) {
		biggerTime.hours--;
		time.minutes += 60;
	}
	time.hours = biggerTime.hours - smallerTime.hours;
	if (time.hours < 0) {
		biggerTime.day--;
		time.minutes += 24;
	}
	time.day = biggerTime.day - smallerTime.day;
	while (time.day < 0) {
		biggerTime.month--;
		time.day += monthDays[biggerTime.month - 1];
	}
	time.month = biggerTime.month - smallerTime.month;
	if (time.month < 0) {
		biggerTime.year--;
		time.month += 12;
	}
	time.year = biggerTime.year - smallerTime.year;
	return time;
}
DateTime& DateTime::operator+(const DateTime& input) {
	StatickLogger::logger.Log("operator+");
	this->seconds += input.seconds;
	if (this->seconds > 59) {
		this->minutes++;
		this->seconds -= 60;
	}
	this->minutes += input.minutes;
	if (this->minutes > 59) {
		this->hours++;
		this->minutes -= 60;
	}
	this->hours += input.hours;
	if (this->hours > 23) {
		this->day++;
		this->hours -= 24;
	}

	this->day += input.day;

	if (monthDays[this->month - 1] > this->day) {
		this->day -= monthDays[this->month - 1];
		this->month++;
	}

	this->month += input.month;
	if (month > 12) {
		this->year++;
		this->month -= 12;
	}
	this->year += input.year;
	return *this;
}

bool DateTime::operator>(const DateTime& input) {
	StatickLogger::logger.Log("operator>");
	if (this->totalDays() > input.totalDays()) {
		return true;
	}
	else if (this->totalDays() < input.totalDays()) {
		return false;
	}
	if (this->totalSeconds() > input.totalSeconds()) {
		return true;
	}
	else if (this->totalSeconds() < input.totalSeconds())
	{
		return false;
	}
}

bool DateTime::operator>=(const DateTime& input)
{
	StatickLogger::logger.Log("operator>=");
	if (this->totalDays() > input.totalDays()) {
		return true;
	}
	else if (this->totalDays() < input.totalDays()
		|| this->totalSeconds() < input.totalSeconds()) {
		return false;
	}
	return true;
}

bool DateTime::operator<(const DateTime& input) {
	StatickLogger::logger.Log("operator<");
	return !(*this > input);
}

bool DateTime::operator<=(const DateTime& input)
{
	StatickLogger::logger.Log("operator<=");
	if (this->totalDays() < input.totalDays()) {
		return true;
	}
	else if (this->totalDays() > input.totalDays()
		|| this->totalSeconds() > input.totalSeconds()) {
		return false;
	}
	return true;
}
bool DateTime::operator==(const DateTime& input)
{
	StatickLogger::logger.Log("operator==");
	if (this->totalDays() > input.totalDays() || this->totalDays() < input.totalDays()
		|| this->totalSeconds() < input.totalSeconds() || this->totalSeconds() > input.totalSeconds()) {
		return false;
	}
	return true;
}

bool DateTime::operator!=(const DateTime& input) {
	StatickLogger::logger.Log("operator!=");
	if (this->totalDays() > input.totalDays() || this->totalDays() < input.totalDays()
		|| this->totalSeconds() < input.totalSeconds() || this->totalSeconds() > input.totalSeconds()) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& output, DateTime& source) {
	StatickLogger::logger.Log("operator<<");
	output << source.toString();
	return output;
}

istream& operator>>(istream& output, DateTime& source) {
	StatickLogger::logger.Log("operator>>");
	output >> source.seconds;
	output >> source.minutes;
	output >> source.hours;
	output >> source.day;
	output >> source.month;
	output >> source.year;

	return output;
}