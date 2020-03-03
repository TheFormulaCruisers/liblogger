#ifndef _LOGGER_H
#define _LOGGER_H

/**
 * @brief Log value types.
 */
typedef enum {
	LOGGER_LOG_SYSTEM,
	LOGGER_LOG_THROTTLE,
	LOGGER_LOG_BRAKE,
	LOGGER_LOG_WHEEL1,
	LOGGER_LOG_WHEEL2,
	LOGGER_LOG_MOTOR_TEMP,
	LOGGER_LOG_FLUID_FLOW,
	LOGGER_LOG_FLUID_TEMP,
	LOGGER_LOG_COUNT
} logger_log_t;

/**
 * @brief Calculate the size of the log
 *
 * Since each log entry is 2 bytes in size, the log size is calculated by
 * multiplying the entry count by 2.
 */
#define LOGGER_LOG_SIZE LOGGER_LOG_COUNT*2

/**
 * @brief Initialize the logger.
 * @param void
 * @return Pointer to the static (readable) buffer.
 */
void *logger_init(void);

/**
 * @brief Write a value to the log.
 * @param type
 * @param value
 * @return void
 */
void logger_log(logger_log_t type, uint16_t value);

/**
 * @brief Rotate the log.
 * @param void
 * @return Pointer to the static (readable) buffer.
 */
void *logger_rotate(void);

#endif // _LOGGER_H