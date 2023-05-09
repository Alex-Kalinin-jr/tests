#ifndef PARAMSWIDGET_H
#define PARAMSWIDGET_H

#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class ParamsWidget : public QWidget {
  Q_OBJECT
 public:
  explicit ParamsWidget(QWidget *parent = nullptr);
  QStringList &GetData();
 private slots:
  // when all fields are filled "okBttn_" should announce this,
  // but sender "okBttn_" is private and not visible out of class
  // due to this "SendData" slot was implemented to realize the next behaviour:
  // ok emits signal "clicked" -> this launchs slot "SendData" which emits
  // signal "DataChanged" visible from outside
  void SendData();

 signals:
  void DataChanged();

 private:
  QFormLayout *formLayout_;
  QLineEdit *userName_;
  QLineEdit *hostName_;
  QLineEdit *databaseName_;
  QLineEdit *password_;
  QPushButton *okBttn_;
  QStringList data_;
};

#endif  // PARAMSWIDGET_H
