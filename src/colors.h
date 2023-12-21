#pragma once

// Function to convert a sing 0-1 float to a 16-bit RGB value
uint16_t floatToRGB16Bit(float value) {
  // Clamp the input value to the 0-1 range
  if (value < 0.0f) value = 0.0f;
  if (value > 1.0f) value = 1.0f;

  // Convert the 0-1 float to a 0-31 range integer for red
  uint8_t redValue5Bit = (uint8_t)(value * 31.0f);

  // Convert the 0-1 float to a 0-63 range integer for green
  uint8_t greenValue6Bit = (uint8_t)(value * 63.0f);

  // Convert the 0-1 float to a 0-31 range integer for blue
  uint8_t blueValue5Bit = (uint8_t)(value * 31.0f);

  // Combine the values into a single 16-bit RGB value
  uint16_t rgb16Bit = (redValue5Bit << 11) | (greenValue6Bit << 5) | blueValue5Bit;

  return rgb16Bit;
}