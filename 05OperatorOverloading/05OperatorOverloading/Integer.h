#pragma once

class Integer {
	int* ptr{};
public:
	Integer();                                     //default constructor
	Integer(int val);                              //parameter constructor
	Integer(const Integer& obj);                   //copy constructor
	Integer(Integer&& obj);                        //move constructor
	Integer& operator=(const Integer& obj);        //copy assignment operator
	Integer& operator=(Integer&& obj);             //move assignment operator

	Integer operator+(const Integer& obj) const;
	Integer operator++(int);
	Integer& operator++();
	bool operator==(const Integer& obj) const;
	void operator()();
	int get_value() const; 
	void set_value(int val);
	~Integer();


};