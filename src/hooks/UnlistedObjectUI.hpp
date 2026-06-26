#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/loader/Loader.hpp>

#include <alphalaneous.editortab_api/include/EditorTabAPI.hpp>
#include "../main.hpp"

using namespace geode::prelude;

class $modify(UnlistedObjectsUI, EditorUI) {
	struct Fields {
		bool m_block;
		bool m_outline;
		bool m_slope;
		bool m_hazard;
		bool m_threeD;
		bool m_portal;
		bool m_monster;
		bool m_pixel;
		bool m_collectable;
		bool m_icon;
		bool m_deco;
		bool m_sawblade;
		bool m_trigger;
	};
	
    bool init(LevelEditorLayer*);
};