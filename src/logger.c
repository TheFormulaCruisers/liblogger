#include <stdint.h>
#include <logger.h>

void logger_init(logger_memory_t *mem) {

	int i;
	for (i = 0; i < LOGGER_BUFSIZE; i++) {
		mem->mem[i] = 0x7F;
	}

	mem->r_pos = 0;
	mem->w_pos = 1;
}

void logger_put(logger_memory_t *mem, logger_log_t type, uint16_t value) {

	const uint8_t w_pos = mem->w_pos;
	const uint8_t log_pos1 = type;
	const uint8_t log_pos2 = type + LOGGER_LOGSIZE;

	if (w_pos > log_pos1 && w_pos <= log_pos2) {
		mem->mem[log_pos2] = value;
	} else {
		mem->mem[log_pos1] = value;
	}
}