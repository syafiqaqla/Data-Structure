#include <iostream>
#include "FP.h"
using namespace std;
int main() {
    buyerList LB;
    itemList LI;
    addressItem AI;
    addressBuyer AB;
    createListItem(LI);
    createListBuyer(LB);

    item I;
    buyer B;

    int choice;
    do {

        cout << "================================" << endl;
        cout << "===       Final Project      ===" << endl;
        cout << "===       Data Structure     ===" << endl;
        cout << "===     BY Edric X Syafiq    ===" << endl;
        cout << "================================" << endl;
        cout << "" << endl;
        cout << "================================" << endl;
        cout << "=== Store Management System ===" << endl;
        cout << "================================" << endl;
        cout << "" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Remove Item" << endl;
        cout << "3. Show Item " << endl;
        cout << "4. Add Buyer" << endl;
        cout << "5. Show Buyer" << endl;
        cout << "6. Remove Buyer" << endl;
        cout << "0. Exit" << endl;
        cout << "" << endl;
        cout << "Select Choice: ";
        cin >> choice;


        if (choice == 1) {
            int insertingChoice;
            cout << "===============================" << endl;
            cout << "===      Add Item Menu      ===" << endl;
            cout << "===============================" << endl;
            cout << " " << endl;
            cout << "1. insertFirst" << endl;
            cout << "2. insertAfter" << endl;
            cout << "3. insertLast" << endl;
            cout << "Select Choice: ";
            cin >> insertingChoice;
            if (insertingChoice == 1) {
                cout << "Enter ID: ";
                cin >> I.id;
                cout << "Enter Item Name: ";
                cin >> I.name;
                cout << "Enter Price: ";
                cin >> I.price;
                cout << "Enter Category: ";
                cin >> I.category;
                AI = allocateItem(I);
                insertFirstItem(LI, AI);

            } else if (insertingChoice == 2) {
                cout << "Enter ID: ";
                cin >> I.id;
                cout << "Enter Item Name: ";
                cin >> I.name;
                cout << "Enter Price: ";
                cin >> I.price;
                cout << "Enter Category: ";
                cin >> I.category;
                AI = allocateItem(I);
                insertAfterItem(LI, AI);
            } else if (insertingChoice == 3) {
                cout << "Enter ID: ";
                cin >> I.id;
                cout << "Enter Item Name: ";
                cin >> I.name;
                cout << "Enter Price: ";
                cin >> I.price;
                cout << "Enter Category: ";
                cin >> I.category;
                AI = allocateItem(I);
                insertLastItem(LI, AI);
            }

        } else if (choice == 2) {
            cout << "===============================" << endl;
            cout << "===    Remove Item Menu     ===" << endl;
            cout << "===============================" << endl;
            cout << " " << endl;
            cout << "1. deleteFirst" << endl;
            cout << "2. deletetAfter" << endl;
            cout << "3. deleteLast" << endl;
            cout << "Select Choice: ";
            int insertingChoice2;
            cin >> insertingChoice2;
            if (insertingChoice2 == 1) {
                deleteFirstItem(LI, AI);
            } else if (insertingChoice2 == 2) {
                deleteAfterItem(LI, AI);
            } else if (insertingChoice2 == 3) {
                deleteLastItem(LI, AI);
            }
        } else if (choice == 3) {
            cout << "===============================" << endl;
            cout << "===     Show Item Menu      ===" << endl;
            cout << "===============================" << endl;
            showAllItem(LI);
            //
            //
            //A
        } else if (choice == 4) {
            int insertingChoice5;
            cout << "===============================" << endl;
            cout << "===        Add Buyer        ===" << endl;
            cout << "===============================" << endl;
            cout << " " << endl;
            cout << "1. insertFirst" << endl;
            cout << "2. insertAfter" << endl;
            cout << "3. insertLast" << endl;
            cout << "Select Choice: ";
            cin >> insertingChoice5;
            if (insertingChoice5 == 1) {
                cout << "Enter Buyer ID: ";
                cin >> B.id;
                cout << "Enter Buyer Name: ";
                cin >> B.name;
                cout << "Enter Buyer Item: ";
                cin >> B.itemContent.name;
                AB = allocateBuyer(B);
                insertFirstBuyer(LB, AB);
                AI = searchItem(LI, B.itemContent.name);
                if (AI != NULL) {
                    AI->mid = AB;
                }
            } else if (insertingChoice5 == 2) {
                cout << "Enter Buyer ID: ";
                cin >> B.id;
                cout << "Enter Buyer Name: ";
                cin >> B.name;
                cout << "Enter Buyer Item: ";
                cin >> B.itemContent.name;
                AB = allocateBuyer(B);
                insertAfterBuyer(LB, AB);
                AI = searchItem(LI, B.itemContent.name);
                if (AI != NULL) {
                    AI->mid = AB;
                }
            } else if (insertingChoice5 == 3) {
                cout << "Enter Buyer ID: ";
                cin >> B.id;
                cout << "Enter Buyer Name: ";
                cin >> B.name;
                cout << "Enter Buyer Item: ";
                cin >> B.itemContent.name;
                AB = allocateBuyer(B);
                insertLastBuyer(LB, AB);
                AI = searchItem(LI, B.itemContent.name);
                if (AI != NULL) {
                    AI->mid = AB;
                }
            }
        } else if (choice == 5) {
            cout << "===============================" << endl;
            cout << "===        Show Buyer       ===" << endl;
            cout << "===============================" << endl;
            showAllBuyer(LB, LI);
        } else if (choice == 6) {
            cout << "===============================" << endl;
            cout << "===      Remove Buyer       ===" << endl;
            cout << "===============================" << endl;
            int insertingChoice7;
            cout << " " << endl;
            cout << "1. deleteFirst" << endl;
            cout << "2. deletetAfter" << endl;
            cout << "3. deleteLast" << endl;
            cout << "Select Choice: ";
            cin >> insertingChoice7;
            if (insertingChoice7 == 1) {
                deleteFirstBuyer(LB, AB);
            } else if (insertingChoice7 == 2) {
                deleteAfterBuyer(LB, AB);
            } else if (insertingChoice7 == 3) {
                deleteLastBuyer(LB, AB);
            }
        } else if (choice == 0) {
            cout << "Exiting..." << endl;
        }else{
            cout << "Invalid choice, Please try again" << endl;
        }
    } while (choice != 0);
    return 0;
};
