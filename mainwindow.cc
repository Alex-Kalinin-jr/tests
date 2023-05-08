#include "mainwindow.h"

#include <QComboBox>
#include <QDebug>
#include <QLabel>
#include <QRandomGenerator>
#include <QSqlQuery>

#include "answergui.h"
#include "ui_mainwindow.h"

bool MainWindow::Ask() {
  ClearQuestion();
  QSqlQuery query;
  query.exec("SELECT COUNT(*) FROM question;");
  if (!query.next()) {
    return false;
  }
  int count = query.value(0).toInt();
  if (asked_.size() >= count - 1) {
    asked_.clear();
  }
  quint32 rand = 0;
  do {
    rand = QRandomGenerator::global()->bounded(count);
    query.exec(
        QString("SELECT text FROM question WHERE id = '%1';").arg(rand + 1));
  } while (asked_.count(static_cast<int>(rand)) || !query.next());
  asked_.emplace(rand);
  QString quest = query.value(0).toString();
  layout_->addWidget(new QLabel(quest), 3, 1, 1, 1);

  query.exec(
      QString("SELECT * FROM answer WHERE question_id = '%1';").arg(rand + 1));
  int i = 4;
  while (query.next()) {
    quest = query.value(2).toString();
    bool isItRight = query.value(3).toBool();
    AnswerGui *chooseCheckBox = new AnswerGui(isItRight, quest, this);
    layout_->addWidget(chooseCheckBox, i, 0, 1, 1);
    ++i;
  }
  return true;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setLayoutActions();
  setCategoryArea();

  bool ok = setConnection();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ClearQuestion() {
  int i = 3;
  QLayoutItem *buff = layout_->itemAtPosition(i, 1);
  while (buff != nullptr) {
    delete buff->widget();
    ++i;
    buff = layout_->itemAtPosition(i, 0);
  }
}

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
