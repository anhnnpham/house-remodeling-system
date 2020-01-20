#include "main.hpp"

class userInfo
{   // base class for user information
protected:
    string _userName;
    string _phoneNumber;
    string _userAddress;

public:
    void setUserInformation();
};

void userInfo::setUserInformation()
{
    cout << "Customer Name: \n";
    getline(cin, _userName);
    cout << "Customer Phone Number: \n";
    getline(cin, _phoneNumber);
    cout << "Customer Address: \n";
    getline(cin, _userAddress);
}

class userOrder : public userInfo
{   // class for users' orders (dimensions, tasks to be done, etc.)
private:
    string _room;
    int _task;
protected:
    float _roomWidth;
    float _roomDepth;
    float _roomHeight;
public:
    void setRoomChoice();
    void setTaskAssignment();
    void setRoomInformation();
    void printJobInformation();
    void printTask();
    int getTaskAssignment()
    {
        return _task;
    }
};

void userOrder::setRoomChoice()
{   // user selects the room to be repaired
    cout << "What room are we remodeling?: \n";
    getline(cin, _room);
}

void userOrder::setTaskAssignment()
{   //the possible task list
    cout << "What job needs to be done?\n";
    cout << "0: paint\n";
    cout << "1: wallpaper\n";
    cout << "2: carpet\n";
    cout << "3: tile\n";
    cout << "4: wood floor\n";
    cin >> _task;
}

void userOrder::setRoomInformation()
{   //all the tasks require the width and depth.
    //wall treatments require the height also
    cout << "What is the room width? \n";
    cin >> _roomWidth;
    cout << "What is the room depth? \n";
    cin >> _roomDepth;
    if (_task == 0 or _task == 1) // if choosing "paint" or "wallpaper", enter also room's height
    {
        cout << "What is the room height? \n";
        cin >> _roomHeight;
    }
}

void userOrder::printJobInformation()
{   //print user information.
    cout << "\nPreparing order for:\n" << _userName << "\n";
    cout << _phoneNumber << "\n";
    cout << _userAddress << "\n";
    printTask();
}

void userOrder::printTask()
{   //depending on which task was selected, print the corresponding descriptive string
    cout << "\tRemodeling the " << _room << " with ";
    switch (_task)
    {
    case 0:
        cout << "paint.";
        break;
    case 1:
        cout << "wallpaper.";
        break;
    case 2:
        cout << "carpet.";
        break;
    case 3:
        cout << "tile.";
        break;
    case 4:
        cout << "wood floor.";
        break;
    default:
        cout << "Invalid task.";
    }
}

class userBill : public userOrder
{   // class to calculate the estimates of all the work 
    // that needs to be done
private:
    float _wallWide;
    float _wallDeep;
    float _wallSurfaceArea;
    float _totalPaintCost;
    float _totalWallpaperCost;

    float _roomArea;
    float _totalCarpetCost;
    float _totalTileCost;
    float _totalWoodFloorCost;

public:
    void calcWallSurfaceArea();
    void printPaintCost();
    void printWallPaperCost();
    void calcFloorArea();
    void printCarpetCost();
    void printTileCost();
    void printWoodFloorCost();
};

void userBill::calcWallSurfaceArea()
{   //Calculate the wall surface area. Assume the room is rectangluar
    //Assume the two walls opposite each other are the same
    _wallWide = _roomWidth * _roomHeight * 2; //two walls
    _wallDeep = _roomDepth * _roomHeight * 2; //two walls
    _wallSurfaceArea = _wallWide + _wallDeep;
}

void userBill::printPaintCost()
{   //cost estimates are simply surface area times material per sq. foot
    _totalPaintCost = PAINTCOST * _wallSurfaceArea;
    cout << "\n\tPaint estimate: €" << _totalPaintCost;
}

void userBill::printWallPaperCost()
{   //cost estimates are simply surface area times material per sq. foot
    _totalWallpaperCost = WALLPAPERCOST * _wallSurfaceArea;
    cout << "\n\tWallpaper estimate: €" << _totalWallpaperCost;
}

void userBill::calcFloorArea()
{
    _roomArea = _roomWidth * _roomDepth;
}

void userBill::printCarpetCost()
{   //cost estimates are simply surface area times material per sq. foot
    _totalCarpetCost = CARPETCOST * _roomArea;
    cout << "\n\tCarpet estimate: €" << _totalCarpetCost;
}

void userBill::printTileCost()
{   //cost estimates are simply surface area times material per sq. foot
    _totalTileCost = TILECOST * _roomArea;
    cout << "\n\tTile estimate: €" << _totalTileCost;
}

void userBill::printWoodFloorCost()
{   //cost estimates are simply surface area times material per sq. foot
    _totalWoodFloorCost = WOODCOST * _roomArea;
    cout << "\n\tWood estimate: €" << _totalWoodFloorCost;
}
