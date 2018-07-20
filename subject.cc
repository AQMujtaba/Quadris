#include <vector>
#include "subject.h"
#include "observer.h"

using namespace std;

void Subject::attach(shared_ptr<Observer> observer) {
	observers.emplace_back(observer);
}

void Subject::detach(shared_ptr<Observer> observer) { 
	for (auto ob = observers.begin(); ob != observers.end(); ++ob) {
		if (*ob == observer) {
			observers.erase(ob);
			break;
		}
	}
}

void Subject::notifyObservers() {
	for (auto &ob: observers) ob->notify(*this);
}
