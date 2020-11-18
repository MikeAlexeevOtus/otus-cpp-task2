#pragma once

#include <iostream>

template<typename T, typename AllocType = std::allocator<T>>
struct stack
{
    stack(): m_allocator(), m_capacity(0), m_size(0)
    {
    }

    ~stack()
    {
        if (m_capacity)
            m_allocator.deallocate(m_storage, m_capacity);
    }

    void push(const T item)
    {
        if (!m_capacity)
            resize(1);

        if (m_size == m_capacity)
            resize(m_capacity * 2);

        m_storage[m_size] = item;
        m_size++;
    }

    T operator[](int index)
    {
        return m_storage[index];
    }

private:
    T* m_storage;
    AllocType m_allocator;
    int m_capacity;
    int m_size;

    void resize(int newCapacity)
    {
        auto new_storage = m_allocator.allocate(newCapacity);
        for (int i=0; i < m_capacity; i++)
            new_storage[i] = m_storage[i];

        if (m_capacity)
            m_allocator.deallocate(m_storage, m_capacity);

        m_storage = new_storage;
        m_capacity = newCapacity;
    }
};
