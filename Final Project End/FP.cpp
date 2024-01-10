#include "FP.h"
#include <iostream>
using namespace std;
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
        cout << "Customer ID: ";
        cout << person->content.id << endl;
        cout << "Name: ";
        cout << person->content.name << endl;
        cout << "Item: ";
        cout << person->content.itemContent.name << endl;
        cout << "Price: ";
        AI = searchItem(LI, person->content.itemContent.name);
        if (AI == NULL) {
            cout << "Item NULL" << endl;
        } else {
            cout << AI->content.price << endl;
            cout << "Item ID: ";
            cout << AI->content.id << endl;
            cout << "Category: ";
            cout << AI->content.category << endl;
        }


        cout << " " << endl;
        person = person->next;

    }
};
void showAllItem(itemList &LI) {
    addressItem person = LI.first;
    while (person != NULL) {
        cout << "Item ID: ";
        cout << person->content.id << endl;
        cout << "Name: ";
        cout << person->content.name << endl;
        cout << "Price: ";
        cout << person->content.price << endl;
        cout << "Category: ";
        cout << person->content.category << endl;
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
