#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/EditButtonBar.hpp>
#include <Geode/loader/Loader.hpp>

#include "../main.hpp"
#include "UnlistedObjectUI.hpp"

using namespace geode::prelude;

class $modify(EditButtonBarUnlistedObjs, EditButtonBar) {
  void loadFromItems(CCArray * items, int r, int c, bool unkBool);
};