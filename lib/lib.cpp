#include "hide.h"
#include <type_traits>



struct image_info
{
    int width;
    int height;
};


template<typename T>
struct converter
{
};

template<typename T>
struct converter<T*>
{
    using type = typename converter<T>::type;
};

template<typename T>
struct converter<const T*>
{
    using type = typename converter<T>::type;
};

template<>
struct converter<h_image_info>
{
    using type = image_info;
};

template<>
struct converter<image_info>
{
    using type = h_image_info;
};

template<typename T>
struct converter<std::unique_ptr<T>>
{
    using type = std::unique_ptr<typename converter<T>::type>;
};

template<typename T>
struct converter<unique_ptr<T>>
{
    using type = unique_ptr<typename converter<T>::type>;
};


template<typename T>
auto& fellow(T& p)
{
    return reinterpret_cast<converter<T>::type&>(p);
}

template<typename T>
auto fellow(T* p)
{
	return reinterpret_cast<converter<T>::type*>(p);
}

template<typename T>
auto fellow(const T* p)
{
	return reinterpret_cast<const converter<T>::type*>(p);
}

size_t h_image_info::obj_size()
{
    return sizeof(image_info);
}

void h_image_info::destroy()
{
    auto p = fellow(this);
    delete p;
}

unique_ptr<h_image_info> h_image_info::make_unique()
{
    auto ptr = unique_ptr<h_image_info>(fellow(new image_info()));
    return std::move(ptr);
}

int& h_image_info::width()
{
    auto p = fellow(this);
    return p->width;
}

int& h_image_info::height()
{
    auto p = fellow(this);
    return p->height;
}


int h_image_info::width() const noexcept
{
    auto p = fellow(this);
    return p->width;
}