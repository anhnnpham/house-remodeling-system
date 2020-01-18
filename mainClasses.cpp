#include "main.hpp"

//Cost of materials for the remodel
const float PAINTCOST = .50;      //per square foot
const float WALLPAPERCOST = 2.00; //per square foot
const float CARPETCOST = 4.00;    //per square foot
const float TILECOST = 5.50;      //per square foot
const float WOODCOST = 6.00;      //per square foot

class userInfo
{
protected:
    string userName_;
    string phoneNumber_;
    string userAddress_;

public:
    void setUserInformation(/* string &userNameInput, string &phoneNumberInput, string &userAddressInput */);
};

void userInfo::setUserInformation(/* string &userNameInput, string &phoneNumberInput, string &userAddressInput */)
{
    cout << "Customer Name: \n";
    getline(std::cin, userName_);
    cout << "Customer Phone Number: \n";
    getline(std::cin, phoneNumber_);
    cout << "Customer Address: \n";
    getline(std::cin, userAddress_);
}

class userOrder : public userInfo
{
private:
    string room_;
    int task_;
protected:
    float roomWidth_;
    float roomDepth_;
    float roomHeight_;
public:
    void setRoomChoice();
    void setTaskAssignment();
    void setRoomInformation(/* int task, float &roomWidthInput, float &roomDepthInput, float &roomHeightInput */);
    void printJobInformation(/* string userName, string phoneNumber, string userAddress, string remodelRoom, int task */);
    void printTask();
    int getTaskAssignment()
    {
        return task_;
    }
};

void userOrder::setRoomChoice()
{
    cout << "What room are we remodeling?: \n";
    getline(std::cin, room_);
}

void userOrder::setTaskAssignment()
{ //the possible task list
    std::cout << "What job needs to be done?\n";
    std::cout << "0: paint\n";
    std::cout << "1: wallpaper\n";
    std::cout << "2: carpet\n";
    std::cout << "3: tile\n";
    std::cout << "4: wood floor\n";
    cin >> task_;
}

void userOrder::setRoomInformation(/* int task, float &roomWidthInput, float &roomDepthInput, float &roomHeightInput */)
{ //all the tasks require the width and depth.
    //wall treatments require the height also
    std::cout << "What is the room width? \n";
    std::cin >> roomWidth_;
    std::cout << "What is the room depth? \n";
    std::cin >> roomDepth_;
    if (task_ == 0 or task_ == 1)
    {
        std::cout << "What is the room height? \n";
        std::cin >> roomHeight_;
    }
}

void userOrder::printJobInformation(/* string userName, string phoneNumber, string userAddress, string remodelRoom, int task */)
{ //print user information. This is the only place the
    //remodelRoom string is used
    cout << "\nPreparing order for:\n"
         << userName_ << "\n";
    cout << phoneNumber_ << "\n";
    cout << userAddress_ << "\n";

    cout << "\tRemodeling the " << room_ << " with";
    printTask();
}

void userOrder::printTask()
{ //depending on which task was selected, print the corresponding string
    switch (task_)
    {
    case 0:
        std::cout << " paint ";
        break;
    case 1:
        std::cout << " wallpaper ";
        break;
    case 2:
        std::cout << " carpet ";
        break;
    case 3:
        std::cout << " tile ";
        break;
    case 4:
        std::cout << " wood floor ";
        break;
    default:
        std::cout << " Ivalid task ";
    }
}

class userBill : public userOrder
{
private:
    float wallWide_;
    float wallDeep_;
    float _wallSurfaceArea;
    float totalPaintCost_;
    float totalWallpaperCost_;

    float _roomArea;
    float _totalCarpetCost;
    float _totalTileCost;
    float _totalWoodFloorCost;

public:
    void setWallSurfaceArea(/* float roomWidth, float roomDepth, float roomHeight */);
    void calcPaintCost(/* float wallSurfaceArea */);
    void calcWallPaperCost(/* float wallSurfaceArea */);
    void setFloorArea(/* float roomWidth, float roomDepth */);
    void calcCarpetCost(/* float floorArea */);
    void calcTileCost(/* float floorArea */);
    void calcWoodFloorCost(/* float floorArea */);
};

void userBill::setWallSurfaceArea(/* float roomWidth, float roomDepth, float roomHeight */)
{                                             //Calculate the wall surface area. Assume the room is rectangluar
                                              //Assume the two walls opposite each other are the same
    wallWide_ = roomWidth_ * roomHeight_ * 2; //two walls
    wallDeep_ = roomDepth_ * roomHeight_ * 2; //two walls
    _wallSurfaceArea = wallWide_ + wallDeep_;
}
void userBill::calcPaintCost(/* float wallSurfaceArea */)
{ //cost estimates are simply surface area times material per sq. foot
    totalPaintCost_ = PAINTCOST * _wallSurfaceArea;
    std::cout << "\n\tPaint Estimate: $" << totalPaintCost_;
}
void userBill::calcWallPaperCost(/* float wallSurfaceArea */)
{ //cost estimates are simply surface area times material per sq. foot
    totalWallpaperCost_ = WALLPAPERCOST * _wallSurfaceArea;
    std::cout << "\n\tWallpaper Estimate: $" << totalWallpaperCost_;
}

void userBill::setFloorArea(/* float roomWidth, float roomDepth */)
{
    _roomArea = roomWidth_ * roomDepth_;
}

void userBill::calcCarpetCost(/* float floorArea */)
{ //cost estimates are simply surface area times material per sq. foot
    _totalCarpetCost = CARPETCOST * _roomArea;
    cout << "\n\tCarpet Estimate: $" << _totalCarpetCost;
}

void userBill::calcTileCost(/* float floorArea */)
{ //cost estimates are simply surface area times material per sq. foot
    _totalTileCost = TILECOST * _roomArea;
    cout << "\n\tTile Estimate: $" << _totalTileCost;
}

void userBill::calcWoodFloorCost(/* float floorArea */)
{ //cost estimates are simply surface area times material per sq. foot
    _totalWoodFloorCost = WOODCOST * _roomArea;
    cout << "\n\tWood Estimate: $" << _totalWoodFloorCost;
}
