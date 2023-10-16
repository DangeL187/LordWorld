class WindowManager {
private:
    std::shared_ptr<RenderWindow> window;
    unsigned int window_w = 1920; //TODO: make resolution customizable
    unsigned int window_h = 1080;
    View view;

    void createWindow(std::string name) {
        window = std::make_shared<RenderWindow>(VideoMode(window_w, window_h), name, sf::Style::Fullscreen);
        window->setFramerateLimit(120);
    }
public:
    WindowManager(std::string name, int w, int h) {
        window_w = w;
        window_h = h;
        createWindow(name);
    }

    void viewSetCenter(float x, float y) {
        view.setCenter(x, y);
    }
    void viewReset() {
        view.reset(FloatRect(0, 0, window_w, window_h));
    }
    float viewGetCenterX() {
        return view.getCenter().x;
    }
    float viewGetCenterY() {
        return view.getCenter().y;
    }

    void windowHandleEvents() {
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                window->close();
            }
        }
    }
    void windowSetView() {
        window->setView(view);
    }
    void windowClear() {
        window->clear();
    }
    void windowDisplay() {
        window->display();
    }
    void windowDraw(Sprite to_draw) {
        window->draw(to_draw);
    }
    void windowDraw(Text to_draw) {
        window->draw(to_draw);
    }

    //TODO: remove AUTO
    void windowDraw(auto to_draw) {
        window->draw(*to_draw);
    }
    bool windowIsOpen() {
        return window->isOpen();
    }
};
