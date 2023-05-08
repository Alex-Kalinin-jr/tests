#include "mainwindow.h"

#include <QComboBox>
#include <QDebug>
#include <QLabel>
#include <QRandomGenerator>
#include <QSqlQuery>
#include <algorithm>
#include <vector>

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
  layout_->addWidget(new QLabel(quest), 2, 0, 1, 4);

  query.exec(
      QString("SELECT * FROM answer WHERE question_id = '%1';").arg(rand + 1));
  int i = 3;
  while (query.next()) {
    quest = query.value(2).toString();
    bool isItRight = query.value(3).toBool();
    AnswerGui *chooseCheckBox = new AnswerGui(isItRight, quest, this);
    layout_->addWidget(chooseCheckBox, i, 0, 1, 1);
    ++i;
  }
  return true;
}

void MainWindow::Answer() {
  int i = 3;
  std::vector<int> wrongAnswers;
  QLayoutItem *layItem = layout_->itemAtPosition(i, 0);
  while (layItem != nullptr) {
    AnswerGui *buff = dynamic_cast<AnswerGui *>(layItem->widget());
    if (!buff->Compare()) {
      wrongAnswers.push_back(i - 2);
    }
    ++i;
    layItem = layout_->itemAtPosition(i, 0);
  }

  QString msg;
  if (!wrongAnswers.empty()) {
    msg = QString("Wrong answers are: ");
    std::for_each(wrongAnswers.begin(), wrongAnswers.end(),
                  [&msg](int &i) { msg = msg + QString::number(i) + ", "; });
  } else {
    msg = "Right";
  }
  statusBar()->showMessage(msg);
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
  int i = 2;
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
  setStatusBar(new QStatusBar);
  layout_ = new QGridLayout();
  layout_->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  centralWidget()->setLayout(layout_);
}

void MainWindow::setCategoryArea() {
  QLabel *lCategory = new QLabel("Choose category");
  layout_->addWidget(lCategory, layoutManager_, 0, 1, 1);
  ++layoutManager_;
  QComboBox *categoryBox = new QComboBox();
  categoryBox->addItems({"linux", "c++"});
  layout_->addWidget(categoryBox, layoutManager_, 0);
  go_ = new QPushButton("Go");
  layout_->addWidget(go_, layoutManager_, 1);
  connect(go_, SIGNAL(clicked()), this, SLOT(Ask()));
  answer_ = new QPushButton("Answer");
  layout_->addWidget(answer_, layoutManager_, 2);
  connect(answer_, SIGNAL(clicked()), this, SLOT(Answer()));
}
