/*Debug the program so that it executes correctly.
 **This program calculates floor or wall surface areas
 **For the purpose of remodeling estimates. 
 **It asks a user to enter their name, phone, address
 **Then enter the room they wish to remodel
 **The user is asked to select a task
 **then a material. 
 **The program will generate an estimate of 
 **the cost of the project. 
 **
 **The user inputs are in the input.txt file.*/

// #include "main.hpp"
// #include "mainFunctions.cpp"
#include "mainClasses.cpp"

int main()
{
    userBill ptr;
    // userInfo* ptr. new userBill();
    // class 1 userInfo
    ptr.setUserInformation();

    // class 2 userOrder
    ptr.getRoomChoice();
     
    //the possible task list
    int task = 0; // make task as a variable of enum task
    enum task {paint, wallpaper, carpet, tile, woodFloor};

    task = ptr.getTaskAssignment();
    ptr.getRoomInformation(/* task, roomWidth, roomDepth, roomHeight */);

    //print the information of the user and room
    ptr.printJobInformation(/* userName, phoneNumber, userAddress, remodelRoom, task */);

    // class 3 userBill
    float wallSurfaceArea = 0;
    float floorArea = 0;

    //If a wall treatment is to be done, get the wall surface area
    // & calculate (paint + wallpaper) costs
    //assume all four walls of the room are to be redone
    if (task == paint or task == wallpaper)
    {
        //calculate and print the estimates for the wall coverings
        ptr.calcWallSurfaceArea(/* roomWidth, roomDepth, roomHeight */);
        ptr.calcPaintCost();
        ptr.calcWallPaperCost();  
    }
    
    //if a floor is to be done, get the square footage of the room
    // & calculate (carpet + tile + woodFloor) costs
    if (task == carpet or task == tile or task == woodFloor)
    {
        //calculate and print the estimates for the floor coverings
        ptr.calcFloorArea(/* roomWidth, roomDepth */);
        ptr.calcCarpetCost(/* floorArea */);
        ptr.calcTileCost(/* floorArea */);
        ptr.calcWoodFloorCost(/* floorArea */);
    }

    // delete ptr    
    return 0;
}