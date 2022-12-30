#pragma once
/*
* Integer Class that wraps an integer
* Class without Move Semantics Implementation
*/
class Integer01 {
	int* ptr{};
public:
	Integer01();
	Integer01(int value);
	Integer01(const Integer01& obj);
	int get_value() const;
	void set_value(int value);
	~Integer01();
};