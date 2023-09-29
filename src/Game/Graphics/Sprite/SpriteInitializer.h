class SpriteInitializer {
public:
    //preinitialized sprites:
    std::vector<Sprite> gui_sprites;
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
    Sprite GuiNoManaSprites[9];
    Sprite GuiIndicatorSprite;
    Sprite GuiInfoSprite;
    Sprite GuiPickedSpellSprite;
    Sprite GuiEquipmentSprites[6];
    Sprite InventoryItemsSprite[27];
    Sprite SpellsInventorySprite[24];
    Sprite SpellsHotbarSprites[9];
    Sprite InventoryItemEmptySprite;
    Sprite AnimationWeaponSprite;
    Sprite AnimationShieldSprite;
    Sprite AnimationDashSprite;

    void initImages() {
        ColdSnapSprite = createSprite("ColdSnap.png");
        ColdSnap2Sprite = createSprite("ColdSnap2.png");
        AnimationDashSprite = createSprite("AnimationDash.png");
        AnimationWoodenSwordSprite = createSprite("AnimationWoodenSword.png");
        AnimationIronShieldSprite = createSprite("AnimationIronShield.png");

        InventoryItemEmptySprite = createSprite("GuiEmptyItem.png");
        AnimationWeaponSprite = createSprite("GuiEmptyItem.png");
        AnimationShieldSprite = createSprite("GuiEmptyItem.png");
        GuiEquipmentSprites[0] = createSprite("GuiSlotWeapon.png"); //TODO: replace with unique sprite names
        GuiEquipmentSprites[1] = createSprite("GuiSlotShield.png");
        GuiEquipmentSprites[2] = createSprite("GuiSlotHelm.png");
        GuiEquipmentSprites[3] = createSprite("GuiSlotChest.png");
        GuiEquipmentSprites[4] = createSprite("GuiSlotPants.png");
        GuiEquipmentSprites[5] = createSprite("GuiSlotBoots.png");
        for (int i = 0; i < 27; i++) {
            InventoryItemsSprite[i] = createSprite("GuiEmptyItem.png");
            //SpellsInventoryPageImage[i] = createSprite("GuiEmptyItem.png");
        }
    }
};
