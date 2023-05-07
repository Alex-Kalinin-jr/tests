#include "answergui.h"

AnswerGui::AnswerGui(bool answ, QString text, QWidget *parent)
    : isRight_(answ), QCheckBox(text, parent) {}
