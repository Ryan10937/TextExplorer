#include<vector>
#include<string>
#include<iostream>
#include"spot.h"
#include"city.h"


using namespace std;


city::city(int height, int width, pair<int,int> center){
    cityLayout = new vector<vector<spot*>*>;
    vector<spot*>* tempRow;
    spot* tempSpot;

    for(int i=0;i<height;i++){
        tempRow = new vector<spot*>;
        for(int j=0;j<width;j++){
            tempSpot = new spot(177);
            tempSpot->SetPosition(j,i);
            //tempSpot->SetPosition(make_pair(j,i));
            //add things to spot?
            tempRow->push_back(tempSpot);
        }
        cityLayout->push_back(tempRow);
    }
    //set center
    centerOnMap = center; 

}
city::city(int height, int width, int xCenter, int yCenter){

    city(height, width, make_pair(xCenter, yCenter));

}
void city::AddEntity(entity* player, pair<int, int> playerPosition){

    ((cityLayout->at(playerPosition.second))->at(playerPosition.first))->SetHasPlayer(true);//adjust boolean for potential convieniece
    ((cityLayout->at(playerPosition.second))->at(playerPosition.first))->SetEntity(player);//set entity in spot
    (((cityLayout->at(playerPosition.second))->at(playerPosition.first))->GetEntity())->SetPosition(playerPosition);//set player position

}
void city::AddPerimeterWalls(){
    bool isYZero = false;
    bool isYMax = false;
    bool isXZero = false;
    bool isXMax = false;


    for(int i=0;i<cityLayout->size();i++){//for each row
        for(int j=0;j<(cityLayout->at(i))->size();j++){//for each column

            //if on edges
            isXZero = (((cityLayout->at(i))->at(j))->GetPosition()).first == 0;
            isYZero = (((cityLayout->at(i))->at(j))->GetPosition()).second == 0;
            isXMax = (((cityLayout->at(i))->at(j))->GetPosition()).first == ((cityLayout->at(i))->size())-1;
            isYMax = (((cityLayout->at(i))->at(j))->GetPosition()).second == cityLayout->size()-1;
            //cout << isXZero << isYZero << isXMax << isYMax << endl;
            //cout << (((cityLayout->at(i))->at(j))->GetPosition()).first << (((cityLayout->at(i))->at(j))->GetPosition()).second << endl;
            cout <<"x max is compared to: " << ((cityLayout->at(i))->size())-1<<endl;
            cout <<"x position is: " << (((cityLayout->at(i))->at(j))->GetPosition()).first <<endl;
            cout <<"isXMax is: " << isXMax << endl;
            if(isXZero || isYZero || isXMax || isYMax){
                if(isXMax){
                    cout <<"isXmax is 1 in if statement"<<endl;
                }
                ((cityLayout->at(i))->at(j))->SetDisplayChar(219);//make it a "wall"
            }
        }
    }
}
void city::AddBlocker(pair<int,int> blockerLocations){
    ((cityLayout->at(blockerLocations.second))->at(blockerLocations.first))->SetDisplayChar(219);//make it a "wall" at specified location
}

vector<vector<spot*>*>* city::GetCityLayout(){
    return cityLayout;
}
pair<int,int> city::GetCenterOnMap(){
    return centerOnMap;
}

void city::SetName(string name){
    this->name = name;
}
string city::GetName(){
    return name;
}
//destructor to deconstruct vector-vector-spot