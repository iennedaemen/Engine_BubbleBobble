#pragma once
#include "GameObject.h"
#include "Transform.h"

class BaseComponent
{
public:
	BaseComponent();
	virtual ~BaseComponent() = default;

	GameObject* GetGameObject() const;
	Transform GetTransform() const;
	void SetGameObject(GameObject* object);
	void NeedsUpdates(bool needsUpdate);

	void RootInitialize();
	void RootUpdate();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

protected:

	GameObject *m_pGameObject;
	bool m_IsInitialized;
	bool m_NeedsUpdate;
};

