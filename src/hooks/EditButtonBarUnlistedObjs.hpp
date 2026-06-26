#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/EditButtonBar.hpp>
#include <Geode/loader/Loader.hpp>

#include "../main.hpp"
#include "UnlistedObjectUI.hpp"

using namespace geode::prelude;

class $modify(EditButtonBarUnlistedObjs, EditButtonBar) {
  struct Fields {
    bool m_block;
    bool m_outline;
    bool m_slope;
    bool m_hazard;
    bool m_threeD;
    bool m_pixel;
    bool m_collectable;
    bool m_deco;
    bool m_sawblade;
    bool m_trigger;
  };

  void loadFromItems(CCArray*, int, int, bool);
};