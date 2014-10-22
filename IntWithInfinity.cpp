#include "IntWithInfinity.h"

const int IntWithInfinity::getValue() const{
	return value;
}

void IntWithInfinity::setValue(int value1) {
	value = value1;
}
	
IntWithInfinity::IntWithInfinity() {
	value = 0;
}

IntWithInfinity::IntWithInfinity(int value1) {
	if (value1 == INF) {
		value = INF;
		return;
	}
	value = value1;

}

IntWithInfinity IntWithInfinity::operator + (const IntWithInfinity& a) {
	IntWithInfinity result;
	if (a.getValue() == INF || getValue() == INF) {
		result.setValue(INF);
	} else {
		result.setValue(getValue() + a.getValue());
	}
	return result;
}

IntWithInfinity& IntWithInfinity::operator += (const IntWithInfinity& a) {
	if (a.getValue() == INF || getValue() == INF) {
		setValue(INF);
	} else {
		setValue(getValue() + a.getValue());
	}
	return *this;
}

bool IntWithInfinity::operator >= (const IntWithInfinity& a) const {
	if (getValue() == INF) {
		return true;
	}
	if (a.getValue() == INF) {
		return false;
	}
	return getValue() >= a.getValue();
}

bool IntWithInfinity::operator < (const IntWithInfinity& a) const {
	if (a.getValue() == INF) {
		return true;
	}
	if (getValue() == INF) {
		return false;
	}
	return getValue() < a.getValue();
}


bool IntWithInfinity::operator > (const IntWithInfinity & a) const {
	if (a.getValue() == INF) {
		return false;
	}
	if (getValue() == INF) {
		return true;
	}

	return getValue() > a.getValue();
}

