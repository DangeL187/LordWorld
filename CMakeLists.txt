cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME "LordWorld")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    src/main.cpp

    src/animations.h
    src/attacks.h
    src/buffs.h
    src/classes.h
    src/cooldowns.h
    src/createItem.h
    src/draw_sprites.h
    src/drawmap.h
    src/equipment.h
    src/gainLVL.h
    src/game_functions.h
    src/game_vars.h
    src/global_timers.h
    src/gui.h
    src/guiTarget.h
    src/images.h
    src/info.h
    src/init_gui.h
    src/init_images.h
    src/init_text.h
    src/item_types.h
    src/keys.h
    src/map.h
    src/monsterDeath.h
    src/monsters.h
    src/NPC.h
    src/spells_set.h
    src/spells.h
    src/split.h
    src/text.h
    src/timers.h
    src/updates.h
    src/view.h
    src/weapon_types.h

)

# SFML
find_package(SFML 2.5 COMPONENTS graphics audio)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
