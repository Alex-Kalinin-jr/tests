#include "mainwindow.h"

#include <QComboBox>
#include <QDebug>
#include <QLabel>
#include <QSqlQuery>

#include "ui_mainwindow.h"

bool MainWindow::Ask() {
  QSqlQuery query;
  QString queryStr = QString("SELECT COUNT(*) FROM question;");
  query.exec(queryStr);
  if (!query.next()) {
    return false;
  }
  int count = query.value(0).toInt();
  queryStr = QString("SELECT * FROM question WHERE id = '%1';")
                 .arg(count);  // count to be changed
  query.exec(queryStr);
  if (!query.next()) {
    return false;
  }
  QString quest = query.value(2).toString();
  layout_->addWidget(new QLabel(quest), 3, 1, 1, 1);

  queryStr = QString("SELECT * FROM answer WHERE question_id = '%1';")
                 .arg(count);  // count to be changed
  query.exec(queryStr);

  int i = 4;
  while (query.next()) {
    quest = query.value(2).toString();
    layout_->addWidget(new QLabel(quest), i, 1, 1, 1);
    ++i;
  }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setLayoutActions();
  setCategoryArea();

  bool ok = setConnection();
}

MainWindow::~MainWindow() { delete ui; }

bool MainWindow::setConnection() {
  dBase_ = (QSqlDatabase::addDatabase("QMYSQL"));
  dBase_.setHostName("localhost");
  dBase_.setDatabaseName("questions");
  dBase_.setUserName("student");
  dBase_.setPassword("student");
  return dBase_.open();
}

void MainWindow::setLayoutActions() {
  layout_ = new QGridLayout();
  layout_->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  centralWidget()->setLayout(layout_);
}

void MainWindow::setCategoryArea() {
  QLabel *lCategory = new QLabel("Choose category");
  layout_->addWidget(lCategory, 0, 0, 1, 1);
  QComboBox *categoryBox = new QComboBox();
  categoryBox->addItems({"linux", "c++"});
  layout_->addWidget(categoryBox, 1, 0);
  go_ = new QPushButton("Go");
  layout_->addWidget(go_);
  connect(go_, SIGNAL(clicked()), this, SLOT(Ask()));
}
