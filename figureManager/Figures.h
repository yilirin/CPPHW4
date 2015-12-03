class Figure{
protected:
    int language;
public:
    void setLanguage(int);
    virtual void inputFigure() = 0;
    virtual void drawFigure() = 0;
};
class Line:public Figure{
    double x1,y1,x2,y2;
public:
    void inputFigure();
    void drawFigure();
};
class Rectangle:public Figure{
    double x1,y1,x2,y2;
public:
    void inputFigure();
    void drawFigure();
};
class Circle:public Figure{
    double x,y,radius;
public:
    void inputFigure();
    void drawFigure();
};
class FigureManager{
    Figure * figureBuf[100];
    int num_of_figures;
    int shape;
    int language;
public:
    void input();
    void display();
};
enum FigureShape {LINE,RECTANGLE,CIRCLE};
enum LanguageType {CHINESE,ENGLISH};