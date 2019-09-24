#include "list.hpp"

FlaskList::FlaskList(){
  this->head = nullptr;
  this->tail = nullptr;
  this->numberOfFlasks = 0;
}

FlaskList::~FlaskList(){

}

void FlaskList::insertFlask(int volume){
  Flask *newFlask = new Flask;
  newFlask->volume = volume;

  if(this->numberOfFlasks == 0){
    this->head = newFlask;
    this->tail = newFlask;
  }else{
    this->tail->next = newFlask;
    this->tail = newFlask;
  }
  newFlask->next = nullptr;
  this->numberOfFlasks++;
}

void FlaskList::removeFlask(int volume){
  Flask *aux = this->head;
  // primeiro termo
  if(aux->volume == volume){
    delete this->head;
    this->head = aux->next;
    delete aux;
    this->numberOfFlasks--;
  }else{
    Flask *auxNext = aux->next;
    // termo do meio
    while(auxNext != nullptr){
      if(auxNext->volume == volume){
        aux->next = auxNext->next;
        std::cout << "Volume deletado." << std::endl;
        delete auxNext;
        delete aux;
        this->numberOfFlasks--;
        return;
      }
      aux = aux->next;
      auxNext = auxNext->next;
    }
    // ultimo termo
    if(auxNext->volume == volume){
      this->tail = aux;
      std::cout << "Volume deletado." << std::endl;
      delete auxNext;
      delete aux;
      this->numberOfFlasks--;
      return;
    }
    delete auxNext;
  }
  delete aux;
  std::cout << "Este volume não existe." << std::endl;
}

bool FlaskList::haveFlask(int volume){
  Flask *aux = this->head;
  int i;
  for(i=0; i<this->numberOfFlasks; i++){
    if(aux->volume == volume){
      std::cout << "O volume de " << volume << " ml existe." << std::endl;
      delete aux;
      return true;
    }
    aux = aux->next;
  }
  delete aux;
  std::cout << "O volume de " << volume << " ml nao existe." << std::endl;
  return false;
}

void FlaskList::printList(){
  if(this->numberOfFlasks == 0){
    std::cout << "Lista vazia." << std::endl;
  }

  Flask *aux = this->head;
  int i;
  for(i=0; i<this->numberOfFlasks; i++){
    std::cout << aux->volume << " ml" << std::endl;  
    aux = aux->next;
  }
  delete aux;
}
