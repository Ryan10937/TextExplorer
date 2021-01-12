#ifndef CITY_H
#define CITY_H


#include<vector>
#include<string>
#include"spot.h"
#include"entity.h"

using namespace std;


class city{

    public:

    city(int height, int width, pair<int,int> center);
    city(int height, int width, int xCenter, int yCenter);
    void AddEntity(entity* player, pair<int, int> playerPosition);
    void AddPerimeterWalls();
    void AddBlocker(pair<int,int> blockerLocations);
    vector<vector<spot*>*>* GetCityLayout();
    pair<int,int> GetCenterOnMap();

    private:
    vector<vector<spot*>*>* cityLayout;
    pair<int,int> centerOnMap;



};
#endif