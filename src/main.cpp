/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/loader/SettingEvent.hpp>
#include <Geode/modify/EditButtonBar.hpp>
#include <Geode/modify/EditorUI.hpp>

/**
 * Brings cocos2d band all Geode namespaces 
 * to the current scope.
 */
using namespace geode::prelude;

// enum for types of unlisted objs
enum types {
	nonReplicable,
	stable,
	unstable
};

EditorUI* editorUI=nullptr;
auto active = Mod::get()->getSettingValue<bool>("activate");
auto unecessary = Mod::get()->getSettingValue<bool>("doNotInclude");
//auto noUnstable = Mod::get()->getSettingValue<bool>("removeUnstable");
auto noUnstable=true;

$execute{
	listenForSettingChanges("activate", +[](bool value) {
		active=value;
	});
	listenForSettingChanges("doNotInclude", +[](bool value) {
		unecessary=value;
	});
	//	listenForSettingChanges("removeUnstable", +[](bool value) {
	//	noUnstable=value;
	//});
}

// gets a reference to the editor UI
class $modify(EditorUI) {
	bool init(LevelEditorLayer* layer) {
		editorUI=this;
		return EditorUI::init(layer);
	}
};

// adds an object to an editor tab
void addObj(int objId, enum types necessary, cocos2d::CCArray* oArr) {
	// if all objects are to be shown, 
	// or if it is unecessary and !unecessary, 
	// or if it is nonReplicable
	if(!noUnstable||
		(necessary==stable&&!unecessary)||
		necessary==nonReplicable) {
		//first argument is obj id, 2nd is always 4
		auto obj=editorUI->getCreateBtn(objId,4);
		oArr->addObject(obj);
	}
}

// modify the EditButtonBar
class $modify(EditButtonBar) {
	$override
	void loadFromItems(CCArray * items, int r, int c, bool unkBool) {
		if (!active) {
			EditButtonBar::loadFromItems(items, r, c, unkBool);
			return;
		}
		if (this->getID() == "block-tab-bar") {
			// old half-slab, replaced with colorable one
			addObj(40, types::nonReplicable, items);
			addObj(369, types::stable, items);
			addObj(370, types::stable, items);
			// old quarter-blocks, replaced with colorable one
			addObj(195, types::nonReplicable, items);
			addObj(196, types::nonReplicable, items);
			// old grey stripes going in,
			// replaced with version without outlines
			addObj(160, types::stable, items);
			addObj(161, types::stable, items);
			addObj(162, types::stable, items);
			addObj(163, types::stable, items);
			addObj(164, types::stable, items);
			addObj(165, types::stable, items);
			addObj(166, types::stable, items);
			addObj(167, types::stable, items);
			addObj(168, types::stable, items);
			addObj(169, types::stable, items);
			addObj(193, types::stable, items);
			addObj(737, types::stable, items);
			// old colored grid blocks, unknown why replaced
			addObj(247, types::stable, items);
			addObj(248, types::stable, items);
			addObj(249, types::stable, items);
			addObj(250, types::stable, items);
			addObj(251, types::stable, items);
			addObj(252, types::stable, items);
			addObj(253, types::stable, items);
			addObj(254, types::stable, items);
			// solid startPos
			addObj(34, types::nonReplicable, items);
			// other weird block (looks like it uses a weird mishmash of textures)
			addObj(3800, types::nonReplicable, items);
		}
		else if (this->getID() == "outline-tab-bar") {
			// alternate basic slope outlines
			// fit with blocks better
			addObj(665, types::nonReplicable, items);
			addObj(666, types::nonReplicable, items);
		}
		else if (this->getID() == "slope-tab-bar") {
			// old grey grid slopes, unknown why replaced
			addObj(289, types::stable, items);
			addObj(291, types::stable, items);
			// other variants of slopes with outlines
			addObj(710, types::stable, items);
			addObj(711, types::stable, items);
			addObj(712, types::stable, items);
			addObj(726, types::stable, items);
			addObj(727, types::stable, items);
			addObj(728, types::stable, items);
			addObj(729, types::stable, items);
			addObj(321, types::stable, items);
			addObj(323, types::stable, items);
			addObj(331, types::stable, items);
			addObj(333, types::stable, items);
			addObj(343, types::stable, items);
			addObj(345, types::stable, items);
			addObj(353, types::stable, items);
			addObj(355, types::stable, items);
			addObj(349, types::stable, items);
			addObj(351, types::stable, items);
			addObj(337, types::stable, items);
			addObj(339, types::stable, items);
			addObj(483, types::stable, items);
			addObj(484, types::stable, items);
			addObj(492, types::stable, items);
			addObj(493, types::stable, items);
			addObj(651, types::stable, items);
			addObj(652, types::stable, items);
			addObj(886, types::stable, items);
			addObj(887, types::stable, items);
		}
		else if (this->getID() == "hazard-tab-bar") {
			// old ground spike, replaced with colorable one
			addObj(9, types::stable, items);
			// old curve spikes, replaced with colorable one
			addObj(61, types::stable, items);
			addObj(243, types::stable, items);
			addObj(244, types::stable, items);
			addObj(366, types::stable, items);
			addObj(367, types::stable, items);
			addObj(368, types::stable, items);
			// old fake spikes, unknown why replaced
			addObj(191, types::stable, items);
			addObj(198, types::stable, items);
			addObj(199, types::stable, items);
			addObj(393, types::stable, items);
			// old spiky spikes, replaced with colorable one
			addObj(363, types::stable, items);
			addObj(364, types::stable, items);
			addObj(365, types::stable, items);
			// old bigger-curve spikes, replaced with colorable one
			addObj(446, types::stable, items);
			addObj(447, types::stable, items);
			// old block-on-top spikes, replaced with colorable one
			addObj(667, types::stable, items);
			addObj(989, types::stable, items);
			addObj(991, types::stable, items);
			addObj(720, types::stable, items);
			// old spike-on-top spikes, replaced with colorable ones
			addObj(421, types::stable, items);
			addObj(422, types::stable, items);
			addObj(768, types::stable, items);
		}
		else if (this->getID() == "3d-tab-bar") {
			// 3D lines with hitboxes
			addObj(1561, types::nonReplicable, items);
			addObj(1562, types::nonReplicable, items);
			addObj(1563, types::nonReplicable, items);
			addObj(1564, types::nonReplicable, items);
			addObj(1565, types::nonReplicable, items);
			addObj(1566, types::nonReplicable, items);
			addObj(1567, types::nonReplicable, items);
			addObj(1568, types::nonReplicable, items);
			addObj(1569, types::nonReplicable, items);
		}
		else if (this->getID() == "portal-tab-bar") {

		}
		else if (this->getID() == "monster-tab-bar") {

		}
		else if (this->getID() == "pixel-tab-bar") {
			/*
				1964-2011 are random pixels
				there are so many of these
				the exact same as one of the ones
				in the pixel blocks tab
				this is much easier to write for adding them to the editor
			*/

			for(int i=1964;i<=2011;i++) {
				addObj(i,types::unstable, items);
			}
		}
		else if (this->getID() == "collectable-tab-bar") {

		}
		else if (this->getID() == "icon-tab-bar") {

		}
		else if (this->getID() == "deco-tab-bar") {
			// old version of circle, unknown why replaced
			addObj(725, types::stable, items);
			// old bush versions, unknown why replaced
			addObj(461, types::stable, items);
			addObj(462, types::stable, items);
			addObj(463, types::stable, items);
			addObj(464, types::stable, items);
			addObj(465, types::stable, items);
			addObj(466, types::stable, items);
		}
		else if (this->getID() == "sawblade-tab-bar") {
			// old sawblades, replaced with colorable ones
			addObj(88, types::stable, items);
			addObj(89, types::stable, items);
			addObj(98, types::stable, items);
			addObj(397, types::stable, items);
			addObj(398, types::stable, items);
			addObj(399, types::stable, items);
		}
		else if (this->getID() == "trigger-tab-bar") {
			// old color Triggers (do not work as fas as I know)
			// replaced with general all-colors trigger in 2.0
			addObj(29, types::unstable, items);
			addObj(30, types::unstable, items);
			addObj(104, types::unstable, items);
			addObj(105, types::unstable, items);
			addObj(744, types::unstable, items);
			addObj(915, types::unstable, items);
			// early version of the end trigger. It does not work at all anymore. 
			addObj(1931, types::stable, items);
		}
		EditButtonBar::loadFromItems(items, r, c, unkBool);
	}
};

