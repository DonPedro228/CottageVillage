#pragma once
#include "CustomException.h"

class BookingException : public CustomException {
public:
    explicit BookingException(const string& msg) : CustomException("Booking Error: " + msg) {}
};

class CottageException : public CustomException {
public:
    explicit CottageException(const string& msg) : CustomException("Cottage Error: " + msg) {}
};

class AmenityException : public CustomException {
public:
    explicit AmenityException(const string& msg) : CustomException("Amenity Error: " + msg) {}
};
