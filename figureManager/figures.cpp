#include "Figures.h"
#include <iostream>

void Figure::setLanguage(int para) {
    language = para;
}

void Line::inputFigure() {
    switch(language) {
        case CHINESE:
            std::cout << "请输入线段的起点和终点坐标(x1, y1, x2, y2) :" << std::endl;
            break;
        case ENGLISH:
            std::cout << "Please input the two ends' coordinates of the line(x1, y1, x2, y2):" << std::endl;
            break;
    }
    std::cin >> x1 >> y1 >> x2 >> y2;
}

void Line::drawFigure() {
    switch(language) {
        case CHINESE:
            std::cout << "线段";
            break;
        case ENGLISH:
            std::cout << "line";
            break;
    }
    std::cout << "（" << x1 << ", " << y1 << ", "<< x2 << ", " << y2 << "）" << std::endl;
}

void Rectangle::inputFigure() {
    switch(language) {
        case CHINESE:
            std::cout << "请输入矩形的左上角和右下角坐标(x1, y1, x2, y2) ：" << std::endl;
            break;
        case ENGLISH:
            std::cout << "Please input the coordinates of top-left-corner and bottom-right-corner(x1, y1, x2, y2):" << std::endl;
            break;
    }
    std::cin >> x1 >> y1 >> x2 >> y2;
}

void Rectangle::drawFigure() {
    switch(language) {
        case CHINESE:
            std::cout << "矩形";
            break;
        case ENGLISH:
            std::cout << "rectangle";
            break;
    }
    std::cout << "（" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ")" << std::endl;
}

void Circle::inputFigure() {
    switch(language) {
        case CHINESE:
            std::cout << "请输入圆的圆心坐标和半径(x, y, radius) ：" << std::endl;
            break;
        case ENGLISH:
            std::cout << "Please input the coordinates of the centre of circle and radius(x, y, radius):" << std::endl;
            break;
    }
    std::cin >> x >> y >> radius;
}

void Circle::drawFigure() {
    switch(language) {
        case CHINESE:
            std::cout << "圆";
            break;
        case ENGLISH:
            std::cout << "circle";
            break;
    }
    std::cout << "（" << x << ", " << y << ", " << radius << "）" << std::endl;
}

void FigureManager::input() {
    std::cout << "请选择语言(language)(0: 中文,1: English):" << std::endl;
    std::cin >> language;
    for (num_of_figures = 0; num_of_figures < 100; ++num_of_figures) {
        do
        {
            switch(language) {
                case CHINESE:
                    std::cout << "请输入图形的种类(0：线段，1：矩形，2：圆，-1：结束)：" << std::endl;
                    break;
                case ENGLISH:
                    std::cout << "Please input the type of figure(0: line, 1: rectangle, 2: circle, -1: end):" << std::endl;
                    break;
            }
            std::cin >> shape;
        }while(shape < -1||shape > 2);//change on 2;
        if (shape == -1 ) break;
        switch (shape)
        {
            case LINE:
                figureBuf[num_of_figures] = new Line;
                break;
            case RECTANGLE:
                figureBuf[num_of_figures] = new Rectangle;
                break;
            case CIRCLE:
                figureBuf[num_of_figures] = new Circle;
                break;
        }
        if(figureBuf[num_of_figures] != 0) {
            figureBuf[num_of_figures]->setLanguage(language);
            figureBuf[num_of_figures]->inputFigure();//动态绑定
        }
    }
}

void FigureManager::display() {
    for (int i = 0; i < num_of_figures; ++i) {
        figureBuf[i]->drawFigure();
    }
}
