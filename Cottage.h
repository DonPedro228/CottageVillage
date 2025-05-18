#pragma once
#include "Amenity.h"
#include <iostream>
#include <string>
#include "Exception_m.h"
using namespace std;

class Cottage {
private:
	string type;
	Amenity** amenities;
	int amenity_count;
	int amenity_capacity;
	double price;
	int guests;
public:
	Cottage(string type, Amenity* amenity = nullptr, double price = 0, int guests = 0);
	~Cottage();

	
	void add_amenity(Amenity* amenity);
	void display_info() const;


	double getPrice() { return price; }
	string getType() { return type; }

	Amenity** get_amenities() {
		return amenities;
	}

	int get_amenity_count() const {
		return amenity_count;
	}

};