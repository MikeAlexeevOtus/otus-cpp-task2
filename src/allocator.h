#pragma once

#include <memory>
#include <utility>


template<int items_count>
struct reserved_allocator
{
    template<typename T>
    struct allocator
    {
        using value_type = T;

        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;

        template<typename U>
        struct rebind
        {
            using other = allocator<U>;
        };

        allocator()
        {
            auto p = std::malloc(items_count * sizeof(T));
            if (!p)
                throw std::bad_alloc();

            m_memBlock = reinterpret_cast<T *>(p);
            m_currentOffset = 0;
        }

        ~allocator()
        {
            std::free(m_memBlock);
        }

        template<typename U>
        allocator(const allocator<U>&) {}

        T *allocate(std::size_t n)
        {
            if (m_currentOffset + n  > items_count)
                throw std::bad_alloc();

            auto p = m_memBlock + m_currentOffset;
            m_currentOffset += n;
            return p;
        }

        void deallocate(T *p, std::size_t n)
        {
        }

        template<typename U, typename ...Args>
        void construct(U *p, Args &&...args)
        {
            new(p) U(std::forward<Args>(args)...);
        }

        template<typename U>
        void destroy(U *p)
        {
            p->~U();
        }

    private:
        T* m_memBlock;
        int m_currentOffset;
    };
};
