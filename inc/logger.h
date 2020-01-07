#ifndef _LOGGER_H
#define _LOGGER_H

/**
 * @brief Log value type.
 */
typedef enum {
	LOGGER_LOG_SYSTEM,
	LOGGER_LOG_THROTTLE,
	LOGGER_LOG_BRAKE,
	LOGGER_LOG_WHEEL1,
	LOGGER_LOG_WHEEL2,
	LOGGER_LOG_MOTOR_TEMP,
	LOGGER_LOG_FLUID_FLOW,
	LOGGER_LOG_FLUID_TEMP
} logger_log_t;

/**
 * @brief Log size.
 */
#define LOGGER_LOGSIZE 8

/**
 * @brief Buffer size.
 */
#define LOGGER_BUFSIZE LOGGER_LOGSIZE*2

/**
 * @brief Memory structure.
 */
typedef struct {
	uint8_t r_pos;
	uint8_t w_pos;
	uint16_t mem[LOGGER_BUFSIZE];
} logger_memory_t;

/**
 * @brief Initialize memory.
 * @param mem
 * @return void
 */
void logger_init(logger_memory_t *mem);

/**
 * @brief Write a value to memory.
 * @param mem
 * @param type
 * @param value
 * @return void
 */
void logger_put(logger_memory_t *mem, logger_log_t type, uint16_t value);

/**
 * @brief Read a value from memory.
 * @param mem
 * @return void
 */
uint16_t logger_get(logger_memory_t *mem);

#endif // _LOGGER_H