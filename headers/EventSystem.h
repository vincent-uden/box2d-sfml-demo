#pragma once 
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>

class KeyCode {
public:
    KeyCode();
    KeyCode(int code);
    KeyCode(std::string label);
    ~KeyCode();

    int code;

    std::string label;

    static std::vector<int> keyCodes;
    static std::vector<std::string> keyLabels;
};

namespace Keyboard {
    extern KeyCode A;
    extern KeyCode B;
    extern KeyCode C;
    extern KeyCode D;
    extern KeyCode E;
    extern KeyCode F;
    extern KeyCode G;
    extern KeyCode H;
    extern KeyCode I;
    extern KeyCode J;
    extern KeyCode K;
    extern KeyCode L;
    extern KeyCode M;
    extern KeyCode N;
    extern KeyCode O;
    extern KeyCode P;
    extern KeyCode Q;
    extern KeyCode R;
    extern KeyCode S;
    extern KeyCode T;
    extern KeyCode U;
    extern KeyCode V;
    extern KeyCode W;
    extern KeyCode X;
    extern KeyCode Y;
    extern KeyCode Z;
}

// Abstract
class Event {
public:
    std::string getType();
protected:
    std::string type;
};

// Also abstract
class KeyboardEvent: public Event {
public:
    KeyboardEvent();
    ~KeyboardEvent();
    KeyCode getKeyCode();

protected:
    KeyCode keyCode;
};

class KeyDownEvent: public KeyboardEvent {
public:
    KeyDownEvent();
    ~KeyDownEvent();

protected:
};

class KeyUpEvent: public KeyboardEvent {
public:
    KeyUpEvent();
    ~KeyUpEvent();

protected:
};

class MouseEvent: public Event {
public:
    MouseEvent();
    ~MouseEvent();

    int getButtonCode();
protected:
    int buttonCode;
};

class WindowEvent: public Event {
public:
    WindowEvent();
    ~WindowEvent();
protected:
};

class EventSystem {
public:
    EventSystem();
    ~EventSystem();

    void pushEvent(sf::Event sfEvent);
    std::shared_ptr<Event> popEvent();

private:
    std::string getSfKeyLabel(sf::Keyboard::Key key);

    std::vector<std::shared_ptr<Event>> eventQueue;
};
