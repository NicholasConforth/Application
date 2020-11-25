#include "pch.h"
#include "ResourceManager.h"

namespace nc
{
	bool ResourceManager::Startup()
	{
		return true;
	}

	void ResourceManager::Shutdown()
	{
		RemoveAll();
	}

	void ResourceManager::Update()
	{
	}
	void ResourceManager::RemoveAll()
	{
		for (auto resource : m_resources)
		{
			resource.second->Destroy();
			delete resource.second;
		}
		m_resources.clear();
	}
}
