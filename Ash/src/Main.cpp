#include"MyLibrary/MyLibrary.hpp"
#include"MyPixelShader/MyPixelShader.hpp"
#include"Config/Config.hpp"

// シーン
#include"Scene/Title/TitleScene.hpp"


void Main()
{
	// ウィンドウの設定
	Window::Resize(Ash::Config::get<Size>(U"Window.size"));
	Window::SetTitle(Ash::Config::get<String>(U"Window.name"));
	
	// 描画設定
	Scene::SetBackground(Ash::MyBlack);
	Scene::Resize(Ash::Config::get<Size>(U"Window.size"));

	// アセット管理
	Ash::registerAsset(U"asset/");
	Ash::MyPixelShader::loadPixelShader();
	for (int32 fontSize = 10; fontSize <= 40; ++fontSize) // フォントサイズ
	{
		FontAsset::Register(ToString(fontSize), fontSize, Typeface::Medium);
	}

	// シーン設定
	Ash::MyApp sceneManager;
	sceneManager.add<Ash::TitleScene>(Ash::SceneName::TITLE);

	while (System::Update())
	{
		sceneManager.update();

		Ash::showFPS();
	}
}