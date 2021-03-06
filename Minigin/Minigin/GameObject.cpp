#include "MiniginPCH.h"
#include "GameObject.h"
#include "BaseComponent.h"


void GameObject::RootInitialize()
{
	if (m_IsInitialized)
		return;

	Initialize();

	for (std::weak_ptr<BaseComponent> pComponent : m_pComponents)
	{
		pComponent.lock()->RootInitialize();
	}

	m_IsInitialized = true;
}

void GameObject::RootUpdate()
{
	if (m_IsInitialized && m_NeedsUpdate)
	{
		Update();

		for (std::weak_ptr<BaseComponent> pComponent : m_pComponents)
		{
			pComponent.lock()->Update();
		}
	}
}

void GameObject::RootRender()
{
	Render();
	
	for (std::weak_ptr<BaseComponent> pComponent : m_pComponents)
	{
		pComponent.lock()->Render();
	}
}

void GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

Transform GameObject::GetTransform()
{
	return m_Transform;
}

void GameObject::AddComponent(std::shared_ptr<BaseComponent> component)
{
	m_pComponents.push_back(component);
	component->SetGameObject(this);
}

void GameObject::NeedsUpdate(bool needsUpdate)
{
	m_NeedsUpdate = needsUpdate;
}
