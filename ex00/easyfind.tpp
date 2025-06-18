#include "easyfind.hpp"

template <typename T> typename T::iterator easyfind (T &container, int needle)
{
	typename T::iterator iteri = std::find(container.begin(), container.end(), needle);
	if (iteri == container.end())
		throw std::runtime_error("Unable to find the needle in the container");
	return (iteri);
}