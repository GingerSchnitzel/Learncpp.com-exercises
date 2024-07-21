#include <iostream>
#include <cstdint>
#include <cassert>
#include <algorithm>

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
		: m_size{ array.m_size }
	{

		m_array = new int32_t[m_size]{}; //deep copy

		for (size_t count{ 0 }; count < array.m_size; ++count)
			m_array[count] = array.m_array[count];
	}

	~IntArray()
	{
		delete[] m_array;
		m_array = nullptr;
	}

	friend std::ostream& operator<< (std::ostream& out, const IntArray& array)
	{
		for (int32_t count{}; count < array.m_size; ++count)
		{
			out << array.m_array[count] << ' ';
		}
		return out;
	}

	int32_t& operator[] (const size_t index)
	{

		assert(index >= 0);
		assert(index < m_size);
		return m_array[index];

	}

	friend void swap(IntArray& first, IntArray& second)
	{
		using std::swap;

		swap(first.m_size, second.m_size);
		swap(first.m_array, second.m_array);
	}

	IntArray& operator= (IntArray other)
	{
		swap(*this, other);
		return *this;
	}
};


IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto ref{ a }; 
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}
