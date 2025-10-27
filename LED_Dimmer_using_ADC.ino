void setup() 
{
  // put your setup code here, to run once:
  DDRB |= (1<<DDB1);
  
  // Enable the Global Interrupt
  sei();

  // Set Reference to NO AVCC and input to ADC0
  ADMUX &= (~(1<<REFS0)) & (~(1<<REFS1));  // No internal Ref Voltage

  // Set data alignment in data register
  ADMUX &= (~(1<<ADLAR));  // Right Alignment

  // Enable ADC, Set Prescaler
  ADCSRA |= (1<<ADEN) | (1<<ADIE) | (1<<ADATE) | (1<<ADPS2);
  ADCSRA &= (~(1<<ADPS0)) & (~(1<<ADPS1));  // Enable ADC & Set Prescaler = 16
  // Clock of ADC = 16MHz / 16 = 1MHz
  
  // Start the Conversion
  ADCSRA |= (1<<ADSC);

  // Select the Channel
  ADMUX &= (~(1<<MUX0)) & (~(1<<MUX1)) & (~(1<<MUX2)) & (~(1<<MUX3));  // ADC0 Channel
}

void loop() 
{
  // put your main code here, to run repeatedly:
}

// Implement ISR Interrupt Handler
ISR(ADC_vect)
{
  OCR1A = ADC;  // 0-1023;
}
