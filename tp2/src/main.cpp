#include "list.hpp"

void partition();
void quickSortRecur();
void quickSort();
void inputTreatment(PlanetList &myPlanets);


// void partition(PlanetList &myPlanets){
//   Planet* prev = nullptr;
//   Planet* tail = pivot;

//   while(cur != pivot){
//     if(cur->namePlanet < pivot->namePlanet){

//     }
//   }
// }

// void quickSortRecur(){

// }

// void quickSort(){

// }

void inputTreatment(PlanetList &myPlanets){
  int timeForMounth;
  int numberOfPlanets;
  int sizeOfName;

  std::cin >> timeForMounth >> numberOfPlanets >> sizeOfName;

  myPlanets.setTimeForMounth(timeForMounth);

  for(int i=0; i<numberOfPlanets; i++){
    int timeStay;
    std::string namePlanet;

    std::cin >> timeStay >> namePlanet;

    myPlanets.insertPlanet(timeStay, namePlanet);

    std::cin.ignore();
    fflush(stdin);
  }
  std::cout << myPlanets.getTimeForMounth() << " " << myPlanets.getNumberOfPlanets() << std::endl;
  myPlanets.printList();
}


int main(){
  PlanetList myPlanets;
  inputTreatment(myPlanets);
}