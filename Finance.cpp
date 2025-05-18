#include "Finance.h"
#include <iomanip>
using namespace std;

Finance::Finance() : total_income(0), total_expenses(0) {}

void Finance::calculate_cottage_income(Cottage* cottage, int nights, int month, int cottage_id) {
    double price_per_night = cottage->getPrice();
    double discount_price = price_per_night;

    if (month == 11 || month == 3) {
        discount_price *= 0.8;
    }

    double lodging_income = discount_price * nights;
    total_income += lodging_income;

    cout << fixed << setprecision(2);
    cout << "\n[Cottage " << cottage_id << " Income] Nights: " << nights
        << ", Month: " << month
        << ", Price per night: " << price_per_night
        << ", Discounted: " << discount_price
        << ", Lodging Income: " << lodging_income << endl;

    Amenity** amenities = cottage->get_amenities();
    int amenity_count = cottage->get_amenity_count();

    double amenities_income = 0;
    for (int i = 0; i < amenity_count; ++i) {
        amenities_income += amenities[i]->getPrice();
    }
    total_income += amenities_income;

    cout << "[Cottage " << cottage_id << " Amenity Income] Amenities Income: " << amenities_income << endl;
}

void Finance::calculate_amenity_expenses(Village& village) {
    Amenity** amenities = village.get_amenities();
    int amenity_count = village.get_amenity_count();

    double amenity_expenses = 0;
    for (int i = 0; i < amenity_count; ++i) {
        amenity_expenses += amenities[i]->getPrice();
    }
    total_expenses += amenity_expenses;

    cout << "[Village Expenses] Total Amenity Expenses: " << amenity_expenses << endl;
}

void Finance::calculate_cottage_expenses(Cottage* cottage, double utilities, int cottage_id) {
    double amenity_expenses = 0;

    Amenity** amenities = cottage->get_amenities();
    int amenity_count = cottage->get_amenity_count();

    for (int i = 0; i < amenity_count; ++i) {
        amenity_expenses += amenities[i]->getPrice();
    }

    double total_cottage_expenses = utilities + amenity_expenses;
    total_expenses += total_cottage_expenses;

    cout << "[Cottage " << cottage_id << " Expenses] Utilities: " << utilities
        << ", Amenity Expenses: " << amenity_expenses
        << ", Total Expenses: " << total_cottage_expenses << endl;
}

double Finance::calculate_net_profit() const {
    return total_income - total_expenses;
}

void Finance::display_statistics() const {
    cout << "\n================= Financial Summary =================\n";
    cout << "Total Income:    " << total_income << endl;
    cout << "Total Expenses:  " << total_expenses << endl;
    cout << "Net Profit:      " << calculate_net_profit() << endl;
    cout << "=====================================================\n";
}
