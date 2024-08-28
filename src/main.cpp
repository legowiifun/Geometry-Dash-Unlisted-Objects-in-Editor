#include <Geode/Geode.hpp>
#include <Geode/loader/SettingEvent.hpp>
#include <Geode/modify/EditButtonBar.hpp>
#include <Geode/modify/EditorUI.hpp>

#include <alphalaneous.editortab_api/include/EditorTabs.hpp>

using namespace geode::prelude;

#define ADD_OBJ(id, type) addObj(ui, id, ObjTypes::type, items)

// enum for types of unlisted objs
enum class ObjTypes {
	NON_REPLICABLE,
	STABLE,
	UNSTABLE
};

enum class Tab {
	BLOCKS,
	SLOPES,
	TDLINE,
	OUTLINE,
	HAZARDS,
	SAWBLADES,
	UNSTABLE,
	DECO,
	UNUSUAL,
	TRIGGERS
};

void addObj(EditorUI* self, int objId, enum ObjTypes necessary, cocos2d::CCArray* oArr);

CCArray* addObjectsForTab(EditorUI* ui, Tab tab, CCArray* items = nullptr) {

	if (!items) items = CCArray::create();

	switch (tab) {
		case Tab::BLOCKS: {
			// old half-slab, replaced with colorable one
			ADD_OBJ(40, NON_REPLICABLE);
			ADD_OBJ(369, STABLE);
			ADD_OBJ(370, STABLE);
			// old quarter-blocks, replaced with colorable one
			ADD_OBJ(195, NON_REPLICABLE);
			ADD_OBJ(196, NON_REPLICABLE);
			// old grey stripes going in,
			// replaced with version without outlines
			ADD_OBJ(160, STABLE);
			ADD_OBJ(161, STABLE);
			ADD_OBJ(162, STABLE);
			ADD_OBJ(163, STABLE);
			ADD_OBJ(164, STABLE);
			ADD_OBJ(165, STABLE);
			ADD_OBJ(166, STABLE);
			ADD_OBJ(167, STABLE);
			ADD_OBJ(168, STABLE);
			ADD_OBJ(169, STABLE);
			ADD_OBJ(193, STABLE);
			ADD_OBJ(737, STABLE);
			// old colored grid blocks, unknown why replaced
			ADD_OBJ(247, STABLE);
			ADD_OBJ(248, STABLE);
			ADD_OBJ(249, STABLE);
			ADD_OBJ(250, STABLE);
			ADD_OBJ(251, STABLE);
			ADD_OBJ(252, STABLE);
			ADD_OBJ(253, STABLE);
			ADD_OBJ(254, STABLE);
			// unique variation of existing blocks, placed by Build Helper
			for (int i = 2808; i <= 2837; i++) {
				ADD_OBJ(i, STABLE);
			}
			break;
		}
		case Tab::SLOPES: {
			// old grey grid slopes, unknown why replaced
			ADD_OBJ(289, STABLE);
			ADD_OBJ(291, STABLE);
			// other variants of slopes with outlines

			ADD_OBJ(710, STABLE);
			ADD_OBJ(711, STABLE);
			ADD_OBJ(712, STABLE);
			ADD_OBJ(726, STABLE);
			ADD_OBJ(727, STABLE);
			ADD_OBJ(728, STABLE);
			ADD_OBJ(729, STABLE);
			ADD_OBJ(321, STABLE);
			ADD_OBJ(323, STABLE);
			ADD_OBJ(331, STABLE);
			ADD_OBJ(333, STABLE);
			ADD_OBJ(343, STABLE);
			ADD_OBJ(345, STABLE);
			ADD_OBJ(353, STABLE);
			ADD_OBJ(355, STABLE);
			ADD_OBJ(337, STABLE);
			ADD_OBJ(339, STABLE);
			ADD_OBJ(483, STABLE);
			ADD_OBJ(484, STABLE);
			ADD_OBJ(492, STABLE);
			ADD_OBJ(493, STABLE);
			ADD_OBJ(651, STABLE);
			ADD_OBJ(652, STABLE);
			ADD_OBJ(886, STABLE);
			ADD_OBJ(887, STABLE);
			ADD_OBJ(299, STABLE);
			ADD_OBJ(301, STABLE);
			ADD_OBJ(309, STABLE);
			ADD_OBJ(311, STABLE);
			ADD_OBJ(315, STABLE);
			ADD_OBJ(317, STABLE);
			ADD_OBJ(709, STABLE);
			break;
		}
		case Tab::OUTLINE: {
			// alternate basic slope outlines
			// fit with blocks better
			ADD_OBJ(665, NON_REPLICABLE);
			ADD_OBJ(666, NON_REPLICABLE);
			break;
		}
		case Tab::TDLINE: {
			// 3D lines with hitboxes
			ADD_OBJ(1561, NON_REPLICABLE);
			ADD_OBJ(1562, NON_REPLICABLE);
			ADD_OBJ(1563, NON_REPLICABLE);
			ADD_OBJ(1564, NON_REPLICABLE);
			ADD_OBJ(1565, NON_REPLICABLE);
			ADD_OBJ(1566, NON_REPLICABLE);
			ADD_OBJ(1567, NON_REPLICABLE);
			ADD_OBJ(1568, NON_REPLICABLE);
			ADD_OBJ(1569, NON_REPLICABLE);
			break;
		}
		case Tab::HAZARDS: {
			// old ground spike, replaced with colorable one
			ADD_OBJ(9, STABLE);
			// old curve spikes, replaced with colorable one
			ADD_OBJ(61, STABLE);
			ADD_OBJ(243, STABLE);
			ADD_OBJ(244, STABLE);
			ADD_OBJ(366, STABLE);
			ADD_OBJ(367, STABLE);
			ADD_OBJ(368, STABLE);
			// old fake spikes, unknown why replaced
			ADD_OBJ(191, STABLE);
			ADD_OBJ(198, STABLE);
			ADD_OBJ(199, STABLE);
			ADD_OBJ(393, STABLE);
			// old spiky spikes, replaced with colorable one
			ADD_OBJ(363, STABLE);
			ADD_OBJ(364, STABLE);
			ADD_OBJ(365, STABLE);
			// old bigger-curve spikes, replaced with colorable one
			ADD_OBJ(446, STABLE);
			ADD_OBJ(447, STABLE);
			// old block-on-top spikes, replaced with colorable one
			ADD_OBJ(667, STABLE);
			ADD_OBJ(989, STABLE);
			ADD_OBJ(991, STABLE);
			ADD_OBJ(720, STABLE);
			// old spike-on-top spikes, replaced with colorable ones
			ADD_OBJ(421, STABLE);
			ADD_OBJ(422, STABLE);
			ADD_OBJ(768, STABLE);
			
			break;
		}
		case Tab::SAWBLADES: {
			// old sawblades, replaced with colorable ones
			ADD_OBJ(88, STABLE);
			ADD_OBJ(89, STABLE);
			ADD_OBJ(98, STABLE);
			ADD_OBJ(397, STABLE);
			ADD_OBJ(398, STABLE);
			ADD_OBJ(399, STABLE);
			break;
		}
		case Tab::UNSTABLE: {
			/*
				1964-2011 are random pixels
				there are so many of these
				the exact same as one of the ones
				in the pixel blocks tab
				this is much easier to write for adding them to the editor 
			*/
			for (int i = 1964; i <= 2011; i++) {
				ADD_OBJ(i, UNSTABLE);
			}
			break;
		}
		case Tab::DECO: {
			// old version of circle, unknown why replaced
			ADD_OBJ(725, STABLE);
			// old bush versions, unknown why replaced
			ADD_OBJ(461, STABLE);
			ADD_OBJ(462, STABLE);
			ADD_OBJ(463, STABLE);
			ADD_OBJ(464, STABLE);
			ADD_OBJ(465, STABLE);
			ADD_OBJ(466, STABLE);
			break;
		}
		case Tab::UNUSUAL: {
			// solid startPos
			ADD_OBJ(34, NON_REPLICABLE);
			// other weird block (looks like it uses a weird mishmash of textures)
			ADD_OBJ(3800, NON_REPLICABLE);
			break;
		}
		case Tab::TRIGGERS: {
			// old color Triggers (do not work as fas as I know)
			// replaced with general all-colors trigger in 2.0
			ADD_OBJ(29, UNSTABLE);
			ADD_OBJ(30, UNSTABLE);
			ADD_OBJ(104, UNSTABLE);
			ADD_OBJ(105, UNSTABLE);
			ADD_OBJ(744, UNSTABLE);
			ADD_OBJ(915, UNSTABLE);
			// early version of the end trigger. It does not work at all anymore. 
			ADD_OBJ(1931, STABLE);
			// State block with no number?
			ADD_OBJ(3655, STABLE);
			break;
		}

	}
	return items;
}

class $modify(EditorUI) {

	bool init(LevelEditorLayer* layer) {
		
		if (!EditorUI::init(layer)) return false; 

		bool separateTab = Mod::get()->getSettingValue<bool>("separateTab");
		bool unecessary = Mod::get()->getSettingValue<bool>("doNotInclude");
		bool active = Mod::get()->getSettingValue<bool>("activate");
		bool noUnstable = true; //Mod::get()->getSettingValue<bool>("removeUnstable");

		if (separateTab && active) {
			// add the new blocks tab
			EditorTabs::addTab(this, TabType::BUILD, "newBlocks"_spr, [](EditorUI* ui, CCMenuItemToggler* toggler) -> CCNode* {
				auto spr = CCSprite::create("NewBlockLabel.png"_spr);
				spr->setScale(0.4f);
				EditorTabUtils::setTabIcons(toggler, spr, spr);
				return EditorTabUtils::createEditButtonBar(addObjectsForTab(ui, Tab::BLOCKS), ui);
			});

			// add the new Slopes tab
			EditorTabs::addTab(this, TabType::BUILD, "newSlopes"_spr, [](EditorUI* ui, CCMenuItemToggler* toggler) -> CCNode* {
				auto spr = CCSprite::create("SlopeLabel.png"_spr);
				spr->setScale(0.4f);
				EditorTabUtils::setTabIcons(toggler, spr, spr);
				return EditorTabUtils::createEditButtonBar(addObjectsForTab(ui, Tab::SLOPES), ui);
			});

			// add the tab with 3D lines and better slope outlines
			EditorTabs::addTab(this,TabType::BUILD, "newOutlines"_spr, [](EditorUI* ui, CCMenuItemToggler* toggler) -> CCNode* {
				auto spr = CCSprite::create("3DLabel.png"_spr);
				spr->setScale(0.8f);
				EditorTabUtils::setTabIcons(toggler, spr, spr);
				return EditorTabUtils::createEditButtonBar(addObjectsForTab(ui, Tab::TDLINE, addObjectsForTab(ui, Tab::OUTLINE)), ui);
			});
			
			// add a tab with more spikes and sawblades
			EditorTabs::addTab(this, TabType::BUILD, "newHazards"_spr, [](EditorUI* ui, CCMenuItemToggler* toggler) -> CCNode* {
				auto spr = CCSprite::create("spikeLabel.png"_spr);
				spr->setScale(0.4f);
				EditorTabUtils::setTabIcons(toggler, spr, spr);
				return EditorTabUtils::createEditButtonBar(addObjectsForTab(ui, Tab::SAWBLADES, addObjectsForTab(ui, Tab::HAZARDS)), ui);
			});

			// if unstable objects are available, add the tab with way too many pixel objects
			if (!noUnstable) {
				EditorTabs::addTab(this, TabType::BUILD, "newPixels"_spr, [](EditorUI* ui, CCMenuItemToggler* toggler) -> CCNode* {
					auto spr = CCSprite::create("PixelLabel.png"_spr);
					spr->setScale(0.6f);
					EditorTabUtils::setTabIcons(toggler, spr, spr);
					return EditorTabUtils::createEditButtonBar(addObjectsForTab(ui, Tab::UNSTABLE), ui);
				});
			}

			// add the tab with new deco objects
			EditorTabs::addTab(this, TabType::BUILD, "newDeco"_spr, [](EditorUI* ui, CCMenuItemToggler* toggler) -> CCNode* {
				auto spr = CCSprite::create("BushLabel.png"_spr);
				spr->setScale(0.3f);
				EditorTabUtils::setTabIcons(toggler, spr, spr);
				return EditorTabUtils::createEditButtonBar(addObjectsForTab(ui, Tab::DECO), ui);
			});

			// add the tab with unusual objects
			EditorTabs::addTab(this, TabType::BUILD, "unusalObjs"_spr, [](EditorUI* ui, CCMenuItemToggler* toggler) -> CCNode* {
				auto spr = CCSprite::create("StartPosLabel.png"_spr);
				spr->setScale(0.6f);
				EditorTabUtils::setTabIcons(toggler, spr, spr);
				return EditorTabUtils::createEditButtonBar(addObjectsForTab(ui, Tab::UNUSUAL), ui);
			});

			// add the tab with more triggers
			EditorTabs::get()->addTab(this, TabType::BUILD, "newTriggers"_spr, [](EditorUI* ui, CCMenuItemToggler* toggler) -> CCNode* {
				auto spr = CCSprite::create("TriggerLabel.png"_spr);
				spr->setScale(0.4f);
				EditorTabUtils::setTabIcons(toggler, spr, spr);
				return EditorTabUtils::createEditButtonBar(addObjectsForTab(ui, Tab::TRIGGERS), ui);
			});
		}
		return true;
	}
};

// adds an object to an editor tab
void addObj(EditorUI* self, int objId, enum ObjTypes type, cocos2d::CCArray* oArr) {
	// if all objects are to be shown, 
	// or if it is unecessary and !unecessary, 
	// or if it is nonReplicable

	bool separateTab = Mod::get()->getSettingValue<bool>("separateTab");
	bool unecessary = Mod::get()->getSettingValue<bool>("doNotInclude");
	bool active = Mod::get()->getSettingValue<bool>("activate");
	bool noUnstable = true; //Mod::get()->getSettingValue<bool>("removeUnstable");

	if (!noUnstable || (type == ObjTypes::STABLE && !unecessary)|| type == ObjTypes::NON_REPLICABLE) {
		//first argument is obj id, 2nd is always 4
		log::info("id: {}", objId);
		auto obj = self->getCreateBtn(objId, 4);
		if (obj && oArr->indexOfObject(obj) == UINT_MAX){
			log::info("here");
			oArr->addObject(obj);
		}
	}
}

// modify the EditButtonBar
class $modify(EditButtonBar) {
	
	$override
	void loadFromItems(CCArray * items, int r, int c, bool unkBool) {

		bool separateTab = Mod::get()->getSettingValue<bool>("separateTab");
		bool unecessary = Mod::get()->getSettingValue<bool>("doNotInclude");
		bool active = Mod::get()->getSettingValue<bool>("activate");
		bool noUnstable = true; //Mod::get()->getSettingValue<bool>("removeUnstable");

		EditorUI* ui = static_cast<EditorUI*>(this->getParent());

		if (!active || separateTab) {
			EditButtonBar::loadFromItems(items, r, c, unkBool);
			return;
		}
		if (this->getID() == "block-tab-bar") {
			addObjectsForTab(ui, Tab::BLOCKS, items);
			addObjectsForTab(ui, Tab::UNUSUAL, items);
		}
		else if (this->getID() == "outline-tab-bar") {
			addObjectsForTab(ui, Tab::OUTLINE, items);
		}
		else if (this->getID() == "slope-tab-bar") {
			addObjectsForTab(ui, Tab::SLOPES, items);
		}
		else if (this->getID() == "hazard-tab-bar") {
			addObjectsForTab(ui, Tab::HAZARDS, items);
		}
		else if (this->getID() == "3d-tab-bar") {
			addObjectsForTab(ui, Tab::TDLINE, items);
		}
		else if (this->getID() == "portal-tab-bar") {

		}
		else if (this->getID() == "monster-tab-bar") {

		}
		else if (this->getID() == "pixel-tab-bar") {
			addObjectsForTab(ui, Tab::UNSTABLE, items);
		}
		else if (this->getID() == "collectable-tab-bar") {

		}
		else if (this->getID() == "icon-tab-bar") {

		}
		else if (this->getID() == "deco-tab-bar") {
			addObjectsForTab(ui, Tab::DECO, items);
		}
		else if (this->getID() == "sawblade-tab-bar") {
			addObjectsForTab(ui, Tab::SAWBLADES, items);
		}
		else if (this->getID() == "trigger-tab-bar") {
			addObjectsForTab(ui, Tab::TRIGGERS, items);
		}
		EditButtonBar::loadFromItems(items, r, c, unkBool);
	}
};

