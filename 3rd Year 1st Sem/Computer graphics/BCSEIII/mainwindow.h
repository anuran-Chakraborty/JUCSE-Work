#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();

    void on_Draw_clicked();

    void on_set_point1_clicked();

    void on_set_point2_clicked();

    void on_pushButton_clicked();

    int changeX(int x);

    int changeY(int y);

    void on_showgrid_clicked();

    void on_dda_clicked();

    void on_bress_clicked();

    void on_midpt_clicked();

    void drawCircle(QPoint p1,int r0);

    void on_bress_circle_clicked();

    void drawCircleBress(QPoint p1,int r0);

    void on_ellipse_clicked();

    void drawEllipse(QPoint p1,int rx,int ry);

    void on_flood_fill_clicked();

    void flood_fill_util(int x1,int y1,int k,QRgb q1,int r,int g,int b);

    void on_boundary_fill_clicked();

    void boundary_fill_util(int x1,int y1,int k,QRgb edgecolor,int r,int g,int b);

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    void point(int x,int y,int r=255,int g=255,int b=0);
};

#endif // MAINWINDOW_H
