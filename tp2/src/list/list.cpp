#include "list.hpp"

PlanetList::PlanetList(){
  this->numberOfPlanets = 0;
}

PlanetList::~PlanetList(){
}

void PlanetList::clearList(){
  for(int i=0; i<this->numberOfPlanets; i++){
    this->planets[i].mounth = 0;
    this->planets[i].namePlanet = "";
    this->planets[i].timeStay = 0;
  }
  this->numberOfPlanets = 0;
}

void PlanetList::insertPlanet(int timeStay, std::string namePlanet){
  Planet newPlanet;
  newPlanet.timeStay = timeStay;
  newPlanet.namePlanet = namePlanet;

  planets[this->numberOfPlanets] = newPlanet;
  
  this->numberOfPlanets++;
}

void PlanetList::printList(){
  for(int i=0; i<this->numberOfPlanets; i++){
    std::cout << planets[i].namePlanet << " " << planets[i].timeStay << std::endl;
  }
}

int PlanetList::getNumberOfPlanets(){
  return this->numberOfPlanets;
}

int PlanetList::getTimeForMounth(){
  return this->timeForMounth;
}

void PlanetList::setNumberOfPlanets(int numberOfPlanets){
  this->numberOfPlanets = numberOfPlanets;
}

void PlanetList::setTimeForMounth(int timeForMounth){
  this->timeForMounth = timeForMounth;
}