#include "paramswidget.h"

#include <QAction>
#include <QLineEdit>

ParamsWidget::ParamsWidget(QWidget *parent) : QWidget(parent) {
  formLayout_ = new QFormLayout(this);
  setLayout(formLayout_);
  hostName_ = new QLineEdit(this);
  databaseName_ = new QLineEdit(this);
  userName_ = new QLineEdit(this);
  password_ = new QLineEdit(this);

  formLayout_->addRow("host", hostName_);
  formLayout_->addRow("database", databaseName_);
  formLayout_->addRow("user", userName_);
  formLayout_->addRow("password", password_);
  okBttn_ = new QPushButton("Change", this);
  formLayout_->addRow("Sure?", okBttn_);
  connect(okBttn_, &QPushButton::clicked, this, &ParamsWidget::SendData);
}

QStringList &ParamsWidget::GetData() {
  data_.clear();
  data_.append(hostName_->text());
  data_.append(databaseName_->text());
  data_.append(userName_->text());
  data_.append(password_->text());
  return data_;
}

void ParamsWidget::SendData() {
  emit DataChanged();
  close();
}
