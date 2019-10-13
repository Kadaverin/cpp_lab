#pragma once

template<typename T>
struct BaseNode {
	T data;
	BaseNode *next;
};