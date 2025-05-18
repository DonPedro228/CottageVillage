#pragma once
#include <iostream>
#include <iomanip>
#include "Amenity.h"
#include "Cottage.h"
#include "Village.h"
using namespace std;


class Finance {
private:
	double total_income;
	double total_expenses;

public:
    Finance();

    void calculate_cottage_income(Cottage* cottage, int nights, int month, int cottage_id);
    void calculate_amenity_expenses(Village& village);
    void calculate_cottage_expenses(Cottage* cottage, double utilities, int cottage_id);

    double calculate_net_profit() const;

    void display_statistics() const;
};