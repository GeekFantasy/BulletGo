#include "button.h"
#include "common.h"


void Button::init()
{
    prev_state = 0;
    pinMode(BUTTON_PIN, INPUT);
}

int Button::getState()
{
    return digitalRead(BUTTON_PIN);
}

ButtonEvent Button::getEvent()
{
    ButtonEvent event = ButtonEvent::NONE;
    int state = digitalRead(BUTTON_PIN);
    
    if(state == 1 && prev_state == 0)
        event = ButtonEvent::BTN_DOWN;
    else if(state == 0 && prev_state == 1)
        event = ButtonEvent::BTN_UP;

    prev_state = state;
    return event;
}