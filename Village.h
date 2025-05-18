#pragma once
#include <iostream>
#include "Amenity.h"
#include "Cottage.h"
#include "Exception_m.h"
using namespace std;

class Village {
private:
	Amenity** amenities;
	int amenities_count;
	int amenities_capacity;

	Cottage** cottages;
	int cottage_count;
	int cottage_capacity;
public:
	Village();
	~Village();

	void add_amenity(Amenity* amenity);
	void add_cottage(Cottage* cottage);
	
	Amenity** get_amenities() {
		return amenities;
	}

	int get_amenity_count() const {
		return amenities_count;
	}

	void display_info() const;
};