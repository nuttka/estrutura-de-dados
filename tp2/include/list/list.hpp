#include <iostream>
#include <string>
#ifndef LIST_H
#define LIST_H

struct Planet{
  int mounth;
  int timeStay;
  std::string namePlanet;
  Planet *next;
};

class PlanetList{
  private:
    Planet *head;
    Planet *tail;
    int numberOfPlanets;
    int timeForMounth;
    
  public:
    PlanetList();
    ~PlanetList();
    void insertPlanet(int timeStay, std::string namePlanet);
    void removePlanet(std::string namePlanet);
    void printList();
    void clearList();
    Planet* getHead();
    void setTimeForMounth(int timeForMounth);
    int getNumberOfPlanets();
    int getTimeForMounth();
};
#endif