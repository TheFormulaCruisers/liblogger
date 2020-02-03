#include <avr/io.h>
#include <logger.h>

// ---------------------------------------------------------------------- Types

typedef struct {
	uint16_t *writable;
	uint16_t buffer1[LOGGER_LOG_SIZE];
	uint16_t buffer2[LOGGER_LOG_SIZE];
} buffer_t;

// --------------------------------------------------------------------- Memory

static volatile buffer_t buffer;

// --------------------------------------------------------- External Functions

void *logger_init(void) {
	uint8_t i;

	for (i = 0; i < LOGGER_LOG_SIZE; i++) {
		buffer.buffer1[i] = UINT16_MAX;
		buffer.buffer2[i] = UINT16_MAX;
	}
	
	buffer.writable = (void *)buffer.buffer1;
	return (void *)buffer.buffer2;
}

void logger_log(logger_log_t type, uint16_t value) {
	const uint8_t sreg_msk = SREG & 0x80;

	SREG ^= sreg_msk;
	*(buffer.writable+type) = value;
	SREG |= sreg_msk;
}

void *logger_rotate(void) {

	if (buffer.writable == buffer.buffer1) {
		buffer.writable = (void *)buffer.buffer2;
		return (void *)buffer.buffer1;
	} else {
		buffer.writable = (void *)buffer.buffer1;
		return (void *)buffer.buffer2;
	}
}