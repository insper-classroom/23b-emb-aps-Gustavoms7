#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"





/*** Defines ***/

//buzzer//
#define BUZZER_PIO PIOA
#define BUZZER_PIO_ID ID_PIOA
#define BUZZER_PIO_IDX 27
#define BUZZER_PIO_IDX_MASK (1 << BUZZER_PIO_IDX)

//start//
#define START_PIO PIOD
#define START_PIO_ID ID_PIOD
#define START_PIO_IDX 28
#define START_PIO_IDX_MASK (1u << START_PIO_IDX)

//seleção//
#define SELECAO_PIO PIOC
#define SELECAO_PIO_ID ID_PIOC
#define SELECAO_PIO_IDX 31
#define SELECAO_PIO_IDX_MASK (1u << SELECAO_PIO_IDX)

// LED1
#define LED1_PIO PIOA
#define LED1_PIO_ID ID_PIOA
#define LED1_PIO_IDX 0
#define LED1_PIO_IDX_MASK (1u << LED1_PIO_IDX)

/*** notas ***/
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

/*** melody1***/
int melody1[] = {

	//Based on the arrangement at https://www.flutetunes.com/tunes.php?id=169
	//Zelda
	
	NOTE_AS4,-2,  NOTE_F4,8,  NOTE_F4,8,  NOTE_AS4,8,//1
	NOTE_GS4,16,  NOTE_FS4,16,  NOTE_GS4,-2,
	NOTE_AS4,-2,  NOTE_FS4,8,  NOTE_FS4,8,  NOTE_AS4,8,
	NOTE_A4,16,  NOTE_G4,16,  NOTE_A4,-2,
	REST,1,

	NOTE_AS4,4,  NOTE_F4,-4,  NOTE_AS4,8,  NOTE_AS4,16,  NOTE_C5,16, NOTE_D5,16, NOTE_DS5,16,//7
	NOTE_F5,2,  NOTE_F5,8,  NOTE_F5,8,  NOTE_F5,8,  NOTE_FS5,16, NOTE_GS5,16,
	NOTE_AS5,-2,  NOTE_AS5,8,  NOTE_AS5,8,  NOTE_GS5,8,  NOTE_FS5,16,
	NOTE_GS5,-8,  NOTE_FS5,16,  NOTE_F5,2,  NOTE_F5,4,

	NOTE_DS5,-8, NOTE_F5,16, NOTE_FS5,2, NOTE_F5,8, NOTE_DS5,8, //11
	NOTE_CS5,-8, NOTE_DS5,16, NOTE_F5,2, NOTE_DS5,8, NOTE_CS5,8,
	NOTE_C5,-8, NOTE_D5,16, NOTE_E5,2, NOTE_G5,8,
	NOTE_F5,16, NOTE_F4,16, NOTE_F4,16, NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,8, NOTE_F4,16,NOTE_F4,8,

	NOTE_AS4,4,  NOTE_F4,-4,  NOTE_AS4,8,  NOTE_AS4,16,  NOTE_C5,16, NOTE_D5,16, NOTE_DS5,16,//15
	NOTE_F5,2,  NOTE_F5,8,  NOTE_F5,8,  NOTE_F5,8,  NOTE_FS5,16, NOTE_GS5,16,
	NOTE_AS5,-2, NOTE_CS6,4,
	NOTE_C6,4, NOTE_A5,2, NOTE_F5,4,
	NOTE_FS5,-2, NOTE_AS5,4,
	NOTE_A5,4, NOTE_F5,2, NOTE_F5,4,

	NOTE_FS5,-2, NOTE_AS5,4,
	NOTE_A5,4, NOTE_F5,2, NOTE_D5,4,
	NOTE_DS5,-2, NOTE_FS5,4,
	NOTE_F5,4, NOTE_CS5,2, NOTE_AS4,4,
	NOTE_C5,-8, NOTE_D5,16, NOTE_E5,2, NOTE_G5,8,
	NOTE_F5,16, NOTE_F4,16, NOTE_F4,16, NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,16,NOTE_F4,8, NOTE_F4,16,NOTE_F4,8
	
};
/***melody2***/
int melody2[] = {

	// Asa branca - Luiz Gonzaga
	// Score available at https://musescore.com/user/190926/scores/181370

	NOTE_G4,8, NOTE_A4,8, NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_B4,4,
	NOTE_C5,4, NOTE_C5,2, NOTE_G4,8, NOTE_A4,8,
	NOTE_B4,4, NOTE_D5,4, NOTE_D5,4, NOTE_C5,4,

	NOTE_B4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
	NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,
	NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,

	NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
	NOTE_G4,2, REST,8, NOTE_G4,8, NOTE_G4,8, NOTE_A4,8,
	NOTE_B4,4, NOTE_D5,4, REST,8, NOTE_D5,8, NOTE_C5,8, NOTE_B4,8,

	NOTE_G4,4, NOTE_C5,4, REST,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8,
	NOTE_A4,4, NOTE_B4,4, REST,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8,
	NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,

	NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
	NOTE_G4,4, NOTE_F5,8, NOTE_D5,8, NOTE_E5,8, NOTE_C5,8, NOTE_D5,8, NOTE_B4,8,
	NOTE_C5,8, NOTE_A4,8, NOTE_B4,8, NOTE_G4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,8, NOTE_G4,8,
	NOTE_G4,-2, REST,4
	
};


/*** variaveis ***/

volatile flag_start = 0;
volatile flag_selecao = 0;

/*** prototipod ***/
void set_buzzer(void);
void clear_buzzer(void);
void get_startstop(void);
void get_selecao(void);



/*** Funções ***/

void set_buzzer(void) {
	// Define o pino do buzzer como 1 (ligado)
	pio_set(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}


void clear_buzzer(void) {
	// Define o pino do buzzer como 0 (desligado)
	pio_clear(BUZZER_PIO, BUZZER_PIO_IDX_MASK);
}


void get_startstop(void) {
	// Verifica se o botão está pressionado
	if (pio_get(START_PIO, PIO_INPUT, START_PIO_IDX_MASK) == 0)
	{
		flag_start = !flag_start; // Botão pressionado
	}

}


void get_selecao(void) {
	// Verifica se o botão está pressionado
	if (pio_get(SELECAO_PIO, PIO_INPUT, SELECAO_PIO_IDX_MASK) == 0)
	{
		flag_selecao = !flag_selecao; // Botão pressionado
	}
}

void buzer_test(int freq){
					
		set_buzzer();
		delay_us(freq);
		clear_buzzer();
		delay_us(freq);
	
	
	
}

void tone(int freq, int tempo) {
	int tempo_t = (1000000 / freq); // Período do ciclo em microssegundos
	int periodo = (tempo * 1000) / (2 * tempo_t); // Número de ciclos para o tempo especificado

	for (int i = 0; i < periodo; i++) {
		buzer_test(tempo_t);
	}
}


void init(void){
	
	// Inicializa clock
	sysclk_init();

	// Desativa watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	//incializando o clock dos perifericos
	pmc_enable_periph_clk(BUZZER_PIO_ID);
	pmc_enable_periph_clk(START_PIO_ID);
	pmc_enable_periph_clk(SELECAO_PIO_ID);
	pmc_enable_periph_clk(LED1_PIO_ID);
	
	//Entrada e saida
	pio_configure(BUZZER_PIO,PIO_OUTPUT_0,BUZZER_PIO_IDX_MASK, PIO_DEFAULT);
	pio_configure(START_PIO, PIO_INPUT, START_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_configure(SELECAO_PIO, PIO_INPUT, SELECAO_PIO_IDX_MASK, PIO_PULLUP | PIO_DEBOUNCE);
	pio_set_output(LED1_PIO, LED1_PIO_IDX_MASK, 0, 0, 0);
	
	//pull_up e debounce
	pio_pull_up(START_PIO, START_PIO_IDX_MASK, 1);
	pio_pull_up(SELECAO_PIO, SELECAO_PIO, 1);
	pio_set_debounce_filter(BUZZER_PIO,BUZZER_PIO_IDX_MASK,60);
	
	
	//interrupção pino função
	pio_handler_set(START_PIO, START_PIO_ID, START_PIO_IDX_MASK, PIO_IT_EDGE, get_startstop);
	pio_handler_set(SELECAO_PIO, SELECAO_PIO_ID, SELECAO_PIO_IDX_MASK, PIO_IT_EDGE, get_selecao);
	
	//Ativa interrupção e limpa primeira IRQ gerada na ativacao
	pio_enable_interrupt(START_PIO, START_PIO_IDX_MASK);
	pio_get_interrupt_status(START_PIO);
	pio_enable_interrupt(SELECAO_PIO, SELECAO_PIO_IDX_MASK);
	pio_get_interrupt_status(SELECAO_PIO);
	
	
	
	// Configura NVIC para receber interrupcoes do PIO do botao
	// com prioridade 4 (quanto mais próximo de 0 maior)
	NVIC_EnableIRQ(START_PIO_ID);
	NVIC_SetPriority(START_PIO_ID, 4);
	NVIC_EnableIRQ(SELECAO_PIO_ID);
	NVIC_SetPriority(SELECAO_PIO_ID, 4);
	


}




int main (void)
{
	board_init();
	sysclk_init();
	delay_init();
	
	init();

	// Init OLED
	gfx_mono_ssd1306_init();
	
	
	int tempo = 200;
	int thisNote = 0;
	int music = 0;
	/* Insert application code here, after the board has been initialized. */
	while(1) {
		

		int wholenote = (60000 * 4) / tempo;
		int notes = sizeof(melody1) / sizeof(melody1[0]) / 2;
		int noteDuration = 0;
		
		while (flag_start){
			if (music)
				{
					gfx_mono_draw_string("Zelda Theme", 0,16, &sysfont);
				}
			else
				{
					gfx_mono_draw_string("Asa Branca \/", 0,16, &sysfont);
				}
			
			if(flag_selecao)
				{
					thisNote=0;
					flag_selecao=0;
					music = !music;
				}
				
			// duração
			int divider = melody1[thisNote + 1];
			if (divider > 0)
					{
						noteDuration = (wholenote) / divider;
					} 
				else if (divider < 0) 
					{
						noteDuration = (wholenote) / abs(divider);
						noteDuration *= 1.5;
					}
			

			
			// interrupção music tone
			if(music == 0)
				{
					tone(melody2[thisNote], noteDuration);
				}
			else
				{
					tone(melody1[thisNote], noteDuration);
				}
			
			//LED1 piscnado no ritmo da musica
			pio_set(LED1_PIO, LED1_PIO_IDX_MASK); 
			delay_ms(noteDuration / 2); 
			pio_clear(LED1_PIO, LED1_PIO_IDX_MASK); 
			delay_ms(noteDuration / 15);

			
			thisNote += 2;
			
		}

	}
}