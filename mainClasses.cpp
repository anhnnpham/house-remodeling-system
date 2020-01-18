#include "main.hpp"

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
protected:
    string room_;
    int task_;
    float roomWidth_;
    float roomDepth_;
    float roomHeight_;

public:
    string getRoomChoice();
    int getTaskAssignment();
    void getRoomInformation(/* int task, float &roomWidthInput, float &roomDepthInput, float &roomHeightInput */);
    void printJobInformation(/* string userName, string phoneNumber, string userAddress, string remodelRoom, int task */);
    void printTask();
};

string userOrder::getRoomChoice()
{
    cout << "What room are we remodeling?: \n";
    getline(std::cin, room_);
    return room_;
}

int userOrder::getTaskAssignment()
{ //the possible task list
    std::cout << "What job needs to be done?\n";
    std::cout << "0: paint\n";
    std::cout << "1: wallpaper\n";
    std::cout << "2: carpet\n";
    std::cout << "3: tile\n";
    std::cout << "4: wood floor\n";
    cin >> task_;
    return task_;
}

void userOrder::getRoomInformation(/* int task, float &roomWidthInput, float &roomDepthInput, float &roomHeightInput */)
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
    cout << "\nPreparing order for:\n\n" << userName_ << "\n";
    cout << "\t" << phoneNumber_ << "\n";
    cout << "\t" << userAddress_ << "\n";

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
    float totalPaintCost_;
    float totalWallpaperCost_;

    float roomArea;
    float totalCarpetCost;
    float totalTileCost;
    float totalWoodFloorCost;
public:
    float calcWallSurfaceArea(/* float roomWidth, float roomDepth, float roomHeight */);
    void calcPaintCost(float wallSurfaceArea);
    void calcWallPaperCost(float wallSurfaceArea);
    float calcFloorArea(/* float roomWidth, float roomDepth */);
    void calcCarpetCost(float floorArea);
    void calcTileCost(float floorArea);
    void calcWoodFloorCost(float floorArea);
};

float userBill::calcWallSurfaceArea(/* float roomWidth, float roomDepth, float roomHeight */)
{                                          //Calculate the wall surface area. Assume the room is rectangluar
                                           //Assume the two walls opposite each other are the same
    wallWide_ = roomWidth_ * roomHeight_ * 2; //two walls
    wallDeep_ = roomDepth_ * roomHeight_ * 2; //two walls
    return wallWide_ + wallDeep_;
}
void userBill::calcPaintCost(float wallSurfaceArea)
{ //cost estimates are simply surface area times material per sq. foot
    totalPaintCost_ = PAINTCOST * wallSurfaceArea;
    std::cout << "\n\t\tPaint Estimate: " << totalPaintCost_;
}
void userBill::calcWallPaperCost(float wallSurfaceArea)
{ //cost estimates are simply surface area times material per sq. foot
    totalWallpaperCost_ = WALLPAPERCOST * wallSurfaceArea;
    std::cout << "\n\t\tWallpaper Estimate: " << totalWallpaperCost_;
}

float userBill::calcFloorArea(/* float roomWidth, float roomDepth */)
{
    roomArea = roomWidth_ * roomDepth_;
    return roomArea;
}

void userBill::calcCarpetCost(float floorArea)
{ //cost estimates are simply surface area times material per sq. foot
    totalCarpetCost = CARPETCOST * floorArea;
    cout << "\n\t\tCarpet Estimate: " << totalCarpetCost;
}

void userBill::calcTileCost(float floorArea)
{ //cost estimates are simply surface area times material per sq. foot
    totalTileCost = TILECOST * floorArea;
    cout << "\n\t\tTile Estimate: " << totalTileCost;
}

void userBill::calcWoodFloorCost(float floorArea)
{ //cost estimates are simply surface area times material per sq. foot
    totalWoodFloorCost = WOODCOST * floorArea;
    cout << "\n\t\tWood Estimate: " << totalWoodFloorCost;
}

