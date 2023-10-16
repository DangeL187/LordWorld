#include "Aiming.h"
#include "Critical.h"
#include "Dash.h"
#include "Defence.h"
#include "Enter.h"
#include "Escape.h"
#include "Events.h"
#include "Inventory.h"
#include "Movement.h"
#include "Targeting.h"

class Controls: virtual public Initializer,
				virtual protected Equipment,
				virtual protected Aiming,
				virtual protected Critical,
				virtual protected Dash,
				virtual protected Defence,
				virtual protected Enter,
				virtual protected Escape,
				virtual protected Events,
				virtual protected Inventory,
				virtual protected Movement,
				virtual protected Targeting {
protected:
	void controls(auto& time, auto& game) {
		auto& entity_manager = game.entity_manager;
		auto& sprite_manager = game.renderer->sprite_manager;
		auto& text_manager = game.renderer->text_manager;
		auto& window_manager = game.window_manager;

		keysMovement(time);
		keysAiming();
		keyCritical();
		keyDash(time);
		keyDefence(text_manager->text_dynamic_shield_cd);
		keyEnter();
		keyEscape();
		keysEvents(entity_manager, sprite_manager, text_manager, window_manager);
		keysInventory();
		keysTargeting(game.entity_manager->v_monsters, game.target_m);
		mouseLeft(time, game);
		mouseRight(game);
		ifs(game);
	}
	void mouseLeft(auto& time, auto& game) {
		if (Mouse::isButtonPressed(Mouse::Left) && key_m1) {
			key_m1_go = true;
		}
		if (!Mouse::isButtonPressed(Mouse::Left)) {
			key_m1 = true;
			if (key_m1_go && !Mouse::isButtonPressed(Mouse::Right)) {
				if (!is_inventory_open && !is_inventory_spells_open && attack_animation == 0 && !is_aiming && attack1_cd == 0) {
					attack_type = 1; //first type of attack
				} else {
					attack_type = 0;
				}
				if (is_aiming) {
					is_aiming = false;
					key_m1 = false;
					game.spell_manager->castSpell(game);
				}
				key_m1_go = false;
			}
		}
	}
	void mouseRight(auto& game) {
		if (Mouse::isButtonPressed(Mouse::Right) && key_m2) {
			key_m2_go = true;
		}
		if (!Mouse::isButtonPressed(Mouse::Right)) {
			key_m2 = true;
			if (key_m2_go && !Mouse::isButtonPressed(Mouse::Left)) {
				bool is_ctrl = Keyboard::isKeyPressed(Keyboard::LControl);
				if (!is_inventory_open && !is_inventory_spells_open && attack_animation == 0 && attack2_cd == 0 && !is_ctrl) {
					attack_type = 2; //second type of attack
				} else {
					attack_type = 0;
				}
				if (is_aiming) {
					is_aiming = false;
					key_m2 = false;
				}
				mouseInventory(game);
				key_m2_go = false;
			}
		}
	}
	void mouseInventory(auto& game) {
		float out = game.player->getX() - (962 - Mouse::getPosition().x);
		float outy = game.player->getY() - (544 - Mouse::getPosition().y);
		float vx = game.window_manager->viewGetCenterX() + 261;
		float vy = game.window_manager->viewGetCenterY() - 343;
		if (is_inventory_open) {
			auto& sprites = game.renderer->sprite_manager->InventoryItemsSprites;
			auto& weapon_sprite = game.renderer->sprite_manager->GuiSlotWeaponSprite;
			auto& shield_sprite = game.renderer->sprite_manager->GuiSlotShieldSprite;
			auto& helm_sprite = game.renderer->sprite_manager->GuiSlotHelmSprite;
			auto& chest_sprite = game.renderer->sprite_manager->GuiSlotChestSprite;
			auto& pants_sprite = game.renderer->sprite_manager->GuiSlotPantsSprite;
			auto& boots_sprite = game.renderer->sprite_manager->GuiSlotBootsSprite;
			auto& empty = game.renderer->sprite_manager->InventoryItemEmptySprite;
			game.renderer->text_manager->text_info.setString("");
			for (int i = 0; i < 6; i++) {
				vx = game.window_manager->viewGetCenterX() + 261;
				for (int j = 0; j < 4; j++) {
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						if (inv_items[i * 4 + j].getType() == 7 && inv_items[24].getID() == 0) { //other1
							sprites[24] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[24] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = Item();
						}
						if (inv_items[i * 4 + j].getType() == 7 && inv_items[25].getID() == 0) { //other2
							sprites[25] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[25] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = Item();
						}
						if (inv_items[i * 4 + j].getType() == 7 && inv_items[26].getID() == 0) { //other3
							sprites[26] = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[26] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = Item();
						}
							if (inv_items[i * 4 + j].getType() == 1 && inv_items[27].getID() == 0) { //weapon
							weapon_sprite = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[27] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = 0;
							setWeaponStats(game.renderer->sprite_manager);
						}
						if (inv_items[i * 4 + j].getType() == 2 && inv_items[28].getID() == 0) { //shield
							shield_sprite = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[28] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = Item();
						}
						if (inv_items[i * 4 + j].getType() == 3 && inv_items[29].getID() == 0) { //helmet
							helm_sprite = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[29] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = Item();
						}
						if (inv_items[i * 4 + j].getType() == 4 && inv_items[30].getID() == 0) { //chestplate
							chest_sprite = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[30] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = Item();
						}
						if (inv_items[i * 4 + j].getType() == 5 && inv_items[31].getID() == 0) { //pants
							pants_sprite = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[31] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = Item();
						}
						if (inv_items[i * 4 + j].getType() == 6 && inv_items[32].getID() == 0) { //boots
							boots_sprite = sprites[i * 4 + j];
							sprites[i * 4 + j] = empty;
							inv_items[32] = inv_items[i * 4 + j];
							inv_items[i * 4 + j] = Item();
						}
					}
					vx += 112;
				}
				vy += 112;
			}
			if (inv_items[24].getID() != 0) {
				vx = game.window_manager->viewGetCenterX() - 203;
				vy = game.window_manager->viewGetCenterY() + 185;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j].getID() == 0) {
							sprites[j] = sprites[24];
							sprites[24] = empty;
							inv_items[j] = inv_items[24];
							inv_items[24] = Item();
						}
					}
				}
			}
			if (inv_items[25].getID() != 0) {
				vx = game.window_manager->viewGetCenterX() - 71;
				vy = game.window_manager->viewGetCenterY() + 185;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j].getID() == 0) {
							sprites[j] = sprites[25];
							sprites[25] = empty;
							inv_items[j] = inv_items[25];
							inv_items[25] = Item();
						}
					}
				}
			}
			if (inv_items[26].getID() != 0) {
				vx = game.window_manager->viewGetCenterX() + 61;
				vy = game.window_manager->viewGetCenterY() + 185;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j].getID() == 0) {
							sprites[j] = sprites[26];
							sprites[26] = empty;
							inv_items[j] = inv_items[26];
							inv_items[26] = Item();
						}
					}
				}
			}
			if (inv_items[27].getID() != 0) {
				vx = game.window_manager->viewGetCenterX() - 231;
				vy = game.window_manager->viewGetCenterY() - 227;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j].getID() == 0) {
							sprites[j] = weapon_sprite;
							weapon_sprite = empty;
							inv_items[j] = inv_items[27];
							inv_items[27] = Item();
							weapon_sprite = createSprite("GuiSlotWeapon.png");
							weapon_sprite.setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
				setWeaponStats(game.renderer->sprite_manager);
			}
			if (inv_items[28].getID() != 0) {
				vx = game.window_manager->viewGetCenterX() + 89;
				vy = game.window_manager->viewGetCenterY() - 227;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j].getID() == 0) {
							sprites[j] = shield_sprite;
							shield_sprite = empty;
							inv_items[j] = inv_items[28];
							inv_items[28] = Item();
							shield_sprite = createSprite("GuiSlotShield.png");
							shield_sprite.setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
			}
			if (inv_items[29].getID() != 0) {
				vx = game.window_manager->viewGetCenterX() - 71;
				vy = game.window_manager->viewGetCenterY() - 351;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j].getID() == 0) {
							sprites[j] = helm_sprite;
							helm_sprite = empty;
							inv_items[j] = inv_items[29];
							inv_items[29] = Item();
							helm_sprite = createSprite("GuiSlotHelm.png");
							helm_sprite.setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
			}
			if (inv_items[30].getID() != 0) {
				vx = game.window_manager->viewGetCenterX() - 71;
				vy = game.window_manager->viewGetCenterY() - 227;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j].getID() == 0) {
							sprites[j] = chest_sprite;
							chest_sprite = empty;
							inv_items[j] = inv_items[30];
							inv_items[30] = Item();
							chest_sprite = createSprite("GuiSlotChest.png");
							chest_sprite.setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
			}
			if (inv_items[31].getID() != 0) {
				vx = game.window_manager->viewGetCenterX() - 71;
				vy = game.window_manager->viewGetCenterY() - 103;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j].getID() == 0) {
							sprites[j] = pants_sprite;
							pants_sprite = empty;
							inv_items[j] = inv_items[31];
							inv_items[31] = Item();
							pants_sprite = createSprite("GuiSlotPants.png");
							pants_sprite.setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
			}
			if (inv_items[32].getID() != 0) {
				vx = game.window_manager->viewGetCenterX() - 71;
				vy = game.window_manager->viewGetCenterY() + 21;
				if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_items[j].getID() == 0) {
							sprites[j] = boots_sprite;
							boots_sprite = empty;
							inv_items[j] = inv_items[32];
							inv_items[32] = Item();
							boots_sprite = createSprite("GuiSlotBoots.png");
							boots_sprite.setTextureRect(IntRect(0, 0, 116, 116));
							break;
						}
					}
				}
			}
		}
		if (is_inventory_spells_open) {
			float vx = game.window_manager->viewGetCenterX() + 231 + 15;
			float vy = game.window_manager->viewGetCenterY() - 373 + 30;
			for (int i = 0; i < 6; i++) {
				vx = game.window_manager->viewGetCenterX() + 231 + 15;
				for (int j = 0; j < 4; j++) {
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
						if (inv_spells[i * 4 + j] != 0) {
							for (int k = 0; k < 9; k++) {
								if (hotbar_spells[k] == 0) {
									hotbar_spells[k] = inv_spells[i * 4 + j];
									inv_spells[i * 4 + j] = 0;
									break;
								}
							}
						}
					}
					vx += 112;
					}
				vy += 112;
				}
			vy = game.window_manager->viewGetCenterY() + 384 + 15;
			for (int i = 0; i < 9; i++) {
				vx = game.window_manager->viewGetCenterX() - 536 + 15 + 112 * i;
					if (vx/1 <= out && out <= vx/1 + 56 && vy/1 <= outy && outy <= vy/1 + 56) {
					for (int j = 0; j < 24; j++) {
						if (inv_spells[j] == 0 && cooldowns[i] <= 0) {
							inv_spells[j] = hotbar_spells[i];
							hotbar_spells[i] = 0;
							break;
						}
					}
				}
			}
		}
	}
	void ifs(auto& game) { //split into several methods
		bool is_info = false;
		float out = game.player->getX() - (962 - Mouse::getPosition().x);
		float outy = game.player->getY() - (544 - Mouse::getPosition().y);
		if (is_inventory_open) {
			float vx = game.window_manager->viewGetCenterX() + 261;
			float vy = game.window_manager->viewGetCenterY() - 343;
			for (int i = 0; i < 6; i++) {
				vx = game.window_manager->viewGetCenterX() + 261;
				for (int j = 0; j < 4; j++) {
					if (isInsideRectangle(out, outy, vx - 25, vy - 25, 105, 105)) {
						setInfo(true, inv_items[i * 4 + j].getID(), game.renderer->text_manager->text_info);
						game.renderer->sprite_manager->GuiInfoSprite.setPosition(out - 10, outy);
						game.renderer->text_manager->text_info.setPosition(out, outy + 15);
						is_info = true;
					}
					vx += 112;
				}
				vy += 112;
			}
		}
		if (is_inventory_spells_open) {
			float vx = game.window_manager->viewGetCenterX() + 261;
			float vy = game.window_manager->viewGetCenterY() - 343;
		    for (int i = 0; i < 6; i++) {
		    	vx = game.window_manager->viewGetCenterX() + 261;
			    for (int j = 0; j < 4; j++) {
					if (vx/1 - 25 <= out && out <= vx/1 + 80 && vy/1 - 25 <= outy && outy <= vy/1 + 80) {
						setInfo(false, inv_spells[i * 4 + j], game.renderer->text_manager->text_info);
						game.renderer->sprite_manager->GuiInfoSprite.setPosition(out - 10, outy);
						game.renderer->text_manager->text_info.setPosition(out, outy + 15);
						is_info = true;
					}
				    vx += 112;
		    	}
			    vy += 112;
		    }
		}

		float vx = game.window_manager->viewGetCenterX() - 506;
		float vy = game.window_manager->viewGetCenterY() + 414;
		for (int i = 0; i < 9; i++) {
			if (vx/1 - 30 <= out && out <= vx/1 + 80 && vy/1 - 30 <= outy && outy <= vy/1 + 80 && hotbar_spells[i] != 0) {
				setInfo(false, hotbar_spells[i], game.renderer->text_manager->text_info);
				game.renderer->sprite_manager->GuiInfoSprite.setPosition(vx - 34, vy - 270);
				game.renderer->text_manager->text_info.setPosition(vx - 24, vy - 270 + 15);
				is_info = true;
			}
			vx += 112;
		}

		vx = game.window_manager->viewGetCenterX() - 940;
		vy = game.window_manager->viewGetCenterY() - 480;
		if (vx/1 <= out && out <= vx/1 + 170 && vy/1 <= outy && outy <= vy/1 + 100) {
			game.renderer->text_manager->text_strength.setString("Strength: " + std::to_string(game.player->strength));
			game.renderer->text_manager->text_damage.setString("Damage: " + std::to_string(game.player->damage));
			game.renderer->text_manager->text_armor.setString("Armor: " + std::to_string(game.player->armor));
			game.renderer->text_manager->text_magic.setString("Magic: " + std::to_string(game.player->magic));
			game.renderer->text_manager->text_critical_chance.setString("Critical Chance: " + std::to_string(static_cast<int>(game.player->critical_chance)) + "%");
			game.renderer->text_manager->text_magic_resistance.setString("Magic Resistance: " + std::to_string(static_cast<int>(game.player->magic_resistance)) + "%");
			game.renderer->text_manager->text_physical_resistance.setString("Physical Resistance: " + std::to_string(static_cast<int>(game.player->physical_resistance)) + "%");
			game.renderer->text_manager->text_magic_ice.setString("Magic Ice: " + std::to_string(game.player->magic_ice));
			game.renderer->text_manager->text_magic_fire.setString("Magic Fire: " + std::to_string(game.player->magic_fire));
			game.renderer->text_manager->text_magic_earth.setString("Magic Earth: " + std::to_string(game.player->magic_earth));
			game.renderer->text_manager->text_magic_wind.setString("Magic Wind: " + std::to_string(game.player->magic_wind));
			game.renderer->text_manager->text_magic_dark.setString("Magic Dark: " + std::to_string(game.player->magic_dark));
			game.renderer->text_manager->text_magic_light.setString("Magic Light: " + std::to_string(game.player->magic_light));
			game.renderer->text_manager->text_melee_weapon.setString("Melee Weapon: " + std::to_string(game.player->melee_weapon));
			game.renderer->text_manager->text_range_weapon.setString("Range Weapon: " + std::to_string(game.player->range_weapon));
			is_stats_open = true;
		} else {
			game.renderer->text_manager->text_strength.setString("");
			game.renderer->text_manager->text_damage.setString("");
			game.renderer->text_manager->text_armor.setString("");
			game.renderer->text_manager->text_magic.setString("");
			game.renderer->text_manager->text_critical_chance.setString("");
			game.renderer->text_manager->text_magic_resistance.setString("");
			game.renderer->text_manager->text_physical_resistance.setString("");
			game.renderer->text_manager->text_magic_ice.setString("");
			game.renderer->text_manager->text_magic_fire.setString("");
			game.renderer->text_manager->text_magic_earth.setString("");
			game.renderer->text_manager->text_magic_wind.setString("");
			game.renderer->text_manager->text_magic_dark.setString("");
			game.renderer->text_manager->text_magic_light.setString("");
			game.renderer->text_manager->text_melee_weapon.setString("");
			game.renderer->text_manager->text_range_weapon.setString("");
			is_stats_open = false;
		}

		if (!is_info) {
			game.renderer->text_manager->text_info.setString("");
		}
	}
};
