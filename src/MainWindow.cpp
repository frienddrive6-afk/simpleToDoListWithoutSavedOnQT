#include "MainWindow.h"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QString>
#include <QScrollArea>


MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent)
{
    setUI();
}

void MainWindow::setUI()
{

    setWindowTitle("To do List");
    resize(500,700);
    setMinimumSize(250,350);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    m_mainLayout = new QVBoxLayout(centralWidget);
    centralWidget->setLayout(m_mainLayout);


    QLabel* TopLabel = new QLabel("Pleas enter your task", this);
    m_mainLayout->addWidget(TopLabel, 0, Qt::AlignCenter);



    QLineEdit* lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Enter your task: ");

    m_mainLayout->addWidget(lineEdit); 



    QPushButton* btn = new QPushButton("Add", this);
    btn->setFixedSize(100,50);
    btn->setStyleSheet("background-color: green; color: white; border-radius: 10px; font-weight: bold;");

    m_mainLayout->addWidget(btn, 0, Qt::AlignCenter);

    QScrollArea* scrollArea = new QScrollArea(this);
    
    scrollArea->setFrameShape(QFrame::NoFrame); 
    scrollArea->setWidgetResizable(true);

    QWidget* scrollContent = new QWidget();
    
    m_tasksLayout = new QVBoxLayout(scrollContent);
    m_tasksLayout->setSpacing(5);
    m_tasksLayout->setAlignment(Qt::AlignTop); 
    

    scrollArea->setWidget(scrollContent);

    m_mainLayout->addWidget(scrollArea);


    connect(btn, &QPushButton::clicked, lineEdit, [=](){
        QString str = lineEdit->text();
        if(str.isEmpty()) return;

        QPushButton* newButtonTask = new QPushButton(str);
        newButtonTask->setStyleSheet(
            "QPushButton {"
            "   text-align: left;" 
            "   border: 1px solid gray; padding: 5px; border-radius: 5px; background: white;"
            "   color: black;" 
            "}"
            "QPushButton:hover {"
            "   background-color: #e0e0e0; border-color: #2980b9;" 
            "   color: #2980b9;" 
            "}"
        );

        m_tasksLayout->addWidget(newButtonTask);

        lineEdit->clear();
    });
}