#include <iostream>
#include <string>

#define MaxTam    150000
#ifndef LIST_H
#define LIST_H

struct Planet{
  int mounth;
  int timeStay;
  std::string namePlanet;
};

class PlanetList{
  private:
    Planet planets[MaxTam];
    int numberOfPlanets;
    int timeForMounth;

  public:
    PlanetList();
    ~PlanetList();
    void insertPlanet(int timeStay, std::string namePlanet);
    void printList();
    void clearList();
    void changePlaces(Planet *i, Planet *j);
    void timeQuicksort(int left, int right);
    void organizeListForMounth();
    int getNumberOfPlanets();
    int getTimeForMounth();
    void setTimeForMounth(int timeForMounth);
    void setNumberOfPlanets(int numberOfPlanets);
};
#endif