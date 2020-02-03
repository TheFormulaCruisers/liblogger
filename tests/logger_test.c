#include <avr/io.h>
#include <avr/interrupt.h>
#include <logger.h>

int main(void) {

	uint16_t *log_buffer;
	sei();

	log_buffer = logger_init();

	logger_log(LOGGER_LOG_SYSTEM, 1);
	logger_log(LOGGER_LOG_THROTTLE, 2);
	logger_log(LOGGER_LOG_BRAKE, 4);
	logger_log(LOGGER_LOG_WHEEL1, 8);
	logger_log(LOGGER_LOG_WHEEL2, 16);
	logger_log(LOGGER_LOG_MOTOR_TEMP, 32);
	logger_log(LOGGER_LOG_FLUID_FLOW, 64);
	logger_log(LOGGER_LOG_FLUID_TEMP, 128);

	log_buffer = logger_rotate();

	logger_log(LOGGER_LOG_SYSTEM, 256);
	logger_log(LOGGER_LOG_THROTTLE, 512);
	logger_log(LOGGER_LOG_BRAKE, 1024);
	logger_log(LOGGER_LOG_WHEEL1, 2048);
	logger_log(LOGGER_LOG_WHEEL2, 4096);
	logger_log(LOGGER_LOG_MOTOR_TEMP, 8192);
	logger_log(LOGGER_LOG_FLUID_FLOW, 16384);
	logger_log(LOGGER_LOG_FLUID_TEMP, 32767);

	while(1);
	return 0;
}