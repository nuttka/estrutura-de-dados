#include <iostream>
#include <string>

#define MaxTam    150000
#ifndef LIST_H
#define LIST_H

struct Planet{
  int month;
  int timeStay;
  std::string namePlanet;
};

class PlanetList{
  private:
    Planet planets[MaxTam];
    int numberOfPlanets;
    int timeForMonth;

  public:
    PlanetList();
    ~PlanetList();
    void insertPlanet(int timeStay, std::string namePlanet);
    void printList();
    void clearList();
    void changePlaces(Planet *i, Planet *j);
    void timeQuicksort(int left, int right);
    void nameQuicksort(int left, int right);
    void organizeListForMonth();
    int getNumberOfPlanets();
    int getTimeForMonth();
    void setTimeForMonth(int timeForMonth);
    void setNumberOfPlanets(int numberOfPlanets);
};
#endif