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

// parent for all action dialogs
// already has a layout and accept reject buttons IMPLICITLY!!!
// for each inherited widget set the layout_ onto it during initialization
// use layout coordinates for applying widgetc
class DialogGui : public QDialog {
  Q_OBJECT
 public:
  DialogGui(QWidget *parent = nullptr);
  DialogGui(const DialogGui &) = delete;
  DialogGui &operator=(const DialogGui &) = delete;
  virtual QStringList GetFields() = 0;

 protected:
  QPushButton *ok_;
  QPushButton *cancel_;
  QGridLayout *layout_;
  // Layout coordinates. After every operation coordinates will be: the next
  // first field of table on the next first empty row.
  int row_;
  int col_;

 private:
};

class WritingGui : public DialogGui {
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
  QPushButton *addAnswer_;

  void PutQuestionArea();
};

class NewCategoryGui : public DialogGui {
  Q_OBJECT
 public:
  NewCategoryGui(QWidget *parent = nullptr);
  NewCategoryGui(const NewCategoryGui &) = delete;
  NewCategoryGui &operator=(const WritingGui &) = delete;

 public slots:
  QStringList GetFields();

 private:
  void PutFieldsOntoLayout();
  QLineEdit *newCategory_;
  QLineEdit *codeForDb_;
};

#endif  // WRITINGGUI_H
