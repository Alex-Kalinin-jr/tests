#include "mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QRandomGenerator>
#include <QSqlQuery>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>

#include "answergui.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  std::srand(time(0));
  setLayoutActions();
  setCategoryArea();
  CreateActions();
  dBaseConnectionData_ << "localhost"
                       << "questions"
                       << "student"
                       << "student";
  bool ok = setConnection();
  if (!ok) {
    statusBar()->showMessage("Db isn't opened");
  }

  // forms vector of empty vectors
  for (int i = 0; i < categoryVector_.size(); ++i) {
    std::vector<int> internalVector(0);
    askedChecker_.push_back(internalVector);
  }

  paramsWidget_ = new ParamsWidget();
  connect(paramsWidget_, &ParamsWidget::DataChanged, this,
          &MainWindow::ChangeConnectionParams);
}

MainWindow::~MainWindow() {
  delete ui;
  delete paramsWidget_;
}

void MainWindow::ChangeConnectionParams() {
  dBaseConnectionData_ = paramsWidget_->GetData();
  std::for_each(askedChecker_.begin(), askedChecker_.end(),
                [](std::vector<int> &i) { i.clear(); });
  dBase_.removeDatabase("QMYSQL");
  dBase_.close();
  setConnection();
}

bool MainWindow::Ask() {
  ClearQuestion();
  RefillQuestions();
  int idRequested = GenerateQuestionId();
  if (idRequested == -1) {
    statusBar()->showMessage("No questions");
    return false;
  }

  QSqlQuery query;
  query.exec(
      QString("SELECT text FROM question WHERE id = '%1';").arg(idRequested));
  query.next();
  QString quest = query.value(0).toString();
  layout_->addWidget(new QLabel(quest), 2, 0, 1, 3);

  query.exec(QString("SELECT * FROM answer WHERE question_id = '%1';")
                 .arg(idRequested));
  int i = 3;
  while (query.next()) {
    AnswerGui *chooseCheckBox =
        new AnswerGui(query.value(3).toBool(), query.value(2).toString(), this);
    layout_->addWidget(chooseCheckBox, i, 0, 1, 3);
    ++i;
  }

  query.exec(QString("SELECT text FROM link WHERE question_id = '%1';")
                 .arg(idRequested));
  while (query.next()) {
    QLineEdit *chooseCheckBox = new QLineEdit(query.value(0).toString());
    layout_->addWidget(chooseCheckBox, i, 0, 1, 3);
    ++i;
  }
  return true;
}

void MainWindow::Answer() {
  int i = 3;
  std::vector<int> wrongAnswers;
  QLayoutItem *layItem = layout_->itemAtPosition(i, 0);
  while (layItem != nullptr && layItem->widget()) {
    AnswerGui *buff = dynamic_cast<AnswerGui *>(layItem->widget());
    if (buff != nullptr && !buff->Compare()) {
      // the first condition should stay first. There can be some links
      // "QLineEdit" on layout after answer variants. They shouldn't be checked.
      // If widget is not AnswerGui then buff will be nullptr after
      // "dynamic_cast" and item will not be checked
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

void MainWindow::ChangeCategory(int index) {
  if (categoryVector_.size() > index) {
    currentCategory_ = index;
  }
}

void MainWindow::ClearQuestion() {
  int i = 2;
  QLayoutItem *buff = layout_->itemAtPosition(i, 1);
  while (buff != nullptr) {
    delete buff->widget();
    ++i;
    buff = layout_->itemAtPosition(i, 0);
  }
}

void MainWindow::ChooseSession() { paramsWidget_->show(); }

bool MainWindow::setConnection() {
  dBase_ = (QSqlDatabase::addDatabase("QMYSQL"));
  dBase_.setHostName(dBaseConnectionData_[0]);
  dBase_.setDatabaseName(dBaseConnectionData_[1]);
  dBase_.setUserName(dBaseConnectionData_[2]);
  dBase_.setPassword(dBaseConnectionData_[3]);
  return dBase_.open();
}

void MainWindow::setLayoutActions() {
  setStatusBar(new QStatusBar);
  layout_ = new QGridLayout();
  layout_->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  centralWidget()->setLayout(layout_);
}

void MainWindow::CreateActions() {
  menuBar_ = menuBar();
  menu_ = new QMenu("menu", this);
  menuBar_->addMenu(menu_);

  aConnect_ = new QAction("Session", this);
  aCreateQuestion_ = new QAction("New question", this);

  menu_->addAction(aConnect_);
  connect(aConnect_, &QAction::triggered, this, &MainWindow::ChooseSession);
  menu_->addAction(aCreateQuestion_);
}

void MainWindow::setCategoryArea() {
  QLabel *lCategory = new QLabel("Choose category", this);
  layout_->addWidget(lCategory, layoutManager_, 0, 1, 1);
  ++layoutManager_;
  categoryBox_ = new QComboBox(this);
  categoryBox_->addItems({"linux", "c++", "sql", "qt"});
  layout_->addWidget(categoryBox_, layoutManager_, 0);
  connect(categoryBox_, SIGNAL(currentIndexChanged(int)), this,
          SLOT(ChangeCategory(int)));

  go_ = new QPushButton("Ask", this);
  layout_->addWidget(go_, layoutManager_, 1);
  connect(go_, SIGNAL(clicked()), this, SLOT(Ask()));

  answer_ = new QPushButton("Answer", this);
  layout_->addWidget(answer_, layoutManager_, 2);
  connect(answer_, SIGNAL(clicked()), this, SLOT(Answer()));
}

void MainWindow::RefillQuestions() {
  if (askedChecker_[currentCategory_].empty()) {
    QString a = QString("SELECT id FROM question WHERE category = '") +
                categoryVector_[currentCategory_] + QString("';");
    QSqlQuery query(a);
    while (query.next()) {
      int id = query.value(0).toInt();
      askedChecker_[currentCategory_].push_back(id);
    }
  }
}

int MainWindow::GenerateQuestionId() {
  int id = -1;
  if (askedChecker_[currentCategory_].size()) {
    int erased = std::rand() % askedChecker_[currentCategory_].size();
    auto itr = askedChecker_[currentCategory_].begin();
    std::advance(itr, erased);
    id = *itr;
    askedChecker_[currentCategory_].erase(itr);
  }
  return id;
}
