#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON_PIN  35

enum BUTTON_STATE
{
    PRESSED = 0,
    RELEASED,
};

enum ButtonEvent
{
    BTN_DOWN = 0,
    BTN_UP, 
    NONE 
};

class Button
{
    private:
        int prev_state;
    public:
        void init();
        int getState();
        ButtonEvent getEvent();
};

#endif