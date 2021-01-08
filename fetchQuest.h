#ifndef FETCH_QUEST_H
#define FETCH_QUEST_H

#include"event.h"
#include"item.h"
#include"entity.h"


using namespace std;

class fetchQuest : public event{

    public:
    //mutators/accessors

    private:
    item* deliveryItem;
    item* reward;
    //vector for dialog tree? linear tree?

};
#endif