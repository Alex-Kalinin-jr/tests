#ifndef ANSWERGUI_H
#define ANSWERGUI_H

#include <QCheckBox>
#include <QObject>

class AnswerGui : public QCheckBox {
  Q_OBJECT
 public:
  explicit AnswerGui(bool, QString, QWidget *parent = nullptr);

 private:
  bool isRight_;
};

#endif  // ANSWERGUI_H
