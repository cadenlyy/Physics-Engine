#pragma once
#include<string>
#include<mutex>
#include<vector>

template <typename T>
class s_vector{
private:
	std::mutex mt;
	std::vector <T> v;

public:
	s_vector();
	s_vector(s_vector& cv);
	void s_push_back(T a);
	void s_pop_back();
	T s_front();
	T s_back();
	std::vector<T> s_get();
	void s_equ(std::vector<T> ev);
};
