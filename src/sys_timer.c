#include "sys_timer.h"
#include <stddef.h>


//! Тип структуры высокоточного таймера.
typedef struct _Sys_Timer {
    TIM_TypeDef* timer; //!< Периферия таймера.
    uint32_t counter; //!< Счётчик переполнений таймера.
} sys_timer_t;

//! Высокоточный таймер.
static sys_timer_t system_timer;

static void sys_timer_priph_init(TIM_TypeDef* TIM)
{
    TIM->CR1 = 0;
    TIM->CR2 = 0;
    TIM->DIER = 0;
    TIM->PSC = SYS_TIMER_PRESCALER - 1;
    TIM->ARR = SYS_TIMER_PERIOD_TICKS - 1;
    TIM->CNT = 0;
    TIM->SR  = 0;
}


void sys_timer_init(TIM_TypeDef* timer)
{
    if(timer == NULL) while(1);
    
    system_timer.timer = timer;
    
    sys_timer_priph_init(timer);
}

void sys_timer_irq_handler(void)
{
    if(system_timer.timer->SR & TIM_SR_UIF){
        system_timer.timer->SR = ~TIM_SR_UIF;
        
        system_timer.counter ++;
    }
}

void sys_timer_irq_set_enabled(bool enabled)
{
    if(enabled){
        system_timer.timer->DIER |= TIM_DIER_UIE;
    }else{
        system_timer.timer->DIER &= ~TIM_DIER_UIE;
    }
}

bool sys_timer_irq_enabled(void)
{
    return system_timer.timer->DIER & TIM_DIER_UIE;
}

void sys_timer_irq_enable(void) {
	system_timer.timer->DIER |= TIM_DIER_UIE;
}

void sys_timer_irq_disable(void) {
	system_timer.timer->DIER &= ~TIM_DIER_UIE;
}

void sys_timer_set_running(bool running)
{
    if(running){
    	sys_timer_start();
    }else{
    	sys_timer_stop();
    }
}

bool sys_timer_running(void)
{
    return system_timer.timer->CR1 & TIM_CR1_CEN;
}

void sys_timer_start(void)
{
    system_timer.timer->CR1 |= TIM_CR1_CEN;
}

void sys_timer_stop(void)
{
    system_timer.timer->CR1 &= ~TIM_CR1_CEN;
}

void sys_timer_reset(void)
{
    system_timer.timer->CNT = 0;
}

__attribute__((noinline))
void sys_timer_value(struct timeval* tv)
{
    if(tv == NULL) return;
    
    // Сохраним флаг разрешения прерывания.
    bool irq_enabled = sys_timer_irq_enabled();
    // Запретим прерывание переполнения.
    sys_timer_irq_disable();
    
    // Считаем значение счётчиков.
    uint32_t cnt_us = system_timer.timer->CNT;
    uint32_t cnt_s = system_timer.counter;
    
    // Защита от переполнения.
    // Повторно считаем счётчик таймера.
    uint32_t cnt_us2 = system_timer.timer->CNT;
    
    // Если прерывание переполнения было разрешено.
    if(irq_enabled){
        // Вновь разрешим прерывание переполнения.
    	sys_timer_irq_enable();
    }
    
    // Если он меньше предыдущего значения - таймер переполнился.
    if(cnt_us2 < cnt_us){
        // Присвоим новое значение.
        cnt_us = cnt_us2;
        // И увеличим счётчик миллисекунд.
        cnt_s ++;
    }
    
    tv->tv_usec = cnt_us;
    tv->tv_sec = cnt_s;
}

void sys_timer_delay(uint32_t sec, uint32_t usec) {
	struct timeval tv_cur;
    struct timeval tv_dt;
    struct timeval tv_end;

    tv_dt.tv_sec = (time_t)sec;
    tv_dt.tv_usec = (suseconds_t)usec;

    sys_timer_value(&tv_cur);
    timeradd(&tv_cur, &tv_dt, &tv_end);

    for(;;){
		if(timercmp(&tv_cur, &tv_end, >=)){
			break;
		}
    	sys_timer_value(&tv_cur);
    }
}

