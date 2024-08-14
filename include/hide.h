#pragma once
#include <memory>

template<typename T>
struct release_h
{
	void operator()(T* p)const
	{
		p->destroy();
	}
};

template<typename T>
using unique_ptr = std::unique_ptr<T, release_h<T>>;
struct h_image_info
{
~h_image_info() = delete;
static size_t obj_size();
void destroy();
static unique_ptr<h_image_info> make_unique();

int& width();
int& height();

int width() const noexcept;
};