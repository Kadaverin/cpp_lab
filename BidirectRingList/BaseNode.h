#pragma once
#include "pch.h"

template<typename T>
struct BaseNode {
	T data;
	BaseNode *next;
};