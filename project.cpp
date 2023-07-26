#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// this function is to check whether a particular index is empty or not
int indexIsEmptyOrNot(vector<int> &parkingSlot, int index, int size)
{
    bool ap = false;
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (index == parkingSlot[mid])
        {
            ap = true;
        }
        if (index > parkingSlot[mid])
        {
            start = mid + 1;
        }
        else //(index < parkingSlot[mid])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ap;
    cout << endl;
}

// this functin will give give all empty space output
void allVacantSpace(const vector<int> &parkingSlot, int size)
{

    cout<<"Following indexes are vacant ";
    for (int i = 0; i < size; i++)
    {
    
        if (parkingSlot[i] >= 0 && parkingSlot[i] <= size - 1)
        {
            cout <<i<<" ";
        }
    }
    cout << endl;
}

// this function will help to park vehicle
void parkVehicle(vector<int> &parkingSlot, int index, int vno,int size)
{
    if ((parkingSlot[index] >= 0 && parkingSlot[index] <= size - 1))
    {
        parkingSlot[index] = vno;
        cout << "Vehicle parked succesfully " << endl;
    }
    else
    {
        cout << "Kindly choose another index" << endl;
    }
    cout << endl;
}

// this function will return all parked vehicle
void allPakredVehicle(vector<int> &parkingSlot, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (parkingSlot[i] > 11)
        {
            cout << "At index " << i << " vehicle no " << parkingSlot[i] << " is parked" << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "No vehicle parked ";
    }

    cout << endl;
}

// this function will exit a vehicle from the parking
void exitVehicle(vector<int> &parkingSlot, int index, int size)
{
    if (parkingSlot[index] >= 0 && parkingSlot[index] <= size - 1)
    {
        cout << "No vehicle is present " << endl;
    }

    else
    {
        parkingSlot[index] = 0;
        cout << "Vehicle has been removed succesfully " << endl;
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{

    cout<<"```Welcome to our parking system````"<<endl;
    vector<int> parkingSlot(12);
    int size = parkingSlot.capacity();

    for (int i = 0; i < size; i++)
    {
        parkingSlot[i] = i;
    }

    int index;
    int choice;
    int vno;
    int opt;
    string svno;
    int vnosize;
    while (1)
    {

        cout << "Enter 1 :- to check a particular index is empty or not.\nEnter 2 :- to park vehicle. \nEnter 3 :- to exit vehicle.\nEnter 4 :- to check all parked vehicle.\nEnter 5 :- to check all available space.\nEnter 6 :- to quit system.\n\nKindly enter prefered option." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter index value to check whether it is empty or not." << endl;
            cin >> index;
            opt = indexIsEmptyOrNot(parkingSlot, index, size);
            if (opt == true)
            {
                cout << "Given index value is empty " << endl;
            }
            else
            {
                cout << "Sorry for inconvinece, entered index value is not empty " << endl;
            }
            cout << endl;
            break;
        case 2:
            cout << "Enter last four digit of your vehicle number " << endl;
            cin >> vno;
            cout << "Enter avalible index number for your parking " << endl;
            cin >> index;
            // svno=vno.str();
            svno = to_string(vno);
            vnosize = svno.size();

            if ((index >= 0 && index <= 11) && (vnosize == 4))
            {
                parkVehicle(parkingSlot, index, vno,size);
            }
            else
            {
                cout << "Kindly enter correct index and vehicle number." << endl;
            }
            cout << endl;
            break;

        case 3:
            cout << "Enter your index number to exit your vehicle " << endl;
            cin >> index;
            exitVehicle(parkingSlot, index, size);
            break;

        case 4:;
            allPakredVehicle(parkingSlot, size);
            cout << endl;
            break;

        case 5:
            allVacantSpace(parkingSlot, size);
            cout << endl;
            break;

        default:
            cout << "Choose right option " << endl;
            break;
        case 6:
            cout << "Hope you enjoyed our service. " << endl;
            cout << endl;
            return 0;
            break;
        }
    }
}
