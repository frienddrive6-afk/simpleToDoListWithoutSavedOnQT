#pragma once

#include <QMainWindow>

class QVBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    QVBoxLayout* m_mainLayout;
    QVBoxLayout* m_tasksLayout;

    void setUI();






};