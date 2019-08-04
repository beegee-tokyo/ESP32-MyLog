#include <Arduino.h>
#include <my-log.h>

void setup(void)
{
	Serial.begin(115200);

	Serial.println("Next line will be logged only if log level ERROR is set!");
	myLog_e("Log level is MYLOG_LOG_LEVEL_ERROR");
	Serial.println("Next line will be logged only if log level WARN is set!");
	myLog_w("Log level is MYLOG_LOG_LEVEL_WARN");
	Serial.println("Next line will be logged only if log level INFO is set!");
	myLog_i("Log level is MYLOG_LOG_LEVEL_INFO");
	Serial.println("Next line will be logged only if log level DEBUG is set!");
	myLog_d("Log level is MYLOG_LOG_LEVEL_DEBUG");
	Serial.println("Next line will be logged only if log level VERBOSE is set!");
	myLog_v("Log level is MYLOG_LOG_LEVEL_VERBOSE");
}

void main(void)
{
	// nothing here
}