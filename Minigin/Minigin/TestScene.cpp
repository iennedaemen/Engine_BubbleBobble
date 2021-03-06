#include "MiniginPCH.h"
#include "TestScene.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "TextComponent.h"
#include "FpsComponent.h"
#include "SpriteComponent.h"
#include "Player.h"
#include "ColliderComponent.h"

TestScene::TestScene()
	: Scene("TestScene")
{
	
}


void TestScene::Initialize()
{
	//auto go = std::make_shared<GameObject>();
	//std::shared_ptr<RenderComponent> pRenderComp = std::make_shared<RenderComponent>();
	//go->AddComponent(pRenderComp);
	//pRenderComp->SetTexture("background.jpg");
	//Add(go);

	auto go = std::make_shared<GameObject>();
	auto pRenderComp = std::make_shared<RenderComponent>();
	go->AddComponent(pRenderComp);
	pRenderComp->SetTexture("bar.png");
	Add(go);
	go->SetRect({ 0, 300, 291, 65 });
	go->SetPosition(0, 300);

	//go = std::make_shared<GameObject>();
	//std::shared_ptr<TextComponent> pTextComp = std::make_shared<TextComponent>("Lingua.otf", 36);
	//go->AddComponent(pTextComp);
	//pTextComp->SetText("Programming 4 Assignment");
	//Add(go);
	//go->SetPosition(80, 20);

	//std::shared_ptr<SpriteComponent> pSpriteComp = std::make_shared<SpriteComponent>(128.0f, 256.0f, 8 ,16, 50);
	//go->AddComponent(pSpriteComp);
	//pSpriteComp->SetTexture("Walk2.png");
	//Add(go);
	//go->SetPosition(10, 50);
	//
	m_pPlayer = std::make_shared<Player>(1);
	Add(m_pPlayer);


	m_pPlayer2 = std::make_shared<Player>(2);
	Add(m_pPlayer2);

	//go = std::make_shared<GameObject>();
	//std::shared_ptr<FpsComponent> pFpsComp = std::make_shared<FpsComponent>(FpsComponent("Lingua.otf", 20, { 255, 255, 0, 255 }));
	//go->AddComponent(pFpsComp);
	//Add(go);
	//go->SetPosition(10, 10);
}

void TestScene::Update()
{

}

void TestScene::Render() const
{
	
}
