//map.h -> set map
//view.h -> center view
//split.h -> split function

//Images for Gui
//Sprites for inventory
//Sprites for hero
//player cords, attack, range, current spell, aiming vars, inventory var
//cooldowns
//player stats, damage, attack speed, weapon type, current weapon

//weapon_types.h -> check_weapon_range()

//classes.h -> Player() -> interactionWithMap()
//          |           -> update()
//          |           -> getplayercoordinateX()
//          |           -> getplayercoordinateY()
//          |-> Monster() -> interactionWithMap()
//          |             -> update()
//          |             -> checkbuff()
//          |             -> hitmonster()
//          |             -> givebuff()
//          |             -> getmonstersprite()
//          |             -> getmonsterHP()
//          |             -> getmonsterMP()
//          |             -> getmonsterLVL()
//          |             -> getmonsterNAME()
//          |             -> getmonstercoordinateX()
//          |             -> getmonstercoordinateY()
//          |-> Item() -> update()
//                     -> makeiteminvisible()
//                     -> sety()
//                     -> getitemsprite()
//                     -> getid()
//                     -> getitemcoordinateX()
//                     -> getitemcoordinateY()
//                     -> getitemNAME()

//monsters vectors
//items on the floor, items inventory
//spells inventory, hotbar

//targeting() - targeting on a monster
//spell_damaged() - who was damaged with a spell
//damaged_numbers() - who was damaged
//monsters_damaged() - the same as above

//main() - main function
    //place ColdSnap to the spells hotbar
    //text part
    //for() - add zero items in inventory

    //images.h -> GUI images

    //create window

    //create player object
    //create monsters objects
    //create zero item object
    //create Wooden Sword object
    //add item on the floor

    //set map image

    //cooldown timer for attack1

    //while () - window is open
        //for() - check monster's buffs and update monsters
        //update items //temp
        
        //attack cooldown timer
        //spells cooldown timer

        //if() - on attack
            //monsters_damaged()
            //for() - hit all monsters in attack range
            //set cooldown of attack
        
        //for() - kill dead monster

        //keys.h -> move (W, A, S, D)
        //       -> pick up items (E)
        //       -> open and close inventory (I, Escape)
        //       -> attack (MouseLeft)
        //       -> targeting (LControl && MouseRight) -> targeting()
        //       -> cast a spell (Num1, MouseLeft) -> spells.h -> spell_damaged()

        //GUI: show current target
        //drawmap.h -> draw map
        //gui.h -> set up gui
        //draw everything