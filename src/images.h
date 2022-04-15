//off_image.loadFromFile("Images/off.png");
//off_texture.loadFromImage(off_image);

//GUI part
    GuiBarImage.loadFromFile("../images/GuiBar.png");
    GuiBarTexture.loadFromImage(GuiBarImage);
    GuiBarSprite.setTexture(GuiBarTexture);
    GuiInventoryImage.loadFromFile("../images/GuiInventory.png");
    GuiInventoryTexture.loadFromImage(GuiInventoryImage);
    GuiInventorySprite.setTexture(GuiInventoryTexture);
//
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
//
