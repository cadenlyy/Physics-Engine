#include "s_vector.h"

template<typename T>
s_vector<T>::s_vector(){
}

template<typename T>
s_vector<T>::s_vector(s_vector& cv){
	std::mutex mt;
	std::vector<T> v = cv.v;

}

template<typename T>
void s_vector<T>::s_push_back(T a) {
	std::lock_guard<std::mutex> lock(mt);
	v.push_back(a);
}

template<typename T>
void s_vector<T>::s_pop_back() {
	std::lock_guard<std::mutex> lock(mt);
	v.pop_back();
}

template<typename T>
T s_vector<T>::s_front() {
	std::lock_guard<std::mutex> lock(mt);
	return v.front();
}

template<typename T>
T s_vector<T>::s_back() {
	std::lock_guard<std::mutex> lock(mt);
	return v.back();
}

template<typename T>
std::vector<T> s_vector<T>::s_get() {
	std::lock_guard<std::mutex> lock(mt);
	std::vector <T> vs;
	for (auto i : v) vs.push_back(i);
	return vs;
}

template<typename T>
void s_vector<T>::s_equ(std::vector<T> ev){
	std::lock_guard<std::mutex> lock(mt);
	for (auto i : ev) v.push_back(i);
}
