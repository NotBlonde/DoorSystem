#ifndef CARDHOLDER_H
#define CARDHOLDER_H

#include "structures.h"

void initializeCardSystem(CardSystem *system);
void freeCardSystem(CardSystem *system);
void loadCardholders(CardSystem *system);
void saveCardholders(CardSystem *system);
void addRemoveAccess(CardSystem *system);
void listAllCards(const CardSystem *system);
void remoteOpenDoor(const CardSystem *system);
void fakeCardScan(const CardSystem *system, const char *cardNumber, const char *cardHolderName);

#endif // CARDHOLDER_H
