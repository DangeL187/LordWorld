class SpriteInitializer {
public:
    //TODO: TEMP:
    std::shared_ptr<CircleShape> circle;
    //preinitialized sprites:
    std::vector<Sprite> NPC_sprites;
    std::vector<Sprite> item_sprites;
    std::vector<Sprite> monster_sprites;
    std::vector<Sprite> current_item_sprites;
    std::vector<Sprite> current_other_sprites;
    int item_sprite_counter = 0;
    int other_sprite_counter = 0;
    //TODO: unite in images.png:
    Sprite ColdSnapSprite;
    Sprite ColdSnap2Sprite;
    Sprite AnimationWoodenSwordSprite;
    Sprite AnimationIronShieldSprite;
    //current sprites:
    Sprite GuiBarSprite;
    Sprite GuiInventorySprite;
    Sprite GuiInventorySpellsSprite;
    Sprite GuiHotbarSprite;
    Sprite GuiStatsSprite;
    Sprite NPCTalkSprite;
    Sprite GuiIndicatorSprite;
    Sprite GuiInfoSprite;
    Sprite GuiPickedSpellSprite;
    Sprite GuiNoManaSprites[9];
    Sprite GuiSlotWeaponSprite;
    Sprite GuiSlotShieldSprite;
    Sprite GuiSlotHelmSprite;
    Sprite GuiSlotChestSprite;
    Sprite GuiSlotPantsSprite;
    Sprite GuiSlotBootsSprite;
    Sprite InventoryItemsSprites[27];
    Sprite InventorySpellsSprites[24];
    Sprite HotbarSprites[9];
    Sprite InventoryItemEmptySprite;
    Sprite AnimationWeaponSprite;
    Sprite AnimationShieldSprite;
    Sprite AnimationDashSprite;

    void initSprites(std::shared_ptr<Map>& map) {
        circle = std::make_shared<CircleShape>(64);
        initMapSprite(map);
        initItemSprites();
        initMonsterSprites();
        initNPCSprites();
        initGuiSprites();
        initAnimationSprites();
        initSpellSprites();
    }
private:
    void initMapSprite(std::shared_ptr<Map>& map) {
        map->setSprite(createSprite("map.png"));
    }
    void initItemSprites() {
        item_sprites.push_back(createSprite("Wooden Sword.png")); //TODO: take names from file
        item_sprites.push_back(createSprite("Iron Shield.png"));
        item_sprites.push_back(createSprite("Iron Helmet.png"));
        item_sprites.push_back(createSprite("Iron Chestplate.png"));
        item_sprites.push_back(createSprite("Iron Pants.png"));
        item_sprites.push_back(createSprite("Iron Boots.png"));
        item_sprites.push_back(createSprite("Iron Ring.png"));
        item_sprites.push_back(createSprite("Rat Tail.png"));
    }
    void initMonsterSprites() {
        monster_sprites.push_back(createSprite("Rat.png"));
        monster_sprites.push_back(createSprite("Rat2.png"));
    }
    void initNPCSprites() {
        NPC_sprites.push_back(createSprite("hero.png"));
    }
    void initGuiSprites() {
        InventoryItemEmptySprite = createSprite("GuiEmptyItem.png");
        GuiSlotWeaponSprite = createSprite("GuiSlotWeapon.png"); //TODO: replace with unique sprite names
        GuiSlotShieldSprite = createSprite("GuiSlotShield.png");
        GuiSlotHelmSprite = createSprite("GuiSlotHelm.png");
        GuiSlotChestSprite = createSprite("GuiSlotChest.png");
        GuiSlotPantsSprite = createSprite("GuiSlotPants.png");
        GuiSlotBootsSprite = createSprite("GuiSlotBoots.png");
        GuiBarSprite = createSprite("GuiBar.png");
        GuiInventorySprite = createSprite("GuiInventory.png");
        GuiInventorySpellsSprite = createSprite("GuiInventorySpells.png");
        GuiHotbarSprite = createSprite("GuiHotbar.png");
        GuiStatsSprite = createSprite("GuiStats.png");
        NPCTalkSprite = createSprite("NPCTalk.png");
        GuiIndicatorSprite = createSprite("GuiIndicator.png");
        GuiInfoSprite = createSprite("GuiInfo.png");
        GuiPickedSpellSprite = createSprite("GuiPickedSpell.png");
        for (auto& i: GuiNoManaSprites) {
            i = createSprite("GuiNoMana.png");
        }

        for (auto& i: InventoryItemsSprites) {
            i = InventoryItemEmptySprite;
            //SpellsInventoryPageImage[i] = createSprite("GuiEmptyItem.png");
        }
        for (auto& i: InventorySpellsSprites) {
            i = InventoryItemEmptySprite;
        }
        for (auto& i: HotbarSprites) {
            i = InventoryItemEmptySprite;
        }
    }
    void initSpellSprites() {
        ColdSnapSprite = createSprite("ColdSnap.png");
        ColdSnap2Sprite = createSprite("ColdSnap2.png");
    }
    void initAnimationSprites() {
        AnimationDashSprite = createSprite("AnimationDash.png");
        AnimationWoodenSwordSprite = createSprite("AnimationWoodenSword.png");
        AnimationIronShieldSprite = createSprite("AnimationIronShield.png");

        AnimationWeaponSprite.setTextureRect(IntRect(0, 0, 1, 1));
        AnimationWeaponSprite = InventoryItemEmptySprite;
        AnimationShieldSprite = InventoryItemEmptySprite;
    }
};
