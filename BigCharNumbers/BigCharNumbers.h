/*BigCharNumbers.h - Library  for printing in LCD 16x2.
  Created by Rodrigo M. da Maia, July 30, 2014
  Released into the public domain.
*/

#ifndef BigCharNumbers_h
#define BigCharNumbers_h

#include "Arduino.h"
#include <LiquidCrystal.h>


class BigCharNumbers
{
  public:
    BigCharNumbers(LiquidCrystal *lcd);
    void SetColumn(int startColumn);
    void SetAmountChars(int amount); //Max.: 5
    void PrintNumber(int num);
    void PrintNumber(float num);
    void PrintNumber(double num);
  private:
    LiquidCrystal* _lcd;
    int _startColumn;
    int _amountChars;
    void LoadCustomChars();
    void PrintChar(int num,int column);
};

#endif
