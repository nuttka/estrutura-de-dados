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

    void insertPlanet(int timeStay, std::string namePlanet);
    void printList();
    void organizeListForMonth();
    void merge(int left, int middle, int right);
    void mergeSort(int left, int right);
    void quicksortB(int start, int end);
    void CountingSort(int start, int end, int planets, size_t sizeString);

    int getNumberOfPlanets();
    int getTimeForMonth();
    int getMaxMonth();
    void getLimits(int limits[], int i);
    void setSizeOfName(int sizeOfName);
    void setTimeForMonth(int timeForMonth);
};
#endif