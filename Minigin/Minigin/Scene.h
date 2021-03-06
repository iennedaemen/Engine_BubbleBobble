#pragma once
#include "SceneManager.h"

	class GameObject;
	class Scene
	{		
	public:
		explicit Scene(const std::string& name);
		~Scene();
		
		void Add(const std::shared_ptr<GameObject>& object);
		void Remove(const std::shared_ptr<GameObject>& object);

		void RootInitialize();
		void RootUpdate();
		void RootRender() const;

		std::string GetName() const;

		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;
		
	protected:
		virtual void Initialize(){};
		virtual void Update(){};
		virtual void Render() const {};
		
	private: 
		//explicit Scene(const std::string& name);

		std::string m_Name;
		std::vector < std::shared_ptr<GameObject>> m_Objects{};

		static unsigned int m_IdCounter;
		bool m_IsInitialized = false;
	};


