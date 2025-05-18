#include "Village.h"

Village::Village() : amenities_count(0), amenities_capacity(5), cottage_count(0), cottage_capacity(5) {
	amenities = new Amenity * [amenities_capacity];
	cottages = new Cottage * [cottage_capacity];
}

Village::~Village() {
	for (int i = 0; i < amenities_count; ++i) {
		delete amenities[i];
	}
	delete[] amenities;

	for (int i = 0; i < cottage_count; ++i) {
		delete cottages[i];
	}
	delete cottages;
}

void Village::add_amenity(Amenity* amenity) {
	if (!amenity) {
		throw AmenityException("Cannot add a null amenity.");
	}

	if (amenities_count >= amenities_capacity) {
		amenities_capacity *= 2;
		Amenity** new_amenities = new Amenity * [amenities_capacity];
		for (int i = 0; i < amenities_count; ++i) {
			new_amenities[i] = amenities[i];
		}
		delete[] amenities;
		amenities = new_amenities;
	}
	amenities[amenities_count++] = amenity;
}


void Village::add_cottage(Cottage* cottage) {
	if (cottage_count >= cottage_capacity) {
		cottage_capacity *= 2;
		Cottage** new_cottages = new Cottage * [cottage_capacity];
		for (int i = 0; i < cottage_count; ++i) {
			new_cottages[i] = cottages[i];
		}
		delete[] cottages;
		cottages = new_cottages;
	}
	cottages[cottage_count++] = cottage;
}

void Village::display_info() const {
	cout << "Amenities of the village: " << endl;
	cout << endl;
	for (int i = 0; i < amenities_count; ++i) {
		cout << "- " << amenities[i]->getName() << ", Extra guests: " << amenities[i]->getExtraGuest()
			<< ", Price: " << amenities[i]->getPrice() << endl;
	}

	cout << endl;

	cout << "Information about cottages: " << endl;
	cout << endl;
	for (int i = 0; i < cottage_count; ++i) {
		cottages[i]->display_info();
	}
}
