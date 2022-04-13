#include <iostream> // include iostream for cout
#include <string> // include string for person name

enum class color { BROWN, BLOND, BLACK }; // create enum for hair color

class Person
{
  	// initialize name, age, and hair color
	std::string name;
	int age;
	color hair;
public:
  	//constructor with three parameters
	Person(std::string name, int age, color hair)
	{
    	// set each parameter to the appropriate property
		this->name = name;
		this->age = age;
		this->hair = hair;
	}
  
  	// create getters to access private members in other areas
	std::string getName()
	{
		return name;
	}

	int getAge()
	{
		return age;
	}

	color getHair()
	{
		return hair;
	}

  	// create setters to change the private members from other areas
	void setName(std::string name)
	{
		this->name = name;
	}

	void setAge(int age)
	{
		this->age = age;
	}

	void setHair(color hair)
	{
		this->hair = hair;
	}
};

int main()
{
  	// create a new Person object with random attributes
	Person Bob = Person("Robert", 23, color::BROWN);
  	// print his name to the console
	std::cout << Bob.getName();
}
