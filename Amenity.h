#pragma once
#include <string>
#include <iostream>
using namespace std;

class Amenity {
private:
	string name_amenity;
	int extra_guest;
	double price;
public:
	Amenity(string name_amenity, int price, int extra_guest);
	~Amenity();

	string getName() const { return name_amenity; }
	int getExtraGuest() const { return extra_guest; }
	double getPrice() const { return price; }


	void setName(string name) { name = name_amenity; }
	void setExtraGuest(double extra) { extra = extra_guest; }
	void getPrice(double current_price) { current_price = price; }
};