#include "Display/PCD8544Driver.h"

PCD8544Driver::PCD8544Driver(uint8_t sclk, uint8_t sdin, uint8_t dc,
                             uint8_t reset, uint8_t sce)
    : pin_sclk(sclk), pin_sdin(sdin), pin_dc(dc), pin_reset(reset),
      pin_sce(sce) {}

void PCD8544Driver::begin() {
  pinMode(this->pin_sclk, OUTPUT);
  pinMode(this->pin_sdin, OUTPUT);
  pinMode(this->pin_dc, OUTPUT);
  pinMode(this->pin_reset, OUTPUT);
  pinMode(this->pin_sce, OUTPUT);

  digitalWrite(this->pin_reset, HIGH);
  digitalWrite(this->pin_sce, HIGH);
  digitalWrite(this->pin_reset, LOW);
  delay(100);
  digitalWrite(this->pin_reset, HIGH);

  setInstructionSet(extended);
  this->send(command, 0x13);  // set bias

  this->send(command, 0xc2);  // set Vop

  setInstructionSet(basic);
  this->send(command, 0x09);  // all pixels on
}

void PCD8544Driver::setInstructionSet(InstructionSet instructionSet) {
   this->send(command, instructionSet);
}

void PCD8544Driver::send(Datatype type, unsigned char *data, int size) {
  digitalWrite(this->pin_dc, type);

  for (int i = 0; i < size; i++) {
    digitalWrite(this->pin_sce, LOW);
    shiftOut(this->pin_sdin, this->pin_sclk, MSBFIRST, data[i]);
    digitalWrite(this->pin_sce, HIGH);
  }
}

void PCD8544Driver::send(Datatype type, unsigned char data) {
  digitalWrite(this->pin_dc, type);

  digitalWrite(this->pin_sce, LOW);
  shiftOut(this->pin_sdin, this->pin_sclk, MSBFIRST, data);
  digitalWrite(this->pin_sce, HIGH);
}
