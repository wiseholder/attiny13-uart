/* Библиотека программной реализации UART для микроконтроллеров ATtiny */
/* Автор: Нагаев Александр, 2015 г. */

#ifndef _UART13_H_
#define _UART13_H_ 1

#include <avr/io.h>
#include <avr/interrupt.h>

/*
*	Ниже настраиваются порты и пины портов которые будут использоваться
*	как передатчик и приемник UART.
*/

#define TXPORT PORTB	// Имя порта для передачи
#define RXPORT PINB		// Имя порта на прием
#define TXDDR DDRB		// Регистр направления порта на передачу
#define RXDDR DDRB		// Регистр направления порта на прием
#define TXD 0			// Номер бита порта для использования на передачу
#define RXD 1			// Номер бита порта для использования на прием

/*
*	Ниже задаются константы, определяющие скорость передачи данных (бодрейт)
*	расчет BAUD_DIV осуществляется следующим образом:
*	BAUD_DIV = (CPU_CLOCK / DIV) / BAUD_RATE
*	где CPU_CLOCK - тактовая частота контроллера, BAUD_RATE - желаемая скорость UART,
*	а DIV - значение делителя частоты таймера, задающееся в регистре TCCR0B.
*	Например, делитель на 8, скорость порта 9600 бод:
*	BAUD_DIV = (9 600 000 / 8) / 9600 = 125 (0x7D).
*/

//#define T_DIV		0x01	// DIV = 1
#define T_DIV		0x02	// DIV = 8
//#define T_DIV		0x03	// DIV = 64
#define BAUD_DIV	0x7D	// Скорость = 9600 бод.

/*
*	Ниже идут объявления глобальных переменных и функций для работы UART
*/

volatile uint16_t txbyte;
volatile uint8_t rxbyte;
volatile uint8_t txbitcount;
volatile uint8_t rxbitcount;

void uart_init();
void uart_send(uint8_t tb);
int16_t uart_recieve(uint8_t* rb);

#endif /* _UART13_H_ */
