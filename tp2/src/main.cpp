#include "list.hpp"

void inputTreatment(PlanetList &myPlanets);


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
  // std::cout << std::endl;
  // myPlanets.timeQuicksort(0, numberOfPlanets-1);
  // std::cout << myPlanets.getTimeForMounth() << " " << myPlanets.getNumberOfPlanets() << std::endl;
  // myPlanets.printList();
}


int main(){
  PlanetList myPlanets;
  inputTreatment(myPlanets);
}