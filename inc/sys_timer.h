/**
 * @file drive_hires_timer.h Библиотека таймера высокого разрешения привода.
 */

#ifndef DRIVE_HIRES_TIMER_H
#define DRIVE_HIRES_TIMER_H

#include <stm32f4xx.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>



// Параметры таймера.
//! Период таймера в тиках.
#define SYS_TIMER_PERIOD_TICKS 1000000
//! Предделитель таймера.
#define SYS_TIMER_PRESCALER 90



/**
 * Инициализирует высокоточный таймер привода.
 * @param TIM Периферия таймера.
 * @return Код ошибки.
 */
extern void sys_timer_init(TIM_TypeDef* timer);

/**
 * Обработчик прерывания переполнения таймера высокого разрешения.
 */
extern void sys_timer_irq_handler(void);

/**
 * Устанавливает разрешение прерывания переполнения таймера.
 * @param enabled Флаг разрешения прерывания.
 */
extern void sys_timer_irq_set_enabled(bool enabled);

/**
 * Получает разрешение прерывания переполнения таймера.
 * @return Флаг разрешения прерывания.
 */
extern bool sys_timer_irq_enabled(void);

/**
 * Включает прерывание таймера.
 */
extern void sys_timer_irq_enable(void);

/**
 * Выключает прерывание таймера.
 */
extern void sys_timer_irq_disable(void);

/**
 * Получает флаг режима однократного срабатывания.
 * @return Флаг режима однократного срабатывания.
 */
extern bool sys_timer_one_pulse_mode(void);

/**
 * Устанавливает флаг режима однократного срабатывания.
 * @return Флаг режима однократного срабатывания.
 */
extern bool sys_timer_one_pulse_mode(void);

/**
 * Устанавливает флаг работы таймера.
 * @param running Флаг работы таймера.
 */
extern void sys_timer_set_running(bool running);

/**
 * Получает флаг работы таймера.
 * @return Флаг работы таймера.
 */
extern bool sys_timer_running(void);

/**
 * Запускает таймер.
 */
extern void sys_timer_start(void);

/**
 * Останавливает таймер.
 */
extern void sys_timer_stop(void);

/**
 * Сбрасывает счётчик таймера.
 */
extern void sys_timer_reset(void);

/**
 * Получает время работы таймера.
 * Переполняется каждые 4294967296 секунд.
 * @param tv Время.
 */
extern void sys_timer_value(struct timeval* tv);

/**
 * Функция задержки
 * @param sec Время задержки в секундах.
 * @param usec Время задержки в микросекундах.
 */
extern void sys_timer_delay(uint32_t sec, uint32_t usec);

#endif /* DRIVE_HIRES_TIMER_H */

