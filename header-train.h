//Adamska-Shalansaska VI/VII/MMXXI
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <exception> //throwing personal exceptions
#include <fstream> //file handling
#include <iostream> //I/O functions
#include <locale> //std::tolower()
#include <string> //string handling
#include <vector> //vector handling
#include <sstream> //std::stringstream
#include <Windows.h> //sleep()

typedef std::string word; //alias for std::string 

const unsigned int maxSize = 11; //Wagons max size
const word term = "-1000"; //when stream read this, it will close

#define TRAIN_H //train type

struct cell; //declaration of train structure
typedef cell* train; //alias for cell*

#define person_H //person type

struct person; //declaration of person structure
typedef std::vector<person> wagon; //alias for std::vector<person>

/*namespace train and it's functions*/

namespace Train{
	void createTrain(train&);
	void printTrain(const train&);

	bool isEmpty(const train&);
	wagon research(const train&, const word);

	train newCell(wagon);
}

/*namespace pe(person) and it's functions*/

namespace pe{
	void readStream(const char*, train&);
	void printWagon(const wagon&);

	wagon createWagon(std::ifstream&);
	bool contest(const person, word);
}

/*Auxiliary functions*/

void menu();

bool goodStream(std::ifstream&, person&);

word ToLower(word);

#endif // !FUNCTIONS_H
