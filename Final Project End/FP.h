#ifndef FP_H_INCLUDED
#define FP_H_INCLUDED
#include <iostream>
using namespace std;
struct item {
    int id;
    string name;
    float price;
    string category;
};
struct buyer {
    int id;
    string name;
    item itemContent;
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
#endif // FP_H_INCLUDED
