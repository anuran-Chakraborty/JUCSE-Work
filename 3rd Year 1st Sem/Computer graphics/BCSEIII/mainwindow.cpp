#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <string>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <unistd.h>
#include <vector>

using namespace std;
QImage img=QImage(700,700,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::point(int x,int y,int r,int g,int b)
{
    int k = ui->gridsize->value();//GridSize
    if(k>1)
    {
        int startX=x/k*k;
        int startY=y/k*k;

        //Drawing the pixels
        for(int i=startX+1;i<(startX+k);i++)
            for(int j=startY+1;j<(startY+k);j++)
                img.setPixel(i,j,qRgb(r,g,b));
    }
    else
        img.setPixel(x,y,qRgb(r,g,b));
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

int MainWindow::changeX(int x)
{
    int k = ui->gridsize->value();
    x=x-img.width()/2;
    x/=k;
    return x;
}

int MainWindow::changeY(int y)
{
    int k = ui->gridsize->value();
    y=img.height()/2-y;
    y/=k;
    return y;
}

void MainWindow::showMousePosition(QPoint &pos)
{
    ui->mouse_movement->setText(" X : "+QString::number(changeX(pos.x()))+", Y : "+QString::number(changeY(pos.y())));
}
void MainWindow::Mouse_Pressed()
{
    ui->mouse_pressed->setText(" X : "+QString::number(changeX(ui->frame->x))+", Y : "+QString::number(changeY(ui->frame->y)));
    //point(ui->frame->x,ui->frame->y);
    ui->x_axis->move(0,ui->frame->y);
    ui->y_axis->move(ui->frame->x,0);
}

void MainWindow::on_show_axes_clicked()
{
    if(ui->show_axes->isChecked())
    {
        //Draw Y-axis
        for(int i=0;i<=img.height();i++)
            point(i,img.width()/2,0,247,255);
        //Draw X-axis
        for(int i=0;i<=img.width();i++)
            point(img.height()/2,i,0,247,255);
    }
    else{
        //Draw Y-axis
        for(int i=0;i<=img.height();i++)
            point(i,img.width()/2,0,0,0);
        //Draw X-axis
        for(int i=0;i<=img.width();i++)
            point(img.height()/2,i,0,0,0);
    }
}
void MainWindow::on_set_point1_clicked()
{
    if(ui->draw_line->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
    }
}

void MainWindow::on_set_point2_clicked()
{
    if(ui->draw_line->isChecked()){
        p2.setX(ui->frame->x);
        p2.setY(ui->frame->y);
    }
}

void MainWindow::on_Draw_clicked()
{
    int r0=ui->circle_radius->value();
    QPainter painter(&img);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    if(ui->draw_circle->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);
        painter.setPen(pen);
        painter.drawEllipse(p1,r0,r0);
    }
    if(ui->draw_line->isChecked()){
        painter.setPen(Qt::yellow);
        painter.drawLine(p1,p2);
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_showgrid_clicked()
{
    int k = ui->gridsize->value();

    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));

    for(int i=0;i<img.height();i+=k)
        for(int j=0;j<img.width();j++)
            img.setPixel(i,j,qRgb(0,255,0));

    for(int i=0;i<img.width();i+=k)
        for(int j=0;j<img.height();j++)
            img.setPixel(j,i,qRgb(0,255,0));

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_dda_clicked()
{
    //This function draws a line between the two selected points using DDA algorithm
    int k = ui->gridsize->value();
    //Now p1 and p2 contains the points
    int x1=(p1.x()/k);
    int y1=(p1.y()/k);

    int x2=(p2.x()/k);
    int y2=(p2.y()/k);


    // here we implement the algorithm
    int dx=x2-x1;
    int dy=y2-y1;
    int steps=0; //number of steps to  put pixel

    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);

    double Xinc=(double)dx/(double)steps;
    double Yinc=(double)dy/(double)steps;

    double x=x1*k+k/2;
    double y=y1*k+k/2;

    for(int v=0; v <steps; v++)
    {
        x = x + Xinc*k;
        y = y + Yinc*k;
        point((int)(x+0.5),(int)(y+0.5));
    }


}

//string s=to_string(changeX(x1))+" "+to_string(changeY(y1))+" "+to_string(changeX(x2))+" "+to_string(changeY(y2))+" "+to_string(p0);
//ui->debugger->setText(s.c_str());




void MainWindow::on_bress_clicked()
{

    int k = ui->gridsize->value();
    //Store the two points
    int x1=p1.x();
    int y1=p1.y();

    int x2=p2.x();
    int y2=p2.y();

    int dx=x2-x1;
    int dy=y2-y1;

    x1=(x1/k)*k+k/2;
    y1=(y1/k)*k+k/2;

    x2=(x2/k)*k+k/2;
    y2=(y2/k)*k+k/2;

    int xinc=(dx>0)?k:-k;
    int yinc=(dy>0)?k:-k;

    dx=abs(dx);
    dy=abs(dy);

    //Case for gentle slope
    if(dx>dy)
    {
        int p=2*(dy)-dx;
        int y=y1;

        for(int x=x1; x!=x2; x+=xinc)
        {
            point(x,y);
            if(p>=0)
            {
                y+=yinc;
                p-=2*dx;
            }
            p+=2*dy;
        }
    }
    //Case for steep slope
    else
    {
        int p=2*(dx)-dy;
        int x=x1;

        for(int y=y1; y!=y2; y+=yinc)
        {
            point(x,y);
            if(p>=0)
            {
                x+=xinc;
                p-=2*(dy);
            }
            p+=2*(dx);
        }
    }
}

void MainWindow::on_midpt_clicked()
{
    //Get the radius
    int r0=ui->circle_radius->value();

    //Set the centre
    if(ui->draw_circle->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);

        drawCircle(p1,r0);
    }
}

void MainWindow::drawCircle(QPoint p1, int r0)
{
    //Function to draw the circle
    int x_centre=p1.x();
    int y_centre=p1.y();

    int k = ui->gridsize->value();//GridSize

    x_centre=(x_centre/k)*k+k/2;
    y_centre=(y_centre/k)*k+k/2;

    int x=r0*k;
    int y=0;

    point(x+x_centre,y+y_centre);

    if(r0>0)
    {
        point(x+x_centre,-y+y_centre);
        point(y+x_centre,x+y_centre);
        point(-y+x_centre,x+y_centre);
    }


    int P=(1-r0)*k;

    while(x>y)
    {
        y++;

        if(P<=0)
            P=P+2*y+1;
        else
        {
            x--;
            P=P+2*y-2*x+1;
        }
        if(x<y)
            break;

        point(x+x_centre,y+y_centre);
        point(-x+x_centre,y+y_centre);
        point(x+x_centre,-y+y_centre);
        point(-x+x_centre,-y+y_centre);

        if(x!=y)
        {
            point(y+x_centre,x+y_centre);
            point(-y+x_centre,x+y_centre);
            point(y+x_centre,-x+y_centre);
            point(-y+x_centre,-x+y_centre);
        }
    }


}

void MainWindow::on_bress_circle_clicked()
{
    //Get the radius
    int r0=ui->circle_radius->value();

    //Set the centre
    if(ui->draw_circle->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);

        drawCircleBress(p1,r0);
    }
}

void MainWindow::drawCircleBress(QPoint p1, int r0)
{
    //Function to draw the circle
    int x_centre=p1.x();
    int y_centre=p1.y();

    int k = ui->gridsize->value();//GridSize

    x_centre=(x_centre/k)*k+k/2;
    y_centre=(y_centre/k)*k+k/2;

    int y=r0*k;
    int x=0;

    int d=(3-2*r0)*k;

    while(y>=x)
    {
        point(x_centre+x,y_centre+y);
        point(x_centre+x,y_centre-y);
        point(x_centre-x,y_centre+y);
        point(x_centre-x,y_centre-y);

        point(x_centre+y,y_centre+x);
        point(x_centre+y,y_centre-x);
        point(x_centre-y,y_centre+x);
        point(x_centre-y,y_centre-x);

        x++;
        if(d>0)
        {
            y--;
            d=d+4*(x-y)+10;
        }
        else
        {
            d=d+4*x+6;
        }
    }
}

void MainWindow::on_ellipse_clicked()
{
    //Get the radius
    int rx=ui->ellipse_rx->value();
    int ry=ui->ellipse_ry->value();

    //Set the centre
    if(ui->draw_ellipse->isChecked()){
        p1.setX(ui->frame->x);
        p1.setY(ui->frame->y);

        drawEllipse(p1,rx,ry);
    }
}

void MainWindow::drawEllipse(QPoint p, int rx, int ry)
{
    //Function to draw the ellipse
    //Get the centre
    int x_centre=p.x();
    int y_centre=p.y();
    int k = ui->gridsize->value();//GridSize

    x_centre=(x_centre/k)*k+k/2;
    y_centre=(y_centre/k)*k+k/2;

    int x=0;
    int y=ry;

    int rx2=rx*rx;
    int ry2=ry*ry;
    int tworx2=2*rx2;
    int twory2=2*ry2;
    int px=0.0;
    int py=tworx2*y;


    //For first region
    int p1=ry2-rx2*ry+(0.25)*rx2; //Initial value of decision paramemter




    while(px<py)
    {
        point(x_centre+x*k,y_centre+y*k);
        point(x_centre-x*k,y_centre+y*k);
        point(x_centre-x*k,y_centre-y*k);
        point(x_centre+x*k,y_centre-y*k);

        x++;
        px+=twory2;

        if(p1>=0)
        {
            y--;
            py-=tworx2;
            p1=p1+ry2+px-py;

        }
        else
        {
            p1=p1+ry2+px;
        }
    }

    //For second region
    p1=ry2*((double)x+0.5)*((double)x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2; //Initial value of decision paramemter


    while(y>=0)
    {
        point(x_centre+x*k,y_centre+y*k);
        point(x_centre-x*k,y_centre+y*k);
        point(x_centre-x*k,y_centre-y*k);
        point(x_centre+x*k,y_centre-y*k);

        y--;
        py-=tworx2;
        if(p1<=0)
        {
            x++;
            px+=twory2;
            p1=p1+rx2-py+px;

        }
        else
        {
            p1=p1+rx2-py;
        }

    }


}

void MainWindow::on_flood_fill_clicked()
{
    //Function to implement flood fill
    int x1=p1.x();
    int y1=p1.y();
    int k = ui->gridsize->value();

    x1=(x1/k)*k+k/2;
    y1=(y1/k)*k+k/2;

    flood_fill_util(x1,y1,k,img.pixel(x1,y1),255,255,255);
}

void MainWindow::flood_fill_util(int x1, int y1,int k, QRgb q1, int r,int g,int b)
{
    if(x1<=0 || x1>img.width()|| y1<=0 || y1>img.height())
        return;
    if(img.pixel(x1,y1)!=q1)
        return;
    if(img.pixel(x1,y1)==qRgb(r,g,b))
        return;
    point(x1,y1,255,255,255);

    flood_fill_util(x1+k,y1,k,q1,r,g,b);
    flood_fill_util(x1-k,y1,k,q1,r,g,b);
    flood_fill_util(x1,y1+k,k,q1,r,g,b);
    flood_fill_util(x1,y1-k,k,q1,r,g,b);
}



void MainWindow::on_boundary_fill_clicked()
{
    //Function to implement flood fill
    int x1=p1.x();
    int y1=p1.y();
    int k = ui->gridsize->value();

    x1=(x1/k)*k+k/2;
    y1=(y1/k)*k+k/2;

    boundary_fill_util(x1,y1,k,qRgb(255,255,0),255,255,255);
}

void MainWindow::boundary_fill_util(int x1, int y1, int k, QRgb edgecolor, int r, int g, int b)
{
    QRgb current;
    current=img.pixel(x1,y1);

    if(x1<=0 || x1>img.width()|| y1<=0 || y1>img.height())
        return;


    if(current!=edgecolor && current!=qRgb(r,g,b))
    {
        point(x1,y1,255,255,255);
        boundary_fill_util(x1+k,y1,k,edgecolor,r,g,b);
        boundary_fill_util(x1-k,y1,k,edgecolor,r,g,b);
        boundary_fill_util(x1,y1+k,k,edgecolor,r,g,b);
        boundary_fill_util(x1,y1-k,k,edgecolor,r,g,b);
    }
}

// ============================== SCAN LINE FILL =================================

void MainWindow::on_scanline_clicked()
{
    // for initialising
    EdgeList.clear();
    initEdgeTable();
}

void MainWindow::on_set_vertex_clicked()
{
    int k=ui->gridsize->value();
    int x=((ui->frame->x)/k)*k+k/2;
    int y=((ui->frame->y)/k)*k+k/2;
    EdgeList.push_back(make_pair(x,y));

    int i=EdgeList.size();

    if(EdgeList.size()>1)
    {
        storeEdgeInTable(EdgeList[i-2].first, EdgeList[i-2].second, EdgeList[i-1].first, EdgeList[i-1].second);//storage of edges in edge table.

        p1.setX(EdgeList[EdgeList.size()-1].first);
        p2.setX(EdgeList[EdgeList.size()-2].first);

        p1.setY(EdgeList[EdgeList.size()-1].second);
        p2.setY(EdgeList[EdgeList.size()-2].second);

        on_bress_clicked();

    }

}

void MainWindow::initEdgeTable()
{
    int i;
    for (i=0; i<maxHt; i++)
    {
        EdgeTable[i].countEdgeBucket = 0;
    }

    ActiveEdgeTuple.countEdgeBucket = 0;
}

void MainWindow::insertionSort(EdgeTableTuple *ett)
{
    int i,j;
    EdgeBucket temp;

    for (i = 1; i < ett->countEdgeBucket; i++)
    {
        temp.ymax = ett->buckets[i].ymax;
        temp.xofymin = ett->buckets[i].xofymin;
        temp.slopeinverse = ett->buckets[i].slopeinverse;
        j = i - 1;

    while ((temp.xofymin < ett->buckets[j].xofymin) && (j >= 0))
    {
        ett->buckets[j + 1].ymax = ett->buckets[j].ymax;
        ett->buckets[j + 1].xofymin = ett->buckets[j].xofymin;
        ett->buckets[j + 1].slopeinverse = ett->buckets[j].slopeinverse;
        j = j - 1;
    }
    ett->buckets[j + 1].ymax = temp.ymax;
    ett->buckets[j + 1].xofymin = temp.xofymin;
    ett->buckets[j + 1].slopeinverse = temp.slopeinverse;
    }
}


void MainWindow::storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv)
{
    (receiver->buckets[(receiver)->countEdgeBucket]).ymax = ym;
    (receiver->buckets[(receiver)->countEdgeBucket]).xofymin = (float)xm;
    (receiver->buckets[(receiver)->countEdgeBucket]).slopeinverse = slopInv;

    insertionSort(receiver);

    (receiver->countEdgeBucket)++;


}

void MainWindow::storeEdgeInTable (int x1,int y1, int x2, int y2)
{
    float m,minv;
    int ymaxTS,xwithyminTS, scanline;

    if (x2==x1)
    {
        minv=0.000000;
    }
    else
    {
    m = ((float)(y2-y1))/((float)(x2-x1));

    if (y2==y1)
        return;

    minv = (float)1.0/m;
    }

    if (y1>y2)
    {
        scanline=y2;
        ymaxTS=y1;
        xwithyminTS=x2;
    }
    else
    {
        scanline=y1;
        ymaxTS=y2;
        xwithyminTS=x1;
    }
    storeEdgeInTuple(&EdgeTable[scanline],ymaxTS,xwithyminTS,minv);


}

void MainWindow::removeEdgeByYmax(EdgeTableTuple *Tup,int yy)
{
    int i,j;
    for (i=0; i< Tup->countEdgeBucket; i++)
    {
        if (Tup->buckets[i].ymax == yy)
        {
            for ( j = i ; j < Tup->countEdgeBucket -1 ; j++ )
                {
                Tup->buckets[j].ymax =Tup->buckets[j+1].ymax;
                Tup->buckets[j].xofymin =Tup->buckets[j+1].xofymin;
                Tup->buckets[j].slopeinverse = Tup->buckets[j+1].slopeinverse;
                }
                Tup->countEdgeBucket--;
            i--;
        }
    }
}


void MainWindow::updatexbyslopeinv(EdgeTableTuple *Tup)
{
    int i;

    for (i=0; i<Tup->countEdgeBucket; i++)
    {
        (Tup->buckets[i]).xofymin =(Tup->buckets[i]).xofymin + (Tup->buckets[i]).slopeinverse;
    }
}


void MainWindow::on_fill_scan_clicked()
{
        int i, j, x1, ymax1, x2, ymax2, FillFlag = 0, coordCount;

        for (i=0; i<maxHt; i++)
        {
            for (j=0; j<EdgeTable[i].countEdgeBucket; j++)
            {
                storeEdgeInTuple(&ActiveEdgeTuple,EdgeTable[i].buckets[j].
                         ymax,EdgeTable[i].buckets[j].xofymin,
                        EdgeTable[i].buckets[j].slopeinverse);
            }

            removeEdgeByYmax(&ActiveEdgeTuple, i);

            insertionSort(&ActiveEdgeTuple);

            j = 0;
            FillFlag = 0;
            coordCount = 0;
            x1 = 0;
            x2 = 0;
            ymax1 = 0;
            ymax2 = 0;
            while (j<ActiveEdgeTuple.countEdgeBucket)
            {
                if (coordCount%2==0)
                {
                    x1 = (int)(ActiveEdgeTuple.buckets[j].xofymin);
                    ymax1 = ActiveEdgeTuple.buckets[j].ymax;
                    if (x1==x2)
                    {
                        if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2)))
                        {
                            x2 = x1;
                            ymax2 = ymax1;
                        }

                        else
                        {
                            coordCount++;
                        }
                    }

                    else
                    {
                            coordCount++;
                    }
                }
                else
                {
                    x2 = (int)ActiveEdgeTuple.buckets[j].xofymin;
                    ymax2 = ActiveEdgeTuple.buckets[j].ymax;

                    FillFlag = 0;
                    if (x1==x2)
                    {
                        if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2)))
                        {
                            x1 = x2;
                            ymax1 = ymax2;
                        }
                        else
                        {
                            coordCount++;
                            FillFlag = 1;
                        }
                    }
                    else
                    {
                        coordCount++;
                        FillFlag = 1;
                    }

                if(FillFlag)
                {
                    p1.setX(x1);p1.setY(i);
                    p2.setX(x2);p2.setY(i);
                    on_bress_clicked();
                }

            }

            j++;
        }
        updatexbyslopeinv(&ActiveEdgeTuple);
    }

        EdgeList.clear();
}
//============================ SCAN LINE END =============================================================
//============================ TRANSFORMATIONS ===========================================================
int* MainWindow::matMul3x3(double mat[3][3],int coord[3])
{
    int i,k,res[3];
    for (i = 0; i < 3; i++)
    {
            res[i]= 0;
            for (k = 0; k < 3; k++)
                res[i] += (int)(mat[i][k]*(double)coord[k]);

    }
    return res;
}

//========= Function for translation ==================================
void MainWindow::translate(int tx,int ty)
{
    int i,len=EdgeList.size();
    // matrix for translation
    double mat[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};

    for(i=0;i<len;i++)
    {
        int* coord=(int*)malloc(3*sizeof(int));
        coord[0]=EdgeList[i].first;
        coord[1]=EdgeList[i].second;
        coord[2]=1;
        coord=matMul3x3(mat,coord);
        EdgeList[i].first=coord[0]/coord[2];
        EdgeList[i].second=coord[1]/coord[2];
    }
}



void MainWindow::on_translate_clicked()
{
    int k=ui->gridsize->value();
    int tx=ui->trans_x->value();
    int ty=ui->trans_y->value();
    tx*=k;
    ty*=k;
    ty=-ty;

    translate(tx,ty);

    drawPoly();
}

void MainWindow::on_scale_clicked()
{
    int sx=ui->scl_x->value();
    int sy=ui->scl_y->value();
    //Point about which to be scaled
    int piv_x=p1.x();
    int piv_y=p1.y();

    int del_x=piv_x-img.width()/2;
    int del_y=piv_y-img.height()/2;
    int i,len=EdgeList.size();

    translate(-del_x,-del_y);
    // matrix for scaling
    double mat[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};

    for(i=0;i<len;i++)
    {
        int* coord=(int*)malloc(3*sizeof(int));
        coord[0]=EdgeList[i].first;
        coord[1]=EdgeList[i].second;
        coord[2]=1;
        coord=matMul3x3(mat,coord);
        EdgeList[i].first=coord[0]/coord[2];
        EdgeList[i].second=coord[1]/coord[2];

//        EdgeList[i].first=changeX(EdgeList[i].first);
//        EdgeList[i].second=changeY(EdgeList[i].second);
    }
    translate(del_x,del_y);
    drawPoly();
}

void MainWindow::on_rotate_clicked()
{
    int angle=ui->rot->value();
    double dang=(double)angle*M_PI/180.0;
    double sinang=sin(dang);
    double cosang=cos(dang);

    //Point about which to be scaled
    int piv_x=p1.x();
    int piv_y=p1.y();

    int del_x=-(piv_x-img.width()/2);
    int del_y=(piv_y-img.height()/2);

    translate(del_x,del_y);
    int i,len=EdgeList.size();

    // matrix for rotation
    double mat[3][3]={{cosang,-sinang,0},{sinang,cosang,0},{0,0,1}};

    for(i=0;i<len;i++)
    {
        int* coord=(int*)malloc(3*sizeof(int));
        coord[0]=EdgeList[i].first;
        coord[1]=EdgeList[i].second;
        coord[2]=1;
        coord=matMul3x3(mat,coord);
        EdgeList[i].first=coord[0]/coord[2];
        EdgeList[i].second=coord[1]/coord[2];
    }
    translate(-del_x,-del_y);
    drawPoly();
}

//=========================================================================================================
void MainWindow::drawPoly()
{
    int i,len=EdgeList.size()-1;
    //Reset the screen and draw the grid
    on_showgrid_clicked();

    // Draw the polygon
    for(i=0;i<len;i++)
    {
        p1.setX(EdgeList[i].first);
        p2.setX(EdgeList[(i+1)%len].first);

        p1.setY(EdgeList[i].second);
        p2.setY(EdgeList[(i+1)%len].second);

        on_bress_clicked();
    }
}





