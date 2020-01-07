#ifndef _LOGGER_H
#define _LOGGER_H

/**
 * @brief
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
 * @brief
 */
#define LOGGER_LOGSIZE 8

/**
 * @brief
 */
#define LOGGER_BUFSIZE LOGGER_LOGSIZE*2

/**
 * @brief
 */
typedef struct {
	uint8_t r_pos;
	uint8_t w_pos;
	uint16_t mem[LOGGER_BUFSIZE];
} logger_memory_t;

/**
 * @brief
 * @param mem
 * @return void
 */
void logger_init(logger_memory_t *mem);

/**
 * @brief
 * @param mem
 * @param type
 * @param value
 * @return void
 */
void logger_put(logger_memory_t *mem, logger_log_t type, uint16_t value);

#endif // _LOGGER_H