#ifndef WRITINGGUI_H
#define WRITINGGUI_H

#include <QDialog>
#include <QGridLayout>
#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>

#include "mainwindow.h"

class WritingGui : public QDialog {
  Q_OBJECT
 public:
  WritingGui(QWidget *parent = nullptr);
  WritingGui(const WritingGui &) = delete;
  WritingGui &operator=(const WritingGui &) = delete;
  void AddOneAnsw();
  QStringList GetFields();
  inline QComboBox *GetCategoryPointer() { return category_; }

 signals:
 public slots:

 private:
  int firstAnswRow_ = 0;
  int questRow_ = 0;
  int countPresented_ = 0;
  QTextEdit *question_;
  QComboBox *category_;
  QGridLayout *layout_;
  QPushButton *addAnswer_;
  QPushButton *ok_;
  QPushButton *cancel_;
  // Layout coordinates. After every operation coordinates will be: the next
  // first field of table on the next first empty row.
  int row_;
  int col_;

  void PutQuestionArea();
};

#endif  // WRITINGGUI_H
