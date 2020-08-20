#include <iostream>
#include <queue>
#include <string>
#include "queuetemplate.h"
#include "Person.h"
#include <array>

using namespace std;


int numberOfEvents = 10;


Queue<Person> event1(10), event2(10), event3(10), event4(10), event5(10),
event6(10), event7(10), event8(10), event9(10), event10(10);

											//  the events in an array 
array<Queue<Person>, 10> eventArray = { event1, event2, event3, event4, event5,  event6, event7, event8, event9, event10 };

											// event names which can be updated. 
array<string, 10> eventNames = { "Event 1", "Event 2", "Event 3", "Event 4", "Event 5",
"Event 6", "Event 7", "Event 8", "Event 9", "Event 10" };



int DisplayMainMenu()							// main menu
{
	int value;
	cout << "\nPlease select one of the following options: \n\n";
	cout << "1. Display all events that have a waiting list and how many people that are in each list\n";
	cout << "2. Select an Event\n";
	cout << "0. Exit Program\n";
	cin >> value;

	return value;
}


void DisplayEventData()
{
													// iterate through each event and output the data
	for (int i = 0; i < numberOfEvents; i++)
	{
		cout << "Size of waiting list for " << eventNames[i] << " is " << eventArray[i].Size() << endl;
	}
}

int DisplayEvents()								// events selection menu
{
	int value;
	cout << "\nPlease select one of the following options: \n\n";
	cout << "1.  " << eventNames[0] << "\n";
	cout << "2.  " << eventNames[1] << "\n";
	cout << "3.  " << eventNames[2] << "\n";
	cout << "4.  " << eventNames[3] << "\n";
	cout << "5.  " << eventNames[4] << "\n";
	cout << "6.  " << eventNames[5] << "\n";
	cout << "7.  " << eventNames[6] << "\n";
	cout << "8.  " << eventNames[7] << "\n";
	cout << "9.  " << eventNames[8] << "\n";
	cout << "10. " << eventNames[9] << "\n";
	cout << "0. Return to previous Menu\n";
	cin >> value;

	return value;
}

int DisplayWaitingListOptions()								// waiting list menu
{
	int value;

	cout << "\nPlease select one of the following options: \n\n";
	cout << "1. Add Person to the waiting list\n";
	cout << "2. Remove the first Person from the waiting list\n";
	cout << "3. Locate a customers position in the waiting list\n";
	cout << "4. Empty all enteries and rename the waiting list\n";
	cout << "0. Return to previous Menu.\n";
	cin >> value;

	return value;
}

void WaitingListMenu()
{
	int waitingListSelection;

	do
	{
		int eventSelection = DisplayEvents();
		waitingListSelection = DisplayWaitingListOptions();

		switch (waitingListSelection)
		{
		case 1:															// Add to queue
		{
			string name, number;
			int peopleToAdd = 0;

			cout << "\nHow many people do you wish to add to the waiting list? \n\n";
			cin >> peopleToAdd;

			for (int i = 0; i < peopleToAdd; i++)
			{
				cout << "Please enter name: \n";
				cin >> name;
				cout << "Please enter tel Number: \n";
				cin >> number;

				Person person(name, number);
				eventArray[eventSelection-1].Add(person);						// adding Person to queue                       
			}
			break;
		}
		case 2:																// Remove from queue
		{
			int peopleToRemove;

			cout << "\nHow many people do you wish to delete from the waiting list?\n\n";
			cin >> peopleToRemove;
			cout << "The following people have been removed from the waiting list\n";

			for (int i = 0; i < peopleToRemove; i++)
			{
				Person person;											// remove Person from queue
				eventArray[eventSelection -1].Remove(person);
				person.printperson();									// print out Person details who was removed  
			}
			break;
		}
		case 3:															// Location position in waiting list
		{
			string name, number;

			cout << "\nPlease enter the Person's name you wish to find in the waiting list\n\n";
			cin >> name;
			cout << "Please enter their Telephone Number\n";
			cin >> number;

			Person personToFind{ name, number };
			int placeInQueue = eventArray[eventSelection -1].Find(personToFind);

			if (placeInQueue != -1)
			{
				cout << "Their place in the waiting list is: " << placeInQueue + 1 << endl;
			}
			else
			{
				cout << "Could not find the person you are looking for in this queue" << endl;
			}

			break;
		}
		case 4:															// Empty the queue
		{
			cout << "\nDeleting the following people from the waiting list as the event has now passed\n\n";
			for (int i = 0; i < numberOfEvents; i++)
			{
				
				Person personToRemove;									// remove people from queue
				if (eventArray[eventSelection -1].Remove(personToRemove))	// only print out if successfully removed someone from the queue
				{
					personToRemove.printperson();
				}
			}

																	// get the new event name
			string newEventName;
			cout << "Enter new event name: \n";
			cin >> newEventName;

																	// update the name
			eventNames[eventSelection -1] = newEventName;

			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "Invalid entry! \a\n" ;				// code to be executed if Menu_main doesn't match any cases

			break;
		}
		}														// end of switch
	} while (waitingListSelection != 0);
}

int main()
{
	int mainSelection;

	do
	{
		mainSelection = DisplayMainMenu();

		switch (mainSelection)
		{
		case 1:
		{
			DisplayEventData();
			break;
		}
		case 2:
		{
			WaitingListMenu();
			break;
		}
		default:
		{
			cout << "Invalid entry! \a\n";
			break;
		}
		}
	} while (mainSelection != 0);

	return 0;
}