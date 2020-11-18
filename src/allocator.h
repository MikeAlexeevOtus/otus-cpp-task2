#include <memory>
#include <utility>


template<typename T>
struct reserved_allocator {
    using value_type = T;

    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    template<typename U>
    struct rebind
    {
        using other = reserved_allocator<U>;
    };

    reserved_allocator() = default;
    ~reserved_allocator() = default;

    
    template<typename U>
    reserved_allocator(const reserved_allocator<U>&) {}

    T *allocate(std::size_t n)
    {
        auto p = std::malloc(n * sizeof(T));
        if (!p)
            throw std::bad_alloc();
        return reinterpret_cast<T *>(p);
    }

    void deallocate(T *p, std::size_t n)
    {
        std::free(p);
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
};
