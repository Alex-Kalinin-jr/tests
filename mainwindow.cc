#include "mainwindow.h"

#include <QDebug>
#include <QSqlQuery>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  dBase_ = (QSqlDatabase::addDatabase("QMYSQL"));
  dBase_.setHostName("localhost");
  dBase_.setDatabaseName("questions");
  dBase_.setUserName("student");
  dBase_.setPassword("student");
  bool ok = dBase_.open();
  if (ok) {
    qDebug("dbase is opened");
    QSqlQuery query("select * from question");
    while (query.next()) {
      QString a =
          query.value(0).toString() + "-->>" + query.value(2).toString();
      qDebug() << a;
    }
  } else {
    qDebug("smthng got wrong!");
  }
}

MainWindow::~MainWindow() { delete ui; }
