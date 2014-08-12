/*BigCharNumbers.cpp - Library  for printing in LCD 16x2.
  Created by Rodrigo M. da Maia, July 30, 2014
  Released into the public domain.
*/

#include  "BigCharNumbers.h"

#include "Arduino.h"
#include <LiquidCrystal.h>

//LiquidCrystal &a;

BigCharNumbers::BigCharNumbers(LiquidCrystal *lcd) {
  _lcd = lcd;
  LoadCustomChars();
}

void BigCharNumbers::SetColumn(int startColumn) {
  _startColumn = startColumn;
}

void BigCharNumbers::SetAmountChars(int amount) {
  _amountChars = amount;
}

void BigCharNumbers::PrintNumber(int num) {
    
  //PrintChar(num,_startColumn + 0);
  //PrintChar(num,_startColumn + 4);
  //PrintChar(num,_startColumn + 8);
  
  //PrintChar(num,startColumn + 12);

  int unidade;
  int dezena;
  int centena;
  int milhar;
  if(num < 10) {
    PrintChar(num,_startColumn + 0);
  }
  else if((num > 9) && (num < 100)) {
    dezena = (int) num / 10;
    unidade = (int) num - (dezena * 10);
    PrintChar(dezena,_startColumn + 0);
    PrintChar(unidade,_startColumn + 4);
  }
  else if((num > 99) && (num < 1000)) {
    centena = (int) num / 100;
    dezena = num - (centena * 100);
    dezena = (int) dezena / 10;
    unidade = (int) (num - (centena * 100)) - (dezena * 10);
    PrintChar(centena,_startColumn + 0);
    PrintChar(dezena,_startColumn + 4);
    PrintChar(unidade,_startColumn + 8);
  }
  
}

void BigCharNumbers::PrintNumber(float num) {
}

void BigCharNumbers::PrintNumber(double num){
	PrintNumber((float)num);
}

void BigCharNumbers::PrintChar(int num,int column) {
  switch(num) {
    case 0:
      _lcd->setCursor(column,0);
      _lcd->write((uint8_t)0);
      _lcd->write((uint8_t)1);
      _lcd->write((uint8_t)0);
      _lcd->setCursor(column,1);
      _lcd->write((uint8_t)0);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)0);
      break;
    case 1:
      _lcd->setCursor(column,0);
      _lcd->print(" ");
      _lcd->print(" ");
      _lcd->write((uint8_t)0);
      _lcd->setCursor(column,1);
      _lcd->print(" ");
      _lcd->print(" ");
      _lcd->write((uint8_t)0);
      break;
    case 2:
      _lcd->setCursor(column,0);
      _lcd->write((uint8_t)1);
      _lcd->write((uint8_t)3);
      _lcd->write((uint8_t)0);
      _lcd->setCursor(column,1);
      _lcd->write((uint8_t)0);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)2);
      break;
    case 3:
      _lcd->setCursor(column,0);
      _lcd->write((uint8_t)1);
      _lcd->write((uint8_t)3);
      _lcd->write((uint8_t)0);
      _lcd->setCursor(column,1);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)0);
      break;
    case 4:
      _lcd->setCursor(column,0);
      _lcd->write((uint8_t)0);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)0);
      _lcd->setCursor(column,1);
      _lcd->print(" ");
      _lcd->print(" ");
      _lcd->write((uint8_t)0);
      break;
    case 5:
      _lcd->setCursor(column,0);
      _lcd->write((uint8_t)0);
      _lcd->write((uint8_t)3);
      _lcd->write((uint8_t)1);
      _lcd->setCursor(column,1);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)0);
      break;
    case 6:
      _lcd->setCursor(column,0);
      _lcd->write((uint8_t)0);
      _lcd->write((uint8_t)3);
      _lcd->write((uint8_t)1);
      _lcd->setCursor(column,1);
      _lcd->write((uint8_t)0);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)0);
      break;
    case 7:
      _lcd->setCursor(column,0);
      _lcd->write((uint8_t)1);
      _lcd->write((uint8_t)1);
      _lcd->write((uint8_t)0);
      _lcd->setCursor(column,1);
      _lcd->print(" ");
      _lcd->write((uint8_t)0);
      _lcd->print(" ");
      break;
    case 8:
      _lcd->setCursor(column,0);
      _lcd->write((uint8_t)0);
      _lcd->write((uint8_t)3);
      _lcd->write((uint8_t)0);
      _lcd->setCursor(column,1);
      _lcd->write((uint8_t)0);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)0);
      break;
    case 9:
      _lcd->setCursor(column,0);
      _lcd->write((uint8_t)0);
      _lcd->write((uint8_t)3);
      _lcd->write((uint8_t)0);
      _lcd->setCursor(column,1);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)2);
      _lcd->write((uint8_t)0);
      break;
  }
}

void BigCharNumbers::LoadCustomChars() {
  /*Criando Caracteres Especiais*/
  byte customChar0[8] = {
	0b01111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11110
  };
  
  byte customChar1[8] = {
	0b01111,
	0b11110,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
  };
  
  byte customChar2[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b01111,
	0b11110
  };
  
  byte customChar3[8] = {
	0b01111,
	0b11110,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b01111,
	0b11110
  };
  
  _lcd->createChar(0,customChar0);
  _lcd->createChar(1,customChar1);
  _lcd->createChar(2,customChar2);
  _lcd->createChar(3,customChar3);
}
