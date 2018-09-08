/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QCheckBox *show_axes;
    QPushButton *Draw;
    QSpinBox *circle_radius;
    QRadioButton *draw_circle;
    QRadioButton *draw_line;
    QPushButton *set_point1;
    QPushButton *set_point2;
    QPushButton *pushButton;
    QSpinBox *gridsize;
    QLabel *label;
    QPushButton *showgrid;
    QLabel *label_2;
    QPushButton *dda;
    QPushButton *bress;
    QLabel *debugger;
    QLabel *label_4;
    QPushButton *midpt;
    QPushButton *bress_circle;
    QRadioButton *draw_ellipse;
    QSpinBox *ellipse_ry;
    QSpinBox *ellipse_rx;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *ellipse;
    QFrame *line;
    QPushButton *flood_fill;
    QPushButton *boundary_fill;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1303, 736);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 700, 700));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QStringLiteral("mouse_movement"));
        mouse_movement->setGeometry(QRect(720, 60, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(720, 40, 111, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QStringLiteral("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(720, 130, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(730, 110, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QStringLiteral("x_axis"));
        x_axis->setGeometry(QRect(0, 0, 700, 1));
        x_axis->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QStringLiteral("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QLatin1String("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName(QStringLiteral("show_axes"));
        show_axes->setGeometry(QRect(720, 0, 91, 21));
        Draw = new QPushButton(centralWidget);
        Draw->setObjectName(QStringLiteral("Draw"));
        Draw->setGeometry(QRect(710, 280, 101, 41));
        circle_radius = new QSpinBox(centralWidget);
        circle_radius->setObjectName(QStringLiteral("circle_radius"));
        circle_radius->setGeometry(QRect(790, 180, 46, 20));
        draw_circle = new QRadioButton(centralWidget);
        draw_circle->setObjectName(QStringLiteral("draw_circle"));
        draw_circle->setGeometry(QRect(710, 180, 81, 17));
        draw_line = new QRadioButton(centralWidget);
        draw_line->setObjectName(QStringLiteral("draw_line"));
        draw_line->setGeometry(QRect(710, 230, 77, 17));
        set_point1 = new QPushButton(centralWidget);
        set_point1->setObjectName(QStringLiteral("set_point1"));
        set_point1->setGeometry(QRect(790, 230, 81, 23));
        set_point2 = new QPushButton(centralWidget);
        set_point2->setObjectName(QStringLiteral("set_point2"));
        set_point2->setGeometry(QRect(880, 230, 81, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(710, 330, 101, 41));
        gridsize = new QSpinBox(centralWidget);
        gridsize->setObjectName(QStringLiteral("gridsize"));
        gridsize->setGeometry(QRect(900, 0, 61, 21));
        gridsize->setMinimum(1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(850, 0, 46, 13));
        showgrid = new QPushButton(centralWidget);
        showgrid->setObjectName(QStringLiteral("showgrid"));
        showgrid->setGeometry(QRect(890, 60, 81, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(710, 380, 121, 16));
        dda = new QPushButton(centralWidget);
        dda->setObjectName(QStringLiteral("dda"));
        dda->setGeometry(QRect(710, 410, 75, 31));
        bress = new QPushButton(centralWidget);
        bress->setObjectName(QStringLiteral("bress"));
        bress->setGeometry(QRect(800, 410, 91, 31));
        debugger = new QLabel(centralWidget);
        debugger->setObjectName(QStringLiteral("debugger"));
        debugger->setGeometry(QRect(710, 630, 171, 51));
        debugger->setFrameShape(QFrame::Panel);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(710, 450, 91, 16));
        midpt = new QPushButton(centralWidget);
        midpt->setObjectName(QStringLiteral("midpt"));
        midpt->setGeometry(QRect(710, 470, 91, 31));
        bress_circle = new QPushButton(centralWidget);
        bress_circle->setObjectName(QStringLiteral("bress_circle"));
        bress_circle->setGeometry(QRect(810, 470, 91, 31));
        draw_ellipse = new QRadioButton(centralWidget);
        draw_ellipse->setObjectName(QStringLiteral("draw_ellipse"));
        draw_ellipse->setGeometry(QRect(710, 520, 81, 17));
        ellipse_ry = new QSpinBox(centralWidget);
        ellipse_ry->setObjectName(QStringLiteral("ellipse_ry"));
        ellipse_ry->setGeometry(QRect(930, 520, 46, 20));
        ellipse_rx = new QSpinBox(centralWidget);
        ellipse_rx->setObjectName(QStringLiteral("ellipse_rx"));
        ellipse_rx->setGeometry(QRect(840, 520, 46, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(810, 520, 46, 13));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(900, 520, 46, 13));
        ellipse = new QPushButton(centralWidget);
        ellipse->setObjectName(QStringLiteral("ellipse"));
        ellipse->setGeometry(QRect(710, 550, 91, 31));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(1020, -20, 20, 691));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        flood_fill = new QPushButton(centralWidget);
        flood_fill->setObjectName(QStringLiteral("flood_fill"));
        flood_fill->setGeometry(QRect(1050, 10, 81, 41));
        boundary_fill = new QPushButton(centralWidget);
        boundary_fill->setObjectName(QStringLiteral("boundary_fill"));
        boundary_fill->setGeometry(QRect(1170, 10, 81, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1303, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "    Mouse Movement", 0));
        mouse_pressed->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Mouse Pressed", 0));
        show_axes->setText(QApplication::translate("MainWindow", "Show Axes", 0));
        Draw->setText(QApplication::translate("MainWindow", "Draw", 0));
        draw_circle->setText(QApplication::translate("MainWindow", "Draw Circle", 0));
        draw_line->setText(QApplication::translate("MainWindow", "Draw Line", 0));
        set_point1->setText(QApplication::translate("MainWindow", "Set point 1", 0));
        set_point2->setText(QApplication::translate("MainWindow", "Set point 2", 0));
        pushButton->setText(QApplication::translate("MainWindow", "RESET", 0));
        label->setText(QApplication::translate("MainWindow", "Grid Size", 0));
        showgrid->setText(QApplication::translate("MainWindow", "Show Grid", 0));
        label_2->setText(QApplication::translate("MainWindow", "Line Drawing Algorithm", 0));
        dda->setText(QApplication::translate("MainWindow", "DDA", 0));
        bress->setText(QApplication::translate("MainWindow", "BRESSENHAM", 0));
        debugger->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Circle Drawing Algo", 0));
        midpt->setText(QApplication::translate("MainWindow", "Midpoint Circle", 0));
        bress_circle->setText(QApplication::translate("MainWindow", "Bressenham", 0));
        draw_ellipse->setText(QApplication::translate("MainWindow", "Draw Ellipse", 0));
        label_6->setText(QApplication::translate("MainWindow", "Rx:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Ry:", 0));
        ellipse->setText(QApplication::translate("MainWindow", "Draw Ellipse", 0));
        flood_fill->setText(QApplication::translate("MainWindow", "Flood Fill", 0));
        boundary_fill->setText(QApplication::translate("MainWindow", "Boundary fill", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
