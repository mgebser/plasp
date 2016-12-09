#ifndef __PLASP__UTILS__SINGLE_OWNER_POINTER_H
#define __PLASP__UTILS__SINGLE_OWNER_POINTER_H

#include <cassert>
#include <string>
#include <type_traits>

namespace plasp
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// SingleOwnerPointer
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
class SingleOwnerPointer
{
	public:
		constexpr SingleOwnerPointer() noexcept
		:	m_pointer{nullptr}
		{
		}

		constexpr SingleOwnerPointer(std::nullptr_t) noexcept
		:	SingleOwnerPointer()
		{
		}

		explicit SingleOwnerPointer(T *pointer, bool isOwning = true)
		:	m_pointer{flagged(pointer, isOwning)}
		{
		}

		~SingleOwnerPointer()
		{
			if (isOwning() && get() != nullptr)
				delete get();
		}

		SingleOwnerPointer(const SingleOwnerPointer<T> &other) = delete;
		SingleOwnerPointer &operator=(const SingleOwnerPointer<T> &other) = delete;

		template<typename U>
		SingleOwnerPointer(SingleOwnerPointer<U> &&other)
		:	m_pointer{other.m_pointer}
		{
			other.release();
		}

		template<typename U>
		SingleOwnerPointer &operator=(SingleOwnerPointer<U> &&other)
		{
			const auto isOwning = other.isOwning();

			reset(other.release(), isOwning);

			return *this;
		}

		T *get() const
		{
			return reinterpret_cast<T *>(reinterpret_cast<std::uintptr_t>(m_pointer) & ~1);
		}

		T *operator->() const
		{
			return get();
		}

		T &operator*() const
		{
			return *get();
		}

		T *release()
		{
			auto * const pointer = get();
			m_pointer = nullptr;

			return pointer;
		}

		void reset(T *pointer = nullptr, bool isOwning = false)
		{
			if (this->isOwning() && pointer != get())
				delete m_pointer;

			m_pointer = flagged(pointer, isOwning);
		}

		void swap(SingleOwnerPointer<T> &pointer)
		{
			std::swap(m_pointer, pointer.m_pointer);
		}

		inline bool isOwning() const
		{
			return reinterpret_cast<std::uintptr_t>(m_pointer) & 1;
		}

	private:
		static constexpr T *flagged(T *pointer, bool flag) noexcept
		{
			return reinterpret_cast<T *>(reinterpret_cast<std::uintptr_t>(pointer) | (flag && pointer != nullptr));
		}

	private:
		template<typename U>
		friend class SingleOwnerPointer;

		T *m_pointer;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T, typename ...Arguments>
SingleOwnerPointer<T> makeSingleOwnerPointer(Arguments &&...arguments)
{
	return SingleOwnerPointer<T>(new T(std::forward<Arguments>(arguments)...), true);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

}

#endif
