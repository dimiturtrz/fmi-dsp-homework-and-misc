#include <iostream>
#include "Stack.hpp"
using namespace std;

int main () {
	Stack<int> st;
	st.push(5);
	st.push(15);
	while(!st.isEmpty()) {
		std::cout<< *(st.getTop())<< std::endl;
		st.pop();
	}

	return 0;
}
