#include "list.hpp"

void inputTreatment(PlanetList &myPlanets);


void inputTreatment(PlanetList &myPlanets){
  int timeForMonth;
  int numberOfPlanets;
  int sizeOfName;

  std::cin >> timeForMonth >> numberOfPlanets >> sizeOfName;

  myPlanets.setTimeForMonth(timeForMonth);
  myPlanets.setSizeOfName(sizeOfName);

  for(int i=0; i<numberOfPlanets; i++){
    int timeStay;
    std::string namePlanet;

    std::cin >> timeStay >> namePlanet;

    myPlanets.insertPlanet(timeStay, namePlanet);

    std::cin.ignore();
    fflush(stdin);
  }
  std::cout << std::endl;
  myPlanets.mergeSort(0, numberOfPlanets-1);
  myPlanets.organizeListForMonth();
  myPlanets.quicksortB();
  std::cout << myPlanets.getTimeForMonth() << " " << myPlanets.getNumberOfPlanets() << std::endl;
  myPlanets.printList();
  
}


int main(){
  PlanetList myPlanets;
  inputTreatment(myPlanets);
}