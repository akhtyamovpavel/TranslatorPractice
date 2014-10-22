#ifndef INT_WITH_INFINITY_H
#define INT_WITH_INFINITY_H

class IntWithInfinity {
int value;
public:
	static const int INF;

	const int getValue() const;

	void setValue(int value1);
	
	IntWithInfinity();

	explicit IntWithInfinity(int value1);

	IntWithInfinity operator + (const IntWithInfinity& a);

	IntWithInfinity& operator += (const IntWithInfinity& a);

	bool operator >= (const IntWithInfinity& a) const;

	bool operator < (const IntWithInfinity& a) const;

	bool operator > (const IntWithInfinity& a) const;
};



#endif // INT_WITH_INFINITY_H
