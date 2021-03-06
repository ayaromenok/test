// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/test/blob/master/LICENSE

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
class YaConstraintOne;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void paintEvent(QPaintEvent *);

private:
    YaConstraintOne*    _fs;
};

#endif // MAINWINDOW_H
