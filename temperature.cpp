
#include "temperature.h"

#include <iostream>
#include <iomanip>

using namespace std;

Temperature::Temperature(double temperature, char sc){
	//check the scale 
	if(sc == 'f' || sc == 'F' || sc == 'k' || sc == 'K' || sc == 'c' || sc == 'C'){
		scale = sc;
	
		//check the value based on the scale, celcius
		if(scale == 'C' || scale == 'c'){
			if(temperature < -273.15){
				temp = 0;
				format = 'D';
			}
			else {
				temp = temperature;
				format = 'D';
			}
		}
		//check the value based on the scale, fahrenheit
		else if(scale == 'F' || scale == 'f'){
			if(temperature < -459.67){
				temp = 0;
				scale = 'C';
				format = 'D';
			}
			else {
				temp = temperature;
				format = 'D';
			}
		}
		//check the value based on the scale, kelvin
		else if(scale == 'K' || scale == 'k'){
			if(temperature < 0){
				temp = 0;
				scale = 'C';
				format = 'D';
			}
			else {
				temp = temperature;
				format = 'D';
			}
		}
	}
	else{
		scale = 'C';
		temp = 0;
		format = 'D';
	}
}

void Temperature::Input() {
	
	double t;
	char s;
	
	//loop until a valid response
	bool notValid = true;
	while(notValid){
		
		//ask user for input
		cout << '\n' << "Please enter a temperature and scale";
		cin >> t >> s;
		
		//check scale entered 
		if(s == 'C' || s == 'c' || s == 'K' || s == 'k' || s == 'F' || s == 'f'){
			cout << '\n' << "Valid scale";
			
			//check the value based on the scale, celcius
			if(s == 'C' || s == 'c'){
				if(t >= -273.15){
					temp = t;
					scale = s;
					format = 'D';
					cout << '\n' << "Valid temperature";
					notValid = false;
				}
				else {
					cout << '\n' << "Invalid temperature, try again";
				}
			}
				
			//check the value based on the scale, fahrenheit
			else if(s == 'F' || s == 'f'){
				if(t >= -459.67){
					temp = t;
					scale = s;
					format = 'D';
					cout << '\n' << "Valid temperature";
					notValid = false;
				}
				else {
					cout << '\n' << "Invalid temperature, try again";
				}
			}
				
			//check the value based on the scale, kelvin
			else if(s == 'K' || s == 'k'){
				if(t >= 0){
					temp = t;
					scale = s;
					format = 'D';
					cout << '\n' << "Valid temperature";
					notValid = false;
				}
				else {
					cout << '\n' << "Invalid temperature, try again";
				}
			}
		}
		
		else{
			cout << '\n' << "Invalid temperature entered, try again";
		}
	}
	
}

bool Temperature::Set(double t, char s){
	
	//check scale entered 
	if(s == 'C' || s == 'c' || s == 'K' || s == 'k' || s == 'F' || s == 'f'){

		
		//check the value based on the scale, celcius
		if(s == 'C' || s == 'c'){
			if(t >= -273.15){
				temp = t;
				scale = s;

				return true;
			}
			else {
				return false;
			}
		}
				
		//check the value based on the scale, fahrenheit
		else if(s == 'F' || s == 'f'){
			if(t >= -459.67){
				temp = t;
				scale = s;

				return true;
			}
			else {
				return false;
			}
		}
				
		//check the value based on the scale, kelvin
		else if(s == 'K' || s == 'k'){
			if(t >= 0){
				temp = t;
				scale = s;

				return true;
					
			}
			else {
				return false;
			}
		}
	}
		
	else{
		return false;
	}
}


//conversion equations used
// c = k - 273.15
// c = ( f - 32 ) * (5/9)
// f = ( c * (9/5)) + 32

bool Temperature::Convert(char ns){
	
	if(toupper(ns) == toupper(scale)){
		cout << '\n' << "already in this scale";
		return false;
	}
	//check the new scale
	else if(ns == 'C' || ns == 'c'){
		
		//check current scale
		if(scale == 'K' || scale == 'k'){
			scale = ns;
			temp = temp - 273.15;

			return true;
		}
		else if(scale == 'F' || scale == 'f'){
			scale = ns;
			temp = (((temp - 32)*5)/9);

			return true;
		}
		
	}
	//check the new scale
	else if(ns == 'K' || ns == 'k'){
		
		//check current scale
		if(scale == 'C' || scale == 'c'){
			scale = ns;
			temp = temp + 273.15;
			return true;
		}
		else if(scale == 'F' || scale == 'f'){
			scale = ns;
			temp = (((temp - 32)*5)/9) + 273.15;
			return true;
		}
	}
	//check the new scale
	else if(ns == 'F' || ns == 'f'){
		
		//check current scale
		if(scale == 'C' || scale == 'c'){
			scale = ns;
			temp = ((temp * 9)/5) + 32;
			return true;
		}
		else if(scale == 'K' || scale == 'k'){
			scale = ns;
			temp = (((temp - 273.15) * 9)/5) + 32;
			return true;
		}
		
	}
	else{
		return false;
	}
}

double Temperature::GetDegrees() const{
	return temp;
}

char Temperature::GetScale() const{
	return scale;
}

bool Temperature::SetFormat(char f) {
	
	//check f then set format if valid
	if(f == 'D' || f == 'd'){
		format = f;
		return true;
	}
	else if(f == 'P' || f == 'p'){
		format = f;
		return true;
	}
	else if(f == 'L' || f == 'l'){
		format = f;
		return true;
	}
	else{
		return false;
	}
}

void Temperature::Show() const{
	
	//print out default format
	if(format == 'D' || format == 'd'){
		cout << '\n' << GetDegrees() << " " << GetScale();
	}
	//print out one decimal place 
	else if(format == 'P' || format == 'p'){
		cout << fixed << showpoint << setprecision(1) << GetDegrees() << " " << GetScale();
	}
	//long format
	else{
		if(GetScale() == 'F' || GetScale() == 'f'){
			cout << '\n' << GetDegrees() << " Fahrenheit";

		}
		else if(GetScale() == 'C' || GetScale() == 'c'){
			cout << '\n' << GetDegrees() << " Celsius";
		}
		else{
			cout << '\n' << GetDegrees() << " Kelvin";

		}
	}
	
	cout << '\n';
}

int Temperature::Compare(const Temperature& d) const{
	
	double temp1;
	double temp2;
	
	//compare the two objects in celcius
	if(GetScale() == 'F' || GetScale() == 'f'){
		
		//convet first temp to celsius
		temp1 = (((temp - 32)*5)/9);
		
		//check scale of second temperature and covert to celsius
		if(d.GetScale() == 'F' || d.GetScale() == 'f'){
			temp2 = (((d.temp - 32)*5)/9);
		}
		else if(d.GetScale() == 'K' || d.GetScale() == 'k'){
			temp2 = (d.temp - 273.15);
		}
	}
	if(GetScale() == 'K' || GetScale() == 'k'){
		
		//convert first temp to celsius
		temp1 = temp - 273.15;
		
		//check scale of second temperature and covert to celsius
		if(d.GetScale() == 'F' || d.GetScale() == 'f'){
			temp2 = (((d.GetDegrees() - 32)*5)/9);
		}
		else if(d.GetScale() == 'K' || d.GetScale() == 'k'){
			temp2 = d.GetDegrees() - 273.15;
		}
	}
	else{
		temp1 = GetDegrees();
		if(d.GetScale() == 'F' || d.GetScale() == 'f'){
			temp2 = (((d.temp - 32)*5)/9);
		}
		else if(d.GetScale() == 'K' || d.GetScale() == 'k'){
			temp2 = (d.temp - 273.15);
		}
	}
	
	//compare
	if(temp1 < temp2){
		return (-1);
	}
	else if(temp1 == temp2){
		return 0;
	}
	else{
		return 1;
	}
}

void Temperature::Increment(int t, char s){
	
	//if they are already the same scale
	if(toupper(s) == toupper(scale)){
		temp = temp + t;
	}
	//check the current scale
	else if(scale == 'C'  || scale == 'c' ){
		//check converting scale
		if(s == 'K' || s == 'k'){
			temp = temp + (t - 273.15);
		}
		else if(s == 'F' || s == 'f'){
			temp = temp + (((t - 32)*5)/9);
		}
	}
	else if(scale == 'K' || scale == 'K' ){
		//check converting scale
		if(s == 'C' || s == 'c'){
			temp = temp + (t + 273.15);
		}
		else if(s == 'F' || s == 'f'){
			temp = temp + ((((t - 32)*5)/9) + 273.15);
		}
	}
	else if(scale == 'F'  || scale == 'f' ){
		//check converting scale
		if(s == 'K' || s == 'k'){
			temp = temp + ((((t - 273.15) * 9)/5) + 32);
		}
		else if(s == 'C' || s == 'c'){
			temp = temp + (((t * 9)/5) + 32);
		}
	}
}







