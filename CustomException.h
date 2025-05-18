#pragma once
#include <exception>
#include <string>
using namespace std;

class CustomException : public exception {
private:
    string message;

public:
    explicit CustomException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

