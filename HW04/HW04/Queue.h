
#ifndef QUEUE_H_
#define QUEUE_H_

class QueueOverFlow {

};
class QueueUnderFlow {

};

template <class T>

class Queue {


private:
	T** data;
	int size = 0;
	int maxSize = 0;

//	Shifts everything to the front of the array
	void shiftItems() {
		for(int i = 0;i < size;i++) {
			data[i] = data[i + 1];
		}
	}

public:
	Queue(int size) {
		data = new T*[size];
		maxSize = size;
	}

	int length() {
		return size;
	}

	void push(T* d) {
		if (size < maxSize) {
			data[size] = d;
			size++;
		}
		else {
			throw new QueueOverFlow();
		}
	}

	T* pop() {
		if(size > 0) {
			T* curr = data[0];
			shiftItems();
			size--;
			return curr;
		}
		else {
			throw new QueueUnderFlow();
		}
	}

	T* top() {
		return data[0];
	}

	void empty() {
		for(int i = 0;i < size;i++) {
			delete data[i];
		}
		size = 0;
	}

};



#endif
