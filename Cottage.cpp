#include "Cottage.h"

Cottage::Cottage(string type, Amenity* amenity, double price, int guests)
	: type(type), price(getPrice()), guests(guests), amenity_count(0), amenity_capacity(5) {
	amenities = new Amenity * [amenity_capacity];
	if (type == "Standard") {
		this->price = 100;
	}
	else if (type == "Lux") {
		this->price = 250;
	}
	else {
		cout << "Error Type!" << endl;
		this->price = 0;
	}

	if (amenity) {
		add_amenity(amenity);
	}
}

Cottage::~Cottage() {
	for (int i = 0; i < amenity_count; ++i) {
		delete amenities[i];
	}
	delete[] amenities;
}

void Cottage::add_amenity(Amenity* amenity) {
	if (!amenity) {
		throw CottageException("Cannot add a null amenity.");
	}

	if (amenity_count >= amenity_capacity) {
		amenity_capacity *= 2;
		Amenity** new_amenities = new Amenity * [amenity_capacity];
		for (int i = 0; i < amenity_count; ++i) {
			new_amenities[i] = amenities[i];
		}
		delete[] amenities;
		amenities = new_amenities;
	}
	amenities[amenity_count++] = amenity;
}


void Cottage::display_info() const {
	int total_guests = guests;

	cout << endl;
	cout << "Cottage type: " << type << endl;
	cout << "Price: " << price << endl;
	cout << "Count of guests: " << guests << endl;

	cout << "Amenities:" << endl;
	for (int i = 0; i < amenity_count; ++i) {
		cout << "- " << amenities[i]->getName()
			<< ", Extra guest: " << amenities[i]->getExtraGuest()
			<< ", Amenity price: " << amenities[i]->getPrice() << endl;
	}

	for (int i = 0; i < amenity_count; ++i) {
		total_guests += amenities[i]->getExtraGuest();
	}
	cout << "Max guests: " << total_guests << endl;
}

