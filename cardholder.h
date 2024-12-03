#ifndef CARDHOLDER_H
#define CARDHOLDER_H

#define FILE_NAME "cardholders.txt" // Define the file name here

// Function declarations
void saveCardholder(const char *cardNumber, const char *cardholderName);
void getCardholderName(const char *cardNumber);

#endif // CARDHOLDER_H