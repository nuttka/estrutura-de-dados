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
    int sizeOfName;

  public:
    PlanetList();
    ~PlanetList();
    void insertPlanet(int timeStay, std::string namePlanet);
    void printList();
    void clearList();
    void changePlaces(Planet *i, Planet *j);
    void merge(int left, int middle, int right);
    void mergeSort(int left, int right);
    // void planetsForMonth(int left, int right);
    // void namesForMonth(int left, int right);
    void organizeListForMonth();
    int getNumberOfPlanets();
    int getTimeForMonth();
    void setSizeOfName(int sizeOfName);
    void setTimeForMonth(int timeForMonth);
};
#endif