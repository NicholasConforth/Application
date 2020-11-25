#pragma once
#include <functional>
#include <map>

namespace nc
{

	template <typename TBase>
	class CreatorBase
	{
	public:
		virtual TBase* Create() const = 0;
	};
	
	template <typename T,typename TBase>
	class Creator : public CreatorBase<TBase>
	{
	public:
		virtual TBase* Create() const override { return new T; }
	};

	template<typename TBase>
	class Prototype : public CreatorBase<TBase>
	{
	public:
		Prototype(TBase* instance) : m_instance{ instance } {}
		TBase* Create() const override { return m_instance->Clone(); }

	private:
		TBase* m_instance{ nullptr };
	};


	template<typename TBase, typename TKey>
	class Factory
	{
	public:
		template <typename T>
		T* Create(TKey key);
		void Register(TKey key, CreatorBase<TBase>* creator);
	protected:
		std::map<TKey, CreatorBase<TBase>*> m_regestry;
	};

	template<typename TBase, typename TKey>
	template <typename T>
	inline T* Factory<TBase, TKey>::Create(TKey key)
	{
		T* object{ nullptr };

		auto iter = m_regestry.find(key);
		if (iter != m_regestry.end())
		{
			CreatorBase <TBase>* creator = iter->second;
			object = dynamic_cast<T*>(creator->Create());
		}

		return object;
	}

	template<typename TBase, typename TKey>
	inline void Factory<TBase, TKey>::Register(TKey key, CreatorBase<TBase>* creator)
	{
		m_regestry[key] = creator;

	}

}