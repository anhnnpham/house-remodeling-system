#pragma once
#ifndef MAIN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

//Cost of materials for the remodel
const float PAINTCOST = .50;      //per square foot
const float WALLPAPERCOST = 2.00; //per square foot
const float CARPETCOST = 4.00;    //per square foot
const float TILECOST = 5.50;      //per square foot
const float WOODCOST = 6.00;      //per square foot

using namespace std;

/* void getUserInformation(string &name, string &number, string &address);
string getRoomChoice();
int getTaskAssignment();
void printTask(int task);
void getRoomInformation(int task, float &roomWidth, float &roomDepth, float &roomHeight);
void printJobInformation(string userName, string phoneNumber, string userAddress, string remodelRoom, int task);
float calcWallSurfaceArea(float roomWidth, float roomDepth, float roomHeight);
float calcPaintCost(float wallSurfaceArea);
float calcWallPaperCost(float wallSurfaceArea);
float calcFloorArea(float roomWidth, float roomDepth);
float calcCarpetCost(float floorArea);
float calcTileCost(float floorArea);
float calcWoodFloorCost(float floorArea); */

class userInfo;
class userOrder;
class userBill;
#endif // MAIN_HPP