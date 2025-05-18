#include <iostream>
#include <string>
#include "Amenity.h"
#include "Cottage.h"
#include "Village.h"
#include "Booking.h"
#include "Finance.h"
using namespace std;

int main() {
    try {
        Amenity* WiFi = new Amenity("WiFi", 50, 1);
        Amenity* kitchen = new Amenity("Kitchen", 150, 2);

        Amenity* football_field = new Amenity("Football Field", 100, 0);
        Amenity* bar = new Amenity("Bar", 200, 0);

        Cottage* cottage1 = new Cottage("Lux", nullptr, 0, 4);
        Cottage* cottage2 = new Cottage("Standard", nullptr, 0, 2);

        cottage1->add_amenity(WiFi);
        cottage2->add_amenity(kitchen);

        Village village;
        village.add_amenity(football_field);
        village.add_amenity(bar);

        village.add_cottage(cottage1);
        village.add_cottage(cottage2);

        village.display_info();

        Booking::book("John Doe", 1, 12, 2024, 5, 12, 2024, cottage1);

        cout << "Checking availability for 3/12/2024 - 4/12/2024:" << endl;
        if (Booking::is_available(cottage1, 3, 12, 2024, 4, 12, 2024)) {
            cout << "Cottage is available!" << endl;
        }
        else {
            cout << "Cottage is not available." << endl;
        }

        cout << "Checking availability for 6/12/2024 - 8/12/2024:" << endl;
        if (Booking::is_available(cottage1, 6, 12, 2024, 8, 12, 2024)) {
            cout << "Cottage is available!" << endl;
        }
        else {
            cout << "Cottage is not available." << endl;
        }

        Finance finance;
        finance.calculate_amenity_expenses(village);


        finance.calculate_cottage_income(cottage1, 5, 12, 1);
        finance.calculate_cottage_expenses(cottage1, 200, 1);


        finance.calculate_cottage_income(cottage2, 5, 11, 2);
        finance.calculate_cottage_expenses(cottage2, 100, 2);

        finance.display_statistics();
    } catch (const CustomException& e) {
        cout << "Error: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Standard Error: " << e.what() << endl;
    }

    return 0;
}
