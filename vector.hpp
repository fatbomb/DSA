
template <typename T>
class Vector
{
private:
    T *m_data;
    int m_size;
    int m_capacity;

public:
    Vector()
    {
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }
    Vector(int n)
    {
        m_data = new T[n];
        m_size = 0;
        m_capacity = n;
    }

    ~Vector()
    {
        delete[] m_data;
    }

    void push_back(T value)
    {
        if (m_size == m_capacity)
        {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        m_data[m_size++] = value;
    }

    void pop_back()
    {
        if (m_size > 0)
        {
            --m_size;
        }
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= m_size)
        {
            throw std::out_of_range("Vector::operator[]: index out of range");
        }
        return m_data[index];
    }

    const T &operator[](int index) const
    {
        if (index < 0 || index >= m_size)
        {
            throw std::out_of_range("Vector::operator[]: index out of range");
        }
        return m_data[index];
    }

    int size() const
    {
        return this->m_size;
    }

    int capacity() const
    {
        return m_capacity;
    }

    void reserve(int newCapacity)
    {
        if (newCapacity <= m_capacity)
        {
            return;
        }
        T *newData = new T[newCapacity];
        for (int i = 0; i < m_size; ++i)
        {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_capacity = newCapacity;
    }
    T *begin()
    {
        return &m_data[0];
    }
    const T *begin() const
    {
        return &m_data[0];
    }
    T *end()
    {
        return &m_data[m_size];
    }
};
