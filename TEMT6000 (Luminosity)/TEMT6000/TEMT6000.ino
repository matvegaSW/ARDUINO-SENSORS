/*
 * TEMT6000 * luminosity *
float volts = analogRead() * 5.0 / 1024.0;
float amps = volts / 10000.0;  // across 10,000 Ohms
float microamps = amps * 1000000;
float lux = microamps * 2.0;
*/
void recupererlaluminosite() {
	float lux = analogRead(2) * 0.9765625;
}
