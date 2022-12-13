#pragma once
//#include <vector>
class Car {
private:			                  // not necessary, private by default
	float fuel{};                     // non-static data member initializer
	float speed{};             
	int passengers{};
	//int* ptr = new int[2]{ 1,2 };   // allocating memory in the declaration
	//std::vector<int> v{ 1,2,3,4 };  // non-static data member initializer
	static int total_cars;

public:
	Car();
	~Car();
	Car(float fuel);
	void fill_fuel(float amount);
	void accelerate();
	void brake();
	void add_passengers(int count);
	void dashboard() const;
	void print_this() const;
	static int get_total_cars();
};