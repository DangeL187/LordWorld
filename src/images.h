map_image.loadFromFile("../images/map.png");
map_texture.loadFromImage(map_image);
map_sprite.setTexture(map_texture);

GuiBarImage.loadFromFile("../images/GuiBar.png");
GuiInventoryImage.loadFromFile("../images/GuiInventory.png");
GuiBarTexture.loadFromImage(GuiBarImage);
GuiInventoryTexture.loadFromImage(GuiInventoryImage);
GuiBarSprite.setTexture(GuiBarTexture);
GuiInventorySprite.setTexture(GuiInventoryTexture);

InventoryItemEmptyImage.loadFromFile("../images/GuiEmptyItem.png");
InventoryItemWeaponImage.loadFromFile("../images/GuiSlotWeapon.png");
InventoryItemShieldImage.loadFromFile("../images/GuiSlotShield.png");
InventoryItemHelmImage.loadFromFile("../images/GuiSlotHelm.png");
InventoryItemChestImage.loadFromFile("../images/GuiSlotChest.png");
InventoryItemPantsImage.loadFromFile("../images/GuiSlotPants.png");
InventoryItemBootsImage.loadFromFile("../images/GuiSlotBoots.png");
for (int i = 0; i < 27; i++) {
    InventoryItemsImage[i].loadFromFile("../images/GuiEmptyItem.png");
}
InventoryItemEmptyTexture.loadFromImage(InventoryItemEmptyImage);
InventoryItemWeaponTexture.loadFromImage(InventoryItemWeaponImage);
InventoryItemShieldTexture.loadFromImage(InventoryItemShieldImage);
InventoryItemHelmTexture.loadFromImage(InventoryItemHelmImage);
InventoryItemChestTexture.loadFromImage(InventoryItemChestImage);
InventoryItemPantsTexture.loadFromImage(InventoryItemPantsImage);
InventoryItemBootsTexture.loadFromImage(InventoryItemBootsImage);
for (int i = 0; i < 27; i++) {
    InventoryItemsTexture[i].loadFromImage(InventoryItemsImage[i]);
}
InventoryItemEmptySprite.setTexture(InventoryItemEmptyTexture);
InventoryItemWeaponSprite.setTexture(InventoryItemWeaponTexture);
InventoryItemShieldSprite.setTexture(InventoryItemShieldTexture);
InventoryItemHelmSprite.setTexture(InventoryItemHelmTexture);
InventoryItemChestSprite.setTexture(InventoryItemChestTexture);
InventoryItemPantsSprite.setTexture(InventoryItemPantsTexture);
InventoryItemBootsSprite.setTexture(InventoryItemBootsTexture);
for (int i = 0; i < 27; i++) {
    InventoryItemsSprite[i].setTexture(InventoryItemsTexture[i]);
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
