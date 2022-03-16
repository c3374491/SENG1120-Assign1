// Student.cpp
// Course: SENG1120
// Coded by: SENG1120 Staff

#include "Student.h"
#include <cstdlib>

// Constructors
Student::Student()
{
	name = "";
	score = 0;
}

Student::Student(string name_, int score_)
{
	name = name_;
	score = score_;	
}

// empty destructor
Student::~Student(){}

// Mutator methods (setters)
void Student::set_name(const string name_) 
{
	name = name_;
}

void Student::set_score(const int score_)
{ 
	score = score_;
}

// Accessor methods (getters)
string Student::get_name() const 
{
	return name;
}
int Student::get_score() const 
{
	return score;
}

// overloaded ostream operator
ostream& operator <<(ostream& out, const Student& value)
{
    out << "(" << value.get_name() << "," << value.get_score() << ") ";
    return out;
} 
