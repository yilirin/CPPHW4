#include "Figures.h"
#include <iostream>

void Figure::setLanguage(int para) {
    language = para;
}

void Line::inputFigure() {
//    switch(language) {
//        case CHINESE:
//            std::cout << "请输入线段的起点和终点坐标(x1, y1, x2, y2) :" << std::endl;
//            break;
//        case ENGLISH:
//            std::cout << "Please input the two ends' coordinates of the line(x1, y1, x2, y2):" << std::endl;
//            break;
//    }
    std::cout << "请输入线段的起点和终点坐标(x1, y1, x2, y2) :" << std::endl;
    std::cin >> x1 >> y1 >> x2 >> y2;
}

void Line::drawFigure() {
//    switch(language) {
//        case CHINESE:
//            std::cout << "线段";
//            break;
//        case ENGLISH:
//            std::cout << "line";
//            break;
//    }
    std::cout << "线段";
    std::cout << "（" << x1 << ", " << y1 << ", "<< x2 << ", " << y2 << "）" << std::endl;
}

void Rectangle::inputFigure() {
//    switch(language) {
//        case CHINESE:
//            std::cout << "请输入矩形的左上角和右下角坐标(x1, y1, x2, y2) ：" << std::endl;
//            break;
//        case ENGLISH:
//            std::cout << "Please input the coordinates of top-left-corner and bottom-right-corner(x1, y1, x2, y2):" << std::endl;
//            break;
//    }
    std::cout << "请输入矩形的左上角和右下角坐标(x1, y1, x2, y2) ：" << std::endl;
    std::cin >> x1 >> y1 >> x2 >> y2;
}

void Rectangle::drawFigure() {
//    switch(language) {
//        case CHINESE:
//            std::cout << "矩形";
//            break;
//        case ENGLISH:
//            std::cout << "rectangle";
//            break;
//    }
    std::cout << "矩形";
    std::cout << "（" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ")" << std::endl;
}

void Circle::inputFigure() {
//    switch(language) {
//        case CHINESE:
//            std::cout << "请输入圆的圆心坐标和半径(x, y, radius) ：" << std::endl;
//            break;
//        case ENGLISH:
//            std::cout << "Please input the coordinates of the centre of circle and radius(x, y, radius):" << std::endl;
//            break;
//    }
    std::cout << "请输入圆的圆心坐标和半径(x, y, radius) ：" << std::endl;
    std::cin >> x >> y >> radius;
}

void Circle::drawFigure() {
//    switch(language) {
//        case CHINESE:
//            std::cout << "圆";
//            break;
//        case ENGLISH:
//            std::cout << "circle";
//            break;
//    }
    std::cout << "圆";
    std::cout << "（" << x << ", " << y << ", " << radius << "）" << std::endl;
}

void FigureManager::input(){
    factories[fcount++] = new LineFactory;
    factories[fcount++] = new RectangleFactory;
    factories[fcount++] = new CircleFactory;
//        factories[fcount++] = new TriangleFactory;
//    std::cout << "请选择语言(language)(0: 中文,1: English):" << std::endl;
//    std::cin >> language;
    for (num_of_figures = 0; num_of_figures < 100; ++num_of_figures) {
        do {
            std::cout << "请输入图形的种类(";
            for (int i = 0; i < fcount; ++i) {
                std::cout << i << ": " << factories[i]->name() << ", ";
            }

            std::cout << "-1：结束)："<<std::endl;

            std::cin >> shape;
        } while (shape < -1 || shape > 2);
        if (shape == -1) {
            fcount = 0;
            break;
        }
        figureBuf[num_of_figures] = factories[shape]->create();
        figureBuf[num_of_figures]->setLanguage(language);
        figureBuf[num_of_figures]->inputFigure();
    }
}

void FigureManager::display() {
    for (int i = 0; i < num_of_figures; ++i) {
        figureBuf[i]->drawFigure();
    }
}

const char *LineFactory::name() {
    return "线段";
}

Figure *LineFactory::create() {
    return new Line;
}

Figure *RectangleFactory::create() {
    return new Rectangle;
}

const char *RectangleFactory::name() {
    return "矩形";
}

Figure *CircleFactory::create() {
    return new Circle;
}

const char *CircleFactory::name() {
    return "圆";
}
