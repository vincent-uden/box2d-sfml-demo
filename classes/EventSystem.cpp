#include "../headers/EventSystem.h"


std::vector<int> KeyCode::keyCodes = {
    65,
    66,
    67,
    68,
    69,
    70,
    71,
    72,
    73,
    74,
    75,
    76,
    77,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    85,
    86,
    87,
    88,
    89,
    90
};

std::vector<std::string> KeyCode::keyLabels = {
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z"
};

// TODO; Add this as some static stuff
KeyCode Keyboard::A(65);    // "A"
KeyCode Keyboard::B(66);    // "B"
KeyCode Keyboard::C(67);    // "C"
KeyCode Keyboard::D(68);    // "D"
KeyCode Keyboard::E(69);    // "E"
KeyCode Keyboard::F(70);    // "F"
KeyCode Keyboard::G(71);    // "G"
KeyCode Keyboard::H(72);    // "H"
KeyCode Keyboard::I(73);    // "I"
KeyCode Keyboard::J(74);    // "J"
KeyCode Keyboard::K(75);    // "K"
KeyCode Keyboard::L(76);    // "L"
KeyCode Keyboard::M(77);    // "M"
KeyCode Keyboard::N(78);    // "N"
KeyCode Keyboard::O(79);    // "O"
KeyCode Keyboard::P(80);    // "P"
KeyCode Keyboard::Q(81);    // "Q"
KeyCode Keyboard::R(82);    // "R"
KeyCode Keyboard::S(83);    // "S"
KeyCode Keyboard::T(84);    // "T"
KeyCode Keyboard::U(85);    // "U"
KeyCode Keyboard::V(86);    // "V"
KeyCode Keyboard::W(87);    // "W"
KeyCode Keyboard::X(88);    // "X"
KeyCode Keyboard::Y(89);    // "Y"
KeyCode Keyboard::Z(90);    // "Z"

KeyCode::KeyCode() {
    this->code = -1;
    this->label = "Unknown";
}

KeyCode::KeyCode(int code) {
    bool found = false;
    for (int i = 0; i < keyCodes.size(); i++) {
        if (code == keyCodes[i]) {
            this->code = code;
            this->label = keyLabels[i];
            found = true;
            break;
        }
    }

    if (!found) {
        this->code = -1;
        this->label = "Unknown";
    }
}

KeyCode::KeyCode(std::string label) {
    bool found = false;
    for (int i = 0; i < keyLabels.size(); i++) {
        if (label == keyLabels[i]) {
            this->code = keyCodes[i];
            this->label = label;
            found = true;
            break;
        }
    }

    if (!found) {
        this->code = -1;
        this->label = "Unknown";
    }
}

KeyCode::~KeyCode() {
    
}

std::string Event::getType() {
    return type;
}

KeyboardEvent::KeyboardEvent() {

}

KeyboardEvent::~KeyboardEvent() {

}

KeyCode KeyboardEvent::getKeyCode() {
    return keyCode;
}

KeyDownEvent::KeyDownEvent() {

}

KeyDownEvent::~KeyDownEvent() {

}

KeyUpEvent::KeyUpEvent() {

}

KeyUpEvent::~KeyUpEvent() {

}

MouseEvent::MouseEvent() {

}

MouseEvent::~MouseEvent() {

}

int MouseEvent::getButtonCode() {
    return buttonCode;
}

WindowEvent::WindowEvent() {

}

WindowEvent::~WindowEvent() {

}

EventSystem::EventSystem() {

}

EventSystem::~EventSystem() {

}

void EventSystem::pushEvent(sf::Event sfEvent) {
    switch (sfEvent.type) {
    case sf::Event::KeyPressed:
        auto output = std::make_shared<KeyDownEvent>();
        break;
    }
}

std::string EventSystem::getSfKeyLabel(sf::Keyboard::Key key) {
    switch(key) {
    default:
    case sf::Keyboard::Unknown:
            return "Unknown";
    case sf::Keyboard::A:
            return "A";
    case sf::Keyboard::B:
            return "B";
    case sf::Keyboard::C:
            return "C";
    case sf::Keyboard::D:
            return "D";
    case sf::Keyboard::E:
            return "E";
    case sf::Keyboard::F:
            return "F";
    case sf::Keyboard::G:
            return "G";
    case sf::Keyboard::H:
            return "H";
    case sf::Keyboard::I:
            return "I";
    case sf::Keyboard::J:
            return "J";
    case sf::Keyboard::K:
            return "K";
    case sf::Keyboard::L:
            return "L";
    case sf::Keyboard::M:
            return "M";
    case sf::Keyboard::N:
            return "N";
    case sf::Keyboard::O:
            return "O";
    case sf::Keyboard::P:
            return "P";
    case sf::Keyboard::Q:
            return "Q";
    case sf::Keyboard::R:
            return "R";
    case sf::Keyboard::S:
            return "S";
    case sf::Keyboard::T:
            return "T";
    case sf::Keyboard::U:
            return "U";
    case sf::Keyboard::V:
            return "V";
    case sf::Keyboard::W:
            return "W";
    case sf::Keyboard::X:
            return "X";
    case sf::Keyboard::Y:
            return "Y";
    case sf::Keyboard::Z:
            return "Z";
    case sf::Keyboard::Num0:
            return "Num0";
    case sf::Keyboard::Num1:
            return "Num1";
    case sf::Keyboard::Num2:
            return "Num2";
    case sf::Keyboard::Num3:
            return "Num3";
    case sf::Keyboard::Num4:
            return "Num4";
    case sf::Keyboard::Num5:
            return "Num5";
    case sf::Keyboard::Num6:
            return "Num6";
    case sf::Keyboard::Num7:
            return "Num7";
    case sf::Keyboard::Num8:
            return "Num8";
    case sf::Keyboard::Num9:
            return "Num9";
    case sf::Keyboard::Escape:
            return "Escape";
    case sf::Keyboard::LControl:
            return "LControl";
    case sf::Keyboard::LShift:
            return "LShift";
    case sf::Keyboard::LAlt:
            return "LAlt";
    case sf::Keyboard::LSystem:
            return "LSystem";
    case sf::Keyboard::RControl:
            return "RControl";
    case sf::Keyboard::RShift:
            return "RShift";
    case sf::Keyboard::RAlt:
            return "RAlt";
    case sf::Keyboard::RSystem:
            return "RSystem";
    case sf::Keyboard::Menu:
            return "Menu";
    case sf::Keyboard::LBracket:
            return "LBracket";
    case sf::Keyboard::RBracket:
            return "RBracket";
    case sf::Keyboard::SemiColon:
            return "SemiColon";
    case sf::Keyboard::Comma:
            return "Comma";
    case sf::Keyboard::Period:
            return "Period";
    case sf::Keyboard::Quote:
            return "Quote";
    case sf::Keyboard::Slash:
            return "Slash";
    case sf::Keyboard::BackSlash:
            return "BackSlash";
    case sf::Keyboard::Tilde:
            return "Tilde";
    case sf::Keyboard::Equal:
            return "Equal";
    case sf::Keyboard::Dash:
            return "Dash";
    case sf::Keyboard::Space:
            return "Space";
    case sf::Keyboard::Return:
            return "Return";
    case sf::Keyboard::BackSpace:
            return "BackSpace";
    case sf::Keyboard::Tab:
            return "Tab";
    case sf::Keyboard::PageUp:
            return "PageUp";
    case sf::Keyboard::PageDown:
            return "PageDown";
    case sf::Keyboard::End:
            return "End";
    case sf::Keyboard::Home:
            return "Home";
    case sf::Keyboard::Insert:
            return "Insert";
    case sf::Keyboard::Delete:
            return "Delete";
    case sf::Keyboard::Add:
            return "Add";
    case sf::Keyboard::Subtract:
            return "Subtract";
    case sf::Keyboard::Multiply:
            return "Multiply";
    case sf::Keyboard::Divide:
            return "Divide";
    case sf::Keyboard::Left:
            return "Left";
    case sf::Keyboard::Right:
            return "Right";
    case sf::Keyboard::Up:
            return "Up";
    case sf::Keyboard::Down:
            return "Down";
    case sf::Keyboard::Numpad0:
            return "Numpad0";
    case sf::Keyboard::Numpad1:
            return "Numpad1";
    case sf::Keyboard::Numpad2:
            return "Numpad2";
    case sf::Keyboard::Numpad3:
            return "Numpad3";
    case sf::Keyboard::Numpad4:
            return "Numpad4";
    case sf::Keyboard::Numpad5:
            return "Numpad5";
    case sf::Keyboard::Numpad6:
            return "Numpad6";
    case sf::Keyboard::Numpad7:
            return "Numpad7";
    case sf::Keyboard::Numpad8:
            return "Numpad8";
    case sf::Keyboard::Numpad9:
            return "Numpad9";
    case sf::Keyboard::F1:
            return "F1";
    case sf::Keyboard::F2:
            return "F2";
    case sf::Keyboard::F3:
            return "F3";
    case sf::Keyboard::F4:
            return "F4";
    case sf::Keyboard::F5:
            return "F5";
    case sf::Keyboard::F6:
            return "F6";
    case sf::Keyboard::F7:
            return "F7";
    case sf::Keyboard::F8:
            return "F8";
    case sf::Keyboard::F9:
            return "F9";
    case sf::Keyboard::F10:
            return "F10";
    case sf::Keyboard::F11:
            return "F11";
    case sf::Keyboard::F12:
            return "F12";
    case sf::Keyboard::F13:
            return "F13";
    case sf::Keyboard::F14:
            return "F14";
    case sf::Keyboard::F15:
            return "F15";
    case sf::Keyboard::Pause:
            return "Pause";
    }
}

