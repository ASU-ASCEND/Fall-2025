#include <AS7331Sensor.h>
#include <SparkFun_AS7331.h>

/**
 * @brief Construct a new AS7331Sensor (UVA/B/C Sensor) object with default
 * minimum_period of 0 ms
 *
 */
AS7331Sensor::AS7331Sensor(uint8_t i2c_addr) : AS7331Sensor(0, i2c_addr) {}

/**
 * @brief Construct a new AS7331Sensor (UVA/B/C Sensor) object
 *
 * @param minium_period Minimum time to wait between readings in ms
 */
AS7331Sensor::AS7331Sensor(unsigned long minium_period, uint8_t i2c_addr)
    : Sensor("AS7331" + String(i2c_addr & 0b11),
             "UVA" + String(i2c_addr & 0b11) + "(nm),UVB" +
                 String(i2c_addr & 0b11) + "(nm),UVC" +
                 String(i2c_addr & 0b11) + "(nm),",
             3, minium_period) {
  this->i2c_addr = i2c_addr;
}

/**
 * @brief Returns if the sensor can be reached
 *
 * @return true always
 * @return false never
 */
bool AS7331Sensor::verify() {
  STRATOSENSE_I2C.begin();
  return myUVSensor.begin(this->i2c_addr, STRATOSENSE_I2C);
}

/**
 * @brief Reads UV data
 *
 * @return String CSV line - UVA, UVB, UVC,
 */
String AS7331Sensor::readData() {
  myUVSensor.readAllUV();

  uint16_t uva = myUVSensor.getUVA();
  uint16_t uvb = myUVSensor.getUVB();
  uint16_t uvc = myUVSensor.getUVC();

  return String(uva) + "," + String(uvb) + "," + String(uvc) + ",";
}

/**
 * @brief Reads UV data from the sensor and writes it to the packet
 *
 * @param packet The data packet to write to.
 */
void AS7331Sensor::readDataPacket(uint8_t*& packet) {
  myUVSensor.readAllUV();

  uint16_t uva16 = static_cast<uint16_t>(myUVSensor.getUVA());
  uint16_t uvb16 = static_cast<uint16_t>(myUVSensor.getUVB());
  uint16_t uvc16 = static_cast<uint16_t>(myUVSensor.getUVC());

  
    std::copy(reinterpret_cast<uint8_t*>(&uva16),
              reinterpret_cast<uint8_t*>(&uva16) + sizeof(uva16),
              packet);
    packet += sizeof(uva16);

    std::copy(reinterpret_cast<uint8_t*>(&uvb16),
              reinterpret_cast<uint8_t*>(&uvb16) + sizeof(uvb16),
              packet);
    packet += sizeof(uvb16);

    std::copy(reinterpret_cast<uint8_t*>(&uvc16),
              reinterpret_cast<uint8_t*>(&uvc16) + sizeof(uvc16),
              packet);
    packet += sizeof(uvc16);
}
/**
 * @brief Decodes a packet into a CSV string
 *
 * @param packet The packet to decode
 * @return String CSV line - UVA, UVB, UVC,
 */
String AS7331Sensor::decodeToCSV(uint8_t*& packet) {
    uint16_t uva16, uvb16, uvc16;
  std::copy(packet, packet + sizeof(uva16), reinterpret_cast<uint8_t*>(&uva16));
  packet += sizeof(uva16);

  std::copy(packet, packet + sizeof(uvb16), reinterpret_cast<uint8_t*>(&uvb16));
  packet += sizeof(uvb16);

  std::copy(packet, packet + sizeof(uvc16), reinterpret_cast<uint8_t*>(&uvc16));
  packet += sizeof(uvc16);


  return String(uva16) + "," + String(uvb16) + "," + String(uvc16) + ",";
}
