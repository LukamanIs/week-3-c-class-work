// program name goes here
// your name goes here
// any example usage or helpful command line arguments go here

#include <iostream>
// Add any other header files here

///////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

int main() {
    std::string itemName, fragile, destination;
    double orderTotal, shippingCost = 0;
    const double FRAGILE_COST = 2.00;

    std::cout << "*******************************************\n";
    std::cout << "ITCS 2530 - Programming Assignment for week #3\n";
    std::cout << "*******************************************\n\n";

    // Input
    std::cout << "Please enter the item name (no spaces)............:";
    std::cin >> itemName;

    std::cout << "Is the item fragile? (y=yes/n=no)..................:";
    std::cin >> fragile;
    std::transform(fragile.begin(), fragile.end(), fragile.begin(), ::toupper);

    // Check for valid input for "fragile" status
    if (fragile != "Y" && fragile != "N") {
        std::cout << "Invalid entry, exiting\n";
        std::cout << "Press any key to continue . . .";
        return 1;
    }

    std::cout << "Please enter your order total......................:";
    std::cin >> orderTotal;

    std::cout << "Please enter destination. (usa/can/aus)............:";
    std::cin >> destination;
    std::transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

    // Check for valid input for "destination"
    if (destination != "USA" && destination != "CAN" && destination != "AUS") {
        std::cout << "Invalid entry, exiting\n";
        std::cout << "Press any key to continue . . .";
        return 1;
    }

    // Shipping cost calculation based on destination and order total
    if (destination == "USA") {
        if (orderTotal <= 50) shippingCost = 6.00;
        else if (orderTotal <= 100) shippingCost = 9.00;
        else if (orderTotal <= 150) shippingCost = 12.00;
        else shippingCost = 0.00;
    }
    else if (destination == "CAN") {
        if (orderTotal <= 50) shippingCost = 8.00;
        else if (orderTotal <= 100) shippingCost = 12.00;
        else if (orderTotal <= 150) shippingCost = 15.00;
        else shippingCost = 0.00;
    }
    else if (destination == "AUS") {
        if (orderTotal <= 50) shippingCost = 10.00;
        else if (orderTotal <= 100) shippingCost = 14.00;
        else if (orderTotal <= 150) shippingCost = 17.00;
        else shippingCost = 0.00;
    }

    // Add fragile cost if applicable
    if (fragile == "Y") shippingCost += FRAGILE_COST;

    double totalCost = orderTotal + shippingCost;

    // Output formatting
    std::cout << "\nYour item is.........................:" << itemName << std::endl;
    std::cout << "Your shipping cost is................:$" << std::fixed << std::setprecision(2) << shippingCost << std::endl;
    std::cout << "You are shipping to..................:" << destination << std::endl;
    std::cout << "Your total shipping costs are........:$" << std::fixed << std::setprecision(2) << totalCost << std::endl;
    std::cout << "------------------------------------Thank You!\n\n";
    std::cout << "Press any key to continue . . .";

    // Write to file
    std::ofstream outFile("Order.txt");
    if (outFile.is_open()) {
        outFile << "*******************************************\n";
        outFile << "ITCS 2530 - Programming Assignment for week #3\n";
        outFile << "*******************************************\n\n";
        outFile << "Your item is.........................:" << itemName << std::endl;
        outFile << "Your shipping cost is................:$" << std::fixed << std::setprecision(2) << shippingCost << std::endl;
        outFile << "You are shipping to..................:" << destination << std::endl;
        outFile << "Your total shipping costs are........:$" << std::fixed << std::setprecision(2) << totalCost << std::endl;
        outFile << "------------------------------------Thank You!\n\n";
        outFile.close();
    }

    return 0;
}
