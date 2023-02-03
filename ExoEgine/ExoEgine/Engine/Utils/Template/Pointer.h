#pragma once
template<typename T> struct RemovePointer {
	using Type = T;
};

template<typename T> struct RemovePointer<T*> {
	using Type = std::remove_pointer<T>::type;
};