#include "list.hpp"

PlanetList::PlanetList(){
  this->numberOfPlanets = 0;
}

PlanetList::~PlanetList(){
}

void PlanetList::clearList(){
  for(int i=0; i<this->numberOfPlanets; i++){
    this->planets[i].month = 0;
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
    std::cout << planets[i].namePlanet << " " << planets[i].timeStay << " mes: " << planets[i].month << std::endl;
  }
}

void PlanetList::changePlaces(Planet *i, Planet *j){
  Planet aux = *i;
  *i = *j;
  *j = aux;
}

void PlanetList::timeQuicksort(int left, int right){
  if(left>=right){
    return;
  }
  int pivot;
  int middle = (left+right)/2;

  // pivot median of 3
  if(this->planets[left].timeStay < this->planets[middle].timeStay){
    if(this->planets[middle].timeStay < this->planets[right].timeStay){
      pivot = planets[middle].timeStay;
    }else{
      if(this->planets[left].timeStay < this->planets[right].timeStay){
        pivot = planets[right].timeStay;
      }else{
        pivot = planets[left].timeStay;
      }
    }
  }else{
    if(this->planets[right].timeStay < this->planets[middle].timeStay){
      pivot = planets[middle].timeStay;
    }else{
      if(this->planets[right].timeStay < this->planets[left].timeStay){
        pivot = planets[right].timeStay;
      }else{
        pivot = planets[left].timeStay;
      }
    }
  }

  int i = left, j = right;

  // Partition
  while(i <= j){
    while(this->planets[i].timeStay < pivot){
      i++;
    }
    while(this->planets[j].timeStay > pivot){
      j--;
    }
    if(i <= j){
      this->changePlaces(&this->planets[i], &this->planets[j]);
      i++;
      j--;
    }
  }
  timeQuicksort(left, j);
  timeQuicksort(i, right);
}

void PlanetList::organizeListForMonth(){
  int month = 1;
  int maxMonth = 0;
  for(int i=0; i<this->numberOfPlanets; i++){
    maxMonth += this->planets[i].timeStay;
    if(maxMonth > this->timeForMonth){
      month++;
      maxMonth = this->planets[i].timeStay;
    }
    this->planets[i].month = month;
  }
}

int PlanetList::getNumberOfPlanets(){
  return this->numberOfPlanets;
}

int PlanetList::getTimeForMonth(){
  return this->timeForMonth;
}

void PlanetList::setNumberOfPlanets(int numberOfPlanets){
  this->numberOfPlanets = numberOfPlanets;
}

void PlanetList::setTimeForMonth(int timeForMonth){
  this->timeForMonth = timeForMonth;
}