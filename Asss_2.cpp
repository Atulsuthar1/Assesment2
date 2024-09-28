#include <iostream>
#include <cmath>  
using namespace std;

const double CostPerHour = 18.50;
const double CostPerMinute = 0.40;
const double CostOfDinner = 20.70;

class Event {
private:
    string eventName;
    string customerFirstName;
    string customerLastName;
    int numberOfGuests;
    int numberOfMinutes;

public: 
    void getEventDetails() {
        cout << "\nEnter the name of the event: ";
        cin>>eventName;

        cout << "\nEnter the customer's first and last name: ";
        cin>>customerFirstName;
        cin>>customerLastName;

        cout << "\nEnter the number of guests: ";
        cin >> numberOfGuests;

        cout << "\nEnter the number of minutes in the event: ";
        cin >> numberOfMinutes;
    } 
void calculateCost() {
        
        int numberOfServers = ceil((double)(numberOfGuests) / 20);
		double cost1 =  (numberOfMinutes / 60.0) * CostPerHour;
		double cost2 =  (numberOfMinutes % 60) * CostPerMinute;
		double costForOneServer = cost1+cost2;  
        double totalFoodCost = numberOfGuests * CostOfDinner;
        double averageCostPerPerson = totalFoodCost / numberOfGuests;
        double totalCost = totalFoodCost + (costForOneServer * numberOfServers);
        double depositAmount = totalCost * 0.25;
  
        cout << "\n\n============Event estimate for : " << customerFirstName << " " << customerLastName << "============\n";
        cout << "Number Of Server: " << numberOfServers << "\n";
        cout << "The Cost for Servers: " << costForOneServer * numberOfServers << "\n";
        cout << "The Cost for Food is: " << totalFoodCost << "\n";
        cout << "Average Cost Per Person: " << averageCostPerPerson << "\n";
        cout << "Total cost is: " << totalCost << "\n";
        cout << "Please deposit a 25% deposit to reserve the event\n";
        cout << "The deposit needed is: " << depositAmount << "\n";
    }
};

int main() {
    cout << "*************Event Management System***************\n";

    Event e1;
    e1.getEventDetails();
    e1.calculateCost();    

    return 0;
}

