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
    userBill customer;
    // class 1 userInfo
    customer.setUserInformation();

    // class 2 userOrder
    customer.setRoomChoice();
     
    //the possible task list
    int task = 0; // make int task a variable of enum task
    enum task {paint, wallpaper, carpet, tile, woodFloor};

    task = customer.getTaskAssignment();
    customer.setRoomInformation(/* task, roomWidth, roomDepth, roomHeight */);

    //print the information of the user and room
    customer.printJobInformation(/* userName, phoneNumber, userAddress, remodelRoom, task */);

    // class 3 userBill
    //If a wall treatment is to be done, get the wall surface area
    // & calculate (paint + wallpaper) costs
    //assume all four walls of the room are to be redone
    if (task == paint or task == wallpaper)
    {
        //calculate and print the estimates for the wall coverings
        customer.calcWallSurfaceArea(/* roomWidth, roomDepth, roomHeight */);
        customer.printPaintCost();
        customer.printWallPaperCost();  
    }
    
    //if a floor is to be done, get the square footage of the room
    // & calculate (carpet + tile + woodFloor) costs
    if (task == carpet or task == tile or task == woodFloor)
    {
        //calculate and print the estimates for the floor coverings
        customer.calcFloorArea(/* roomWidth, roomDepth */);
        customer.printCarpetCost(/* floorArea */);
        customer.printTileCost(/* floorArea */);
        customer.printWoodFloorCost(/* floorArea */);
    }

    // delete ptr    
    return 0;
}