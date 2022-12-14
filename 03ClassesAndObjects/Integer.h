#pragma once

class Integer {
private:
	int* ptr{};
public:
	Integer();
	Integer(int value);
	Integer(const Integer& obj);  //Copy Constructor
	int get_value()const;
	void set_value(int value);
	~Integer();
};

void print(Integer i);
Integer add_integer(int x, int y);