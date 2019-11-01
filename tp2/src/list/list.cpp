#include "list.hpp"

PlanetList::PlanetList(){
  this->head = nullptr;
  this->tail = nullptr;
  this->numberOfPlanets = 0;
}

PlanetList::~PlanetList(){
  Planet* temp;
  while(this->head != nullptr){
    temp = this->head->next;
    delete this->head;
    this->head = temp;
  }
}

void PlanetList::clearList(){
  Planet* temp;
  while(this->head != nullptr){
    temp = this->head->next;
    delete this->head;
    this->head = temp;
  }
  this->head = nullptr;
  this->tail = nullptr;
  this->numberOfPlanets = 0;
}

void PlanetList::insertPlanet(int timeStay, std::string namePlanet){
  Planet *newPlanet = new Planet;
  newPlanet->timeStay = timeStay;
  newPlanet->namePlanet = namePlanet;

  if(this->numberOfPlanets == 0){
    this->head = newPlanet;
    this->tail = newPlanet;
  }else{
    this->tail->next = newPlanet;
    this->tail = newPlanet;
  }
  newPlanet->next = nullptr;
  this->numberOfPlanets++;
}

void PlanetList::removePlanet(std::string namePlanet){
  Planet *aux = this->head;
  // primeiro termo e unico da lista
  if(this->numberOfPlanets == 1){
    delete aux;
    this->head = nullptr;
    this->tail = nullptr;
    this->numberOfPlanets--;
  } // primeiro termo mas n o unico
  else if(aux->namePlanet == namePlanet){
    this->head = aux->next;
    delete aux;
    this->numberOfPlanets--;
  }else{
    // termo do meio
    while(aux->next->next != nullptr){
      if(aux->next->namePlanet == namePlanet){
        Planet *auxNext = aux->next;
        aux->next = auxNext->next;
        delete auxNext;
        this->numberOfPlanets--;
        return;
      }
      aux = aux->next;
    }
    // ultimo termo
    if(aux->next->namePlanet == namePlanet){
      Planet *auxNext = aux->next;
      delete auxNext;
      this->tail = aux;
      aux->next = nullptr;
      this->numberOfPlanets--;
    }
  }
}

void PlanetList::printList(){
  Planet* aux = this->head;
  for(int i=0; i<this->numberOfPlanets; i++){
    std::cout << aux->namePlanet << " " << aux->timeStay << std::endl;
    aux = aux->next;
  }
}

Planet* PlanetList::getHead(){
  return this->head;
}

int PlanetList::getNumberOfPlanets(){
  return this->numberOfPlanets;
}

int PlanetList::getTimeForMounth(){
  return this->timeForMounth;
}

void PlanetList::setTimeForMounth(int timeForMounth){
  this->timeForMounth = timeForMounth;
}