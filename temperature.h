
#ifndef TEMP_TEMPERATURE_H
#define TEMP_TEMPERATURE_H

class Temperature{
	
	public:
	
		//default temperature constructor
		Temperature(double = 0, char = 'C');
	
		void Input();
		bool Set(double, char);
		bool Convert(char);
		void Increment(int, char);
		bool SetFormat(char f);
	
		double GetDegrees() const;
		char GetScale() const;
		void Show() const;
		int Compare(const Temperature& d) const;
	
	private:
	
		double temp;
		char scale;
		char format;
	
};

#endif