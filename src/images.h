GuiBarImage.loadFromFile("../images/GuiBar.png");
GuiBarTexture.loadFromImage(GuiBarImage);
GuiBarSprite.setTexture(GuiBarTexture);
GuiInventoryImage.loadFromFile("../images/GuiInventory.png");
GuiInventoryTexture.loadFromImage(GuiInventoryImage);
GuiInventorySprite.setTexture(GuiInventoryTexture);

InventorySlotWeaponImage.loadFromFile("../images/GuiSlotWeapon.png");
InventorySlotShieldImage.loadFromFile("../images/GuiSlotShield.png");
InventorySlotHelmImage.loadFromFile("../images/GuiSlotHelm.png");
InventorySlotChestImage.loadFromFile("../images/GuiSlotChest.png");
InventorySlotPantsImage.loadFromFile("../images/GuiSlotPants.png");
InventorySlotBootsImage.loadFromFile("../images/GuiSlotBoots.png");
for (int i = 0; i < 27; i++) {
    InventorySlotsImage[i].loadFromFile("../images/GuiSlot.png");
}
InventorySlotWeaponTexture.loadFromImage(InventorySlotWeaponImage);
InventorySlotShieldTexture.loadFromImage(InventorySlotShieldImage);
InventorySlotHelmTexture.loadFromImage(InventorySlotHelmImage);
InventorySlotChestTexture.loadFromImage(InventorySlotChestImage);
InventorySlotPantsTexture.loadFromImage(InventorySlotPantsImage);
InventorySlotBootsTexture.loadFromImage(InventorySlotBootsImage);
for (int i = 0; i < 27; i++) {
    InventorySlotsTexture[i].loadFromImage(InventorySlotsImage[i]);
}
InventorySlotWeaponSprite.setTexture(InventorySlotWeaponTexture);
InventorySlotShieldSprite.setTexture(InventorySlotShieldTexture);
InventorySlotHelmSprite.setTexture(InventorySlotHelmTexture);
InventorySlotChestSprite.setTexture(InventorySlotChestTexture);
InventorySlotPantsSprite.setTexture(InventorySlotPantsTexture);
InventorySlotBootsSprite.setTexture(InventorySlotBootsTexture);
for (int i = 0; i < 27; i++) {
    InventorySlotsSprite[i].setTexture(InventorySlotsTexture[i]);
}

InventoryItemEmptyImage.loadFromFile("../images/GuiEmptyItem.png");
InventoryItemWeaponImage.loadFromFile("../images/GuiEmptyItem.png");
InventoryItemShieldImage.loadFromFile("../images/GuiEmptyItem.png");
InventoryItemHelmImage.loadFromFile("../images/GuiEmptyItem.png");
InventoryItemChestImage.loadFromFile("../images/GuiEmptyItem.png");
InventoryItemPantsImage.loadFromFile("../images/GuiEmptyItem.png");
InventoryItemBootsImage.loadFromFile("../images/GuiEmptyItem.png");
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
