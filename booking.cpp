#include "Booking.h"
using namespace std;

vector<Booking*> Booking::bookings;

Booking::Booking(string client_name, int start_day, int start_month, int start_year,
    int end_day, int end_month, int end_year, Cottage* cottage)
    : client_name(client_name), cottage(cottage) {
    start_date[0] = start_day;
    start_date[1] = start_month;
    start_date[2] = start_year;

    end_date[0] = end_day;
    end_date[1] = end_month;
    end_date[2] = end_year;
}

void Booking::display_booking_info() const {
    cout << "Booking for client: " << client_name << endl;
    cout << "Start date: " << start_date[0] << "/" << start_date[1] << "/" << start_date[2] << endl;
    cout << "End date: " << end_date[0] << "/" << end_date[1] << "/" << end_date[2] << endl;
    cout << "Cottage type: " << cottage->getType() << endl;
}

bool Booking::is_conflicting(Cottage* cottage, int start_day, int start_month, int start_year,
    int end_day, int end_month, int end_year) {
    for (const auto& booking : bookings) {
        if (booking->cottage == cottage) {

            int b_start_day = booking->start_date[0];
            int b_start_month = booking->start_date[1];
            int b_start_year = booking->start_date[2];

            int b_end_day = booking->end_date[0];
            int b_end_month = booking->end_date[1];
            int b_end_year = booking->end_date[2];


            if (!(end_year < b_start_year ||
                (end_year == b_start_year && end_month < b_start_month) ||
                (end_year == b_start_year && end_month == b_start_month && end_day < b_start_day)) &&
                !(start_year > b_end_year ||
                    (start_year == b_end_year && start_month > b_end_month) ||
                    (start_year == b_end_year && start_month == b_end_month && start_day > b_end_day))) {
                return true; 
            }
        }
    }
    return false;
}

bool Booking::book(string client_name, int start_day, int start_month, int start_year,
    int end_day, int end_month, int end_year, Cottage* cottage) {
    if (!cottage) {
        throw BookingException("Cottage is null.");
    }

    if (is_conflicting(cottage, start_day, start_month, start_year, end_day, end_month, end_year)) {
        throw BookingException("The cottage is already booked for the selected dates!");
    }

    Booking* new_booking = new Booking(client_name, start_day, start_month, start_year,
        end_day, end_month, end_year, cottage);
    bookings.push_back(new_booking);
    cout << endl << "Booking successfully created!" << endl;
    new_booking->display_booking_info();
    return true;
}

bool Booking::is_available(Cottage* cottage, int start_day, int start_month, int start_year,
    int end_day, int end_month, int end_year) {
    for (const auto& booking : bookings) {
        if (booking->cottage == cottage) {

            int b_start_day = booking->start_date[0];
            int b_start_month = booking->start_date[1];
            int b_start_year = booking->start_date[2];

            int b_end_day = booking->end_date[0];
            int b_end_month = booking->end_date[1];
            int b_end_year = booking->end_date[2];

      
            if (!(end_year < b_start_year ||
                (end_year == b_start_year && end_month < b_start_month) ||
                (end_year == b_start_year && end_month == b_start_month && end_day < b_start_day)) &&
                !(start_year > b_end_year ||
                    (start_year == b_end_year && start_month > b_end_month) ||
                    (start_year == b_end_year && start_month == b_end_month && start_day > b_end_day))) {
                return false; 
            }
        }
    }
    return true; 
}