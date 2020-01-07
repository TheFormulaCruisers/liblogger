#include <avr/io.h>
#include <avr/interrupt.h>
#include <logger.h>

int main(void) {

	logger_memory_t log_mem;
	uint16_t log_val;

	logger_init(&log_mem);
	logger_put(&log_mem, LOGGER_LOG_SYSTEM, 0);
	logger_put(&log_mem, LOGGER_LOG_THROTTLE, 0);

	log_val = logger_get(&log_mem);
	log_val = logger_get(&log_mem);

	logger_put(&log_mem, LOGGER_LOG_SYSTEM, 1);
	logger_put(&log_mem, LOGGER_LOG_THROTTLE, 1);

	log_val = logger_get(&log_mem);
	log_val = logger_get(&log_mem);

	return 0;
}