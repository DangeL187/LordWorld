#include "WindowManager.h"
#include "Renderer.h"
#include "Items/DefineItemType.h"
#include "Player/Player.h"
#include "NPC/NPC.h"
#include "Monster/Monster.h"

class Game: public Renderer, public DefineItemType {
public:
    float time;
    Clock clock;
    std::shared_ptr<Player> player;
    std::vector<NPC> v_NPC;
    std::vector<Monster> v_monsters;
    std::array<std::vector<int>, 5> items_dropped;

    Game() = default;

    void initResources(auto& map_manager) {
        initText();
        createMapSprite("map.png", map_manager);
        item_sprites.push_back(createSprite("Wooden Sword.png"));
        //createGuiSprites()...
    }
    void setText() {
        font.loadFromFile("../font/OceanSummer.ttf");
        //text_cd_0.setColor(Color::White);
        //text_cd_1.setColor(Color::White);
        //text_cd_2.setColor(Color::White);
        //text_cd_3.setColor(Color::White);
        //text_cd_4.setColor(Color::White);
        //text_cd_5.setColor(Color::White);
        //text_cd_6.setColor(Color::White);
        //text_cd_7.setColor(Color::White);
        //text_cd_8.setColor(Color::White);
        //text.setColor(Color::White);
        //player_stats_hp.setColor(Color::White);
        //player_stats_hp.setStyle(sf::Text::Bold);
        //player_stats_mp.setColor(Color::White);
        //player_stats_mp.setStyle(sf::Text::Bold);
        //player_stats_lvl.setColor(Color::White);
        //player_stats_lvl.setStyle(sf::Text::Bold);
    }
    void viewSetCenter() {
        view.setCenter(player->getX(), player->getY());
    }
    void drawSprites(auto& map_manager) {
        for (int i = 0; i < map_manager.getMapHeight(); i++) {
            for (int j = 0; j < map_manager.getMapWidth(); j++) {
                map_manager.defineTile(i, j);
                map_manager.setSpritePosition(j * 64, i * 64);
                window->draw(map_manager.getSprite());
            }
        }
        for (auto& i_sprite: gui_sprites) {
            window->draw(i_sprite);
        }
        window->draw(player->getSprite());
    }
    void createItem(int id, int x, int y) {
        items_dropped[0].push_back(id);
        items_dropped[1].push_back(x);
        items_dropped[2].push_back(y);
        items_dropped[3].push_back(sprite_counter);
        defineItemType(id, other_sprites, item_sprites, items_dropped);
        other_sprites[sprite_counter].setTextureRect(IntRect(0, 0, 56, 56));
        other_sprites[sprite_counter].setScale(0.75, 0.75);
        other_sprites[sprite_counter].setPosition(x, y);
        sprite_counter++;
    }
    void createPlayer(float x, float y, float w, float h) {
        player = std::make_shared<Player>(x, y, w, h);
    }
    void updates(auto& map_manager, auto& game) {
        time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;
        player->update(time, map_manager, v_NPC, v_monsters, game);
        viewSetCenter();
    }
};
