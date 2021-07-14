//Adamska-Shalansaska VI/VII/MMXXI

#include "header-train.h"

/*Structures*/

struct date{
	int dd;
	int mm;
	int yyyy;
};

struct person{
	word surname;
	word name;
	int age;
	word city;
	date departure_date; //date type (dd/mm/yyyy)
};

struct cell {
	wagon info;
	cell* next;
};

/*Auxiliary functions*/

void menu(){
	system("cls"); //clean the I/O console
	std::cout << "1 data insert" << std::endl;
	std::cout << "2 data print" << std::endl;
	std::cout << "3 data search" << std::endl;
}

//from UpperCase to LowerCase
word ToLower(word s){
	for(auto& c : s) c = std::tolower(c);
	return s;
}

/*insert*/

//format the input
bool goodStream(std::ifstream& f, person& p){
	word line = "";

	if(!getline(f, line) || (line == term)) return false;
	else{
		for(unsigned int i = 0; i < line.size(); i++) 
			if(line[i] == ',') line[i] = ' ';
	}

	std::stringstream ss(line);
	ss >> p.surname;
	ss >> p.name;
	ss >> p.age;
	ss >> p.city;
	ss >> p.departure_date.dd;
	ss >> p.departure_date.mm;
	ss >> p.departure_date.yyyy;

	return f.good();
}

//init the trainlist
void Train::createTrain(train& t) { t = nullptr; }

//create a new wagon
train Train::newCell(wagon w) {
	cell* aux = new cell;
	aux->info = w;
	aux->next = nullptr;
	return aux;
}

//create a vector of passeggers
wagon pe::createWagon(std::ifstream& f) {
	wagon w;

	int i = 0;
	while(i < maxSize){
		person g;
		if(goodStream(f, g)) w.push_back(g);
		i++;
	}

	return w;
}

//read from file and create the train
void pe::readStream(const char* filename, train& t) {
	std::ifstream f(filename);

	if (!f.is_open()) throw std::invalid_argument("File not open");
	else {
		train trainaux = nullptr;
		bool esci = false;

		while(!esci){
			wagon w = createWagon(f);
			if (w.size() == 0) esci = true; //when reach the term, the loop will end
			else {
				if (trainaux == nullptr) {
					trainaux = Train::newCell(w);
					t = trainaux;
				}
				else {
					trainaux->next = Train::newCell(w);
					trainaux = trainaux->next;
				}
			}
			w.clear(); //clean the auxwagon for eliminate double inputs
		}
	}
	f.close();
}

/*printing*/

//The train isEmpty?
bool Train::isEmpty(const train& t) { return(t == nullptr); }

//print the wagon
void pe::printWagon(const wagon& w){
	for (unsigned int i = 0; i < w.size(); i++)
		std::cout << "Surname: " << w.at(i).surname << " Name: " << w.at(i).name << " Age: " << w.at(i).age << " City: " << w.at(i).city << " Departure: " << w.at(i).departure_date.dd << "/" << w.at(i).departure_date.mm << "/" << w.at(i).departure_date.yyyy << std::endl;
}

void Train::printTrain(const train& t) {
	if (isEmpty(t)) throw std::invalid_argument("Empty_list");

	int cont = 1;
	train trainaux = t;
	while(trainaux != nullptr){
		std::cout << "Nella " << cont << "* carrozza:" << std::endl;
		pe::printWagon(trainaux->info);
		cont++;
		trainaux = trainaux->next;
	}
}

/*research*/

//is who we searching?
bool pe::contest(const person p, word surname) { return(p.surname == surname); }

wagon Train::research(const train& t, const word surname){
	wagon w;
	train trainaux = t;
	
	while(trainaux != nullptr){
		int i = 0;
		while(i < trainaux->info.size()){
			if(pe::contest(trainaux->info.at(i), surname)) w.push_back(trainaux->info.at(i));
			i++;
		}
		trainaux = trainaux->next;
	}
	return w;
}
