#pragma once

#include"../ButtonSet/Button/Button.hpp"
#include"../SliceTexture/Animation/Animation.hpp"

namespace Ash
{
	/// <summary>
	/// 定数の管理(App/asset/data/config.toml)
	/// </summary>
	class Config
	{
	private:

		// 設定ファイル
		const TOMLReader m_toml;

	public:

		Config()
			: m_toml(U"asset/data/config.toml")
		{
		}

	private:

		static Config& instance()
		{
			static Config config;
			return config;
		}

	public:

		/// <summary>
		/// 設定された定数の取得
		/// </summary>
		/// <typeparam name="Type"> 取得する型 </typeparam>
		/// <param name="name"> 定数の名前 </param>
		/// <returns> 設定された定数 </returns>
		template<typename Type>
		static Type get(const String& name);

	};


	template<typename Type>
	inline Type Config::get(const String& name)
	{
		return instance().m_toml[name].get<Type>();
	}

	template<>
	inline Point Config::get(const String& name)
	{
		return Point(
			instance().m_toml[name][U"x"].get<int32>(),
			instance().m_toml[name][U"y"].get<int32>()
		);
	}

	template<>
	inline Rect Config::get(const String& name)
	{
		return Rect(
			instance().m_toml[name][U"x"].get<int32>(),
			instance().m_toml[name][U"y"].get<int32>(),
			instance().m_toml[name][U"w"].get<int32>(),
			instance().m_toml[name][U"h"].get<int32>()
		);
	}

	template<>
	inline RoundRect Config::get(const String& name)
	{
		return RoundRect(
			instance().get<Rect>(name),
			instance().m_toml[name][U"r"].get<double>()
		);
	}

	template<>
	inline ColorF Config::get(const String& name)
	{
		ColorF color(instance().m_toml[name][U"rgb"].getOr<double>(0.0));
		color.r = instance().m_toml[name][U"r"].getOr<double>(color.r);
		color.g = instance().m_toml[name][U"g"].getOr<double>(color.g);
		color.b = instance().m_toml[name][U"b"].getOr<double>(color.b);
		color.a = instance().m_toml[name][U"a"].getOr<double>(1.0);
		return color;
	}

	template<>
	inline Circle Config::get(const String& name)
	{
		return Circle
		(
			instance().m_toml[name][U"x"].get<double>(),
			instance().m_toml[name][U"y"].get<double>(),
			instance().m_toml[name][U"r"].get<double>()
		);
	}

	template<>
	inline Line Config::get(const String& name)
	{
		return Line
		(
			instance().m_toml[name][U"x1"].get<double>(),
			instance().m_toml[name][U"y1"].get<double>(),
			instance().m_toml[name][U"x2"].get<double>(),
			instance().m_toml[name][U"y2"].get<double>()
		);
	}

	template<>
	inline Button Config::get(const String& name)
	{
		return Button
		(
			instance().m_toml[name][U"name"].getString(),
			instance().get<Rect>(name + U".region")
		);
	}

	template<>
	inline Animation Config::get(const String& name)
	{
		PosOrder posOrder;
		for (const auto& obj : instance().m_toml[name][U"posOrder"].tableArrayView())
		{
			std::pair<double, Point> timePos;
			timePos.first    = obj[U"t"].get<double>();
			timePos.second.x = obj[U"x"].get<int32>();
			timePos.second.y = obj[U"y"].get<int32>();
			posOrder << timePos;
		}
		bool loop = instance().m_toml[name][U"loop"].get<bool>();
		return std::move(Animation(posOrder, loop));
	}
}