#include "Aiming.h"
#include "Critical.h"
#include "Dash.h"
#include "Defence.h"
#include "Enter.h"
#include "Escape.h"
#include "Events.h"
#include "Inventory.h"
#include "Movement.h"
#include "MouseButtons.h"
#include "Targeting.h"

class Controls: virtual public Initializer,
				virtual protected Aiming,
				virtual protected Critical,
				virtual protected Dash,
				virtual protected Defence,
				virtual protected Enter,
				virtual protected Escape,
				virtual protected Events,
				virtual protected Inventory,
				virtual protected Movement,
				virtual protected MouseButtons,
				virtual protected Targeting {
protected:
	void controls(auto& time, auto& game) {
		auto& entity_manager = game.entity_manager;
		auto& window_manager = game.window_manager;

		keysMovement(time);
		keysAiming();
		keyCritical();
		keyDash();
		keyDefence();
		keyEnter();
		keyEscape();
		keysEvents(entity_manager, window_manager);
		keysInventory();
		keysTargeting(game.entity_manager->v_monsters, game.renderer->interface_manager->interface_target);
		mouseButtons(game);
	}
};
