#include "list.hpp"

PlanetList::PlanetList(){
  this->numberOfPlanets = 0;
}

PlanetList::~PlanetList(){
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

void PlanetList::merge(int left, int middle, int right){
  int i, j, k;
  int n1 = middle-left + 1; 
  int n2 = right-middle; 
  Planet L[n1], R[n2]; 

  for(i = 0; i < n1; i++){
    L[i] = this->planets[left + i];
  }
  for(j = 0; j < n2; j++){
    R[j] = this->planets[middle + 1+ j];
  }

  i = 0;
  j = 0;
  k = left;

  while(i < n1 && j < n2){
    if(L[i].timeStay <= R[j].timeStay){
      this->planets[k] = L[i];
      i++;
    }else{
      this->planets[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1){ 
    this->planets[k] = L[i]; 
    i++; 
    k++; 
  }
  while(j < n2){ 
    this->planets[k] = R[j]; 
    j++; 
    k++; 
  }
}

void PlanetList::mergeSort(int left, int right){
  if(left < right){
    int middle = left+(right-left)/2;
    mergeSort(left, middle);
    mergeSort(middle+1, right);
    merge(left, middle, right);
  }
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

void PlanetList::quicksortB(){
  size_t k = this->planets[0].namePlanet.size();

  for(size_t digit = k; digit > 0; digit--) {
    CountingSort(digit-1);
  }
}

void PlanetList::CountingSort(size_t sizeString){
  Planet b[this->numberOfPlanets]; 
  int *c = NULL;
  c = new int[257];

  for (int i=0; i<257; i++){
    c[i] = 0;
  }

  for (int j=0; j<this->numberOfPlanets; j++){   
    c[(int)(unsigned char)this->planets[j].namePlanet[sizeString] + 1]++;
  }

  for (int f=1; f<257; f++){
    c[f] += c[f-1];
  }

  for (int r=this->numberOfPlanets-1; r>=0; r--){
    b[c[(int)(unsigned char)this->planets[r].namePlanet[sizeString] + 1] - 1] = this->planets[r];
    c[(int)(unsigned char)this->planets[r].namePlanet[sizeString] + 1]--;
  }

  for (int l=0; l<this->numberOfPlanets; l++){
    this->planets[l] = b[l];
  }
  delete[] c;
}

int PlanetList::getNumberOfPlanets(){
  return this->numberOfPlanets;
}

int PlanetList::getTimeForMonth(){
  return this->timeForMonth;
}

void PlanetList::setSizeOfName(int sizeOfName){
  this->sizeOfName = sizeOfName;
}

void PlanetList::setTimeForMonth(int timeForMonth){
  this->timeForMonth = timeForMonth;
}