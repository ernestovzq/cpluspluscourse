#pragma once

/*
* Wrapper around the primitive type integer(int)
* -It does not include copy constructor
*/
class Integer0 {
private:
	int* ptr{};
public:
	Integer0();
	Integer0(int value);
	int get_value()const;
	void set_value(int value);
	void test() const;
	~Integer0();
};

void print(Integer0 i);
Integer0 add_integer0(int x, int y);