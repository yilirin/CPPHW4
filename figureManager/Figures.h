class Figure{
protected:
    int language;
public:
    void setLanguage(int);
    virtual void inputFigure() = 0;
    virtual void drawFigure() = 0;
};

class Factory{
public:
    virtual Figure *create() = 0;
    virtual const char *name() = 0;
};

class Line: public Figure{
    double x1,y1,x2,y2;
public:
    void inputFigure();
    void drawFigure();
};

class LineFactory: public Factory{
    virtual Figure *create() override;
    virtual const char *name() override;
};
class Rectangle: public Figure{
    double x1,y1,x2,y2;
public:
    void inputFigure();
    void drawFigure();
};
class RectangleFactory: public Factory{
    virtual Figure *create() override;
    virtual const char *name() override;
};
class Circle:public Figure{
    double x,y,radius;
public:
    void inputFigure();
    void drawFigure();
};
class CircleFactory:public Factory{
    virtual Figure *create() override;
    virtual const char *name() override;
};
class FigureManager{
    Figure * figureBuf[100];
    Factory * factories[10];
    int num_of_figures;
    int fcount;
    int shape;
    int language;
public:
    void input();
    void display();
};

enum FigureShape {LINE,RECTANGLE,CIRCLE};
enum LanguageType {CHINESE,ENGLISH};