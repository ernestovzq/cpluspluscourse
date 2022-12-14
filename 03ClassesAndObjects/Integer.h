#pragma once

class Integer {
private:
	int* ptr = new int{ 0 };
public:
	Integer() = default;             //Default Constructor
	Integer(int value);
	Integer(const Integer& obj);     //Copy Constructor
	int get_value()const;
	void set_value(int value);
	void set_value(double) = delete; // Prevent casting
	~Integer();
};

void print(Integer i);
Integer add_integer(int x, int y);