
#ifndef TRIANGLE_TRIANGLE_H
#define TRIANGLE_TRIANGLE_H

class Triangle {

public:
    //default triangle constructor
    Triangle(int, char = '#', char = '*');

    //all the constructors to access the triangle
    void SetSize(int);
    void SetBorder(char);
    void SetFill(char);
	void Grow();
    void Shrink();
	void Summary() const;
    void Draw() const;
	
    double Area() const;
	
    int Perimeter() const;
    int GetSize() const;

private:
    //triangle characteristics
    int length;
    char borderC;
    char fillerC;
};


#endif 
