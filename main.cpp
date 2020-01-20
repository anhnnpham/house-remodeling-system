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

    customer.setTaskAssignment();
    task = customer.getTaskAssignment();
    customer.setRoomInformation();

    //print the information of the user and room
    customer.printJobInformation();

    // class 3 userBill
    //If a wall treatment is to be done, get the wall surface area
    // & calculate (paint + wallpaper) costs
    //assume all four walls of the room are to be redone
    if (task == paint or task == wallpaper)
    {
        //calculate and print the estimates for the wall coverings
        customer.calcWallSurfaceArea();
        customer.printPaintCost();
        customer.printWallPaperCost();  
    }
    
    //if a floor is to be done, get the square footage of the room
    // & calculate (carpet + tile + woodFloor) costs
    if (task == carpet or task == tile or task == woodFloor)
    {
        //calculate and print the estimates for the floor coverings
        customer.calcFloorArea();
        customer.printCarpetCost();
        customer.printTileCost();
        customer.printWoodFloorCost();
    }

    // delete ptr // if using pointer as object
    return 0;
}