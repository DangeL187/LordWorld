map_image.loadFromFile("../images/map.png");
map_texture.loadFromImage(map_image);
map_sprite.setTexture(map_texture);

GuiBarImage.loadFromFile("../images/GuiBar.png");
GuiInventoryImage.loadFromFile("../images/GuiInventory.png");
GuiSpellsHotbarImage.loadFromFile("../images/GuiSpellsHotbar.png");
GuiBarTexture.loadFromImage(GuiBarImage);
GuiInventoryTexture.loadFromImage(GuiInventoryImage);
GuiSpellsHotbarTexture.loadFromImage(GuiSpellsHotbarImage);
GuiBarSprite.setTexture(GuiBarTexture);
GuiInventorySprite.setTexture(GuiInventoryTexture);
GuiSpellsHotbarSprite.setTexture(GuiSpellsHotbarTexture);

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
    InventoryItemsTexture[i].loadFromImage(InventoryItemsImage[i]);
    InventoryItemsSprite[i].setTexture(InventoryItemsTexture[i]);
}

for (int i = 0; i < 9; i++) {
    SpellsHotbarImages[i].loadFromFile("../images/GuiEmptySpell.png");
    SpellsHotbarTextures[i].loadFromImage(SpellsHotbarImages[i]);
    SpellsHotbarSprites[i].setTexture(SpellsHotbarTextures[i]);
}
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
