
#include "triangle.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

//making the triangle 
Triangle::Triangle(int size, char border, char filler) {
    SetSize(size);
    SetBorder(border);
    SetFill(filler);
}

//sets side length
void Triangle::SetSize(int s) {
    //if the size of the triangle is greater than 39 set the size to 39
    if(s > 39){
        s = 39;
    }
    //if the size of the triangle is less than 1 set the size to 1
    else if(s < 1){
        s = 1;
    }
    length = s;
}

//sets the border of triangle
void Triangle::SetBorder(char b) {
    //default is #
    if(b == ' ' || int(b) > 126 || int(b) < 33){
        b = '#';
    }
    borderC = b;
}

//sets the filler of the triangle
void Triangle::SetFill(char f) {
    //default is *
    if(f == ' ' || int(f) > 126 || int(f) < 33){
        f = '*';
    }
    fillerC = f;
}

//returns the size of the triangle
int Triangle::GetSize() const {
    return length;
}

//calculates the area of the triangle
double Triangle::Area() const {
    double area = ((sqrt(3))/4)*(length * length);
    return area;
}

//calculates the perimeter of the triangle
int Triangle::Perimeter() const {
    return (3*length);
}

//prints out the triangle
void Triangle::Draw() const {
	
	//number of rows
	for(int i = 0; i < length; i++){
		
		//number of empty spaces
		for(int j = 0; j < length-i; j++){
			cout << " ";
		}
		
		//printing the triangle
		for(int k = 0; k <= i; k++){
			if(i == 0 || i == length - 1 || k == 0 || k == i){
				cout << borderC << " ";
			}
			else if(i != 0 || i != length - 1 || k != 0 || k != i){
				cout << fillerC << " ";
			}
		}
		
		cout << '\n';
	}
    
}



//increase the size of the triangle size by one
void Triangle::Grow() {
    //check to see if triangle is the max size
    int check = GetSize();
    if(check == 39){
        cout << '\n' << "Triangle is already maximum size";
        cout << '\n';
    }
    //otherwise change the size of the triangle
    else{
        length++;
        SetSize(length);
    }
}

//decrease the size of the triangle by one
void Triangle::Shrink() {
    //check to see if the triangle is the minimum size
    int check = GetSize();
    if(check == 1){
        cout << '\n' << "Triangle is already minimum size";
        cout << '\n';
    }
    //otherwise change the size of the triangle
    else {
        length--;
        SetSize(length);
    }

}

//gives all the information of the triangle, includes redrawing it
void Triangle::Summary() const {

	Draw();
    
    //print out triangle info
    cout << '\n' << "The size of the side of the triangle is: " << GetSize();
    cout << '\n' << "The perimeter of the triangle is: " << Perimeter();
    cout << '\n' << "The area of the triangle is: " << Area();
}