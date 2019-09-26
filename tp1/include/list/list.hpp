#include <iostream>
#ifndef LIST_H
#define LIST_H

struct Flask{
  int volume;
  int operations;
  Flask *next;
};

class FlaskList{
  private:
    Flask *head;
    Flask *tail;
    int numberOfFlasks;
    
  public:
    FlaskList();
    ~FlaskList();
    void insertFlask(int volume, int operations);
    void removeFlask(int volume);
    bool haveFlask(int volume);
    void printList();
    void flaskMeasurement(int volume);
    Flask* getHead();
    int getNumberOfFlasks();
};
#endif