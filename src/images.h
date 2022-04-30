map_image.loadFromFile("../images/map.png");
map_texture.loadFromImage(map_image);
map_sprite.setTexture(map_texture);

GuiBarImage.loadFromFile("../images/GuiBar.png");
GuiInventoryImage.loadFromFile("../images/GuiInventory.png");
GuiSpellsInventoryImage.loadFromFile("../images/GuiSpellsInventory.png");
GuiSpellsHotbarImage.loadFromFile("../images/GuiSpellsHotbar.png");
GuiInfoImage.loadFromFile("../images/GuiInfo.png");
GuiStatsImage.loadFromFile("../images/GuiStats.png");
GuiPickedSpellImage.loadFromFile("../images/GuiPickedSpell.png");
GuiBarTexture.loadFromImage(GuiBarImage);
GuiInventoryTexture.loadFromImage(GuiInventoryImage);
GuiSpellsInventoryTexture.loadFromImage(GuiSpellsInventoryImage);
GuiSpellsHotbarTexture.loadFromImage(GuiSpellsHotbarImage);
GuiInfoTexture.loadFromImage(GuiInfoImage);
GuiStatsTexture.loadFromImage(GuiStatsImage);
GuiPickedSpellTexture.loadFromImage(GuiPickedSpellImage);
GuiBarSprite.setTexture(GuiBarTexture);
GuiInventorySprite.setTexture(GuiInventoryTexture);
GuiSpellsHotbarSprite.setTexture(GuiSpellsHotbarTexture);
GuiInfoSprite.setTexture(GuiInfoTexture);
GuiStatsSprite.setTexture(GuiStatsTexture);
GuiPickedSpellSprite.setTexture(GuiPickedSpellTexture);
GuiSpellsInventorySprite.setTexture(GuiSpellsInventoryTexture);

InventoryItemEmptyImage.loadFromFile("../images/GuiEmptyItem.png");
InventoryItemWeaponImage.loadFromFile("../images/GuiSlotWeapon.png");
InventoryItemShieldImage.loadFromFile("../images/GuiSlotShield.png");
InventoryItemHelmImage.loadFromFile("../images/GuiSlotHelm.png");
InventoryItemChestImage.loadFromFile("../images/GuiSlotChest.png");
InventoryItemPantsImage.loadFromFile("../images/GuiSlotPants.png");
InventoryItemBootsImage.loadFromFile("../images/GuiSlotBoots.png");
InventoryItemEmptyTexture.loadFromImage(InventoryItemEmptyImage);
InventoryItemWeaponTexture.loadFromImage(InventoryItemWeaponImage);
InventoryItemShieldTexture.loadFromImage(InventoryItemShieldImage);
InventoryItemHelmTexture.loadFromImage(InventoryItemHelmImage);
InventoryItemChestTexture.loadFromImage(InventoryItemChestImage);
InventoryItemPantsTexture.loadFromImage(InventoryItemPantsImage);
InventoryItemBootsTexture.loadFromImage(InventoryItemBootsImage);
InventoryItemEmptySprite.setTexture(InventoryItemEmptyTexture);
InventoryItemWeaponSprite.setTexture(InventoryItemWeaponTexture);
InventoryItemShieldSprite.setTexture(InventoryItemShieldTexture);
InventoryItemHelmSprite.setTexture(InventoryItemHelmTexture);
InventoryItemChestSprite.setTexture(InventoryItemChestTexture);
InventoryItemPantsSprite.setTexture(InventoryItemPantsTexture);
InventoryItemBootsSprite.setTexture(InventoryItemBootsTexture);
for (int i = 0; i < 27; i++) {
    InventoryItemsImage[i].loadFromFile("../images/GuiEmptyItem.png");
    SpellsInventoryPageImage[i].loadFromFile("../images/GuiEmptyItem.png");
    InventoryItemsTexture[i].loadFromImage(InventoryItemsImage[i]);
    SpellsInventoryPageTexture[i].loadFromImage(SpellsInventoryPageImage[i]);
    InventoryItemsSprite[i].setTexture(InventoryItemsTexture[i]);
    SpellsInventoryPageSprite[i].setTexture(SpellsInventoryPageTexture[i]);
}

for (int i = 0; i < 9; i++) {
    SpellsHotbarImages[i].loadFromFile("../images/GuiEmptySpell.png");
    SpellsHotbarTextures[i].loadFromImage(SpellsHotbarImages[i]);
    SpellsHotbarSprites[i].setTexture(SpellsHotbarTextures[i]);
}
////////////////////////////////////////////////////////////////////////////////
ColdSnapImage.loadFromFile("../images/ColdSnap.png");
ColdSnap2Image.loadFromFile("../images/ColdSnap2.png");
ColdSnapTexture.loadFromImage(ColdSnapImage);
ColdSnap2Texture.loadFromImage(ColdSnap2Image);
ColdSnapSprite.setTexture(ColdSnapTexture);
ColdSnap2Sprite.setTexture(ColdSnap2Texture);
////////////////////////////////////////////////////////////////////////////////
MonsterRatImage.loadFromFile("../images/Rat.png");
MonsterRatTexture.loadFromImage(MonsterRatImage);
MonsterRatSprite.setTexture(MonsterRatTexture);
////////////////////////////////////////////////////////////////////////////////
WoodenSwordImage.loadFromFile("../images/Wooden Sword.png");
IronShieldImage.loadFromFile("../images/Iron Shield.png");
IronHelmetImage.loadFromFile("../images/Iron Helmet.png");
IronChestplateImage.loadFromFile("../images/Iron Chestplate.png");
IronPantsImage.loadFromFile("../images/Iron Pants.png");
IronBootsImage.loadFromFile("../images/Iron Boots.png");
IronRingImage.loadFromFile("../images/Iron Ring.png");
WoodenSwordTexture.loadFromImage(WoodenSwordImage);
IronShieldTexture.loadFromImage(IronShieldImage);
IronHelmetTexture.loadFromImage(IronHelmetImage);
IronChestplateTexture.loadFromImage(IronChestplateImage);
IronPantsTexture.loadFromImage(IronPantsImage);
IronBootsTexture.loadFromImage(IronBootsImage);
IronRingTexture.loadFromImage(IronRingImage);
WoodenSwordSprite.setTexture(WoodenSwordTexture);
IronShieldSprite.setTexture(IronShieldTexture);
IronHelmetSprite.setTexture(IronHelmetTexture);
IronChestplateSprite.setTexture(IronChestplateTexture);
IronPantsSprite.setTexture(IronPantsTexture);
IronBootsSprite.setTexture(IronBootsTexture);
IronRingSprite.setTexture(IronRingTexture);
