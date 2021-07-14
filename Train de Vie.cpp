//Adamska-Shalansaska VI/VII/MMXXI

#include "functions.cpp"

using namespace pe; //namespace person{}
using namespace std; //namespace std{}
using namespace Train; //namespace Train{}

int main()
{
    /*Declarations*/

    train t;
    createTrain(t); //init the train to nullptr.

    wagon w;
    word surname = "";
    int opz = 0;

    do{
       try{
           Sleep(1500); //a bit for see the outputs
           menu(); //display menu
           cin >> opz;
           switch (opz){
                case 1: readStream("passeggers.txt", t); break;
                case 2: printTrain(t); break;
                case 3: cin >> surname;
                        surname = ToLower(surname); //input formatting (to lower)
                        w = research(t, surname);
                        printWagon(w); //print who were found by research function 
                        break;
           }
       }catch(exception& e){ cerr << e.what() << std::endl; }
    } while (opz != 3);

    return 0;
}

