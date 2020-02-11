//
// Created by Henning on 22.01.2020.
//

#ifndef DESCRACKER_ALIGNED_ALLOCATOR_H
#define DESCRACKER_ALIGNED_ALLOCATOR_H

#endif //DESCRACKER_ALIGNED_ALLOCATOR_H

/**
 * adapted from
 * https://stackoverflow.com/questions/8456236/how-is-a-vectors-data-aligned
 */
#include <cstdlib>
#include <malloc.h>

template<typename T, std::size_t N = 16>
class aligned_allocator {
public:
    typedef T value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    typedef T *pointer;
    typedef const T *const_pointer;

    typedef T &reference;
    typedef const T &const_reference;

public:
    inline aligned_allocator() noexcept = default;

    template<typename T2>
    inline explicit aligned_allocator(
            const aligned_allocator<T2, N> &) noexcept {}

    inline ~aligned_allocator() noexcept = default;

    inline pointer adress(reference r) { return &r; }

    inline const_pointer adress(const_reference r) const { return &r; }

    inline pointer allocate(size_type n) {
#ifdef _MSC_VER
        return (pointer)_aligned_malloc(n * sizeof(value_type), N);
#else
        //cout  << N << " "<< n* sizeof(value_type) << endl;
        void *m = _aligned_malloc(n * sizeof(value_type), N);
        if (!m) {
            puts("cannot allocate that much memory!");
            exit(1); // couldn't allocate enough memory
        }
        return (pointer) m;
#endif
    }

    inline void deallocate(pointer p, size_type) {
#ifdef _MSC_VER
        _aligned_free(p);
#else
        _aligned_free(p);
#endif
    }

    inline void construct(pointer p, const value_type &wert) {
        new(p) value_type(wert);
    }

    inline void destroy(pointer p) { p->~value_type(); }

    inline size_type max_size() const noexcept {
        return size_type(-1) / sizeof(value_type);
    }

    template<typename T2>
    struct rebind {
        typedef aligned_allocator<T2, N> other;
    };

    bool operator!=(const aligned_allocator<T, N> &other) const {
        return !(*this == other);
    }

    // Returns true if and only if storage allocated from *this
    // can be deallocated from other, and vice versa.
    // Always returns true for stateless allocators.
    bool operator==(const aligned_allocator<T, N> &other) const { return true; }
};
