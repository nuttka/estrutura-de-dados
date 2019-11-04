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


void PlanetList::merge(int left, int middle, int right){
  int i, j, k;
  int n1 = middle-left + 1; 
  int n2 = right-middle; 

  /* create temp arrays */
  Planet L[n1], R[n2]; 

  /* Copy data to temp arrays L[] and R[] */
  for(i = 0; i < n1; i++){
    L[i] = this->planets[left + i];
  }
  for(j = 0; j < n2; j++){
    R[j] = this->planets[middle + 1+ j]; 
  }
  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray 
  j = 0; // Initial index of second subarray 
  k = left; // Initial index of merged subarray 
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

  /* Copy the remaining elements of L[], if there 
      are any */
  while(i < n1){ 
    this->planets[k] = L[i]; 
    i++; 
    k++; 
  } 

  /* Copy the remaining elements of R[], if there 
      are any */
  while(j < n2){ 
    this->planets[k] = R[j]; 
    j++; 
    k++; 
  }
}

void PlanetList::mergeSort(int left, int right){
  if(left < right){ 
    // Same as (l+r)/2, but avoids overflow for 
    // large l and h 
    int middle = left+(right-left)/2; 

    // Sort first and second halves 
    mergeSort(left, middle); 
    mergeSort(middle+1, right); 

    merge(left, middle, right); 
  } 
}

// void PlanetList::planetsForMonth(int left, int right){
//   if(left>=right){
//     return;
//   }
//   int pivot;
//   int middle = (left+right)/2;

//   // pivot median of 3
//   if(this->planets[left].timeStay < this->planets[middle].timeStay){
//     if(this->planets[middle].timeStay < this->planets[right].timeStay){
//       pivot = planets[middle].timeStay;
//     }else{
//       if(this->planets[left].timeStay < this->planets[right].timeStay){
//         pivot = planets[right].timeStay;
//       }else{
//         pivot = planets[left].timeStay;
//       }
//     }
//   }else{
//     if(this->planets[right].timeStay < this->planets[middle].timeStay){
//       pivot = planets[middle].timeStay;
//     }else{
//       if(this->planets[right].timeStay < this->planets[left].timeStay){
//         pivot = planets[right].timeStay;
//       }else{
//         pivot = planets[left].timeStay;
//       }
//     }
//   }

//   int i = left, j = right;

//   // Partition
//   while(i <= j){
//     while(this->planets[i].timeStay < pivot){
//       i++;
//     }
//     while(this->planets[j].timeStay > pivot){
//       j--;
//     }
//     if(i <= j){
//       this->changePlaces(&this->planets[i], &this->planets[j]);
//       i++;
//       j--;
//     }
//   }
//   planetsForMonth(left, j);
//   planetsForMonth(i, right);
// }

// void PlanetList::namesForMonth(int left, int right){
  
// }

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

void PlanetList::setSizeOfName(int sizeOfName){
  this->sizeOfName = sizeOfName;
}

void PlanetList::setTimeForMonth(int timeForMonth){
  this->timeForMonth = timeForMonth;
}