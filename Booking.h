#pragma once
#include "Cottage.h"
#include <string>
#include <vector>
#include "Exception_m.h"
using namespace std;

class Booking {
private:
	string client_name;
	int start_date[3];
	int end_date[3];
	Cottage* cottage;
	static vector<Booking*> bookings;
public:
	Booking(string client_name, int start_day, int start_month, int start_year,
		int end_day, int end_month, int end_year, Cottage* cottage);

	static bool book(string client_name, int start_day, int start_month, int start_year,
		int end_day, int end_month, int end_year, Cottage* cottage);

	static bool is_conflicting(Cottage* cottage, int start_day, int start_month, int start_year,
		int end_day, int end_month, int end_year);


	static bool is_available(Cottage* cottage, int start_day, int start_month, int start_year,
		int end_day, int end_month, int end_year);


	void display_booking_info() const;

	const int* get_start_date() const {
		return start_date;
	}

	const int* get_end_date() const {
		return end_date;
	}

};