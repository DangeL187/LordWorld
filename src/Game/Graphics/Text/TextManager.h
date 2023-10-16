#include "DynamicText.h"
#include "TextInitializer.h"
#include "TextDrawer.h"

class TextManager: virtual public TextInitializer, virtual public TextDrawer {
public:
    TextManager() {
        initText();
    }

    void createDynamicText(Font font, int size, int timer, std::string value="None", float x=0, float y=0, bool isRed=false) {
        DynamicText dynamic_text(font, size, timer, value, x, y, isRed);
        v_dynamic_texts.push_back(dynamic_text);
    }
};
