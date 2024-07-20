#include <iostream>
#include <cstdint>
#include <cassert>

class IntArray
{
private:
	size_t m_size; //private, because we can't change it and we only need it for initializing the array in the constructor
	int32_t* m_array;

public:
	explicit IntArray(size_t size)
		: m_size{ size }
		, m_array{ nullptr }

	{
		assert(m_size > 0 && "IntArray size should be a positive integer");

		m_array = new int32_t[m_size]{};
	}

	IntArray(const IntArray& array)
		:m_size{ array.m_size }
	{

		m_array = new int32_t[m_size] {}; //deep copy

		for (size_t count{ 0 }; count < array.m_size; ++count)
			m_array[count] = array.m_array[count];
	}

	~IntArray()
	{
		delete[] m_array;
	}

	friend std::ostream operator<< (std::ostream& out, const IntArray& array)
	{
		for (int32_t count{}; count < array.m_size; ++count)
		{
			out << array.m_array[count] << ' ';
		}
		return out;
	}


};


int main()
{

	return 0;
}
