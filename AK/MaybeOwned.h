/*
 * Copyright (c) 2022, Tim Schumacher <timschumi@gmx.de>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/NonnullOwnPtr.h>
#include <AK/Variant.h>

namespace AK {

template<typename T>
class MaybeOwned {
public:
    template<DerivedFrom<T> U>
    MaybeOwned(NonnullOwnPtr<U> handle)
        : m_handle(adopt_own<T>(*handle.leak_ptr()))
    {
    }

    // This is made `explicit` to not accidentally create a non-owning MaybeOwned,
    // which may not always be intended.
    explicit MaybeOwned(T& handle)
        : m_handle(&handle)
    {
    }

    T* ptr()
    {
        if (m_handle.template has<T*>())
            return m_handle.template get<T*>();
        else
            return m_handle.template get<NonnullOwnPtr<T>>();
    }

    T const* ptr() const
    {
        if (m_handle.template has<T*>())
            return m_handle.template get<T*>();
        else
            return m_handle.template get<NonnullOwnPtr<T>>();
    }

    T* operator->() { return ptr(); }
    T const* operator->() const { return ptr(); }

    T& operator*() { return *ptr(); }
    T const& operator*() const { return *ptr(); }

private:
    Variant<NonnullOwnPtr<T>, T*> m_handle;
};

}

#if USING_AK_GLOBALLY
using AK::MaybeOwned;
#endif
