const int stepper_pins[] = { 9, 10, 11, 12 };
const int pin_number = 4;
int step_number = 0;

const bool clkw = true;        // turn the motor clockwise*
const bool aclkw = false;      // turn the motor anti-clockwise*
                               // *when the turn shaft is facing up
void setup() 
{
        // initialize output pins
        for(int i = 0; i < 4; ++i)
        {
                pinMode(stepper_pins[i], OUTPUT);
        }
}

void loop() 
{
        step(aclkw);
        delay(20);
}

void step(bool direction)
{
        if(direction)
        {
                write_select_high(stepper_pins, step_number, pin_number);
        }
        else
        {
                write_select_high(stepper_pins, 3 - step_number, pin_number);
        }

        step_number++;
        if(step_number > 3)
        {
                step_number = 0;
        }
}

void write_index_high(const int pins[], const int index, const int size)
{
        for(int i = 0; i < size; ++i)
        {
                digitalWrite(pins[i], ( i == index ? HIGH : LOW));
        }
}
