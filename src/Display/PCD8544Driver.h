#include "Arduino.h"

enum Datatype {
  command = LOW,
  data = HIGH
};

enum InstructionSet {
  basic = 0x20,
  extended = 0x21
};

class PCD8544Driver {
public:
  PCD8544Driver(uint8_t sclk = 3, uint8_t sdin = 4, uint8_t dc = 5, uint8_t reset = 6, uint8_t sce = 7);

  void begin();
  void setCursor(uint8_t column, uint8_t line);
  void setContrast(uint8_t level);

  void send(Datatype type, unsigned char *data, int size);
  void send(Datatype type, unsigned char data);
  void clear();

private:
  void setInstructionSet(InstructionSet instructionSet);

  uint8_t pin_sclk;
  uint8_t pin_sdin;
  uint8_t pin_dc;
  uint8_t pin_reset;
  uint8_t pin_sce;

};
