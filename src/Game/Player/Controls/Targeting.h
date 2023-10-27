class Targeting: virtual public Initializer {
protected:
    void keysTargeting(auto& monsters, auto& interface_target) {
        if (Keyboard::isKeyPressed(Keyboard::LControl) && key_m2_go) {
            int mouse_x = x - (962 - Mouse::getPosition().x);
            int mouse_y = y - (544 - Mouse::getPosition().y);
            for (auto& monster: monsters) {
                float mx = monster.getX();
                float my = monster.getY();
                float mw = monster.getWidth();
                float mh = monster.getHeight();
                if (isInsideRectangle(mouse_x, mouse_y, mx, my, mw, mh)) {
                    //game.renderer->sprite_manager->circle->setRadius( )
                    //game.renderer->sprite_manager->circle->setOrigin(64, 64);
                    //game.renderer->sprite_manager->circle->setPosition(mx+mw/2, my+mh/2);
                    //game.renderer->sprite_manager->circle->setFillColor(Color(255, 255, 255, 0));
                    //game.renderer->sprite_manager->circle->setOutlineColor(Color(255, 255, 255, 255));
                    //game.renderer->sprite_manager->circle->setOutlineThickness(1);
                    interface_target.setTargetedMonster(&monster);
                    break;
                }
            }
            attack_type = 0;
        }
    }
};
