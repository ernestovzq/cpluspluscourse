#pragma once

/*
* Integer Class that wraps an integer
* Move Semantics Implementation
*/
class Integer02 {
	int* ptr{};
public:
	Integer02();
	Integer02(int value);
	Integer02(const Integer02& obj);  //copy constructor
	Integer02(Integer02&& obj);       //move constructor
	int get_value() const;
	void set_value(int value);
	~Integer02();
};