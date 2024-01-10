#include <iostream>

using namespace std;

struct item {
    int id;
    string name;
    float price;
    string category;
    int date;
};
struct buyer {
    int id;
    string name;
    item itemContent;
    int date;
};
typedef item infotypeItem;
typedef buyer infotypeBuyer;

typedef struct itemElement *addressItem;
typedef struct buyerElement *addressBuyer;


struct itemElement {
    infotypeItem content;
    addressItem next;
    addressItem prev;
    addressBuyer mid;
};
struct buyerElement {
    infotypeBuyer content;
    addressBuyer next;
    addressBuyer prev;
};

struct itemList {
    addressItem first;
    addressItem last;
};
struct buyerList {
    addressBuyer first;
    addressBuyer last;
};

void createListItem(itemList &LI);
void createListBuyer(buyerList &LB);
addressBuyer allocateBuyer(infotypeBuyer x);
addressItem allocateItem(infotypeItem x);
void insertFirstBuyer(buyerList &LB, addressBuyer P);
void insertAfterBuyer(buyerList &LB, addressBuyer P);
void insertLastBuyer(buyerList &LB, addressBuyer P);
void deleteFirstBuyer(buyerList &LB, addressBuyer P);
void deleteAfterBuyer(buyerList &LB, addressBuyer P);
void deleteLastBuyer(buyerList &LB, addressBuyer &P);
void insertFirstItem(itemList &LI, addressItem P);
void insertAfterItem(itemList &LI, addressItem P);
void insertLastItem(itemList &LI, addressItem P);
void deleteFirstItem(itemList &LI, addressItem &P);
void deleteAfterItem(itemList &LI, addressItem &P);
void deleteLastItem(itemList &LI, addressItem &P);
void showAllBuyer(buyerList &LB, itemList &LI);
void showAllItem(itemList &LI);
addressItem searchItem(itemList LI, string item);

int main() {
    buyerList LB;
    itemList LI;
    addressItem AI;
    addressBuyer AB;
    createListItem(LI);
    createListBuyer(LB);


   // AB = allocateBuyer(your_buyer_data_here);

    item I;
    buyer B;

    int choice;
    do {

        cout << "================================" << endl;
        cout << "===       Final Project      ===" << endl;
        cout << "===        Programming       ===" << endl;
        cout << "===         Algorithm        ===" << endl;
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
                cout << "Enter Name: ";
                cin >> I.name;
                cout << "Enter Price: ";
                cin >> I.price;
                cout << "Enter Category: ";
                cin >> I.category;
                cout << "Enter Date: ";
                cin >> I.date;
                AI = allocateItem(I);
                insertFirstItem(LI, AI);

            } else if (insertingChoice == 2) {
                cout << "Enter ID: ";
                cin >> I.id;
                cout << "Enter Name: ";
                cin >> I.name;
                cout << "Enter Price: ";
                cin >> I.price;
                cout << "Enter Category: ";
                cin >> I.category;
                cout << "Enter Date: ";
                cin >> I.date;
                AI = allocateItem(I);
                insertAfterItem(LI, AI);
            } else if (insertingChoice == 3) {
                cout << "Enter ID: ";
                cin >> I.id;
                cout << "Enter Name: ";
                cin >> I.name;
                cout << "Enter Price: ";
                cin >> I.price;
                cout << "Enter Category: ";
                cin >> I.category;
                cout << "Enter Date: ";
                cin >> I.date;
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
                cout << "Enter Buyer Date: ";
                cin >> B.date;
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
                cout << "Enter Buyer Date: ";
                cin >> B.date;
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
                cout << "Enter Buyer Date: ";
                cin >> B.date;
                AB = allocateBuyer(B);
                insertLastBuyer(LB, AB);
                AI = searchItem(LI, B.itemContent.name);
                if (AI != NULL) {
                    AI->mid = AB;
                }
            }

            //
            //
            //
        } else if (choice == 5) {
            cout << "===============================" << endl;
            cout << "===        Show Buyer       ===" << endl;
            cout << "===============================" << endl;
            showAllBuyer(LB, LI);

            //
            //
            //
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
            //
            //
            //
        } else if (choice == 0) {
            cout << "Exiting..." << endl;
        }else{
            cout << "Invalid choice, Please try again" << endl;
        }
    } while (choice != 0);
    return 0;
};

void createListItem(itemList &LI) {
    LI.first = NULL;
    LI.last = NULL;
};
void createListBuyer(buyerList &LB) {
    LB.first = NULL;
    LB.last = NULL;
};
addressBuyer allocateBuyer(infotypeBuyer x) {
    addressBuyer Parent = new buyerElement;
    Parent->content.id = x.id;
    Parent->content.name = x.name;
    Parent->content.itemContent= x.itemContent;
    Parent->content.date = x.date;
    Parent->next = NULL;
    Parent->prev = NULL;
    return Parent;
};

addressItem allocateItem(infotypeItem x) {
    addressItem child = new itemElement;
    child->content.id = x.id;
    child->content.name = x.name;
    child->content.price = x.price;
    child->content.category = x.category;
    child->content.date = x.date;
    child->next = NULL;
    child->prev = NULL;
    child->mid = NULL;
    return child;
};

void insertFirstBuyer(buyerList &LB, addressBuyer P) {
    if (LB.first != NULL) {
        P->next = LB.first;
        LB.first->prev = P;
        LB.first = P;
    } else {
        LB.first = P;
        LB.last = P;
    }

};
void insertAfterBuyer(buyerList &LB, addressBuyer P) {
    if (LB.first != NULL) {
        P->next = LB.first->next;
        if (LB.first->next != NULL) {
            LB.first->next->prev = P;
        }
        P->prev = LB.first;
        LB.first->next = P;
        if (P->next == NULL) {
            LB.last = P;
        }
    } else {
        LB.first = P;
        LB.last = P;
    }
}


void insertLastBuyer(buyerList &LB, addressBuyer P) {
    addressBuyer person = LB.first;
    if (LB.first != NULL) {
        if (LB.first == LB.last) {
            person->next = P;
            LB.last = P;
            P->prev = person;
        } else {
            while (person != LB.last) {
                person = person->next;
            }
            person->next = P;
            LB.last = P;
            P->prev = person;
        }
    } else {
        LB.first = P;
        LB.last = P;
    }
}

void deleteFirstBuyer(buyerList &LB, addressBuyer P) {
    if (LB.first != NULL) {
        addressBuyer person = LB.first;
        LB.first = person->next;
        if (LB.first != NULL) {
            LB.first->prev = NULL;
        } else {
            LB.last = NULL; // If the list becomes empty after deletion
        }
        P->content.id = person->content.id;
        delete person;
    }
};
void deleteAfterBuyer(buyerList &LB, addressBuyer P) {
    addressBuyer person = P->next;
    if (P != NULL && P->next != NULL) {
        P->next = person->next;
        if (person->next != NULL) {
            person->next->prev = P;
        } else {
            LB.last = P; // If the last node is deleted
        }
        person->next = NULL;
        person->prev = NULL;
        P->content.id = person->content.id;
        delete person;
    }
};
void deleteLastBuyer(buyerList &LB, addressBuyer &P) {
    addressBuyer person = LB.last;
    if (LB.first != NULL) {

        if (LB.first == LB.last) {
            LB.first = NULL;
            LB.last = NULL;
        } else {
            LB.last = person->prev;
            LB.last->next = NULL;
            person->prev = NULL;
        }
        P->content = person->content;
        delete person;
    }
};

void insertFirstItem(itemList &LI, addressItem P) {
    if (LI.first != NULL) {
        P->next = LI.first;
        LI.first->prev = P;
        LI.first = P;
    } else {
        LI.first = P;
        LI.last = P;
    }
};

void insertAfterItem(itemList &LI, addressItem P) {
    if (LI.first != NULL) {
        P->next = LI.first->next;
        if (LI.first->next != NULL) {
            LI.first->next->prev = P;
        }
        P->prev = LI.first;
        LI.first->next = P;
        if (P->next == NULL) {
            LI.last = P;
        }
    } else {
        LI.first = P;
        LI.last = P;
    }
};

void insertLastItem(itemList &LI, addressItem P) {
    addressItem person = LI.first;
    if (LI.first != NULL) {
	if (LI.first == LI.last) {
	    person->next = P;
	    LI.last = P;
	} else {
	    while (person != LI.last) {
		person = person->next;
	    }
	    person->next = P;
	    LI.last = P;
        }
    } else {
        LI.first = P;
        LI.last = P;
    }
}


void deleteFirstItem(itemList &LI, addressItem &P) {
    if (LI.first != NULL) {
        addressItem person = LI.first;
        LI.first = person->next;
        if (LI.first != NULL) {
            LI.first->prev = NULL;
        } else {
            LI.last = NULL; // If the list becomes empty after deletion
        }
        P->content.id = person->content.id;
        delete person;
    }
}

void deleteAfterItem(itemList &LI, addressItem &P) {
    if (P != NULL && P->next != NULL) {
        addressItem person = P->next;
        P->next = person->next;
        if (person->next != NULL) {
            person->next->prev = P;
        } else {
            LI.last = P; // If the last node is deleted
        }
        person->next = NULL;
        person->prev = NULL;
        P->content.id = person->content.id;
        delete person;
    }
}

void deleteLastItem(itemList &LI, addressItem &P) {
    if (LI.first != NULL) {
        addressItem person = LI.last;
        if (LI.first == LI.last) {
            LI.first = NULL;
            LI.last = NULL;
        } else {
            LI.last = person->prev;
            LI.last->next = NULL;
        }
        P->content.id = person->content.id;
        delete person;
    }
}

void showAllBuyer(buyerList &LB, itemList &LI) {
    addressBuyer person = LB.first;
    addressItem AI;
    while (person != NULL) {
        cout << "ID: ";
        cout << person->content.id << endl;
        cout << "Name: ";
        cout << person->content.name << endl;
        cout << "Item: ";
        cout << person->content.itemContent.name << endl;
        cout << "Date: ";
        cout << person->content.date << endl;
        cout << "Price: ";
        AI = searchItem(LI, person->content.itemContent.name);
        if (AI == NULL) {
            cout << "Item NULL" << endl;
        } else {
            cout << AI->content.price << endl;
        }


        cout << " " << endl;
        person = person->next;

    }
};
void showAllItem(itemList &LI) {
    addressItem person = LI.first;
    while (person != NULL) {
        cout << "ID: ";
        cout << person->content.id << endl;
        cout << "Name: ";
        cout << person->content.name << endl;
        cout << "Price: ";
        cout << person->content.price << endl;
        cout << "Category: ";
        cout << person->content.category << endl;
        cout << "Date: ";
        cout << person->content.date << endl;
        cout << "Buyer: ";
        if (person->mid == NULL) {
            cout << "kosong masseh" << endl;
        } else {
            cout << person->mid->content.name << endl;
        }
        cout << " " << endl;
        person = person->next;
    }
};



addressItem searchItem(itemList LI, string item) {
    addressItem AI = LI.first;
    while (AI != NULL) {
        if (AI->content.name == item) {
            return AI;
        }
        AI = AI->next;
    }
    return NULL;
}




