#pragma once
class Integer03 {
	int* ptr{};
public:
	Integer03();                                  //default constructor
	Integer03(int value);                         //parameterized constructor
	Integer03(const Integer03& obj);              //copy constructor
	Integer03(Integer03&& obj);                   //move constructor
	Integer03& operator=(const Integer03& obj);   //copy assignment operator
	Integer03& operator=(Integer03&& obj);        //move assignment operator
	~Integer03();                                 //destructor
	int get_value()const;                     
	void set_value(int value);

};