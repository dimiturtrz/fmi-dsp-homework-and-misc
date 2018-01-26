#include <iostream>
#include "Queue.hpp"
using namespace std;

int main () {
	Queue<int> q;
	q.enqueue(5);
	q.enqueue(15);
	q.enqueue(25);
	q.enqueue(35);
	q.enqueue(45);

	Queue<int> q2(q);
	while(!q2.isEmpty()) {
		std::cout<< q2.getFront()<< std::endl;
		q2.dequeue();
	}

	return 0;
}
