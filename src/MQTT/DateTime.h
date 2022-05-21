#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>
#include <TZ.h>
#include <FS.h>
#include <LittleFS.h>
#include <CertStoreBearSSL.h>

// required for CA certificates
void setDateTime()
{
	// Only the date is needed for validating the certificates.
	configTime(TZ_Europe_Berlin, "pool.ntp.org", "time.nist.gov");

	Serial.print("Waiting for NTP time sync: ");
	time_t now = time(nullptr);
	while (now < 8 * 3600 * 2)
	{
		delay(100);
		Serial.print(".");
		now = time(nullptr);
	}
	Serial.println();

	struct tm timeinfo;
	gmtime_r(&now, &timeinfo);
	Serial.printf("%s %s", tzname[0], asctime(&timeinfo)); // actually NOT an error
}